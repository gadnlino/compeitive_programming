#include <bits/stdc++.h>

using namespace std;

int main(void)
{
		int n;
		int totui,totri,totii;

		while(true)
		{
			scanf("%d",&n);
			totui = totri = totii = 0;
			if(n == 0) break;

			for(int i = 0;i < n;i++)
			{
				int ui,ri,ii;

				scanf("%d %d %d",&ui,&ri,&ii);
				int maxi = max(ui,max(ri,ii));

				if(fmod(log2(ui),1) == 0)
				{
					totui++;
					if(ui == maxi)	totui++;
				}

				if(fmod(log2(ri),1) == 0)
				{
					totri++;
					if(ri == maxi)	totri++;
				}

				if(fmod(log2(ii),1) == 0)
				{
					totii++;
					if(ii == maxi)	totii++;
				}
			}

			int maxtot = max(totui,max(totii,totri));

			if(totii == maxtot && totui != maxtot && totri != maxtot)	printf("Ingred\n");
			else if(totii != maxtot && totui == maxtot && totri != maxtot)	printf("Uilton\n");
			else if(totii != maxtot && totui != maxtot && totri == maxtot)	printf("Rita\n");
			else printf("URI\n");
		}

		return 0;
}
