#include <iostream>
#include <vector>
#include <sstream>

#include "../src/BigInt.h"

using namespace std;

// Creation and initialization
void testInitEmpty()
{
  cout << "\tInitEmpty...";
  BigInt a{};
  assert(a.toString() == "0");
  cout << "OK\n";
}
void testInitWithString()
{
  cout << "\tInitWithString...";

  BigInt a{"1234"};
  assert(a.toString() == "1234");

  cout << "OK\n";
}
void testInitWithVector()
{
  cout << "\tInitWithVector...";

  BigInt b{vector<int>{1, 2, 3, 4}};
  assert(b.toString() == "4321");

  cout << "OK\n";
}
void testInitWithBigInt()
{
  cout << "\tInitWithBigInt...";
  BigInt a{"1234"};
  BigInt b{a};
  assert(b.toString() == "1234");
  cout << "OK\n";
}

// Getters
void testToString()
{
  cout << "\tToString...";
  BigInt a{"4432"};
  BigInt b{
      vector<int>{4, 2, 3, 1}};
  assert(a.toString() == "4432");
  assert(b.toString() == "1324");
  cout << "OK\n";
}

// Setters
void testSetWithString()
{
  cout << "\tSetWithString...";
  BigInt a{"4321"};
  assert(a.toString() == "4321");
  a.set("7676");
  assert(a.toString() == "7676");

  // And once more :)
  assert(a.set("8143").toString() == "8143");
  assert(a.toString() == "8143");
  cout << "OK\n";
}
void testSetWithVector()
{
  cout << "\tSetWithVector...";
  BigInt a{vector<int>{1, 2, 3, 4}};
  assert(a.toString() == "4321");
  a.set(vector<int>{6, 7, 6, 7});
  assert(a.toString() == "7676");

  // And once more :)
  assert(a.set(vector<int>{3, 4, 1, 8}).toString() == "8143");
  assert(a.toString() == "8143");
  cout << "OK\n";
}
void testSetWithBigInt()
{
  cout << "\tSetWithBigInt...";
  BigInt a{"4321"}, b{"7676"}, c{"8143"};
  assert(a.toString() == "4321");
  a.set(b);
  assert(a.toString() == "7676");

  // And once more :)
  assert(a.set(c).toString() == "8143");
  assert(a.toString() == "8143");
  cout << "OK\n";
}

// Mutators
void testIncrement()
{
  cout << "\tIncrement...";

  BigInt a{"0001"}, b{"0002"};
  a.increment(b);
  assert(a.toString() == "0003");
  assert(a.increment(a).toString() == "0006");
  assert(a.increment(b).toString() == "0008");
  assert(a.increment(b).toString() == "0010");

  // TODO: Will fail.
  // assert(a.increment(a).increment(a).toString() == "0006");

  cout << "OK\n";
}
void testDecrement()
{
  cout << "\tDecrement...";

  {
    BigInt a{"0002"}, b{"0001"};
    assert(a.decrement(b).toString() == "0001");
  }
  {
    BigInt a{"1234"}, b{"0123"};
    assert(a.decrement(b).toString() == "1111");
  }
  {
    BigInt a{"0010"}, b{"0001"};
    assert(a.decrement(b).toString() == "0009");
  }
  {
    BigInt a{"1234"}, b{"0345"};
    assert(a.decrement(b).toString() == "0889");
  }
  {
    BigInt a{"0001"}, b{"0002"};
    assert(a.decrement(b).toString() == "-0001");
  }
  {
    BigInt a{"321"}, b{"1234"};
    // cout << a.decrement(b).toString() << '\n';
    assert(a.decrement(b).toString() == "-1087");
  }

  cout << "OK\n";
}
void testMultiply()
{
  cout << "\tMultiply...";
  {
    BigInt a{"0123"}, b{"0006"};
    assert(a.multiply(b).toString() == "0738");
  }
  {
    BigInt a{"0123"}, b{"0006"};
    assert(b.multiply(a).toString() == "0738");
  }
  {
    BigInt a{"0123"}, b{"0056"};
    assert(a.multiply(b).toString() == "6888");
  }
  {
    BigInt a{"0123"}, b{"0056"};
    assert(b.multiply(a).toString() == "6888");
  }
  cout << "OK\n";
}

