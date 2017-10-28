#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int dia,larg,alt,prof;
  cin >> dia;
  cin >> larg >> alt >> prof;

  if( larg >= dia && alt >= dia && prof >= dia) printf("S\n");
  else printf("N\n");


  return 0;
}
