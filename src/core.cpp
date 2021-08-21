#include <vector>

typedef int T;

namespace BICore
{
  // Arithmetic operators
  std::vector<T> add(std::vector<T> &out, const std::vector<T> &a, const std::vector<T> &b)
  {
    if (a.size() >= b.size())
    {
      if (a.size() > out.size())
        out.resize(a.size());
      int carry{};
      for (int i{}; i < b.size(); ++i)
      {
        out[i] = b[i] + a[i] + carry;
        carry = out[i] / 10;
        out[i] %= 10;
      }

      for (int i{static_cast<int>(b.size())}; i < a.size(); ++i)
      {
        out[i] = a[i] + carry;
        carry = out[i] / 10;
        out[i] %= 10;
      }
      if (carry)
        out.push_back(carry);
      return out;
    }
    else
      return add(out, b, a);
  }
  std::vector<T> subtract(std::vector<T> &out, const std::vector<T> &big, const std::vector<T> &small)
  {
    // Here we assume a >= b
    out.resize(big.size());
    int carry{};
    for (int i{}; i < small.size(); ++i)
    {
      if (big[i] < (small[i] + carry))
      {
        out[i] = (big[i] + 10) - (small[i] + carry);
        carry = 1;
      }
      else
      {
        out[i] = big[i] - (small[i] + carry);
        carry = 0;
      }
    }
    for (int i{static_cast<int>(small.size())}; i < big.size(); ++i)
    {
      out[i] = big[i] - carry;
      carry = 0;
    }
    return out;
  }
  std::vector<T> multiply(std::vector<T> &out, const std::vector<T> &a, const std::vector<T> &b)
  {
    int carry{};
    for (int i{}; i < a.size(); ++i)
    {
      for (int j{}; j < b.size(); ++j)
      {
        if ((i + j) >= out.size())
          out.push_back(0);
        out[i + j] += a[i] * b[j] + carry;
        carry = out[i + j] / 10;
        out[i + j] %= 10;
      }
      if (carry)
      {
        if ((i + b.size()) >= out.size())
          out.push_back(0);
        out[i + b.size()] += carry;
      }
      carry = 0;
    }
    return out;
  }

  // Comparison operators
  bool equal(const std::vector<T> &a, const std::vector<T> &b)
  {
    if (a.size() != b.size())
      return false;
    else
    {
      for (int i{}; i < a.size(); ++i)
      {
        if (a[i] != b[i])
          return false;
      }
    }
    return true;
  }
  bool greaterThan(const std::vector<T> &a, const std::vector<T> &b)
  {
    if (a.size() != b.size())
    {
      return (a.size() > b.size());
    }
    else
    {
      for (int i{static_cast<int>(a.size()) - 1}; i >= 0; --i)
      {
        if (a[i] != b[i])
          return (a[i] > b[i]);
      }
    }
    return false;
  }
  bool lessThan(const std::vector<T> &a, const std::vector<T> &b)
  {
    return greaterThan(b, a);
  }
}
