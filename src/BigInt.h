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

  BigInt(const string &s);
  BigInt(const vector<T> &v);
  BigInt(const BigInt &a);
  string toString();
  BigInt &set(const string &s);
  BigInt &assign(const BigInt &other);
  BigInt &increment(const BigInt &other);
  BigInt &add(const BigInt &other);
};
#endif