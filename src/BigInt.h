#ifndef BIGINT_H
#define BIGINT_H

#include <vector>

using namespace std;

typedef int T;

class BigInt
{
private:
  vector<T> vec;
  bool negative{false};

public:
  // Constructors
  BigInt(const string &s);
  BigInt(const vector<T> &v);
  BigInt(const BigInt &a);

  // Getters
  const string toString() const;

  // Setters
  BigInt &set(const string &s);
  BigInt &set(const vector<T> &other);
  BigInt &set(const BigInt &other);

  // Mutators
  void trim();
  BigInt &increment(const BigInt &other);
  BigInt &decrement(const BigInt &other);
  BigInt &multiply(const BigInt &other);

  // Operators
  friend BigInt operator+(const BigInt &a, const BigInt &b);
  friend BigInt operator-(const BigInt &a, const BigInt &b);
  friend bool operator==(const BigInt &a, const BigInt &b);
  friend bool operator!=(const BigInt &a, const BigInt &b);
  friend bool operator>(const BigInt &a, const BigInt &b);
  friend bool operator<(const BigInt &a, const BigInt &b);
  friend bool operator<=(const BigInt &a, const BigInt &b);
  friend bool operator>=(const BigInt &a, const BigInt &b);

  friend ostream &operator<<(ostream &out, const BigInt &self);
  friend istream &operator>>(istream &in, BigInt &self);
};
#endif