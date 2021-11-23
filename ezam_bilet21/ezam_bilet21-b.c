#include <stdio.h> //FILE, fopen(), fclose(), fgets()
#include <string.h> // srlen(), strcpy(), strchr()

#define max_txt 256

int main()
{
	FILE *f1 = fopen("exam21-in.txt", "r");
	FILE *f2 = fopen("exam21-out.txt", "w+");
	
	int i = 1;
		
	while(1)
	{
		char s[max_txt];
		if (fgets(s, max_txt, f1) == NULL) break;
		
		char *c = strchr(s, '\n');
		if(c != NULL) *c = '\0';
		
		fprintf(f2, "%d %s\n", i, s);
		
		i++;
	}
		fprintf(f2, "Строк в исходном файле: %d\n", i - 1);
	fclose(f1);
	fclose(f2);
	
	return 0;
	
	
}
