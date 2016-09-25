#include <stdio.h>
#include <stdlib.h>
#include <string.h>

strEnd (char *str, char *t)
{
    char *p;
    p = str + strlen(str) - strlen(t); /* p aponta para o final da string str - tamanho de t */
    while (*t){
      if (*p != *t) return 0;
      p++;
      t++;
    }
    return 1;
} 

int main(int argc, char** argv) {

	char str1[40] = "teste";
	char str2[40] = "teste";

	strEnd(&str1, &str2);

	printf("String: %s\n", str1);
}