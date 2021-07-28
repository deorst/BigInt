# BigInt
Big integer type for C++

# Issues

a.increment(a).increment(a)
----
```
BigInt a{"0001"};
a.increment(a).increment(a).toString(); // 4, not 3
^           ^            ^
1           1            2
```

Memory leak in `.add()` method
----
Need to set up destructor, smart pointers or something.



