#include <stdio.h>
#include <string.h>
int main(void){
	int n ,i , s ;
   char str1[51];
   char str2[51];
   int len1,len2,maior;
   
   scanf("%d",&n);

   for(i = 0;i < n;i++){
	   
     scanf("%s %s",&str1,&str2);

     len1 = strlen(str1);
     len2 = strlen(str2);
     
     if(len1 < len2) maior = len2;
     else maior = len1;
     
     for(s = 0;s < maior;s++){
		if(s < len1) printf("%c",str1[s]);
		if (s < len2) printf("%c",str2[s]); 
		 }
	printf("\n");
		
	}
	return 0;
}
