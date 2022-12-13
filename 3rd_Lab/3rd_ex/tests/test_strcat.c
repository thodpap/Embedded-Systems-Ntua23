#include <stdio.h>

extern char *strcat(char *dest, const char *src);

int main() {
   char str1[100] = "This is ", str2[] = "our test";
   char *s;
   // concatenates str1 and str2
   // the resultant string is stored in str1.
   s = strcat(str1, str2);
 
   printf("%s\n%s\n%s\n", str1, str2, s);

   return 0;
}