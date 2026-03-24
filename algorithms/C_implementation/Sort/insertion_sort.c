/*
    Problem: sort
    Input: an array of elements
    Output: an array of the same elements, but in an order such that, given some numerical property, y, of these elements, the element in x position has y less than the y of element in x+1. This so-called y property is chosen beforehand.  

    The insertion sort is an algorithm that starts analizing the second element of the array and compares it to the first. If the second is lower than the first, it will swap them. Now he is sure that, for the third element, any element before it is already sorted. With that in mind, we can go downwards, from 3rd down to 1st comparing it with each element until we find one that is lower than the third. The algorithm stop the comparasion as soon as it finds an element lower than the current element in analyzing, because, we are sure that any element before it is even lower, so we can move on to the next element to be analyzed.
*/

#include <stdio.h>

#define newline printf("\n")

void swap_int(int * x, int * y)
{
    int p = *x;
    *x = *y;
    *y = p;
}

// insertion sort in an array of integers.
void isort(int numbers[], size_t size)
{
    for (size_t i = 1; i <= size; i++)
    {
        int j = i - 1;
        while ((numbers[j + 1] < numbers[j]) && (j >= 0))
        {
            swap_int((numbers + j + 1), (numbers + j));
            j--;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int num[] = {3, 6, 9, 4, 7, 0, 43, 37};
/*
    int * x = (num + 0);
    int * y = (num + 2);

    swap_int(x, y);

    printf("%d %d\n", num[0], num [2]);
*/
    printf("Before sorting: \n");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d\t", num[i]);
    }
    
    isort(num, 8);

    newline;
    printf("After sorting: \n");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d\t", num[i]);
    }
    newline;

    return 0;
}
