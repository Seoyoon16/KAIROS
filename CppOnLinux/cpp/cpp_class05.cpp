#include <iostream>

class Person {
public:
    int money;
    static int sharedMoney;

    void addMoney(int money) {
        this->money += money;
        // std::cout << this << std::endl;
    }

    static void addShared(int n) {
        sharedMoney += n;
    }
};

int Person::sharedMoney = 10;

int main() {
    using namespace std;

    Person::addShared(50);
    cout << Person::sharedMoney << endl;

    Person han;
    han.money = 100;
    han.sharedMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney(200);
    lee.addShared(200);

    cout << han.money << ' ' << lee.money << endl;
    cout << Person::sharedMoney << ' ' << lee.sharedMoney << endl;

    return 0;
}