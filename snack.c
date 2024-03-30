// Headers
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ------------------------------------------------------------------------------------------------------------------------

// Constants

const int TOTAL_ITEMS = 10;
const int STRING_LENGTH = 100;

// ------------------------------------------------------------------------------------------------------------------------

// Custom types

typedef struct
{
    char *food;
    float cost;
} snack;

// ------------------------------------------------------------------------------------------------------------------------

// Signatures

void print_menu(snack menu_items[TOTAL_ITEMS]);
void populate_menu(snack menu_items[TOTAL_ITEMS], char *item_names[TOTAL_ITEMS], float prices[TOTAL_ITEMS]);
float take_order(snack menu_items[TOTAL_ITEMS]);

// ------------------------------------------------------------------------------------------------------------------------

int main()
{
    // Menu items and prices
    char *item_names[] = {"Burger", "Vegan Burger", "Hot Dog", "Cheese Dog", "Fries", "Chilli Fries", "Cold Pressed Juice", "Cold Brew", "Water", "Soda"};
    float prices[] = {9.50, 11.00, 5.00, 7.00, 5.00, 6.00, 7.00, 3.00, 2.00, 2.00};

    // Build and display the menu.
    snack menu[TOTAL_ITEMS];
    populate_menu(menu, item_names, prices);
    print_menu(menu);

    // Get the order from the user
    float bill = take_order(menu);
    printf("Total: $%.2f\n", bill);
}
// ------------------------------------------------------------------------------------------------------------------------

void populate_menu(snack menu_items[TOTAL_ITEMS], char *item_names[TOTAL_ITEMS], float prices[TOTAL_ITEMS])
// Takes an array of strings and floats and snack structs and adds a snack struct for each item in found in the arrays.
{
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        menu_items[i] = (snack){
            .food = item_names[i],
            .cost = prices[i]};
    }
}

// ------------------------------------------------------------------------------------------------------------------------

void print_menu(snack menu_items[TOTAL_ITEMS])
// Prints out items and prices names found in the passed array of snack structs.
{
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu_items[i].food, menu_items[i].cost);
    }
}

// ------------------------------------------------------------------------------------------------------------------------

float take_order(snack menu_items[TOTAL_ITEMS])
// Takes user input and sums the total value of their order.
{
    // Record the total bill
    float bill = 0.0;

    bool taking_input = true;
    while (taking_input)
    {
        // Take user input
        printf("Select an item: ");
        char user_input[STRING_LENGTH];
        fgets(user_input, STRING_LENGTH, stdin);

        // Break condition
        if (user_input[0] == '\n')
        {
            taking_input = false;
        }

        // Make a version of the user input without trailing whitespace from fgets for comparison
        char no_white[STRING_LENGTH];

        // Flush buffer or we get garbage values in the string.
        for (int i = 0; i <= STRING_LENGTH; i++)
        {
            no_white[i] = 0;
        }

        // Build the new string
        for (int i = 0; i < strlen(user_input); i++)
        {
            if (user_input[i] != '\n')
            {
                no_white[i] = user_input[i];
            }
            else
            {
                user_input[i] == '\0';
            }
        }

        // Compare user Input to menu items. If input is value then add the item to the order.
        for (int j = 0; j < TOTAL_ITEMS; j++)
        {
            if (strcmp(no_white, menu_items[j].food) == 0)
            {
                bill += menu_items[j].cost;
                printf("Subtotal: $%.2f\n", bill);
            }
        }
    }
    return bill;
}