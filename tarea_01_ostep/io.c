#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reverse(char *x, int begin, int end)
{
	char a;
	if (begin >= end)
		return;
	a = *(x+begin);
	*(x+begin) = *(x+end);
	*(x+end) = a;
	reverse(x, ++begin, --end);
}

int main (int argc, char *argv[])
{
   int c, i;
   char file [100];
   printf("Digite el nombre del archivo: ");
   scanf("%s", file);
   FILE* fp=fopen(file, "r");
   if (fp==NULL){
      printf("No se puede abrir el archivo \n");
      return 1;
}
   char output [256];
   for (c = 1; fgets(output, sizeof(output),fp) != NULL; c++)
{
      printf("%02d: %s\n",c);
}
   rewind(fp);
   char a [256];
   while (fgets(a, sizeof(a),fp) != NULL)
{
      i=i+1;
      reverse(a, 0,strlen(a)-1);
      printf("%02d: %s\n" , i, a);
}

   fclose(fp);

   return 0;
}
//
