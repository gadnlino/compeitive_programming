#include <bits/stdc++.h>

using namespace std;


vector<int> v;
int root = 1;

int seq(int,int);
int split(int);

int main(void){
  int j;

  cin >> j;
  seq(1,j);

  for(int i = 0;i < v.size();i++){
    cout << v[i] << endl;
  }

  /*for(int k = 0;k < j;k++){

  }*/

  return 0;
}


int seq(int num,int pos)
{
  /*if(v.size() == num){  return 0;}
  for(int k = root;k <= pos;k++){
    v.push_back(k);
  }
  return seq(num,pos + 1);*/
  int k = 1;
	while(k <= num && num <= pos)
	{
		v.push_back(k);
		k++;
	
		if(k == num)
		{
			num++;
			k = 1;
		}
	}
}


