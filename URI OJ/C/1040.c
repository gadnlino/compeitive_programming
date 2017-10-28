#include <stdio.h>
int main(void)
{
	float N1,N2,N3,N4,NOTADOEXAME,MEDIA;

	scanf("%f %f %f %f",&N1,&N2,&N3,&N4);

	MEDIA = (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10;

	printf("Media: %.1f\n",MEDIA);

	if (MEDIA >= 7){
		printf("Aluno aprovado.\n");
	}
	if (MEDIA < 5){
		printf("Aluno reprovado.\n");
	}
	if (MEDIA >= 5 && MEDIA < 7){
		printf("Aluno em exame.\n");
		scanf("%f",&NOTADOEXAME);
		printf("Nota do exame: %.1f\n",NOTADOEXAME);
		MEDIA = (MEDIA + NOTADOEXAME) / 2;
		if(MEDIA >= 5){
			printf("Aluno aprovado.\n");
			}
		else{
			printf("Aluno reprovado.\n");
			}
			printf("Media final: %.1f\n",MEDIA);
	}
	return 0;
}
