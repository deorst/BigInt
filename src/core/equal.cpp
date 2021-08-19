#include <vector>

using namespace std;

typedef int T;

namespace BICore
{
  bool equal(const vector<T> &a, const vector<T> &b)
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
}