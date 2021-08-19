#include <vector>

typedef int T;

namespace BICore
{
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