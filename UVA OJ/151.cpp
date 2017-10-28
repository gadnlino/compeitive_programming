#include <bits/stdc++.h>
#include <vector>
#include <time.h>

using namespace std;

vector<int> array;
vector<int> backup;

int main(void){
	int qtd,step,i,a,red,ver;
	
	srand(time(NULL));
	
	while (1){
		scanf("%d",&qtd);
		if(qtd == 0){break;}
		
		
		for(a = 1;a <= qtd;a++){
			array.push_back(a);
			backup.push_back(a);
		}
		
		ver = qtd;
		
		while (ver > 1){
			step = rand() % (qtd + 1);
			cout << step << "\n";
			for(i = 0;;i += step){
				red = i % qtd;
				
				if(array[red] != 13){
					array[red] = 0;
					ver--;	
				}
				
				if(array[red] == 13){
					array = backup;
					ver = qtd;
					break;
				}
			}
				
		}
		
		printf("step = %d\n",step);
	}
	
	
	return 0;
}
