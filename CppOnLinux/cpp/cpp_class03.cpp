#include <iostream>

class Rectangle {
    public:
        int width, height;

        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int l);
        bool isSquare();
};

// constructors
Rectangle::Rectangle() {
    width = height = 1;
}
Rectangle::Rectangle(int w, int h) {
    width = w; height = h;
}
Rectangle::Rectangle(int l) {
    width = height = 1;
}

// function
bool Rectangle::isSquare() {
    if (width == height) return true;
    else return false;
}

int main() {
    using namespace std;

    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if (rect1.isSquare()) cout << "rect1 is square." << endl;
    if (rect2.isSquare()) cout << "rect2 is square." << endl;
    if (rect3.isSquare()) cout << "rect3 is square." << endl;


    return 0;
}