//14 Инфа о банковских счетах
//na 3 - "Заполнить таблицу информамацией и вывести на экран, расчитать для каждого счета величену суммы в конце месяца." 
//na 4 - "Выполнить поиск информации по номеру счета или ФИО владельца, в случае успешного поиска вывести всю инфу о счете"
//na 5 - "Дополнительно выдать номер счетом с конкретым банковским процентов, который вводится пользователем"

#include <stdlib.h> // atoi(), atof()
#include <stdio.h> 
#include <string.h> // strcmp(), strtok()

struct record
{
	int acc;
	char fio[32];
	float sum;
	int prc;
	
	float res;
};


#define rows 3
struct record tab[rows];

int main()
{
	char tmp[32];
	for(int i = 0; i < rows; i++)
	{
		printf("[record %d]\n", i);
		
		printf("acc: ");
		gets(tmp);
		tab[i].acc = atoi(tmp);
		
		printf("fio: ");
		gets(tab[i].fio);
		
		printf("sum: ");
		gets(tmp);
		tab[i].sum = atof(tmp);
		
		printf("%%: ");
		gets(tmp);
		tab[i].prc = atoi(tmp);
		
		printf("\n");
	}
	
	for(int i = 0; i < rows; i++)
		tab[i].res = tab[i].sum + (tab[i].sum * tab[i].prc / 100.0f) / 12.0f;
	
	for(int i = 0; i < rows; i++)
		printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
	
	return 0;
	
}
