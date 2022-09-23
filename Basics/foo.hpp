template<typename T>
void foo(T t)
{
  // undeclared();
  // undeclared(t);
  // static_assert(sizeof(int) >  10, "int too small");
  static_assert(sizeof(T) > 10, "T too small");
}