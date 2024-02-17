#include <iostream>

int big(int a, int b) {
    if (a>b) return a;
    else return b;
}

int big(int a[], int size) {
    int res = a[0];
    for (int i=1; i<size; i++) {
        if (res<a[i]) res = a[i];
    }
    return res;
}

int small(int a, int b) {
    if (a>b) return b;
    else return a;
}

int small(int a[], int size) {
    int res = a[0];
    for (int i=1; i<size; i++) {
        if (res>a[i]) res = a[i];
    }
    return res;
}

int main() {
    using namespace std;

    int array[5] = {1, 9, -2, 8, 6};
    cout << big(2, 3) << endl;
    cout << big(array, 5) << endl;
    cout << small(2, 3) << endl;
    cout << small(array, 5) << endl;

}