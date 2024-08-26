#include <stdio.h>

int main() {
    int N, t[100];
    
    while (scanf("%d", &N) != EOF) {
        if(N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &t[i]);
        }

        int active_time = 0;
        int end_time = 0;

        for (int i = 0; i < N; i++) {
            if (t[i] < end_time) {
                active_time += (t[i] + 10 - end_time);
            } else {
                active_time += 10;
            }

            end_time = t[i] + 10;
        }

        printf("%d\n", active_time);
    }

    return 0;
}
