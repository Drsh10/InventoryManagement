#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to represent an inventory item
typedef struct {
    char name[50];
    int quantity;
    float price;
} InventoryItem;

// array to store inventory items
InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add an item to the inventory
void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", inventory[itemCount].name);
        printf("Enter quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        printf("Enter price: ");
        scanf("%f", &inventory[itemCount].price);
        printf("Item added successfully.\n");
        itemCount++;
    } else {
        printf("Inventory is full. Cannot add more items.\n");
    }
}

// Function to update an existing item in the inventory
void updateItem() {
    char itemName[50];
    printf("Enter item name to update: ");
    scanf("%s", itemName);
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

// Function to delete an item from the inventory
void deleteItem() {
    char itemName[50];
    printf("Enter item name to delete: ");
    scanf("%s", itemName);
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

// Function to generate a report of the current inventory
void generateReport() {
    printf("Inventory Report:\n");
    printf("-------------------------------------------------\n");
    printf("Item Name\t\tQuantity\t\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s\t\t\t%d\t\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. Generate Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addItem();
        } else if (choice == 2) {
            updateItem();
        } else if (choice == 3) {
            deleteItem();
        } else if (choice == 4) {
            generateReport();
        } else if (choice == 5) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
