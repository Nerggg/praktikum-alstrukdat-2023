#include <stdio.h>
#include <stdlib.h>

int ctoi(char inp[]) {
   int result = 0;
   for (int i = 0; inp[i] != '\0'; i++) {
      printf("awal %d\n", result);
      result = result * 10 + (inp[i] - '0');
      printf("akhir %d\n", result);
   }
   return result;
}

int main( ) {

   char tes[100] = "8";
   char tes2[100] = "4";

   printf("%d\n", ctoi(tes) + ctoi(tes2));

   return 0;
}
