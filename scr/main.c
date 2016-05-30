#include <stdio.h>
// #include <locale.h>
#include <stdlib.h>
#include "scaning.h"
double complete(double pr)
{
	pr = pr * 5.0;
	return pr;
}

int main()
{
	// setlocale(LC_ALL, "Russian");
	double r = 0.0, proc = 0.0;
	r = scanning();
	//perevod v procenti
	proc = complete(r);
	printf("\nYour result: %.2f %% \n", proc);
	return 0;
}
