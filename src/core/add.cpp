#include <vector>

using namespace std;

typedef int T;

vector<T> add(vector<T> &out, const vector<T> &a, const vector<T> &b)
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