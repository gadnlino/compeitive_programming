#include <stdio.h>

int main(int argc, char **argv){
	int n,i,a,b,c,l,k;
	
	scanf("%d",&n);
	a = 1;
	b = 1;
	c = 1;
	l = 0;
	k = 1;
	
	printf("%d %d %d\n",a,b,c);
	
	for(i = 1;i < 2 * n;i++){ 
		if(i % 2 == 1){
			b++;
			c = a * b - l;
			k *= 2;
			printf("%d %d %d\n",a,b,c);
		}
		if(i % 2 == 0 && i > 0 ){
			b += k;
			c = a * b - l;
			l++;
			printf("%d %d %d\n",a,b,c);
			a++;
		}
	}
	
	return 0;
}

