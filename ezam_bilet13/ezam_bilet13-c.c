//13 массив структур
//na 3 - "Заполнить таблицу информацией и вывести на экран, осуществить номер телефона(контактная книга)..
//..	  и доп информации по вводимой фамилии, если такой записи нет сообщить об этом"
//na 4 - "Дополнительно выдать телефон нужной категории"
//na 5 - "Сохранить информацию о телефонах в тектовом файле"

#include <stdio.h>
#include <string.h> // strcmp(), strtok()
#include <ctype.h>

struct record
{
	char fio[32];
	char cat[48];
	char number[24];
	char info[64];
};

#define numOfRows 3
struct record row[rows];

int main()
{
	for (int i = 0; i < rows; i++)
	{
		printf("[record %d]\n", i);

		printf("fio: ");
		gets(row[i].fio);

		printf("cat: ");
		gets(row[i].cat);

		printf("number: ");
		gets(row[i].number);

		printf("info: ");
		gets(row[i].info);

		printf("\n");
	}

	FILE *file1 = fopen("exam13-c.txt", "w");
	for (int i = 0; i < rows; i++) //Output in file
	{
		fprintf(file1, "%s\t%s\t%s\t%s\n",
				row[i].fio, row[i].cat,
				row[i].number , row[i].info);
	}
	fclose(file1);

	for (int i = 0; i < rows; i++)
	printf("%s\t%s\t%s\t%s\n", row[i].fio, row[i].cat, row[i].number, row[i].info);

	printf("search LastName: ");
	char fio[32];
	gets(fio);
	printf("\n");

	int findedRows = 0;
	for (int i = 0; i < rows; i++)
	{
		char *lastNameFromFIO = strtok(row[i].fio, " "); //read anytil " "
		if (strcmp(lastNameFromFIO, fio) == 0)
		{
			printf("number: %s\n", row[i].number);
			printf("info: %s\n", row[i].info);
			findedRows++;
		}
	}
	if(findedRows < 1) printf("not fount laste name\n");

	printf("search cat: ");
	char cat[48];
	gets(cat);
	printf("\n");

	findedRows = 0;
	for (int i = 0; i < rows; i++)
	{
		char *categoryFromTable = strtok(row[i].cat, "\n"); //read anytil " "
		if (strcmp(categoryFromTable, cat) == 0)
		{
			printf("number: %s\n", row[i].number);
			findedRows++;
		}
	}
	if(findedRows < 1) printf("not fount cat\n");



	return 0;

}
