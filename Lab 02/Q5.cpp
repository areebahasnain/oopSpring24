/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Description: Develop a basic product management system for an online store with functions to add new products, 
display detailed information about a product by ID, and update product information based on the given ID and new details */

#include <iostream>

using namespace std;

struct Product {
    string name;
    float price;
    int quantity, id;
};

void menu(int c) {
    cout << "--------------" << endl << "\tMenu" << endl << "--------------" << endl
         << "1. Add product" << endl
         << "2. Update product information" << endl
         << "3. Display product information " << endl
         << "4. Exit" << endl;
}

int input_id() {
    int id;
    cout << "Enter product ID: ";
    cin >> id;

    return id;
}

Product* find_by_id(Product products[100], int c, int id) {
    for (int i = 0; i < c; i++)
        if (products[i].id == id) return &products[i];
    
    Product *null_product = new Product();
    null_product->name = "NOT_FOUND";
    return null_product;
}

void input_product(Product products[100], int i) {
    Product newProduct;
    newProduct.id = i;

    cout << "Product ID: " << i << endl;
    cout << "Enter product name: ";
    cin >> newProduct.name;

    cout << "Enter product price: ";
    cin >> newProduct.price;

    cout << "Enter product quantity: ";
    cin >> newProduct.quantity;

    products[i] = newProduct;
}

void output_product(Product products[100], int c, int id) {
    Product* product = find_by_id(products, c, id);
    cout << endl;

    if (product->name == "NOT_FOUND") {
        cout << "Product not found" << endl;
        return;
    }

    cout << "ID    --> " << product->id << endl
         << "name  --> " << product->name << endl
         << "price --> " << product->price << endl
         << "qty.  --> " << product->quantity << endl;

}

void update_product(Product products[100], int c, int id) {
    Product* product = find_by_id(products, c, id);

    if (product->name == "NOT_FOUND") {
        cout << "Product not found" << endl;
        return;
    }

    input_product(products, id);
}

int main() {
    Product products[100];
    int c = 0;

    bool flag = true;
    while(flag) {
        int choice;
        menu(c);
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                input_product(products, c++);
                break;
            case 2:
                update_product(products, c, input_id());
                break;
            case 3:
                output_product(products, c, input_id());
                break;
            case 4:
            default:
                flag = false;
        }
        cout << endl;
    }

    return 0;
}
