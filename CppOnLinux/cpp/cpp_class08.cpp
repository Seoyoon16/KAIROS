#include <iostream>
#include <string>

class Point {
    int x, y;
public:
    Point(int x, int y) {
        this->x=x; this->y=y;
    }
    int getX() { return x; }
    int getY() { return y; }
protected:
    void move(int x, int y) {
        this->x=x; this->y=y;
    }
};

class ColorPoint: public Point {
    std::string color;
public:
    ColorPoint(int x, int y, std::string color): Point(x, y) {
        this->color=color;
    }
    void setPoint(int x, int y) {
        move(x, y);
    }
    void setColor(std::string color) {
        this->color=color;
    }
    void show() {
        std::cout << color << ", " << getX() << ", " << getY() << std::endl; 
    }
};


int main() {
    using namespace std;

    ColorPoint cp(5, 5, "RED");
    cp.setPoint(10, 20);
    cp.setColor("BLEU");
    cp.show();
}