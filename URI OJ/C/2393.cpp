 #include <bits/stdc++.h>
 #define MAXN 102
 using namespace std;

 bool matriz[MAXN][MAXN];

 int main(void)
 {
   memset(matriz,false,MAXN * MAXN * sizeof(bool));

   int n,area = 0;
   scanf("%d",&n);

   for(int i = 0;i < n;i++)
   {
   	int xi,xf,yi,yf;
   	scanf("%d %d %d %d",&xi,&xf,&yi,&yf);

   	for(int j = xi;j < xf;j++)
   	{
   		for(int k = yi;k < yf;k++)
   		{
   			if(!matriz[j][k])
   			{
   				matriz[j][k] = true;
   				area++;
   			}
   		}
   	}
   }

   cout << area << endl;
   
   return 0;
 }
