#include <stdio.h>
#include <stdint.h>

#define ISSET(x, n) ((x >> n) & 1)
#define SET(x, n) (x |= (1UL << n))

#define SIZEMASK 16
#define nl printf("\n")

int main(int argc, char const *argv[])
{
    uint16_t mask = 0;
    
    for (size_t i = 0; i < SIZEMASK; i++)
    {
        printf("%d", ISSET(mask, i));
    }

    nl;

    SET(mask, 10);
    SET(mask, 3);
    SET(mask, 6);
    SET(mask, 14);

    for (size_t i = 0; i < SIZEMASK; i++)
    {
        printf("%d", ISSET(mask, i));
    }

    nl;

    return 0;
}
