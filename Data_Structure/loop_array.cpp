#include<algorithm>
template<typename T>
class loop_array{
  T *array;
  size_t sum;
  int zero;
  int Index(const int index) const;
  void Init();
  void Release();
public:
  explicit loop_array(size_t n);
  loop_array(size_t n,int z);
  loop_array(loop_array<T> &other);
  virtual ~loop_array();
  bool Copy(const loop_array<T> &other);
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
  loop_array<T> &operator =(const loop_array<T> &other);
  T *operator +(const int right) const;
  T *operator -(const int right) const;
};

template<typename T>
T *loop_array<T>::operator +(const int right) const
{
  return array+right;
}

template<typename T>
T *loop_array<T>::operator -(const int right) const
{
  return array-right;
}

template<typename T>
bool loop_array<T>::is_valid() const
{
  return array!=NULL;
}

template<typename T>
size_t loop_array<T>::size() const
{
  return sum;
}

template<typename T>
loop_array<T>::operator const T*() const
{
  return array;
}

template<typename T>
loop_array<T>::loop_array(size_t n)
{
  array=new T[n];
  sum=n;
  set(0);
}

template<typename T>
loop_array<T>::loop_array(size_t n,int z)
{
  array=new T[n];
  sum=n;
  set(z);
}

template<typename T>
loop_array<T>::loop_array(loop_array<T> &other)
{
  Init();
  Copy(other);
}

template<typename T>
loop_array<T>::~loop_array()
{
  Release();
}

template<typename T>
int loop_array<T>::Index(const int index) const
{
  if(zero+index>=0)
    return (zero+index)%sum;
  else
    return (zero+(sum-std::abs(index)%sum))%sum;
}

template<typename T>
void loop_array<T>::set(const int z)
{
  zero=Index(z);
}

template<typename T>
T loop_array<T>::begin() const
{
  return this[0];
}

template<typename T>
T loop_array<T>::end() const
{
  return this[size()-1];
}

template<typename T>
void loop_array<T>::sort()
{
  std::sort(array,array+sum);
  set(0);
}

template<typename T>
void loop_array<T>::reverse()
{
  int i;
  int n=size()/2;
  for(i=0;i<n;i++)
    std::swap(this[i],this[size()-i-1]);
}

template<typename T>
void loop_array<T>::dump()
{
#ifdef DEBUG
  int i;
  for(i=0;i<size();i++)
    std::cout<<"this["<<i<<"]"<<" = "<<this[i];
#endif
}

template<typename T>
T &loop_array<T>::operator [](int index)
{
  return array[Index(index)];
}

template<typename T>
T loop_array<T>::operator [](int index) const
{
  return array[Index(index)];
}

template<typename T>
bool loop_array<T>::Copy(const loop_array<T> &other)
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
      for(int i=0;i<sum;i++)
        array=other[i];
    }
  return true;
}

template<typename T>
loop_array<T> &loop_array<T>::operator =(const loop_array<T> &other)
{
  Copy(other);
  return *this;
}

template <typename T>
void loop_array<T>::Init()
{
  array=NULL;
  sum=0;
  zero=0;
}

template<typename T>
void loop_array<T>::Release()
{
  if(is_valid()==true)
    {
      delete[] array;
      Init();
    }
}
