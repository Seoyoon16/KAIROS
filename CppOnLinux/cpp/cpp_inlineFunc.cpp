#include <iostream>

inline int odd (int x) {
    return (x%2);
}

int main() {
    using namespace std;
    
    int sum = 0;
    for (int i; i<=10000; i++) {
        if ((odd(i)))
            sum += i;
    }
    cout << sum;
    
    return 0;
}