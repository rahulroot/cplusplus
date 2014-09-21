#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

struct Range_error
{
  int i;
    Range_error (int n)
  {
    i = n;
  }
};

char
to_char (int n)
// if n is an integer in the range of valid character codes, return n as a char,
// // otherwise throw a range error.
{
  if (n < numeric_limits < char >::min ()
      || numeric_limits < char >::max () < n)
    throw Range_error (n);
  return n;
}

void
g (int m)
{
  try
  {
    char c = to_char (m);
  }
  catch (Range_error x)
  {
  cerr <<"oops:to_char (" << x.i << ")\n";
  }
}

int main(int argc, char **argv)
{
	g( atoi(argv[1]));
	return 0;
	
}
