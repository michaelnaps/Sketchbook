#include <iostream>
using namespace std;

int main()
{
   int val(0);
   float desired(0);

   // initial and final parameters
   int init1(0), fin1(1023);
   int init2(0), fin2(5);

   cout << "Enter initial number (0-1023 range): ";
   cin >> val;

   desired = (float)val / (float)(fin1 - init1);
   desired *= (float)(fin2 - init2);
   desired += (float)init2;

   cout << "The value in 0-5 range is " << desired << endl;

   return 0;
}
