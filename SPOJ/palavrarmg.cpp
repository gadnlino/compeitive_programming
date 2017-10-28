#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cctype>

using namespace std;

int bubble(vector<char>);

int main()
{
  int tc;
  cin >> tc;

  for(int i = 0;i < tc;i++)
  {
    string str;
    cin >> str;
    vector<char> vetor;
    for(int j = 0;j < (int)str.size();j++)
    {
      vetor.push_back(tolower(str[j]));
    }

    bubble(vetor) == 0? cout << str << ": O" << endl : cout << str << ": N" << endl;

  }


  return 0;
}

int bubble(vector<char> vetor)
{
  int trocas = 0;

  for(int i = 0;i < (int)vetor.size();i++)
  {
    for(int j = 0;j < (int)vetor.size()- 1 - i;j++)
    {
      if(vetor[j] >= vetor[j+1])
      {
        char tmp = vetor[j+1];
        vetor[j+1] = vetor[j];
        vetor[j] = tmp;
        trocas++;
      }
    }
  }

  return trocas;
}
