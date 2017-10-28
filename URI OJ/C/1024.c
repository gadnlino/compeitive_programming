#include <stdio.h>
#include <string.h>
int main(void){
  int n, i, o , len , len1 , j , c;
  char array1[1001];
  char array2[1001];

  scanf("%d",&n);
  getchar();
  
  for(i = 0;i < n;i++){
    gets(array1);
    len = strlen(array1);
    
    for(o = 0 ; o < len ; o++){
      if((array1[o] >= 'A' && array1[o] <= 'Z')|| (array1[o] >= 'a'&& array1[o] <='z')){
        array1[o] += 3;
        }
      }
    
    c = 0;
    len = strlen(array1);
    
    for(j=len-1 ; j>=0 ; j--){
        array2[c] = array1[j];
        c++;
    }

    array2[c] = '\0';
    len1 = len/2;

    for(o = len1; o < len ;o++){
      array2[o] -= 1;
    }

	printf("%s\n",array2);
}
	
	return 0;
  }


