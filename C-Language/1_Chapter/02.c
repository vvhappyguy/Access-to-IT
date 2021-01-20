#include <stdio.h>

int main()
{
   /* When I compile this code, compiler show me warning
    *  that it doesn't now about this
    *  escape sequence */
   printf("\c\n");
   return 0;
}
