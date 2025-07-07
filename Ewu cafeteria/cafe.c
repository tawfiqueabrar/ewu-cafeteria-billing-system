#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[100];
    float price;
};

void printLine() {
    printf("--------------------------------------------------\n");
}

void showMenu(struct Item menu[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Tk %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void showAndSaveReceipt(char customer[], struct Item ordered[], int count, float total) {
    FILE *file = fopen("receipt.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n============== EWU Cafeteria Receipt ==============\n");
    fprintf(file, "============== EWU Cafeteria Receipt ==============\n");

    printf("Customer Name: %s\n", customer);
    fprintf(file, "Customer Name: %s\n", customer);

    printLine();
    fprintf(file, "---------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%2d. %-35s Tk %.2f\n", i + 1, ordered[i].name, ordered[i].price);
        fprintf(file, "%2d. %-35s Tk %.2f\n", i + 1, ordered[i].name, ordered[i].price);
    }

    printLine();
    fprintf(file, "---------------------------------------------------\n");

    printf("Total Amount:                              Tk %.2f\n", total);
    fprintf(file, "Total Amount:                              Tk %.2f\n", total);

    printf("===================================================\n\n");
    fprintf(file, "===================================================\n\n");

    fclose(file);
    printf("Receipt saved successfully\n");
}

void readPreviousBill() {
    FILE *file = fopen("receipt.txt", "r");
    if (file == NULL) {
        printf("No previous bill found.\n");
        return;
    }

    char line[200];
    printf("\n----- Previous Bill -----\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    char customer[50];
    printf("\nWelcome to EWU Cafeteria!\n\nEnter your name: ");
    fgets(customer, sizeof(customer), stdin);
    customer[strcspn(customer, "\n")] = 0; // Remove newline

    // Menu Items by Category
    struct Item breakfast[] = {
        {"Toasted Bread with Jelly & Butter", 25},
        {"Paratha/Rooti Combo", 42.5},
        {"Boiled Egg", 15}
    };

    struct Item lunch[] = {
        {"Rice + Vegetable", 50},
        {"Rice + Vegetable + Daal", 60},
        {"Rice + Egg", 72.5},
        {"Rice + Chicken", 115},
        {"Rice + Beef", 160},
        {"Chicken Tehari", 100},
        {"Fried Rice/Khichuri Set", 125},
        {"Biriyani/Polao", 135}
    };

    struct Item snacks[] = {
        {"Singara/Samucha/Egg Chop", 15},
        {"Rolls/Burgers/Sandwiches", 45},
        {"Chicken Pasta", 100},
        {"French Fries", 60},
        {"Vegetable Salad", 20},
        {"Russian Salad", 40}
    };

    struct Item beverages[] = {
        {"Standard Tea", 10},
        {"Lemon Tea", 15},
        {"Milk Tea", 15},
        {"Coffee", 20},
        {"Cold Coffee", 50},
        {"Juice", 30},
        {"Milkshakes", 75}
    };

    struct Item specials[] = {
        {"Mini Set Menu", 90},
        {"Medium Set Menu", 110},
        {"Chicken Lollipop/Wings", 70},
        {"Special Burgers/Pasta", 100}
    };

    struct Item orderList[50];
    int orderCount = 0;
    float total = 0;

    int mainChoice;
    do {
        printLine();
        printf("Main Menu:\n");
        printf("1. New Order\n");
        printf("2. Previous Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);
        getchar(); // clear newline

        if (mainChoice == 1) {
            int catChoice;
            printf("\nChoose your category\n");
            printf("1. Breakfast\n2. Lunch & Dinner\n3. Snacks\n4. Beverages\n5. Smokey Dine Specials\n");
            printf("\nChoose your category: ");
            scanf("%d", &catChoice);

            struct Item *menu = NULL;
            int size = 0;
            switch (catChoice) {
                case 1: menu = breakfast; size = sizeof(breakfast)/sizeof(breakfast[0]); break;
                case 2: menu = lunch; size = sizeof(lunch)/sizeof(lunch[0]); break;
                case 3: menu = snacks; size = sizeof(snacks)/sizeof(snacks[0]); break;
                case 4: menu = beverages; size = sizeof(beverages)/sizeof(beverages[0]); break;
                case 5: menu = specials; size = sizeof(specials)/sizeof(specials[0]); break;
                default: printf("Invalid category.\n"); continue;
            }

            showMenu(menu, size);

            int howMany;
            printf("\nHow many items you want to order: ");
            scanf("%d", &howMany);

            for (int i = 0; i < howMany; i++) {
                int itemNumber;
                printf("Enter item number for item %d: ", i + 1);
                scanf("%d", &itemNumber);
                if (itemNumber > 0 && itemNumber <= size) {
                    orderList[orderCount] = menu[itemNumber - 1];
                    total += menu[itemNumber - 1].price;
                    orderCount++;
                } else {
                    printf("Invalid item number.\n");
                }
            }

            showAndSaveReceipt(customer, orderList, orderCount, total);

            // Reset order
            orderCount = 0;
            total = 0;

        } else if (mainChoice == 2) {
            readPreviousBill();
        } else if (mainChoice == 3) {
            printf("Thank you! Exiting...\n");
        } else {
            printf("Invalid choice.\n");
        }

    } while (mainChoice != 3);

    return 0;
}