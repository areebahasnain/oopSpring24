/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

#define MAX_ITEMS 100

using namespace std;

class stationary_shop {
private:
    string items[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int count = 0;

public:
    void add_item(string item, float price) {
        items[count] = item;
        prices[count++] = price;
        cout << "Item added successfully.\n";
    }

    string get_item(int item) {
        return items[item - 1];
    }

    float get_price(int item) {
        return prices[item - 1];
    }

    int get_count() {
        return count;
    }

    void modify_price(int price, int item_num) {
        prices[item_num - 1] = price;
        cout << "Price modified successfully.\n";
    }

    void display() {
        if (count == 0) {
            cout << "No items available.\n";
        } else {
            cout << "Items available:\n";
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". " << items[i] << ": " << prices[i] << endl;
            }
        }
    }
};

void menu() {
    cout << "\nStationary Shop Menu:" << endl
         << "\t1. Add item" << endl
         << "\t2. Modify price" << endl
         << "\t3. Display items" << endl
         << "\t4. Purchase item" << endl
         << "\t5. Generate receipt" << endl
         << "\t6. Exit" << endl
         << "Enter your choice: ";
}

void enter_item(stationary_shop &shop) {
    string item;
    float price;

    cout << "Enter item name: ";
    cin >> item;
    cout << "Enter item price: ";
    cin >> price;

    shop.add_item(item, price);
}

void change_price(stationary_shop &shop) {
    int item_num;
    float price;

    cout << "Enter item number: ";
    cin >> item_num;
    cout << "Enter new item price: ";
    cin >> price;

    shop.modify_price(price, item_num);
}

void buy_item(string items[MAX_ITEMS], float prices[MAX_ITEMS], int &c, stationary_shop &shop) {
    int item;

    cout << "Enter item to buy: ";
    cin >> item;

    items[c] = shop.get_item(item);
    prices[c] = shop.get_price(item);
    c++;
}

float find_sum(float arr[MAX_ITEMS], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

void generate_receipt(string items[MAX_ITEMS], float prices[MAX_ITEMS], int c) {
    if (c == 0) {
        cout << "No items purchased yet.\n";
        return;
    }

    cout << "\nReceipt:\n";
    for (int i = 0; i < c; i++) {
        cout << items[i] << ": " << prices[i] << endl;
    }
    cout << "Total: " << find_sum(prices, c) << endl;
}

int main() {
    stationary_shop shop;
    string receipt_items[MAX_ITEMS];
    float receipt_prices[MAX_ITEMS];
    int receipt_count = 0;

    bool flag = true;
    while (flag) {
        menu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                enter_item(shop);
                break;
            case 2:
                change_price(shop);
                break;
            case 3:
                shop.display();
                break;
            case 4:
                if (shop.get_count() == 0) {
                    cout << "No items available for purchase.\n";
                } else {
                    buy_item(receipt_items, receipt_prices, receipt_count, shop);
                }
                break;
            case 5:
                generate_receipt(receipt_items, receipt_prices, receipt_count);
                break;
            case 6:
                flag = false;
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
