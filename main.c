#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "scaning.c"
double complete(double pr)
{
	pr = pr*5.0;
	return pr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double r = 0.0, proc = 0.0;
	r = scanning();
	printf("\n %.3f %% \n", r);
	//perevod v procenti
	proc = complete(r);
	printf("\n %.3f %% \n", proc);
	return 0;
}
