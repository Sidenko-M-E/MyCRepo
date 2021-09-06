#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

//функция для ввода исходной матрицы
void vvod(int n, int *arr) {
	printf("Поэлементное заполнение матрицы.\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", arr++);
	while (getchar() != '\n');
}


//функция для вывода исходной матрицы
void vivod(int n, int *arr) {
	printf("Вывод матрицы.\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("[%6d] ", (*(arr)++));
		printf("\n");
	}
}


//функция определения максимума исходной матрицы
void maxel(int n, int* max, int *arr) {
	*max = *arr;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (*(arr+i*n+j) > * max) *max = *(arr + i * n + j);
}


//функция обработки исходной матрицы
void obr(int n, int* max, int* sch, int *arr, int *arr_obr, int *arr_max) {
	int i, j;

	//определение максимального эл-та матрицы
	maxel(n, max, arr);

	//формирование двумерной матрицы максимумов
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (*(arr+i*n+j) == *max) {
				*(arr_obr + 2*(*sch)) = i;
				*(arr_obr + 2 * (*sch) + 1) = j;
				(*sch)++;
			}

	//подсчёт количества максимумов в разных частях матрицы
	for (i = 0; i < *sch; i++) {
		if (*(arr_obr + i * (*sch)) < *(arr_obr + i * (*sch) + 1)) (*(arr_max))++;
		if (*(arr_obr + i * (*sch)) > *(arr_obr + i * (*sch) + 1)) (*(arr_max+1))++;
		if (*(arr_obr + i * (*sch)) == *(arr_obr + i * (*sch) + 1)) (*(arr_max+2))++;
	}
}

//основная функция
int main() {
	setlocale(LC_ALL, "RUS");
	int arr[20][20], max, n;
	int arr_obr[20][2];
	int arr_max[3] = { 0 };
	int sch = 0;

	//ввод ранга матрицы
	do {
		printf("Введите ранг матрицы.\n");
		scanf("%d", &n); while (getchar() != '\n');
		if (n <= 0) printf("Неверный ввод.\n");
	} while (n <= 0);

	//ввод исходной матрицы
	vvod(n, &arr[0][0]);
	system("cls");

	//вывод исходной матрицы
	vivod(n, &arr[0][0]);
	printf("Для продолжения нажмите любую клавишу.\n");
	_getch();
	system("cls");

	//функция обработки матрицы
	obr(n, &max, &sch, &arr[0][0], &arr_obr[0][0], arr_max);

	//вывод результатов обработки
	printf("Вывод результатов обработки матрицы.\n");
	printf("Вывод матрицы максимумов:\n");
	for (int i = 0; i < sch; i++) {
		printf("[%6d] [%6d]\n", arr_obr[i][0], arr_obr[i][1]);
	}
	printf("\nВывод кол-во максимумов в разных частях таблицы:\n");
	printf("Кол-во максимумов выше главной диагонали - %d\n", arr_max[0]);
	printf("Кол-во максимумов ниже главной диагонали - %d\n", arr_max[1]);
	printf("Кол-во максимумов на главной диагонали - %d\n", arr_max[2]);

	printf("\nДля завершения работы нажмите любую клавишу\n");
	_getch();
}