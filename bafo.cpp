#include <stdio.h>

int main() {
    int R, Aldo, Beto;
    int test_case = 1;

    while(scanf("%d", &R) != EOF) {
        if(R == 0) {
            break;
        }

        int total_Aldo = 0, total_Beto = 0;

        for(int i = 0; i < R; i++) {
            scanf("%d %d", &Aldo, &Beto);

            total_Aldo += Aldo;
            total_Beto += Beto;
        }

        printf("Teste %d\n", test_case);

        if(total_Aldo > total_Beto) {
            printf("Aldo\n");
        } else {
            printf("Beto\n");
        }

        printf("\n");

        test_case++;
    }

    return 0;
}
