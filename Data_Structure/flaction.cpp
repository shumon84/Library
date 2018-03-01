#include<string>
#include<cstdio>

class flaction {
private:
  int numer; // 分子
  int denom; // 分母

public:
  flaction();
  flaction(const int numer, const int denom = 1);
  flaction(const flaction &other);
  virtual ~flaction();

public:
  int Numer() const;
  void Numer(const int numer);
  int Denom() const;
  void Denom(const int denom);
  static void Correspondence(const flaction &a, const flaction &b); // 通分
  static void Normal(const flaction &a); // 約分
  static flaction Reciprocal(const flaction a); // 逆数
  static std::string to_string(const flaction a); // 文字列化
  void Correspondence(flaction &a) const; // 通分
  void Normal() const; // 約分
  flaction Reciprocal() const; // 逆数
  std::string to_string() const; // 文字列化

public:
  flaction operator -() const {
    return flaction(- Numer(), Denom());
  }
  flaction operator +() const {
    return *this;
  }
  flaction &operator =(const flaction &other) {
    this->Numer(other.Numer());
    this->Denom(other.Denom());
    return *this;
  }
  flaction operator +(const flaction &right) const {
    int n = std::max(this->Denom(), right.Denom());
    int m = std::min(this->Denom(), right.Denom());
    while(m != 0) {
      n = n % m;
      std::swap(n, m);
    }
    int mul = this->Denom() * right.Denom() / n;
    int nmul = this->Numer() * right.Denom() / n;
    int mmul = right.Numer() * this->Denom() / n;
    return flaction(nmul + mmul, mul);
  }
  flaction operator -(const flaction &right) const {
    return flaction(*this + -right);
  }
  flaction operator *(const flaction &right) const {
    return flaction(this->Numer() * right.Numer(),
                    this->Denom() * right.Denom());
  }
  flaction operator /(const flaction &right) const {
    return flaction(*this * Reciprocal(right));
  }
  flaction operator +=(const flaction &right) {
    return *this = *this + right;
  }
  flaction operator -=(const flaction &right) {
    return *this = *this - right;
  }
  flaction operator *=(const flaction &right) {
    return *this = *this * right;
  }
  flaction operator /=(const flaction &right) {
    return *this = *this / right;
  }
  bool operator >(const flaction &right) const {
    return (*this - right).Numer() > 0;
  }
  bool operator >=(const flaction &right) const {
    return (*this - right).Numer() >= 0;
  }
  bool operator ==(const flaction &right) const {
    return  (*this - right).Numer() == 0;
  }
  bool operator <=(const flaction &right) const {
    return  !(*this > right);
  }
  bool operator <(const flaction &right) const {
    return  !(*this >= right);
  }
  bool operator !=(const flaction &right) const {
    return !(*this == right);
  }
  operator int() const {
    return Numer() / Denom();
  }
  operator double() const {
    return (double)Numer() / Denom();
  }
};

void flaction::Correspondence(const flaction &a, const flaction &b) {
  int n = std::max(a.Denom(), b.Denom());
  int m = std::min(a.Denom(), b.Denom());
  while(m != 0) {
    n = n % m;
    std::swap(n, m);
  }
  int mul = a.Denom() * b.Denom() / n;
  *const_cast<flaction*>(&a) = flaction(a.Numer() * mul / a.Denom(), mul);
  *const_cast<flaction*>(&b) = flaction(b.Numer() * mul / b.Denom(), mul);
}

void flaction::Correspondence(flaction &a) const {
  Correspondence(*this, a);
}

void flaction::Normal(const flaction &a) {
  int n = std::max(a.Numer(), a.Denom());
  int m = std::min(a.Numer(), a.Denom());
  while(m != 0) {
    n = n % m;
    std::swap(n, m);
  }
  const_cast<flaction*>(&a)->Numer(a.Numer()/n);
  const_cast<flaction*>(&a)->Denom(a.Denom()/n);
}

void flaction::Normal() const {
  Normal(*this);
}

flaction flaction::Reciprocal(const flaction a) {
  return flaction(a.Denom(), a.Numer());
}

flaction flaction::Reciprocal() const {
  return Reciprocal(*this);
}

std::string flaction::to_string(const flaction a) {
  return std::to_string(a.Numer()) + "/" + std::to_string(a.Denom());
}

std::string flaction::to_string() const {
  return to_string(*this);
}

flaction::flaction() {
  numer = 0;
  denom = 1;
}

flaction::flaction(const int numer, const int denom) {
  this->numer = numer;
  if(denom  == 0)
    this->denom = 1;
  else
    this->denom = denom;
}

flaction::flaction(const flaction &other) {
  numer  = other.numer;
  denom = other.denom;
}

flaction::~flaction() {
}

int flaction::Numer() const{
  return numer;
}

void flaction::Numer(const int numer) {
  this->numer = numer;
}

int flaction::Denom() const{
  return denom;
}

void flaction::Denom(const int denom) {
  if(denom != 0)
    this->denom = denom;
}
