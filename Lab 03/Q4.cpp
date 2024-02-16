/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Smartphone {
    
private:
    string brand;
    string model;
    string res;
    int ram; 
    int rom;
    int storage;
    
public:
    string get_brand() {
        return brand;
    }

    string get_model() {
        return model;
    }

    string get_resolution() {
        return res;
    }

    int get_ram() {
        return ram;
    }

    int get_rom() {
        return rom;
    }

    int get_storage() {
        return storage;
    }

    void set_brand(string new_brand) {
        brand = new_brand;
    }

    void set_model(string new_model) {
        model = new_model;
    }

    void set_resolution(string new_res) {
        res = new_res;
    }

    void set_ram(int new_ram) {
        ram = new_ram;
    }

    void set_rom(int new_rom) {
        rom = new_rom;
    }

    void set_storage(int new_storage) {
        storage = new_storage;
    }

    void make_call(string contact) {
        cout << "called " << contact << endl;
    }

    void send_message(string message) {
        cout << "sent message" << endl;
        cout << message << endl;
    }

    void connect_to_wifi(string wifi) {
        cout << "connected to " << wifi << endl;
    }

    void browse_internet() {
        cout << "internet browsed" << endl;
    }
};

int main()
{
    Smartphone phone1, phone2;
    phone1.set_brand("Apple");
    phone1.set_model("Iphone 13");
    phone1.set_ram(6);
    phone1.set_rom(256);
    phone1.set_storage(512);

    phone2.set_brand("Samsung");
    phone2.set_model("Galaxy s21");
    phone2.set_ram(8);
    phone2.set_rom(128);
    phone2.set_storage(256);
    
    cout << "Phone 1:\n";
    
    cout << phone1.get_brand() << endl;
    cout << phone1.get_model() << endl;
    cout << phone1.get_ram() << endl;
    cout << phone1.get_rom() << endl;
    cout << phone1.get_storage() << endl;
    
    phone1.connect_to_wifi("HomeWiFi");
    phone1.send_message("hellooo");

    cout << endl << endl;
    
    cout << "Phone 2:\n";
    
    cout << phone2.get_brand() << endl;
    cout << phone2.get_model() << endl;
    cout << phone2.get_ram() << endl;
    cout << phone2.get_storage() << endl;
    cout << phone2.get_rom() << endl;
    
    phone2.browse_internet();
    phone2.make_call("Landline");

    return 0;
}