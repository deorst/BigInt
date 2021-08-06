#include "BigInt.h"
#include <iostream>
#include <vector>

using namespace std;

typedef int T;

// Helpers
int toInt(const char &c)
{
  return c - '0';
}
char toChar(const int &i)
{
  return i + '0';
}

// Constructors
BigInt::BigInt(const string &s)
{
  set(s);
}
BigInt::BigInt(const vector<T> &vec)
{
  this->vec.assign(vec.begin(), vec.end());
}
BigInt::BigInt(const BigInt &other)
{
  vec.assign(other.vec.begin(), other.vec.end());
}

// Getters
const &string BigInt::toString() const
{
  string res{};
  if (negative)
    res.push_back('-');
  for (auto i{vec.rbegin()}; i != vec.rend(); ++i)
  {
    res.push_back(toChar(*i));
  }
  return res;
}

// Setters
BigInt &BigInt::set(const string &s)
{
  vec.clear();
  for (auto i{s.rbegin()}; i != s.rend(); ++i)
  {
    vec.push_back(toInt(*i));
  }
  return *this;
}
BigInt &BigInt::set(const vector<T> &other)
{
  this->vec.assign(other.begin(), other.end());
  return *this;
}
BigInt &BigInt::set(const BigInt &other)
{
  this->vec.assign(other.vec.begin(), other.vec.end());
  return *this;
}

// Mutators
BigInt &BigInt::increment(const BigInt &a)
{
  if (a.vec.size() > vec.size())
    vec.resize(a.vec.size());
  int carry{};
  for (int i{}; i < vec.size(); ++i)
  {
    vec[i] += a.vec[i] + carry;
    carry = 0;
    if (vec[i] >= 10)
    {
      carry = vec[i];
      vec[i] %= 10;
      carry /= 10;
    }
  }
  return *this;
}
BigInt &BigInt::decrement(const BigInt &other)
{
  if (other.vec.size() > vec.size())
    vec.resize(other.vec.size());
  for (int i{}; i < vec.size(); ++i)
  {
    if (vec[i] < other.vec[i])
    {
      if ((i + 1) < vec.size() && vec[i + 1] > 0)
      {
        --vec[i + 1];
        vec[i] += 10;
      }
      else
      {
        negative = true;
      }
    }
    if (!negative)
      vec[i] -= other.vec[i];
    else
      vec[i] = other.vec[i] - vec[i];
  }
  return *this;
}
BigInt &BigInt::multiply(const BigInt &other)
{
  if (other.vec.size() > vec.size())
    vec.resize(other.vec.size());

  vector<T> temp(vec.size());
  temp.assign(vec.begin(), vec.end());
  vec.clear();
  vec.resize(temp.size());

  int carry{};
  for (int i{}; i < other.vec.size(); ++i)
  {
    for (int j{}; j < temp.size(); ++j)
    {
      vec[i + j] += other.vec[i] * temp[j] + carry;
      carry = 0;
      if (vec[i + j] >= 10)
      {
        carry = vec[i + j];
        vec[i + j] %= 10;
        carry /= 10;
      }
    }
  }
  return *this;
}

// Creators
BigInt BigInt::add(const BigInt &other)
{
  BigInt *temp{new BigInt(*this)};
  // Returns by value. Use move semantic here.
  return temp->increment(other);
}
