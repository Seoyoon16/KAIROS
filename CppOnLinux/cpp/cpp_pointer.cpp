#include <iostream>

int main() {
    int a = 10, b = 20;

    int* c = &a; // address of a is in c
    int* d = &b; // address of b is in d

    std::cout << c << ' ' << d << std::endl; // address
    std::cout << *c << ' ' << *d << std::endl; // value

    *c = 50;
    std::cout << c << ' ' << *c << std::endl;

    c = &b;
    std::cout << c << ' ' << *c << std::endl;
}