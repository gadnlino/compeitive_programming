#include <bits/stdc++.h>
#define MAXN 102
using namespace std;

int main(int argc, char const *argv[])
{
	int qProvas = 0;
	float media = 0.0;
	string num;

	cin >> num;

	for(int a = 0;a < num.length();a++)
	{
		//printf("num [%d] = %c\n",a,num[a]);
		int dezenas = (int)num[a] - '0';
		//cout << "dezenas = " << dezenas << endl;
		if(dezenas >= 2 && dezenas <= 9)
		{
			media += dezenas;
			qProvas++;
		}
		else if(dezenas == 1 && a < num.length() - 1)
		{
			int unidades = (int)num[a + 1] - '0';
			//cout << "unidades = " << unidades << endl;
			
			if(unidades == 0)
			{
				int at = 10 * dezenas + 1 * unidades;
				media += at;
				qProvas++;
				a++;
				//cout << "at = " << at << endl;
			}
			else
			{
				media += dezenas;
				qProvas++;
			}
		}
		else
		{
			media += dezenas;
			qProvas++;
		}
		//cout << "media = " << media << endl;
	}

	media /= qProvas;

	printf("%.2f\n",media);

	return 0;
}