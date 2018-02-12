#include<algorithm>
#include<iostream>
template<typename T>
class RingBuffer{
  T *array;
  size_t sum;
  int zero;
  bool rev;
  int Index(const int index) const;
  void Init();
  void Release();
public:
  explicit RingBuffer(size_t n);
  RingBuffer(size_t n,int z);
  RingBuffer(RingBuffer<T> &other);
  virtual ~RingBuffer();
  bool copy(const RingBuffer<T> &other);
  bool is_valid() const;
  size_t size() const;
  T begin() const;
  T end() const;
  void sort();
  void reverse();
  void dump();
  void set(const int z);
  void reset();
  T operator [](const int i) const;
  T &operator [](const int i);
  operator const T*() const;
  RingBuffer<T> &operator =(const RingBuffer<T> &other);
  T *operator +(const int right) const;
  T *operator -(const int right) const;
};

template<typename T>
T *RingBuffer<T>::operator +(const int right) const
{
  return *array[right];
}

template<typename T>
T *RingBuffer<T>::operator -(const int right) const
{
  return *array[-right];
}

template<typename T>
bool RingBuffer<T>::is_valid() const
{
  return array!=NULL;
}

template<typename T>
size_t RingBuffer<T>::size() const
{
  return sum;
}

template<typename T>
RingBuffer<T>::operator const T*() const
{
  return array;
}

template<typename T>
RingBuffer<T>::RingBuffer(size_t n)
{
  array=new T[n];
  sum=n;
  set(0);
  rev=true;
}

template<typename T>
RingBuffer<T>::RingBuffer(size_t n,int z)
{
  array=new T[n];
  sum=n;
  set(z);
  rev=true;
}

template<typename T>
RingBuffer<T>::RingBuffer(RingBuffer<T> &other)
{
  Init();
  copy(other);
}

template<typename T>
RingBuffer<T>::~RingBuffer()
{
  Release();
}

template<typename T>
int RingBuffer<T>::Index(const int index) const
{
  int i;
  if(rev==true)
    i=index;
  else
    i=-(index+1);
  if(zero+i>=0)
    return (zero+i)%sum;
  else
    return (zero+(sum-std::abs(i)%sum))%sum;
}

template<typename T>
void RingBuffer<T>::set(const int z)
{
  zero=Index(z);
}

template<typename T>
void RingBuffer<T>::reset()
{
  zero=0;
}

template<typename T>
T RingBuffer<T>::begin() const
{
  return this[0];
}

template<typename T>
T RingBuffer<T>::end() const
{
  return this[size()-1];
}

template<typename T>
void RingBuffer<T>::sort()
{
  std::sort(array,array+sum);
  set(0);
}

template<typename T>
void RingBuffer<T>::reverse()
{
  rev=!rev;
}

template<typename T>
void RingBuffer<T>::dump()
{
#ifdef DEBUG
  int i;
  for(i=0;i<size();i++)
    std::cout<<"this["<<i<<"]"<<" = "<<(*this)[i]<<std::endl;
#endif
}

template<typename T>
T &RingBuffer<T>::operator [](int index)
{
  return array[Index(index)];
}

template<typename T>
T RingBuffer<T>::operator [](int index) const
{
  return array[Index(index)];
}

template<typename T>
bool RingBuffer<T>::copy(const RingBuffer<T> &other)
{
  if(this==&other)
    return true;

  Release();

  if(other.is_valid()==true)
    {
      array=new T[other.size()];
      if(array==NULL)
        return false;
      zero=other.zero;
      sum=other.size();
      rev=other.rev;
      for(int i=0;i<sum;i++)
        array=other[i];
    }
  return true;
}

template<typename T>
RingBuffer<T> &RingBuffer<T>::operator =(const RingBuffer<T> &other)
{
  copy(other);
  return *this;
}

template <typename T>
void RingBuffer<T>::Init()
{
  array=NULL;
  sum=0;
  zero=0;
  rev=true;
}

template<typename T>
void RingBuffer<T>::Release()
{
  if(is_valid()==true)
    {
      delete[] array;
      Init();
    }
}
