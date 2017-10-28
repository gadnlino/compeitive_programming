#include <bits/stdc++.h>

using namespace std;

bool confere(string str)
{
  if(str.empty()) return true;

  char ch;
  stack<char> pilha;

  stringstream ss;
  ss << str;

  while(ss >> ch)
  {
    if(ch == '[' || ch == '(') pilha.push(ch);

    if(ch == ')')
    {
      if(pilha.empty() || pilha.top() != '(') return false;
      else pilha.pop();
    }
    if(ch == ']')
    {
      if(pilha.empty() || pilha.top() != '[') return false;
      else pilha.pop();
    }
    // cout << ch << "\n";
  }

  return pilha.empty();
}

int main(void)
{
  int tc;
  scanf("%d",&tc);

  getchar();

  for(int i = 0;i < tc;i++)
  {
    string in;
    getline(cin,in);

    confere(in) ? printf("Yes\n") : printf("No\n");
  }

  return 0;
}
