#include <iostream>
using namespace std;

namespace Error
{
  int count = 0;
  struct the_Towel
  {
  };				// empty struct, default generated constructor
  struct the_Game
  {
  };				// empty struct
  struct the_Ball
  {
    int b;
    the_Ball (int x = 0):b (x)
    {
    }
  };
  void update ()
  {
    count++;
  }
}

void
Pitcher ()
{
/* . */
  throw Error::the_Ball (6);
}

void
Boxer ()
{
/* . */
  throw Error::the_Towel ();
}

void
PoorSport ()
{
/* . */
  throw Error::the_Game ();
}

int main ()
{
/* . stuff here */
  try
  {
    Pitcher ();
    Boxer ();
    PoorSport ();
  }
  catch (Error::the_Ball c)
  {
    Error::update ();
    cerr << Error::count << ": threw ball " << c.b << "\n";
  }
  catch (Error::the_Towel)
  {
    Error::update ();
    cerr << Error::count << ": threw in the towel\n";
  }
  catch (Error::the_Game)
  {
    Error::update ();
    cerr << Error::count << ": threw the game\n";
  }

  return 0;
}
