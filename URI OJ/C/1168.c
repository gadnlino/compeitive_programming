#include <stdio.h>
#include <string.h>
int main(void){
	 int n;
	 int i,k;
	 char numero[1000];
	 int len;
	 unsigned int leds = 0;

	 scanf("%d",&n);

	 for (i = 0;i < n;i++){
		 scanf("%s",numero);
		 len = strlen(numero);

		 for (k = 0;k < len;k++){
			 switch ((char)(numero[k])) {
			 	case '0':
					leds += 6;
					break;
				case '1':
					leds += 2;
					break;
				case '2':
					leds += 5;
					break;
				case '3':
					leds += 5;
					break;
				case '4':
					leds += 4;
					break;
				case '5':
					leds += 5;
					break;
				case '6':
					leds += 6;
					break;
				case '7':
					leds += 3;
					break;
				case '8':
					leds += 7;
					break;
				case '9':
					leds += 6;
					break;
			 }
		 }

		 printf("%d leds\n",leds);
		 leds = 0;
	 }
	return 0;
}
