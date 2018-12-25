#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmpfunc( const void *a, const void *b) 
{
  return *(char*)a - *(char*)b;
}

int areAnagram(char* str1, char* str2)
{
    size_t n1 = strlen(str1);
    size_t n2 = strlen(str2);
    if (n1 != n2)
    {
        return 0;
    }
    char buff1[256];
    char buff2[256];
    int i = 0;
    for (i = 0; i < n1; ++i)
    {
        buff1[i] = str1[i];
        buff2[i] = str2[i];
    }
    qsort(buff1, n1, sizeof(char), cmpfunc);
    qsort(buff2, n2, sizeof(char), cmpfunc);
    n1 = 0;
    while (n1 < n2)
    {
        if (buff1[n1] != buff2[n1])
        {
            return 0;
        }
        else
        {
            ++n1;
        }
    }
    return 1;

}

int main()
{
    printf("Enter string 1\n");
    char string1[256];
    scanf( "%s", string1 );
    printf("Enter string 2\n");
    char string2[256];
    scanf( "%s", string2);
    if (areAnagram(string1, string2))
    {
        printf("%s, %s are anagrams \n", string1, string2);
    }
    else
    {
        printf("%s, %s are not anagrams \n", string1, string2);
    }
    system("pause");
}