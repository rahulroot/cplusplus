#include <exception>
#include <iostream>
using namespace std;

class MyExceptionBase { };

class MyExceptionDerived : public MyExceptionBase { };

void f(MyExceptionBase& e)
{
     throw e;
}

void g()
{
  MyExceptionDerived e;
  try {
    f(e);
  }
  catch (MyExceptionDerived& e) {
    cout <<"MeExceptionDerived." << endl;
  }
  catch (...) {
    cout <<"MeExceptionBase and any other exception.." << endl;
  }  
}

int main()
{
  g();
  return 0;
}
