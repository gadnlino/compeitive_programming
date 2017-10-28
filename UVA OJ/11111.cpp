#include <bits/stdc++.h>
#define MAXN 0x3f3f3f
using namespace std;

int dentro[MAXN];

int main(void)
{
  string entrada;
  int n;

  while(getline(cin,entrada))
  {
    bool dah = true;

    if(entrada.empty())
    {
      printf(":-) Matrioshka!\n");
      continue;
    }

    stringstream ss;
    ss << entrada;
    stack<int> pilha;
    map<int,int> mapa;

    for(int i = 0;i < MAXN;i++)
    {
      dentro[i] = 0;
    }

    while(ss >> n)
    {
      if(mapa.find(abs(n)) == mapa.end())
      {
        mapa[abs(n)] = 0;
      }

      if(pilha.empty())
      {
        pilha.push(n);
      }
      else
      {
        if(n < 0)
        {
          pilha.push(n);
        }
        else if(n > 0)
        {
          if(n == abs(pilha.top()))
          {
            // printf("%d - - %d\n",arr[i],pilha.top());
            int num = abs(pilha.top());
            pilha.pop();

            mapa[num] = 0;

            if(!pilha.empty())
            {
              int current = abs(pilha.top());
              // printf("%d\n",current);
              mapa[current] = mapa[current] + num;

              if(mapa[current] >= current)
              {
                dah = false;
                break;
              }
              // printf("d %d %d\n",current,dentro[current]);
            }
          }
          else
          {
            dah = false;
            break;
          }
        }
    }
  }

  if(!pilha.empty()) dah = false;

  dah ? printf(":-) Matrioshka!\n") : printf(":-( Try again.\n");
  }

  return 0;
}
