/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pp pair<int, int>

const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";
class Animal {
public:
  virtual void eat() = 0;
};

class Mammal : virtual public Animal {
public:
  virtual void breathe() = 0;
};

class Bird : virtual public Animal {
public:
  virtual void fly() = 0;
};

class Bat : public Mammal, public Bird {
public:
  virtual void eat() override { /* implementation */
  }
  virtual void breathe() override { /* implementation */
  }
  virtual void fly() override { /* implementation */
  }
};

class A {
private:
  static int a; // static member variable / class member variable
  // one copy for whole class
  // object can also access this same copy
  int b;

public:
  A() { // constructor can never be made static (a type of (non-static)instance
        // member function)
    // default constructor
  }
  A(int b) { this->b = b; }

  // revisit
  // copy constructor#imp
  // Saurabh shukla #lecture 9 part3 #video26
  A(A &aa) { b = aa.b; }
  static void setData(int a) {
    a = a;
    // b = 0; //<-- wrong
    // static member function can access only static member variables of the
    // class
    // (obviously as we don't need objects to access them).
  }
  static int getData() { // static member function / class member function
    return a;
  }
  friend void fun(A);
  // #revisit
  // can only be declared and not defined here
  // can be declared in private as well as public as it is a non member function
  // it wont make a difference

  // operator overloading
  A operator+(A aa) {
    // operator overloading can be done
    // it is a way to implement compile time polymorphism
    // sizeof and ternary conditional operator cannot be overload (?:)
    A aaa;
    aaa.b = b + aa.b;
    return aaa;
  }
  A operator-() {
    // operator overloading can be done
    // it is a way to implement compile time polymorphism
    // sizeof and ternary conditional operator cannot be overload (?:)
    A temp;
    temp.b = -b;
    return temp;
  }

  ~A() {
    // revisit
    // Saurabh shukla #lecture 10 part3 #video27

    // destructor
    // cannot be static
    // takes no argument (#cannot be overloaded unlinke constructors, obviously)
    // no return type
    // invoked when object is going to be destroyed
    // doesnot destroy the object
    // actually its the last function of the object to be called before it is
    // destroyed

    // WHY?
    // defined to release resources allocated to an object
  }
};

void fun(A a) { cout << a.b << endl; }

// if static variable is private getter and setter functions must be static to
// be accessed without object creation of
//  a class maintaining the importance and sanity of static keyword

int A::a = 1;
// static variable won't be created if this line is missing
// A:: <-- membership label;

// whenever an object is created - a constructor is called !!!
// if no explicit constructor in class,

//------------------------------------------very-important-------------------------------------------------//
// compiler always creates two constructors #implicitly 1-(default constructor)
// 2-(copy constructor)

// if any constructor is created mainly parametrised, compiler does not creates
// the default constructor, but still creats  copy constructor. now this default
// non-parametrised (if you want to create) should be created explicitly if copy
// constructor is created explicitly , compiler does not creates any constructor
// now implicitly,
//------------------------------------------very-important-------------------------------------------------//

void solve() {
  A::setData(5);

  // cout << A::getData() << endl;

  // A obj1;
  // A obj2(6);

  // no constructor of this type is created
  // stil no error due to implicit creation of copy constructor by compiler
  //  A obj3(obj1);
  //  A obj4(obj2);

  // A obj5(7), obj6(8);

  // A obj7 = obj5 + obj6;    <-- gives error

  // A obj7;
  // obj7 = obj5 + obj6;
  // similar to obj7 = obj5.operator+(obj6)
  // in binary operator left one is always caller object jiski details impicilty
  // access hongi

  // obj7 = -obj2;
  // similar to obj7 = obj2.operator-();
  // should behave as a unary operator for A
  // should negate obj2 and assign to obj7

  // fun(obj2);//#revisit
  // can be called directly , because since non-member function doesnot have a
  // caller object since we cannot access member variables directly so we pass
  // the object reference
}

signed main() {
  solve();

  return 0;
}
