#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int gold;
    int silver;
    int bronze;
} Country;

int compare(const void *a, const void *b) {
    Country *countryA = (Country *)a;
    Country *countryB = (Country *)b;

    if (countryA->gold != countryB->gold)
        return countryB->gold - countryA->gold; 
    
    if (countryA->silver != countryB->silver)
        return countryB->silver - countryA->silver; 
    
    if (countryA->bronze != countryB->bronze)
        return countryB->bronze - countryA->bronze;
    
    return strcmp(countryA->name, countryB->name);
}

int main() {
    int N;
    scanf("%d", &N);

    Country countries[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", countries[i].name, &countries[i].gold, &countries[i].silver, &countries[i].bronze);
    }

    qsort(countries, N, sizeof(Country), compare);

    for (int i = 0; i < N; i++) {
        printf("%s %d %d %d\n", countries[i].name, countries[i].gold, countries[i].silver, countries[i].bronze);
    }

    return 0;
}
