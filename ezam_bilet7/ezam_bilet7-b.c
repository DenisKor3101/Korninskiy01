#include <stdio.h>
#include <stdlib.h>

#define n_max 100

int n;
int mmax, mmin;
int mark[n_max];

char randM;
#define mmin 2
#define mmax 5
#define mpass 4.6f

int calculatingCertificate()
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  sum += mark[i];
  float avg = (float) sum / (float) n;
  printf("avg: %.1f\n", avg);
  if (avg >= mpass)
  printf("yes\n");
  else
  printf("no\n");
}

int main()
{
  printf("Кол-во оценок: ");
  scanf("%d", &n);

  printf("Задать оценки случайно?\nY/N: ");
  scanf("%s", &randM);
  if(randM == 'y' || randM == 'Y')
  {
    for(int i = 0; i < n; i++)
    {
      mark[i] = mmin + rand() % (mmax - mmin + 1);
      printf("%d ", mark[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Введите оценки:");
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &mark[i]);
      if(mark[i]<mmin)
      {
        printf("Error\n");
        return 0;
      }
      if(mark[i]>mmax)
      {
        printf("Error\n");
        return 0;
      }
    }
  }

  calculatingCertificate(); 

  return 0;
}
