#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 1024
#define X 0
#define Y 1

#define CAL(a, b, c, d) ((a) * (d) - (c) * (b))

double area(double vertex[SIZE][2], int n)
{
    double area = 0;
    int i;
    for (i = 2; i < n; i++)
    {
        area += CAL(vertex[i - 1][X] - vertex[0][X],
                    vertex[i - 1][Y] - vertex[0][Y],
                    vertex[i][X] - vertex[0][X],
                    vertex[i][Y] - vertex[0][Y]);
    }
    return fabs(area) / 2.0;
}

int is_cross(double vertex[SIZE][2], int i1, int i2, int j1, int j2)
{
    double a, b, c, d;
    a = CAL(vertex[i1][X] - vertex[j1][X],
            vertex[i1][Y] - vertex[j1][Y],
            vertex[j2][X] - vertex[j1][X],
            vertex[j2][Y] - vertex[j1][Y]);

    b = CAL(vertex[j2][X] - vertex[j1][X],
            vertex[j2][Y] - vertex[j1][Y],
            vertex[i2][X] - vertex[j1][X],
            vertex[i2][Y] - vertex[j1][Y]);

    c = CAL(vertex[j1][X] - vertex[i1][X],
            vertex[j1][Y] - vertex[i1][Y],
            vertex[i2][X] - vertex[i1][X],
            vertex[i2][Y] - vertex[i1][Y]);

    d = CAL(vertex[i2][X] - vertex[i1][X],
            vertex[i2][Y] - vertex[i1][Y],
            vertex[j2][X] - vertex[i1][X],
            vertex[j2][Y] - vertex[i1][Y]);

    if (a * b >= 0 && c * d >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int judge(double vertex[SIZE][2], int n)
{
    int i, j;
    for (i = 3; i < n; i++)
    {
        for (j = 1; j < i - 1; j++)
        {
            if (is_cross(vertex, i - 1, i, j - 1, j))
            {
                return 0;
            }
        }
    }
    for (i = 2; i < n - 1; i++)
    {
        if (is_cross(vertex, i - 1, i, n - 1, 0))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i, n, flag;
    double vertex[SIZE][2];
    flag = 0;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%lf %lf", &vertex[i][X], &vertex[i][Y]);
        }
        if (flag != 0)
        {
            puts("");
        }
        flag++;
        printf("Figure %d: ", flag);
        if (n < 3 || !judge(vertex, n))
        {
            puts("Impossible");
            continue;
        }
        if (judge(vertex, n))
        {
            printf("%.2lf\n", area(vertex, n));
        }
    }
    return 0;
}