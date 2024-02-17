#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    string s = "hey~";
    char c[10] = "hi!";

    int m = s.length();
    int n = strlen(c);

    cout << m << ',' << n << endl;

    cout << "Enter your address: ";
    char address[100];
    cin.getline(address, 100, '\n');

    cout << "Address is " << address << endl;

    return 0;
}