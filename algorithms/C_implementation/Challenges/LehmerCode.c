/*
When I started my attempt to print all possible permutations of a sequence, I didn't know about mixed radix, factoradic, etc. I'm happy that I made something very close to an algorithm based on factoradic.

I will implement here the Lehmer code, which is a bijection of {1, ..., n!} to each permutation of a list with n different elements.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define nl printf("\n")

int factorial(int n)
{
    int j = n;
    for (size_t i = 2; i < n; i++)
    {
        j *= i;
    }
    
    return j;
}

// Validation of factoradic
int isFactoradic(int num[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (num[i] >= length - i)
        {
            return -1;
        }        
    }

    return 0;    
}

typedef struct Node
{
    int element;
    struct Node * next;
    struct Node * predecessor;
} Node;

Node * listInitialization(int num[], int length)
{
    Node * list = (Node *)malloc((length + 2)*sizeof(Node));
    list->predecessor = list;
    list->next = (list + 1);
    list->element = length;
    
    for (size_t i = 1; i <= length; i++)
    {
        (list + i)->element = num[i - 1];
        (list + i)->predecessor = (list + i - 1);
        (list + i - 1)->next = (list + i);
    }

    (list + length)->next = (list + length + 1);
    (list + length + 1)->predecessor = (list + length);
    (list + length + 1)->next = (list + length + 1);
    (list + length + 1)->element = length;
    
    return list;
}

int removeNode(Node * node)
{
    if (node->next == node)
    {
        return -1;
    }
    if (node->predecessor == node)
    {
        return -1;
    }    
    
    Node * nodeBefore = node->predecessor;
    Node * nodeAfter = node->next;
    nodeBefore->next = nodeAfter;
    nodeAfter->predecessor = nodeBefore;

    //free(node);

    return 0;
}

int main(int argc, char const *argv[])
{
    #define SIZE 4
    int nums[SIZE] = {1, 2, 3, 4};

    Node * list;

    list = listInitialization(nums, SIZE);

    Node * i = list + 1;

    while (i != i->next)
    {
        printf("%d\t", i->element);
        i = i->next;
    }      

    nl;

    removeNode(list + 3);

    i = list + 1;

    while (i != i->next)
    {
        printf("%d\t", i->element);
        i = i->next;
    }

    nl;

    free(list);
    
    return 0;
}

