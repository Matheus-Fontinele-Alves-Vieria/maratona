#include <stdio.h>
#include <stdlib.h>

int computeCost(int consumption) {
    if (consumption <= 100) {
        return consumption * 2;
    } else if (consumption <= 10000) {
        return 2 * 100 + 3 * (consumption - 100);
    } else if (consumption <= 1000000) {
        return 2 * 100 + 3 * 9900 + 5 * (consumption - 10000);
    } else {
        return 2 * 100 + 3 * 9900 + 5 * 990000 + 7 * (consumption - 1000000);
    }
}

int computeConsumption(int cost) {
    if (cost <= 200) {
        return cost / 2;
    } else if (cost <= 200 + 3 * 9900) {
        return 100 + (cost - 200) / 3;
    } else if (cost <= 200 + 3 * 9900 + 5 * 990000) {
        return 10000 + (cost - (200 + 3 * 9900)) / 5;
    } else {
        return 1000000 + (cost - (200 + 3 * 9900 + 5 * 990000)) / 7;
    }
}

int findMinimumCost(int totalConsumption, int B) {
    int left = 0;
    int right = totalConsumption;
    int result = 0;

    while (left <= right) {
        int myConsumption = (left + right) / 2;
        int neighborConsumption = totalConsumption - myConsumption;

        int myCost = computeCost(myConsumption);
        int neighborCost = computeCost(neighborConsumption);
        int difference = abs(myCost - neighborCost);

        if (difference == B) {
            result = (myCost < neighborCost) ? myCost : neighborCost;
            break;
        } else if (difference < B) {
            right = myConsumption - 1;
        } else {
            left = myConsumption + 1;
        }
    }

    return result;
}

int main() {
    int A, B;

    while (1) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) break;

        int totalConsumption = computeConsumption(A);
        int yourBill = findMinimumCost(totalConsumption, B);

        printf("%d\n", yourBill);
    }

    return 0;
}
