#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item in the knapsack
struct Item {
    int value;
    int weight;
};

// Function to compare two items by their value-to-weight ratio
int compare_items(const void* a, const void* b) {
    struct Item* item_a = (struct Item*)a;
    struct Item* item_b = (struct Item*)b;
    double ratio_a = (double)item_a->value / (double)item_a->weight;
    double ratio_b = (double)item_b->value / (double)item_b->weight;
    if (ratio_a > ratio_b) {
        return -1;
    } else if (ratio_a < ratio_b) {
        return 1;
    } else {
        return 0;
    }
}

// Function to solve the knapsack problem using a greedy algorithm
int knapsack_greedy(struct Item items[], int n, int capacity) {
    // Sort the items by their value-to-weight ratio in decreasing order
    qsort(items, n, sizeof(struct Item), compare_items);

    // Initialize the total value and remaining capacity
    int total_value = 0;
    int remaining_capacity = capacity;

    // Select items in order until the knapsack is full
    for (int i = 0; i < n; i++) {
        if (remaining_capacity >= items[i].weight) {
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            total_value += items[i].value * ((double)remaining_capacity / (double)items[i].weight);
            break;
        }
    }

    // Return the total value of the selected items
    return total_value;
}

// Main function to test the knapsack_greedy function
int main() {
    struct Item items[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(items) / sizeof(struct Item);
    int capacity = 50;

    int total_value = knapsack_greedy(items, n, capacity);

    printf("Total value of items in the knapsack: %d\n", total_value);

    return 0;
}
