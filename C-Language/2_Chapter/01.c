#include <stdio.h>
#include <limits.h>
#include <float.h>

void printFromLib(void);
void printFromCalculations(void);
long long int pow2(long long int);

int main(void)
{
   printFromLib();
   printFromCalculations();
   return 0;
}

void printFromLib(void)
{
   printf("Printing from limits.h\n");
   printf("char   MIN=%20d MAX=%20d\n", CHAR_MIN, CHAR_MAX);
   printf("uchar  MIN=%20d MAX=%20u\n", 0, UCHAR_MAX);
   printf("short  MIN=%20d MAX=%20d\n", SHRT_MIN, SHRT_MAX);
   printf("ushort MIN=%20d MAX=%20u\n", 0, USHRT_MAX);
   printf("int    MIN=%20d MAX=%20d\n", INT_MIN, INT_MAX);
   printf("uint   MIN=%20d MAX=%20u\n", 0, UINT_MAX);
   printf("long   MIN=%20ld MAX=%20ld\n", LONG_MIN, LONG_MAX);
   printf("ulong  MIN=%20d MAX=%20lu\n", 0, ULONG_MAX);

   printf("FLOATs\n");
   printf("float  MIN=%20e MAX=%20e\n", FLT_MIN, FLT_MAX);
   printf("double float  MIN=%20e MAX=%20e\n", DBL_MIN, DBL_MAX);
   printf("long double  MIN=%20Le MAX=%20Le\n", LDBL_MIN, LDBL_MAX);
}


#define SIGNED_MAX(x) (~(-1 << (sizeof(x) * 8 - 1)))
void printFromCalculations(void)
{
   printf("Printing from Calculations\n");
   printf("char   MIN=%20d MAX=%20d\n", SIGNED_MAX(char) * -1 - 1, SIGNED_MAX(char));

   unsigned char c = 0;
   printf("uchar   MIN=%20d MAX=%20d\n", c, c--);

   printf("int   MIN=%20d MAX=%20d\n", SIGNED_MAX(int) * -1 - 1, SIGNED_MAX(int));

   unsigned int i = 0;
   i--;
   printf("uint   MIN=%20d MAX=%20u\n", 0, i);


   printf("short   MIN=%20d MAX=%20d\n", SIGNED_MAX(short int) * -1 - 1, SIGNED_MAX(short int));

   unsigned short int s = 0;
   s--;
   printf("ushort   MIN=%20d MAX=%20d\n", 0, s);


   unsigned long int l = 0;
   l--;
   printf("ulong   MIN=%20d MAX=%20lu\n", 0, l);
   l = l / 2 + 1;
   printf("long   MIN=%20ld MAX=%20ld\n", -1 * l, l - 1);

   // Can calculate floats using only bit mask of number in computer memory.
}
