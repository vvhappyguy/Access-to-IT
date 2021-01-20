#include <stdio.h>

int main()
{
   /* When I compile this code, compiler show me warning
    *  that it doesn't know about this
    *  escape sequence */
   printf("i\c\na");
   // But stackoverflow says: https://stackoverflow.com/questions/7154800/what-is-the-bash-escape-character-c 
   return 0;
}
