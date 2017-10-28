#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string entrada;
  int n;

  while(getline(cin,entrada))
  {
    if(entrada.empty()) break;

    stringstream ss;
    ss << entrada;
    int maxi = 0;
    while(ss >> n)
    {
      cout << "ss " <<  n << " ";
    }

    cout << endl;

  }

  return 0;
}
