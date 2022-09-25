// #include "Basics/max1.hpp"
#include "Basics/foo.hpp"
// #include "Basics/maxauto.hpp"
// #include "Basics/maxdecltype.hpp"
// #include "Basics/maxdecltypedecay.hpp"
#include "Basics/maxcommon.hpp"
#include <string>
#include <iostream>

int main()
{
  int n = ::max(4,5);
  std::cout<<"max(4,5) is "<<n<<std::endl;

  double f1 = 22.7;
  double f2 = 100.98;
  std::cout<<"max(f1,f2) is "<< ::max(f1,f2)<<std::endl;

  std::string s1 = "mathematics";
  std::string s2 = "math";

  std::cout<<"max(s1,s2) is "<<::max(s1,s2)<<std::endl;

  uint32_t i32;
  std::cout<<sizeof(i32)<<std::endl;

  uint64_t i64;
  std::cout<<sizeof(i64)<<std::endl;

  int i = 42;
  const int c =42;
  std::cout<<::max(i,c)<<"\n";
  std::cout<<::max(c,c)<<"\n";

  int& ir = i;
  std::cout<<::max(i,ir)<<"\n";

  int arr[4];
  ::foo(&i, arr);

  // Following are errors for wrong typename
  // std::cout<<::max(4,7.2)<<"\n"; //Error: no matching function for call max(int, double) 
  std::string s;
  // ::foo("hello",s); //Error: No matching function for call to foo(const char [6], std::string&)

  // Three ways to error handling 
  // 1. Cast the arguments so that they both match.
  std::cout<<::max(static_cast<double>(4),7.2)<<"\n";
  
  // 2. Specify explicitly the type of T to prevent the compiler from attempting type deduction:
  std::cout<<::max<double>(4,7.2)<<"\n"; 

  // 3. Specify that the parameters may have different types.
  // TODO : To be discussed.

  // Type Deduction for Default Arguments
  ::f(1);
  ::f();

  auto m = ::max(66.66, 42);
  std::cout<<"max(66.66,42) is "<<m<<std::endl;
  m = ::max(42, 66.66);
  std::cout<<"max(42, 66.66) is "<<m<<std::endl;
  // In the second case the value 66.66 was type deduced to T1 i.e int so the returned value is int 66.
  
  // How to address return types in Multiple Template parameters
  // 1. Introduce a third template paramter for the return type.
  // 2. Let the Compiler find out the return type.
  // 3. Declare the return type to be the "common type" of the two paramter types
  
  // Template Parameters for Return Types
  /* 
    1. Specify the template parameters explicitly

    template<typename T>
    T max(T a, T b);

    ...

    ::max<double>(4,7.2) //explicitly instantiate T as  double

    2. Passing return type as argument

    template<typename T1, typename T2, typename RT>
    RT max (T1 a, T2 b);

    However, template argument deduction does not take return types into account, and does not appear in the types of the function call parameters. Therefore RT cannot be deduced. As a consequence, i have to manually specify the template argument list explicitly.

    Example:
    template<typename T1, typename T2, typename RT>
    RT max(T1 a, T2 b);

    ::max<int, double, double>(4, 7.2); // This works, but tedious.

    3. Explicitly specify return argument

    template<typename RT, typename T1, typename T2>
    RT max(T1 a, T2 b);

    ::max<double>(4, 7.2) // return type is double, T1 and T2 are deduced.

   */
    // Deducing the Return type:

std::cout<<::max(4,7.2)<<std::endl;

std::cout<<"max from decltype "<<::max(4, 7.2)<<std::endl;





}