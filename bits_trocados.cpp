#include <stdio.h>

int main() {
    int V;
    int test_case = 1;

    while(scanf("%d", &V) != EOF) {
        if(V == 0) {
            break;
        }

        int I = 0, J = 0, K = 0, L = 0;

        I = V / 50;
        V %= 50;

        J = V / 10;
        V %= 10;

        K = V / 5;
        V %= 5;

        L = V;

        printf("Teste %d\n", test_case);
        printf("%d %d %d %d\n", I, J, K, L);
        printf("\n");

        test_case++;
    }

    return 0;
}
