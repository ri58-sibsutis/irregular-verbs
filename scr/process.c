#include <stdio.h>
// #include <locale.h>
#include <stdlib.h>
int slen(char str[])
{
	int len, i = 0;
	while(str[i] != '\0')
		i++;
	len = i;
	return len;
}
char toLowCase(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return ch + ('a' - 'A');
	return ch;
}
double podschet_flg(int i, double flg, char* ptr[])
{
	char userverb[1024] = "";
	int lenusr[261] = {0}, lenverb[261] = {0}, n;
	char* stroka;
	printf("\n%d) Input %d form of verb \n", i + 2, i + 2);
	fgets(userverb, 1024, stdin);		
	flg = 0.0;
	lenusr[i] = slen(userverb) - 1;
	if(lenusr[i] < 14)//lengh of irr v can't be over 14 symbols
	{
		int l;
		for(l = 0; l < lenusr[i] + 1; l++)
			userverb[l] = toLowCase(userverb[l]);
		lenverb[i] = slen(ptr[i + 1]);
		if (i == 1) lenverb[i] = lenverb[i] - 2;
		stroka = ptr[i + 1];
		printf ("%s", stroka);	
		for(n = 0; n < lenusr[i]; n++)
		{
			if(stroka[n] == userverb[n]) flg += 1.0;
		}
		flg = flg / lenverb[i];
		if((flg > 1.0) || (flg < 1.0)) flg = 0;
		return flg;
	}
	printf("\tAre you sure?\n");	
	return flg;
}
double process(char* ptr[], double calc)
{
	int i;
	calc = 0;
	double flg = 0.0;
	for (i = 0; i < 2; i++)
	{
		flg = podschet_flg(i, flg,  ptr);
		calc = calc + flg;
	}
	return calc;
}
