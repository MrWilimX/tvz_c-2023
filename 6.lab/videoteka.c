#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pronadjiFilm(char** polica,
	int r,
	int s,
	int* redakPronadenog,
	int* stupacPronadenog) 
{
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (polica[i][j] == 'N' &&
				polica[i][j + 1] == 'N' &&
				polica[i][j + 2] == 'N') 
			{

				redakPronadenog[0] = i;

				stupacPronadenog[0] = j;
				stupacPronadenog[1] = j + 1;
				stupacPronadenog[2] = j + 2;

			}
		}
	}


}



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	char** polica = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		polica[i] = (char*)malloc(m * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &polica[i][j]);
		}
	}

	int redakPronadjenog[1] = { 0 };
	int stupacPronadjenog[3] = { 0 };
	
	int jeliDostupno = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (polica[i][j]=='N'&&
				polica[i][j+1]=='N'&&
				polica[i][j+2]=='N'
				) 
			{
				jeliDostupno = 1;
			}

		}
	}

	if (jeliDostupno) {

		pronadjiFilm(polica, n, m, &redakPronadjenog, &stupacPronadjenog);
		printf("\n\n\nPosudba filmova: [%d, %d], [%d, %d] i [%d, %d]\n\n\n", 
			redakPronadjenog[0]+1, stupacPronadjenog[0]+1,
			redakPronadjenog[0]+1, stupacPronadjenog[1]+1,
			redakPronadjenog[0]+1, stupacPronadjenog[2]+1
			);
	}
	else
	{
		printf("Sve smo skoro gledali :(");
	}

	for (int i = 0; i < n; i++)
	{
		free(polica[i]);
	}

	free(polica);

	return 0;
}
