#include <iostream>
#include <string>

class Point {
    int x, y;
public:
    void set(int x, int y) {
        this->x=x;
        this->y=y;
    }
    void showPoint() {
        std::cout << '(' << x << ',' << y << ')' << std::endl;
    }
};

class ColorPoint: public Point {
    std::string color;
public:
    void setColor(std::string color) {
        this->color=color;
    }
    void showColorPoint();
};
void ColorPoint::showColorPoint() {
        std::cout << color << ':';
        showPoint();
    }

int main() {
    using namespace std;

    Point p;
    ColorPoint cp;
    cp.set(3, 4);
    cp.setColor("Red");
    cp.showColorPoint();
}