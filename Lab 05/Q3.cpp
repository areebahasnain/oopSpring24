/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class ValidateString {
private:
    string str;
public:
    ValidateString(string str) : str(str) {}

    // Declaring isValid() as constant ensures it only reads the str member without modifying the object's state.
    bool isValid() const {
        for (char c : str)
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
        return true;
    }
};

int main()
{
    ValidateString str1("HelloWorld");
    ValidateString str2("124!");

    cout << "str1: " << str1.isValid() << "\n" << "str2: " << str2.isValid() << endl;
    return 0;
}