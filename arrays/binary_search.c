#include <stdio.h>
#include <stdlib.h>

int *binary_search(int *low, int *high, int target)
{
    if (low == high)
    {
        return NULL;
    }

    int *mid = low + (high - low) / 2;

    if (*mid == target)
    {
        return mid;
    }
    else if (target > *mid)
    {
        return binary_search(mid + 1, high, target);
    }
    else
    {
        return binary_search(low, mid, target);
    }
}

int main(void)
{
    int a[] = { 0, 1, 2, 3, 4 };
    int b[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int c[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    int d[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 };

    int *a_p = binary_search(a, (a + 5), 4);
    int *b_p = binary_search(b, (b + 10), 7);
    int *c_p = binary_search(c, (c + 20), 14);
    int *d_p = binary_search(d, (d + 40), 22);

    printf("a: %i\n", *a_p);
    printf("b: %i\n", *b_p);
    printf("c: %i\n", *c_p);
    printf("d: %i\n", *d_p);

    return 0;
}