#include <iostream>

class Circle {
    public:
        int radius;

        Circle();
        Circle(int r);
        // destructor
        ~Circle();

        double getArea();
};

Circle::Circle() {
    radius = 1;
    std::cout << "R: " << radius << std::endl;
}
Circle::Circle(int r) {
    using namespace std;

    radius = r;
    cout << "R: " << radius << endl;
}
Circle::~Circle() {
    std::cout << "Remove " << radius << "R Circle" << std::endl;
}


int main() {
    using namespace std;

    Circle donut;
    Circle pizza(30);

    return 0;
}