// Overloaded operators
void testAddition()
{
  cout << "\tAddition...";
  {
    BigInt a{"1"}, b{"2"};
    assert((a + b).toString() == "3");
    assert((b + a).toString() == "3");
    // Initial variables not changed
    assert(a.toString() == "1");
    assert(b.toString() == "2");
  }
  {
    BigInt a{"1"}, b{"9"};
    assert((a + b).toString() == "10");
    assert((b + a).toString() == "10");
    // Initial variables not changed
    assert(a.toString() == "1");
    assert(b.toString() == "9");
  }
  cout << "OK\n";
}
void testSubtraction()
{
  cout << "\tSubtraction...";
  {
    BigInt a{"2"}, b{"1"};
    assert((a - b).toString() == "1");
  }
  {
    BigInt a{"21"}, b{"10"};
    assert((a - b).toString() == "11");
  }
  {
    BigInt a{"31"}, b{"12"};
    assert((a - b).toString() == "19");
  }
  {
    BigInt a{"1234"}, b{"123"};
    assert((a - b).toString() == "1111");
  }
  {
    BigInt a{"10"}, b{"1"};
    assert((a - b).toString() == "9");
  }
  {
    BigInt a{"1234"}, b{"345"};
    assert((a - b).toString() == "889");
  }
  {
    BigInt a{"1"}, b{"2"};
    assert((a - b).toString() == "-1");
  }
  {
    BigInt a{"321"}, b{"1234"};
    assert((a - b).toString() == "-913");
  }
  cout << "OK\n";
}
void testMultiplication()
{
  cout << "\tMultiplication...";
  {
    BigInt a{"1"}, b{"2"};
    assert((a * b).toString() == "2");
    assert((b * a).toString() == "2");
    assert((a * a).toString() == "1");
    assert((b * b).toString() == "4");
    assert((b * b * b).toString() == "8");
    assert((b * b * b * b).toString() == "16");
  }
  {
    BigInt a{"123"}, b{"6"};
    assert((a * b).toString() == "738");
    assert((b * a).toString() == "738");
  }
  {
    BigInt a{"123"}, b{"56"};
    assert((a * b).toString() == "6888");
    assert((b * a).toString() == "6888");
  }
  cout << "OK\n";
}
void testOutStream()
{
  cout << "\tOutstream...";
  {
    BigInt a{"123454"};
    stringstream ss;
    string s;

    ss << a;
    ss >> s;
    assert(s == "123454");
  }
  cout << "OK\n";
}
void testInStream()
{
  cout << "\tInstream...";
  {
    BigInt a{"0"};
    stringstream ss;
    ss << "456";
    ss >> a;
    assert(a.toString() == "456");
  }
  {
    BigInt a{"0"};
    stringstream ss;
    ss << "-456";
    ss >> a;
    assert(a.toString() == "-456");
  }
  cout << "OK\n";
}
void testEqual()
{
  cout << "\tEqual...";
  {
    BigInt a{"1234"}, b{"1234"};
    assert(a == b);
  }
  {
    BigInt a{"1233"}, b{"1234"};
    assert(!(a == b));
  }
  {
    BigInt a{"123"}, b{"12"};
    assert(!(a == b));
  }
  cout << "OK\n";
}
void testNotEqual()
{
  cout << "\tNotEqual...";
  {
    BigInt a{"1234"}, b{"1234"};
    assert(!(a != b));
  }
  {
    BigInt a{"1233"}, b{"1234"};
    assert(a != b);
  }
  {
    BigInt a{"123"}, b{"12"};
    assert(a != b);
  }
  cout << "OK\n";
}
void testGreaterThan()
{
  cout << "\tGreater...";
  {
    BigInt a{"1234"}, b{"123"};
    assert(a > b);
    assert(!(b > a));
  }
  {
    BigInt a{"1234"}, b{"1235"};
    assert(!(a > b));
    assert(b > a);
  }
  {
    BigInt a{"1234"}, b{"1234"};
    assert(!(a > b));
  }
  cout << "OK\n";
}
void testLessThan()
{
  cout << "\tLess...";
  {
    BigInt a{"1234"}, b{"123"};
    assert(!(a < b));
    assert(b < a);
  }
  {
    BigInt a{"1234"}, b{"1235"};
    assert(a < b);
    assert(!(b < a));
  }
  {
    BigInt a{"1234"}, b{"1234"};
    assert(!(b < a));
  }
  cout << "OK\n";
}
void testLessThanOrEqual()
{
  cout << "\tLessOrEqual...";
  {
    BigInt a{"1234"}, b{"123"};
    assert(!(a <= b));
    assert(b <= a);
  }
  {
    BigInt a{"1234"}, b{"1235"};
    assert(a <= b);
    assert(!(b <= a));
  }
  {
    BigInt a{"1234"}, b{"1234"};
    assert(a <= b);
    assert(b <= a);
  }
  cout << "OK\n";
}
void testGreaterThanOrEqual()
{
  cout << "\tGreaterOrEqual...";
  {
    BigInt a{"1234"}, b{"123"};
    assert(a >= b);
    assert(!(b >= a));
  }
  {
    BigInt a{"1234"}, b{"1235"};
    assert(!(a >= b));
    assert(b >= a);
  }
  {
    BigInt a{"1234"}, b{"1234"};
    assert(a >= b);
    assert(b >= a);
  }
  cout << "OK\n";
}
void testTrim()
{
  cout << "\tTrim...";
  {
    BigInt a{"001"};
    assert(a.toString() == "001");
    a.trim();
    assert(a.toString() == "1");
  }
  {
    BigInt a{"00100"};
    assert(a.toString() == "00100");
    a.trim();
    assert(a.toString() == "100");
  }
  {
    BigInt a{"0012300"};
    assert(a.toString() == "0012300");
    a.trim();
    assert(a.toString() == "12300");
  }
  cout << "OK\n";
}

int main()
{
  // Creation and initialization
  cout << "\nCreation and initialization\n\n";
  testInitEmpty();
  testInitWithString();
  testInitWithVector();
  testInitWithBigInt();

  // Getters
  cout << "\nGetters\n\n";
  testToString();

  // Setters
  cout << "\nSetters\n\n";
  testSetWithString();
  testSetWithVector();
  testSetWithBigInt();

  // Mutators
  cout << "\nMutators\n\n";
  testIncrement();
  testDecrement();
  testMultiply();

  // Overloaded operators
  cout << "\nOverloaded operators\n\n";
  testAddition();
  testSubtraction();
  testMultiplication();

  testOutStream();
  testInStream();

  testEqual();
  testNotEqual();

  testGreaterThan();
  testLessThan();
  testLessThanOrEqual();
  testGreaterThanOrEqual();

  // Trimming leading zeros
  cout << "\nTrimming leading zeros\n\n";
  testTrim();
}