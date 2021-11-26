#include <stdlib.h>
#include <stdio.h>

int numOfMarks = 10;
int mark0 = 1;
int mark1 = 10;




printf(" %.2f", (float)cMark/(float)mark1);
printf("\n");

return (float)cMark/(float)mark1;
}*/

int main()
{

	int numOfSportsmans = 5;
	int sportsman[numOfSportsmans][numOfMarks+1];
	float meanMarks[numOfSportsmans];
	float maxMarks = -1.0;


	for(int i = 0; i < numOfMarks; i++)
	{
		printf("\t%d", i+1);
	}
	printf("\n");

	for(int i = 0; i < numOfSportsmans; i++)
	{
		printf("%d", i+1);
		
		sportsman[i][numOfMarks] = 0;
		for(int j = 0; j < numOfMarks; j++)
		{
			sportsman[i][j] =  mark0 + (rand() % (mark1 - mark0 + 1));
			printf("\t%d", sportsman[i][j]);
			sportsman[i][numOfMarks] += sportsman[i][j];
		}

		printf("\t%.2f", (float)sportsman[i][numOfMarks]/(float)mark1);
		printf("\n");

		
		if(sportsman[i][numOfMarks] >= maxMarks)
		{
			maxMarks = sportsman[i][numOfMarks];
		}
	}

	for(int i = 0; i < numOfSportsmans; i++)
	if(sportsman[i][numOfMarks] >= maxMarks)
	printf("\nsportsman number %d is the better\n", i+1);



	return 0;
}
