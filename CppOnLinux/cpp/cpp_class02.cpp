#include <iostream>

class Rectangle {
    public:
        int h;
        int w;
        int getArea();
};

int Rectangle::getArea() {
    return h * w;
}

int main() {
    using namespace std;

    Rectangle rect;
    rect.w = 3;
    rect.h = 5;

    cout << "size of rectangle is: " << rect.getArea() << endl;
}