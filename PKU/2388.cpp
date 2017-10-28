#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  vector<int> v;
  int n;
  scanf("%d",&n);

  for(int i = 0;i < n;i++)
  {
    int num;
    scanf("%d",&num);
    v.push_back(num);
  }

  sort(v.begin(),v.end());

  printf("%d\n",v[(v.size() / 2)]);

  return 0;
}
