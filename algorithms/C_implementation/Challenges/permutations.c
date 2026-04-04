#include <stdio.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define newline printf("\n")
#define factorialLookSize 12

int factorialLook[factorialLookSize + 1] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

void swap(int * x, int * y);

int factorial(int n)
{
    int result = 1;

    for (size_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
    
}

typedef struct
{
    int state;
    int end;
} Generator;

int yieldPermutations(Generator * g, int arr[])
{
    if (g->state == g->end)
    {
        return 1;
    }
    
    int position = factorialLookSize;

    while ((g->state % factorialLook[position]) != 0)
    {
        position--;
    }

    swap(&arr[(g->end) - position], &arr[(g->end) - position - 1]);

    g->state++;

    return 0;
    
}

int yield(Generator * g)
{
    int s = g->state;

    if (s == g->end)
    {
        return -1;
    }
    
    g->state++;
    return s;
}

int yieldChar(Generator * g, int (* funcName)(char *, int), char * name)
{
    int s = g->state;

    if (s == g->end)
    {
        return -1;
    }

    int result = funcName(name, s);
    
    g->state++;
    return result;
}

int showLetter(char * text, int index)
{
    if (index >= 0)
    {
        printf("%c", text[index]);
        return 0;
    }

    return -1;
    
}

void swap(int * x, int * y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void i_sorting(int arr[], size_t size)
{

    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (arr[j-1] > arr[j] && j > 0)
        {
            swap(&arr[j-1], &arr[j]);
            j--;
        }
        
    }
}

int permutations(int arr[], size_t size)
{
    /*
        If we have an array with n elements and we fix the m first positions, then each of the free elements (not used to fix any position)
        will repeat (n - m)! times. For instance, if we fixed all positions except the last, then we have (n-n+1)! = 1 possibility for the first position.
        
        After thinking a lot (it's quite embarrassing to think that hard to reach this), I find out that if I chose the place to apply the swap based on the fact stated above, the problem is solved.
    */

    Generator * permutations = {0};
    permutations->end = factorial(size);
    permutations->state = 1;

    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    newline;

    while (yieldPermutations(permutations, arr) != 1)
    {
        for (size_t i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }  

        newline;      
    }
    
    free(permutations);

    return 0;
}

int main(int argc, char const *argv[])
{
    int number[4] = {2, 3, 1, 4};
    i_sorting(number, 4);
    for (size_t i = 0; i < 4; i++)
    {
        printf("%d\t", number[i]);
    }

    newline;

    printf("Digit your name: ");
    size_t sizeName = 32;
    char name[sizeName];

    if (fgets(name, sizeName, stdin) == NULL)
    {
        printf("fgets");
        return -1;
    }

    name[sizeName - 1] = '\0';

    Generator nameGenarator = {0, strlen(name)};
    
    yieldChar(&nameGenarator, showLetter, name);    
    yieldChar(&nameGenarator, showLetter, name);
    yieldChar(&nameGenarator, showLetter, name);

    newline;

    printf("Pausing the consumption of the \"stream\"...\n");

    while (nameGenarator.state != nameGenarator.end)
    {
        yieldChar(&nameGenarator, showLetter, name);
    }

    permutations(number, 4);
    
    
    return 0;
}
