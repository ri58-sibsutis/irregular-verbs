#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int slen(char str[])
{
	int len, i=0;
	while(str[i]!='\0')i++;
	len=i;
	return len;
}
double process(char* ptr[], double calc)
{
	int i, lenusr[261]={0}, lenverb[261]={0}, n;
	char *stroka;
	calc = 0;
	double flg = 0.0; char userverb[1024] = "";
	for (i = 0; i < 2; i++)
	{
		printf("Допишите %d-ю форму глагола \n", i+2);
		scanf("%s", userverb);
		flg = 0.0;
		//stroka = {0};
		lenusr[i] = slen(userverb);
		lenverb[i] = slen(ptr[i + 1]);
		stroka = ptr[i + 1];
		printf ("%s", stroka);
		if (i == 1) lenverb[i]--;
		if (lenusr[i] == lenverb[i])
		{
			for(n=0; n < lenusr[i]; n++)
			{
				if(stroka[n] == userverb[n]) flg += 1.0;
			}
			flg = flg / lenusr[i];
		}
		printf("\n %.3f flg \n", flg);
		calc = calc + flg;
	}
	return calc;
}
