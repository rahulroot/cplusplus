#include<iostream>
#include<exception>
using namespace std;
int
main ()
{
  try
  {
    cout << "sum";
    throw 3;
  }
  catch (int a)
  {
    cout << a << endl;
  }
  catch (exception e)
  {
    cout << "exception";
  }
/* this catch must be last catch statement */
  catch (...)
  {
    cout << "dot";
  }
  return 0;
}
