#include <stdio.h>
#include <stdlib.h>

#include "sum.h"
#include "dif.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage: %s int1 int2\r\n", argv[0]);
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("sum of %i and %i: %i\r\n", a, b, sum(a, b));
    printf("dif of %i and %i: %i\r\n", a, b, dif(a, b));

    return 0;
}
