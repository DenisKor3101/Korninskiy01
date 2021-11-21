//13 массив структур
//na 3 - "Заполнить таблицу информацией и вывести на экран, осуществить номер телефона(контактная книга).. 
//..	  и доп информации по вводимой фамилии, если такой записи нет сообщить об этом"
//na 4 - "Дополнительно выдать телефон нужной категории"
//na 5 - "Сохранить информацию о телефонах в тектовом файле"

#include <stdio.h>
#include <string.h> // strcmp(), strtok()

struct record
{
	char fio[32];
	char cat[48];
	char num[24];
	char inf[64];
};

#define rows 3
struct record tab[rows];

int main()
{
	for (int i = 0; i < rows; i++)
	{
		printf("[record %d]\n", i);
		
		printf("fio: ");
		gets(tab[i].fio);
		
		printf("cat: ");
		gets(tab[i].cat);
		
		printf("num: ");
		gets(tab[i].num);
		
		printf("inf: ");
		gets(tab[i].inf);
		
		printf("\n");
	}
	
	for (int i = 0; i < rows; i++)
		printf("%s\t%s\t%s\t%s\n", tab[i].fio, tab[i].cat, tab[i].num, tab[i].inf);
	
	printf("search: ");
	char fio[32];
	gets(fio);
	
	printf("\n");
	
	int n = 0;
	
	for (int i = 0; i < rows; i++)
	{
		char *p = strtok(tab[i].fio, " ");
		if (strcmp(p, fio) == 0)
		{
			printf("num: %s\n", tab[i].num);
			printf("inf: %s\n", tab[i].inf);
			n++
		}
		
	}
	
	if(n < 1) printf("not fount!\n");
	
	return 0;
	
}