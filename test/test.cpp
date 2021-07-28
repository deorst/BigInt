#include <iostream>
#include <vector>

#include "../src/BigInt.h"

using namespace std;

// Creation and initialization
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

// Creators
void testAdd()
{
  cout << "\tAdd...";

  BigInt a{"0001"}, b{"0002"};
  assert(a.add(b).toString() == "0003");

  // Initial variables not changed
  assert(a.toString() == "0001");
  assert(b.toString() == "0002");

  cout << "OK\n";
}

int main()
{
  // Creation and initialization
  cout << "\nCreation and initialization\n\n";
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

  // Creators
  cout << "\nCreators\n\n";
  testAdd();
}