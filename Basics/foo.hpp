#include <iostream>
#include <iostream>


template<typename T>
void foo(T t1,T t2)
{
  // undeclared();
  // undeclared(t);
  // static_assert(sizeof(int) >  10, "int too small");
  static_assert(sizeof(T) > 4, "T too small");
}

template<typename T = std::string>
void f(T = "")
{
  std::cout<<"template function f called"<<"\n";
}