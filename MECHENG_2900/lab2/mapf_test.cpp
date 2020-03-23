/*
#include <iostream>
using namespace std;

int main()
{
   char cont('y');
   int val(0);
   float desired(0);

   // initial and final parameters
   int init1(0), fin1(0);
   int init2(0), fin2(0);
   
   do {
      cout << "Enter value: ";
      cin >> val;
      cout << "Enter initial range (2 values): ";
      cin >> init1 >> fin1;
      cout << "Enter new range (2 values): ";
      cin >> init2 >> fin2;

      desired = (float)val / (float)(fin1 - init1);
      desired *= (float)(fin2 - init2);
      desired += (float)init2;

      cout << "The new value range is " << desired << endl;
      
      cout << "Continue? (y/n) ";
      cin >> cont;
   } while (cont != 'n');

   return 0;
}
*/
