#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> foo()
{
  unique_ptr<int> p( new int(10) );

  //return p;                   // 1
  return move( p );         // 2
}

int main()
{
  unique_ptr<int> p = foo();

  cout << *p << endl;
  return 0;
}
