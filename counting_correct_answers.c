#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int counting_correct_answers(char verbs[], char userverbs[], int calc)//V OTDELNII FAIL
{
    int i, flg = 1, n = 0;
    for (i = 0; verbs[i] != '\0'; i++) n = i;
    for(i = 0; i < n; i++)
		if(verbs[i] != userverbs[i]) flg = 0;
    if (flg == 1) 
	{
		calc++;
		printf ("Правильно!\n");
	}
	else printf ("Не верно\n");
	return calc;
}
