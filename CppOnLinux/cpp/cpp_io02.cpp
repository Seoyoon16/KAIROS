#include <iostream>

int main() {
    using namespace std;
    
    float r, res;
    const float pie = 3.14;

    cout << "enter value of radius: ";
    cin >> r;

    res = r * r * pie;
    cout << "area of a circle: " << res << endl;

    float a, b;
    cout << "enter square length and width with blank: ";
    cin >> a >> b;
    cout << "area of a square: " << a * b << endl;

    return 0;
}