#include <bits/stdc++.h>


using namespace std;

int main(void)
{
  int tc;
  while(true)
  {
    cin >> tc;
    if(tc == 0) break;
    queue<int> j1,j2;
    for(int i = 0;i < tc;i++)
    {
      int c;
      cin >> c;
      j1.push(c);
    }

    for(int i = 0;i < tc;i++)
    {
      int c;
      cin >> c;
      j2.push(c);
    }
    int rol1 = 0,rol2 = 0;
    int qual1 = -1,qual2 = -1;
    int pont1 = 0,pont2 = 0;

    while(!j1.empty() && !j2.empty())
    {
      int num1 = j1.front();
      j1.pop();
      int num2 = j2.front();
      j2.pop();

      // printf("%d %d\n",num1,num2);

      if(qual1 == -1)
      {
        qual1 = num1;
        rol1++;
      }
      else if(num1 == qual1) rol1++;
      else if(rol1 > 0) rol1 = 1;
      qual1 = num1;

      if(qual2 == -1)
      {
        qual2 = num2;
        rol2++;
      }
      else if(num2 == qual2) rol2++;
      else if(rol2 > 0) rol2 = 1;
      qual2 = num2;

      if(rol1 != 3 && rol2 != 3)
      {
        pont1 += num1;
        pont2 += num2;
      }
      else if(rol1 == 3 && rol2 != 3)
      {
        pont1 += 30 + num1;
        pont2 += num2;
        rol1 = rol2 = -1000;
      }
      else if(rol1 != 3 && rol2 == 3)
      {
        pont1 += num1;
        pont2 += 30 + num2;
        rol1 = rol2 = -1000;
      }
      else if(rol1 == 3 && rol2 == 3)
      {
        pont1 += num1;
        pont2 += num2;
        rol1 = -1000;
        rol2 = -1000;
      }

      //printf("m%d l%d\n",pont1,pont2);
      // printf("num1=%d -rol1=%d num2=%d -rol2=%d\n",num1,rol1,num2,rol2);

      if(rol1 > 3) rol1 = 1;
      if(rol2 > 3) rol2 = 1;
      // printf("pont1=%d pont2=%d\n",pont1,pont2);
    }


    // printf("m%d l%d\n",pont1,pont2);

    if(pont1 > pont2) printf("M\n");
    else if(pont1 < pont2) printf("L\n");
    else printf("T\n");
    // printf("\n\n");
  }



  return 0;
}
