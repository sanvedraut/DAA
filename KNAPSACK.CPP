#include <stdio.h>
#include <conio.h>

int main() {
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit = 0;
    int weight[10];
    int value[10];
    int i;
    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d items:\n", no_items);
    for (i = 0; i < no_items; i++) {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }

    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    while (cur_weight > 0) {
        item = -1;
        for (int i = 0; i < no_items; ++i) {
            if (!used[i] && (item == -1 || ((float)value[i] / weight[i]) > ((float)value[item] / weight[item])))
                item = i;
        }

        used[item] = 1;
        if (cur_weight >= weight[item]) {
            printf("Added object %d (%d Rs., %d Kg) completely in the bag. Space left: %d.\n",
                item + 1, value[item], weight[item], cur_weight - weight[item]);
            cur_weight -= weight[item];
            total_profit += value[item];
        } else {
            int item_percent = (int)(((float)cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d Rs., %d Kg) of object %d in the bag.\n",
                item_percent, value[item], weight[item], item + 1);
            total_profit += (float)cur_weight / weight[item] * value[item];
            cur_weight = 0;
        }
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);

    getch(); // Wait for a key press
    clrscr(); // Clear the screen

    return 0;
}
