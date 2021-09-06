#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

void prt(double x, double y, double e) {
	printf("Значение переменной - %lf\n", x);
	printf("Значение функции - %lf\n", y);
	printf("Значение точности - %lf\n", e);
}

double fact(double n) {
	double rez = 1;
	double i = 1;

	while (i <= n) {
		rez = rez * i;
		i++;
	}

	return(rez);
}

double erf(double x, double e) {
	double y = 0;
	double an = 1;
	double n = -1;
	while (fabs(an) > e) {
		n++;
		an = (2 * pow(x, 2 * n + 1) * pow(-1, n)) / (sqrt(PI) * fact(n) * (2 * n + 1));
		y += an;
	}
	return (y);
}

double ln(double x, double e) {
	double y = 0;
	double an = 1;
	double n = 0;
	while (fabs(an) > e) {
		n++;
		an = pow(x - 1, n) * pow(-1, n + 1) / n;
		y += an;
	}
	return (y);
}

double calcul(double x, double e, double (*fp)(double x, double e)) {
	double rez;
	rez = (*fp)(x, e);
	return(rez);
}

int main() {
	setlocale(LC_ALL, "RUS");
	double x, e, y;
	int n;
	do {
		system("cls");
		do {
			printf("Введите значения X, E, N - номер вызываемой функции.\n");
			printf("Учтите, что ряд для определения логарифма сходится только при 0<x<=2. \n");
			scanf("%lf %lf %d", &x, &e, &n); while (getchar() != '\n');
			if ((n == 2 && ((x <= 0) || (x > 2))) || ((n != 1) && (n != 2)) || (e <= 0))
				printf("\nНеправильный ввод.\n");
		} while ((n == 2 && ((x <= 0) || (x > 2))) || ((n != 1) && (n != 2)) || (e <= 0));

		if (n == 1) {
			printf("\nВычисляется значение функции erf(x)\n");
			y = calcul(x, e, erf);
		}
		if (n == 2) {
			printf("\nВычисляется значение функции ln(x)\n");
			y = calcul(x, e, ln);
		}
		prt(x, y, e);
		printf("\nВыполнение программы закончено. Повторить выполнение?\n");
		printf("<да> - любая клавиша / <esc> - нет\n");
	} while (_getch() != 27);
}
