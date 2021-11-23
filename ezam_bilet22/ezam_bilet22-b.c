#include <stdio.h>
#include <string.h> 

struct theRow
{
	char title[50];
	char mfg[100];
	short year;
	int price;
};

#define rowNum 3
struct theRow row[rowNum];


void theUpdateRow();

void writeInTxt()
{
  
	FILE *theWriteFile = fopen("exam22.txt", "w+");
	
	for(int i = 0; i < rowNum; i++)
	fprintf(theWriteFile, "%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
	fclose(theWriteFile);
}

void outputTable()
{
	//OUTPUT TABLE
	for(int i = 0; i < rowNum; i++)
	printf("%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
}


void menuCall()
{
	
	int theChooseOne = 0;
	printf(" [0]  	[1]\n");
	printf("[EXIT] [UPDATE]\n");
	printf("Choose(0/1): ");
	scanf("%d", &theChooseOne);
	if (theChooseOne == 0)
	exit(0);
	else if (theChooseOne == 1)
	theUpdateRow();
	else
	{
		printf("write 0 or 1\n");
		menuCall();
	}
}

void theUpdateRow()
{
    outputTable();
	int fondRowNum = 0;
	char xTitle[50];
	printf("Title: ");
	scanf("%s", xTitle);
	printf("Foundindg for %s\n", xTitle);
	

	for(int i = 0; i < rowNum; i++)
	{
		if(strcmp(row[i].title, xTitle) == 0)
		{
			fondRowNum++;

			char newTitle[50];
			printf("New title: ");
			scanf("%s", newTitle);
			strcpy(row[i].title, newTitle);

			char newMfg[100];
			printf("New mfg: ");
			scanf("%s", newMfg);
			strcpy(row[i].mfg, newMfg);

			short newYear;
			printf("New year: ");
			scanf("%hd", &newYear);
			row[i].year = newYear;

			int newPrice;
			printf("New price: ");
			scanf("%d", &newPrice);
			row[i].price = newPrice;

		
			FILE *theUpdateFile = fopen("exam22.bin", "wb+");
			fwrite(row, sizeof(struct theRow), 3, theUpdateFile);
			fclose(theUpdateFile);
			writeInTxt();

			outputTable();
		}
		else if(fondRowNum != 0)
		{
			printf("Number of founds rows: %d\n", fondRowNum);
			printf("End finding title %s\n", xTitle);
			menuCall();
		}
	}
}

int main()
{
	FILE *theReadFile = fopen("exam22.bin", "rb+");
	fread(row, sizeof(struct theRow), 3, theReadFile);
	fclose(theReadFile);

	writeInTxt(); //na 4

	outputTable();


	char xTitle[50];
	printf("find: ");
	fgets(xTitle, 50, stdin);
	
	char *p = strchr(xTitle, '\n');
	if (p != NULL) *p = 0;
	p = strchr(xTitle, '\r');
	if (p != NULL) *p = 0;

	
	int thereIsNoXTitle = 1;
	for(int i = 0; i < rowNum; i++)
	if (strcmp(row[i].title, xTitle) == 0)
	{
		puts(row[i].mfg);
		thereIsNoXTitle = 0;
	}
	if(thereIsNoXTitle == 1)
	printf("No title found\n");




	return 0;
}
