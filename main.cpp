#include "Basics/max1.hpp"
#include <string>
#include <iostream>

int main()
{
  int m = ::max(4,5);
  std::cout<<"max(4,5) is "<<m<<std::endl;

  double f1 = 22.7;
  double f2 = 100.98;
  std::cout<<"max(f1,f2) is "<< ::max(f1,f2)<<std::endl;

  std::string s1 = "mathematics";
  std::string s2 = "math";

  std::cout<<"max(s1,s2) is "<<::max(s1,s2)<<std::endl;
}