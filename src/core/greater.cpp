#include <vector>

using namespace std;

typedef int T;

namespace BICore 
{
  bool greater(const vector<T> &a, const vector<T> &b)
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
}
