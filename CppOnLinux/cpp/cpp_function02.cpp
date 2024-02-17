#include <iostream>

void number(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;

    std:: cout << &a << ' ' << &b << std::endl;
}

int main() {
    int a=2, b=9;
    number(a, b);

    std::cout << &a << ' ' << &b;
}