#include <iostream>
#include <string>

int main() {
    using namespace std;

    string song("I love you so much.");
    string name("Kairos Robot");
    string answer;

    cout << song + "The name of a program you take part in: ";

    getline(cin, answer);
    if (name==answer) {
        cout << "right" << endl << "answer: " << name << endl;
    }
    else {
        cout << "wrong. here is hint: " << name[0] << endl;
    }

    return 0;
}