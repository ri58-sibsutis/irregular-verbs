#include <stdio.h>
//#include <locale.h>
#include <stdlib.h>
#include "scaning.h"
#include "process.h"
int schr(char* str, char ch)
{
	int i = 0, idx = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
	if(str[i] == ch) idx = i;
	return idx;
}
int stok(char str[], char delim, char* ptr[])
{
	char* suf = str;
	ptr[0] = str;
	int i, j = 1;
	while((i = schr(suf, delim)) >= 0)
	{
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}
double scanning()
{
	int j; double calc = 0.0;
	char* ptr[261] = {0};
	FILE* pFile;
	char line[1024] = "";
	pFile = fopen("IRR_V.txt", "r");
	if( pFile == NULL )
		printf("Error opening file %s\n", "IRR_V.txt");
	else
	{
		for (j = 0; j < 10; j++)
		{
			printf("\n\tTASK NUMBER %d", j + 1);
			fgets(line, 1024, pFile);
			stok(line, ' ', ptr);
			printf("\n1) The first form = %s \n", ptr[0]);
			calc = calc + process(ptr, calc);
		}
		fclose(pFile);
		printf ("\nYour number of correct answers : %.0f\n", calc);
	}
	return calc;
}
