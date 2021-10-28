#include <stdio.h>
#include <stdlib.h>

#define n_max 100

int n;
int mmax, mmin;
int mark[n_max];

//#define mmin 2
//#define mmax 5

#define mpass 4.6f

int main()
{
    printf("Введите минимальный балл: ");
    scanf("%d", &mmin);
    //if(mmin < 2) printf("Ошибка: Минимальный балл 2\n"); 
    printf("Введите максимальный балл: ");
    scanf("%d", &mmax);
   // if(mmax > 5) printf("Ошибка: Максимальный балл 5\n"); 
	printf("Введите колличество оценок: ");
    scanf("%d", &n);
    printf("Введите оценки: ");
    
	
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mark[i]);
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++)
    	sum += mark[i];
		
    float avg = (float) sum / (float) n;

    printf("Средний балл: %.1f\n", avg);
    if (avg >= mpass) printf("Вы поступили\n");
    else printf("Вы не поступили\n");

    return 0;
	

}
