#include <iostream>
#include <exception>
using namespace std;
class MyExceptionBase {
public:
  virtual void raise();
};

void MyExceptionBase::raise()
{ cout << "MyExceptionBase::raise " << endl; throw *this; }

class MyExceptionDerived : public MyExceptionBase {
public:
  virtual void raise();
};

void MyExceptionDerived::raise()
{ cout << "MyExceptionDerived:: raise " << endl; throw *this; }

void f(MyExceptionBase& e)
{
  e.raise();
}

void g()
{
  MyExceptionDerived e;
  try {
    f(e);
  }
  catch (MyExceptionDerived& e) {
    cout <<"code to handle MyExceptionDerived..." << endl;
  }
  catch (...) {
    cout <<"code to handle other exceptions..." << endl;
  }
}

int main()
{
  g();
  return 0;
}
