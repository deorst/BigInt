#ifndef BIGINT_H
#define BIGINT_H

#include <vector>

using namespace std;

typedef int T;

class BigInt
{
private:
public:
  vector<T> vec;
  bool negative{false};

  // Constructors
  BigInt(const string &s);
  BigInt(const vector<T> &v);
  BigInt(const BigInt &a);

  // Getters
  string toString();

  // Setters
  BigInt &set(const string &s);
  BigInt &set(const vector<T> &other);
  BigInt &set(const BigInt &other);

  // Mutators
  BigInt &increment(const BigInt &other);
  BigInt &decrement(const BigInt &other);
  BigInt &multiply(const BigInt &other);

  // Creators
  BigInt add(const BigInt &other);
};
#endif