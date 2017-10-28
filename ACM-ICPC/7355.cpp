#include <bits/stdc++.h>

using namespace std;

int ordena(std::vector<string>,int);

int main(void)
{
  int na;
  vector<string> v1,v2;

  while(scanf("%d",&na) != EOF)
  {
    string str;
    cin >> str;
    v1.push_back(str);
    v2.push_back(str);
  }

  int x = ordena(v1,1);
  int c = ordena(v2,2);

  printf("%d-%d\n",x,c);

  return 0;
}


int ordena(vector<string> v,int mode)
{

  int conti = 0,contd = 0;

  if(mode == 1)
  {
    conti++;
    for(int i = 0;i < (int)v.size();i++)
    {
      for(int j = 0;j < (int)v.size();j++)
      {
        if(v[j] > v[j+1])
        {
          conti++;
          string temp = v[j];
          v[j] = v[j+1];
          v[j+1] = temp;
        }
      }
    }
    return conti;
  }

  if(mode == 2)
  {
    for(int i = 0;i < (int)v.size();i++)
    {
      for(int j = 0;j < (int)v.size();j++)
      {
        if(v[j] < v[j+1])
        {
          contd++;
          string temp = v[j];
          v[j] = v[j+1];
          v[j+1] = temp;
        }
      }
    }
  }
  return contd;
}

