#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
char toLowCase(char ch)
{
	if(ch>='A'&&ch<='Z')
		return ch+('a'-'A');
	return ch;
}
int schr(char*str, char ch)
{
	int i=0, idx=-1;
	for(i=0;(str[i]!='\0')&&(str[i]!=ch);i++);
	if(str[i]==ch) idx=i;
	//printf("%d=idx\n", idx);
	return idx;
}
int slen(char str[])
{
	int len, i=0;
	while(str[i]!='\0')i++;
		len=i;
	return len;
}
int forbSymb(char str[])
{
    char symbols[] = {"/?'.,;:-)(*&^%$#@!~`�"};
    int lensymb = slen(symbols);
    int flg = -1;
    for (int i = 0; i < lensymb; i++)
    {
        flg = schr(str, symbols[i]);
        if (flg != -1)
        {
            break;
        }
    }
    return flg;
}
double process(char* ptr[], double calc)
{
	int i, lenusr[261]={0}, lenverb[261]={0}, n, erorsymb;
	char *stroka;
	calc = 0;
	double flg = 0.0; char userverb[1024] = "";
	for (i = 0; i < 2; i++)
	{
		printf("Dopishite %d formu glagola \n", i+2);
		scanf("%s", userverb);
		erorsymb = forbSymb(userverb);
		flg = 0.0;
		lenusr[i] = slen(userverb);
		lenverb[i] = slen(ptr[i + 1]);
		stroka = ptr[i + 1];
		printf ("%s", stroka);
		if (i == 1) lenverb[i]--;
		if (lenusr[i] == lenverb[i])
		{
			for(n=0; n < lenusr[i]; n++)
			{
				userverb[n] = toLowCase(userverb[n]);
				if(stroka[n] == userverb[n]) flg += 1.0;
			}
			flg = flg / lenusr[i];
		}
		printf("\n %.3f flg \n", flg);
		calc = calc + flg;
	}
	return calc;
}
