#include <iostream>

class Circle {
    public:
        int radius;
        double getArea();
};

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    using namespace std;

    Circle baseball;
    baseball.radius = 1;
    double area = baseball.getArea();
    cout << "size of baseball : " << area << endl;

    Circle pie;
    pie.radius = 30;
    area = pie.getArea();
    cout << "size of pie : " << area << endl;
    
    return 0;
}