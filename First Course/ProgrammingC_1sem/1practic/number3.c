#include <stdio.h>

int main()
{
    int N, K;

    printf("Input N: ");
    scanf("%d", &N);

    printf("Input K: ");
    scanf("%d", &K);

    if (N % K == 0) {
        printf("multiple");
    } else {
        printf("not a multiple");
    }

    return(0);
}
