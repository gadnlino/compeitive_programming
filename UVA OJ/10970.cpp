#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

int main(void)
{
  string str;

  while(true)
  {
    getline(cin,str);
    if(str.empty()) break;

    stringstream ss;
    ss << str;
    int linha,coluna;
    ss >> linha >> coluna;

    int cont = 0;

    stack<pair<int,int> > pedacos;

    pedacos.push(make_pair(linha,coluna));

    while(!pedacos.empty())
    {
      pair<int,int> atual = pedacos.top();
      int l = atual.st;
      int c = atual.nd;

      //if(l == 1 && c == 1) pedacos.pop();

      if(l == 1 && c != 1)
      {
        //printf("parti o pedaco %dx%d com %d cortes\n",l,c,c-1);

        cont += c -1;
        pedacos.pop();
      }
      else if(l != 1 && c == 1)
      {

        //printf("parti o pedaco %dx%d com %d cortes\n",l,c,l-1);

        cont += l-1;
        pedacos.pop();
      }
      else if(l == 1 && c == 1) pedacos.pop();
      else
      {
        pedacos.pop();

        //printf("cortando %d pedacos de %dx%d\n",max(l,c),min(l,c),1);

        for(int i = 0;i < max(l,c);i++)
        {
          pedacos.push(make_pair(min(l,c),1));
          //cont++;
        }
        cont += max(l,c)-1;
        //printf("%dl %dc\n",l,c);
      }

      //printf("cont = %d\n",cont);

    }

    printf("%d\n",cont);
  }


  return 0;
}
