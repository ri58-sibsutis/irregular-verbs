#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "process.c"
int schr(char*str, char ch)
{
	int i=0, idx=-1;
	for(i=0;(str[i]!='\0')&&(str[i]!=ch);i++);
	if(str[i]==ch) idx=i;
	//printf("%d=idx\n", idx);
	return idx;
}
int stok(char str[], char delim, char*ptr[])
{
	char*suf=str;
	ptr[0]=str;
	int i, j=1;
	while((i=schr(suf,delim))>=0)
	{
		suf[i]='\0';
		suf=suf+i+1;
		ptr[j]=suf;
		j++;
	}
	return j;
}
double scanning()
{
	int j; double calc = 0.0;
	char* ptr[261] = {0}; //char* usr[261] = {0};
	FILE *pFile;
	char line[1024] = "";
	pFile = fopen("IRR_V.txt", "r");
	for (j = 0; j < 10; j++)
	{
		fgets(line, 1024, pFile);
		stok(line, ' ', ptr);
		printf("\n");
		printf("\n the first form = %s \n", ptr[0]);
		calc = calc + process(ptr, calc);
		printf ("%f\n", calc);
	}
	fclose(pFile);
	printf ("%f\n", calc);
	return calc;
}
