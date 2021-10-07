#include <stdio.h>
                    //возращает длину строки
#include <string.h> // strlen() , size_t


int main()
{
		char s[256];
		    //строка //не больше 256 символов //входной файл(ввод с клавы)
		fgets(s, 256, stdin);
		
		char *p = strchr(s, '\n'); //убрать Enter, чтобы не считался за символ
		if (p != NULL) p[0] = '\0';
		
		size_t n = strlen(s);
		
		printf("len: %ld\n", n);
		
		int m = 0;
		for (int i = 0; i < n; i++)
		{
			 if (s[i] == ' ') m++;
		}	  
		
		if(n > 0) m++;
		printf("words: %d\n", m);
		
		return 0;
}
