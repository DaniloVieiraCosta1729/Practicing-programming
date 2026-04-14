/*
Simple implementation: implementing a binary tree just as an excuse to write something.
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define nl printf("\n")

// General definitions
typedef struct Node
{
    int32_t value;
    struct Node * rigth;
    struct Node * left;
} Node;
typedef Node Btree;

void swap(int32_t * x, int32_t * y);
void insertionSort(int32_t arr[], size_t size);
Btree * initializeBtree(int value);
void add2Btree(Btree * tree, int value);

// Implementations
void insertionSort(int32_t arr[], size_t size)
{
    for (size_t i = 1; i <= size; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (arr[j] > arr[j + 1]))
        {
            swap(&arr[j + 1], &arr[j]);
            j--;
        }
        
    }    
}
void swap(int32_t * x, int32_t * y)
{
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void printall(int32_t arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    nl;
}

Btree * initializeBtree(int value)
{
    Node * root = (Node *)malloc(sizeof(Node));
    root->value = value;
    root->left = NULL;
    root->rigth = NULL;

    return root;
}

void add2Btree(Btree * tree, int value)
{
    int finished = 0;
    Node * ptr = tree;

    while (!finished)
    {
        if (value > ptr->value)
        {
            if (ptr->rigth != NULL)
            {
                ptr = ptr->rigth;
                continue;
            }
            ptr->rigth = (Node *)malloc(sizeof(Node));
            ptr->rigth->value = value;
            ptr->rigth->rigth = NULL;
            ptr->rigth->left = NULL;
            break;          
        }

        if (value <= ptr->value)
        {
            if (ptr->left != NULL)
            {
                ptr = ptr->left;
                continue;
            }
            ptr->left = (Node *)malloc(sizeof(Node));
            ptr->left->value = value;
            ptr->left->rigth = NULL;
            ptr->left->left = NULL;
            break;          
        }        
    }    
}

int main(int argc, char const *argv[])
{
    #define SIZE 5
    int32_t num[SIZE] = {3, 4, 2, 8, 1};

    printall(num, SIZE);
    insertionSort(num, SIZE);
    printall(num, SIZE);

    Btree * tree = initializeBtree(5);
    printf("The value of the root is: %d\n", tree->value);

    add2Btree(tree, 3);
    add2Btree(tree, 7);
    printf("The value of the child at left is: %d\n", tree->left->value);
    printf("The value of the child at rigth is: %d\n", tree->rigth->value);

    free(tree);

    return 0;
}
