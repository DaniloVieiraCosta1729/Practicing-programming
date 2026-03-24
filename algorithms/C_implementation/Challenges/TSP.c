/*
    Problem: traveling salesman problem (the book presents it as the robot tour optimization.)
    Input: a set of points in a plane.
    Output: the smaller distance that someone can travel through each point.
*/

/*
    Thoughts: the brute force approach consists of comparing the result of a function f(x) for all possible x, where x is a n-upla (x1, x2, ..., xn) and gives a real number that matches the sum of the distances between the points x1 to x2, x2 to x3, and so forth, up to x_(n-1) to x_n.
    Since no point will be visited twice, we have n! possibilities to check, which is extremelly high.

    We know that a good path should avoid crossing a trajectory made before. One way I thought to achieve a solution that does not intersect itself is by calculating the centroid and sorting the points by their distance from the centroid and then calculating f(x). The result shoulnd't be great, but it's probably not that bad neither.
*/

#include <stdio.h>
#include <immintrin.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
    double r;
} Point;

double rootSquare(double x)
{
    __m128d a = _mm_set_sd(x);
    a = _mm_sqrt_sd(a,a);
    return _mm_cvtsd_f64(a);
}

double distance(Point * x, Point * y)
{
    return rootSquare((x->x - y->x)*(x->x - y->x) + (x->y - y->y)*(x->y - y->y));
}

double bruteForceTSP(Point distribution[], size_t quantity)
{
    double totalDistance = 0;

    for (size_t i = 1; i <=quantity; i++)
    {
        totalDistance += distance(&distribution[i], &distribution[i-1]);
    }

    double shortestPath = totalDistance;
    
    int * seq = malloc(sizeof(int)*quantity);

    for (size_t i = 0; i < quantity; i++)
    {
        seq[i] = i;
    }
    

    free(seq);
    
}

int main(int argc, char const *argv[])
{
    Point p1 = {5, 2, 0};
    Point p2 = {10, 15, 0};
    Point p3 = {1, 30, 0};
    Point p4 = {50, 12, 0};
    Point p5 = {88, 34, 0};
    Point p6 = {0, 18, 0};

    Point distribution[6] = {p1, p2, p3, p4, p5, p6};

    printf("The distance between (%d, %d) and (%d, %d) is %f\n", (int)p1.x, (int)p1.y, (int)p4.x, (int)p4.y, (float)distance(&distribution[0], &distribution[3]));
    
    return 0;
}
