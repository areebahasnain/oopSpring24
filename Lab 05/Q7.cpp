/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
#include <vector>

using namespace std;

class MenuItem
{
private:
    string foodName;
    double foodPrice;

public:
    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}

    string getFoodName() const
    {
        return foodName;
    }

    double getFoodPrice() const
    {
        return foodPrice;
    }
};

class Menu
{
private:
    vector<MenuItem> items;

public:
    void addItem(const MenuItem &item)
    {
        items.push_back(item);
    }

    void removeItem(int index)
    {
        if (index >= 0 && index < items.size())
        {
            items.erase(items.begin() + index);
        }
    }

    void displayMenu() const
    {
        cout << "Menu:\n";
        for (size_t i = 0; i < items.size(); ++i)
        {
            cout << i + 1 << ". " << items[i].getFoodName() << " - Rs " << items[i].getFoodPrice() << endl;
        }
    }
};

class Order
{
private:
    vector<MenuItem> items;
    double totalPayment;

public:
    Order() : totalPayment(0) {}

    void addMenuItem(const MenuItem &item)
    {
        items.push_back(item);
        totalPayment += item.getFoodPrice();
    }

    double getTotalPayment() const
    {
        return totalPayment;
    }
};

class Payment
{
private:
    double amount;

public:
    Payment(double amount) : amount(amount) {}

    double getAmount() const
    {
        return amount;
    }
};

class Restaurant
{
private:
    Menu menu;

public:
    void setMenu(const Menu &m)
    {
        menu = m;
    }

    Menu getMenu() const
    {
        return menu;
    }

    Order placeOrder(const vector<MenuItem> &orderedItems)
    {
        Order order;
        for (const auto &item : orderedItems)
        {
            order.addMenuItem(item);
        }
        return order;
    }
};

int main()
{
    MenuItem i1("Biryani", 950.00);
    MenuItem i2("Karhai", 1300.00);

    Menu menu;
    menu.addItem(i1);
    menu.addItem(i2);

    Restaurant restaurant;
    restaurant.setMenu(menu);

    restaurant.getMenu().displayMenu();

    vector<MenuItem> orderedItems = {i1, i2};
    Order order = restaurant.placeOrder(orderedItems);
    cout << endl << "Bill: Rs " << order.getTotalPayment() << endl;
    cout << endl;
    return 0;
}
