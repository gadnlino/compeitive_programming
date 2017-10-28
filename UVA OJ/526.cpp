#include <bits/stdc++.h>

using namespace std;

char str1[20];
char str2[20];
char memo[20][20];

int edit(int,int);

int main(void){
  gets(str1);
  gets(str2);

  edit(strlen(str1) - 1,strlen(str2) - 1);
  return 0;
}

int edit(int a,int b){
  if(a == 0){ return b; }
  if(b == 0){ return a;}

  if(memo[a][b] != -1){ return memo[a][b];}

  if(str1[a] == str2[b]){
    memo[a][b] = str1[b];
   return edit(a-1,b-1);
 }

 return memo[a][b] =  1 + min(edit(a,b - 1),min(edit(a - 1,b),edit(a,b)));

}
