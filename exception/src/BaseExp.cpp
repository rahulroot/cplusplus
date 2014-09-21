#include <iostream>
using namespace std;
 
class X {
public:
  class Trouble {};
  class Small : public Trouble {};
  class Big : public Trouble {};
  void f() { throw Big(); }
};
 
int main() {
  X x;
#ifdef CORRECT

 // correct scene, to handle the exception involves derived and base class 
  try {
    x.f();
  } catch(X::Small&) {
    cout << "caught Small Trouble" << endl;
  } catch(X::Big&) {
    cout << "caught Big Trouble" << endl;
  } catch(X::Trouble&) {
    cout << "caught Trouble" << endl;
  }
#endif

#ifdef ERROR
 // wrong way to handle exception, base class catch will hide all other exception involving derived class 
  try {
    x.f();
  } catch(X::Trouble&) {
    cout << "caught Trouble" << endl;
  } catch(X::Small&) {
    cout << "caught Small Trouble" << endl;
  } catch(X::Big&) {
    cout << "caught Big Trouble" << endl;
  }
#endif
}
