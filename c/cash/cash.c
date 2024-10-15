#include <stdio.h>


int calculate_coins(int change) {
    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    int num_denominations = 4;
    for (int i = 0; i < num_denominations; i++) {
        coins += change / denominations[i];
        change %= denominations[i];
    }
    return coins;
}

int main() {
    int change;
    do {
        printf("Enter the amount of change owed: ");
        scanf("%d", &change);
    } while (change < 0);
    int coins = calculate_coins(change);
    printf("Minimum number of coins required: %d\n", coins);
    return 0;
}
