#include <stdio.h>
#include <string.h>

int main () {

    // strcat()
    char str1[100] = "This is ", str2[] = "programiz.com";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   strcat(str1, str2);

   puts(str1);
   puts(str2);


   // strcmp()

//     char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
//     int result;

//   // comparing strings str1 and str2
//   result = strcmp(str1, str2);
//   printf("strcmp(str1, str2) = %d\n", result);

//   // comparing strings str1 and str3
//   result = strcmp(str1, str3);
//   printf("strcmp(str1, str3) = %d\n", result);


// strlen()
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};

    // using the %zu format specifier to print size_t
    printf("Length of string a = %zu \n",strlen(a));
    printf("Length of string b = %zu \n",strlen(b));


   return 0;
}