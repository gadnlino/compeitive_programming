  #include <bits/stdc++.h>

  using namespace std;

  int main()
  {
    long long unsigned int a,b;

    while(scanf("%llu %llu",&a,&b ) != EOF)
    {
      long long unsigned int c = a^b;

      printf("%llu\n",c);
    }
    return 0;
  }
