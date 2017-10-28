 #include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int k,certa = 0;
	scanf("%d",&k);

	for(int l = 0;l < 5;l++)
	{
		int a;
		scanf("%d",&a);
		if (a == k) certa++;
	}

	cout << certa << endl;

	return 0;
}
