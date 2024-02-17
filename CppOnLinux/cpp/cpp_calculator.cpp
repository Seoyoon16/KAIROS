#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void timeoutHandler(int signum) {
    exit(0);
}

class Add {
        int a, b;
    public:
        void setValue(int x, int y);
        int calculate();

};
void Add::setValue(int x, int y) {
    a = x; b = y;
}
int Add::calculate() {
    return a + b;
}

class Sub {
        int a, b;
    public:
        void setValue(int x, int y);
        int calculate();
};
void Sub::setValue(int x, int y) {
    a = x; b = y;
}
int Sub::calculate() {
    return a - b;
}

class Mul {
        int a, b;
    public:
        void setValue(int x, int y);
        int calculate();
};
void Mul::setValue(int x, int y) {
    a = x; b = y;
}
int Mul::calculate() {
    return a * b;
}

class Div {
        double a, b;
    public:
        void setValue(double x, double y);
        double calculate();
};
void Div::setValue(double x, double y) {
    a = x; b = y;
}
double Div::calculate() {
    if (b != 0) return a / b;
    else {
        std::cout << "cannot divide by zero" << std::endl;
        return -1;
    }
}

int main() {
    using namespace std;

    Add a; Sub s; Mul m; Div d;

    unsigned int timeout_sec = 7;
    signal(SIGALRM, timeoutHandler);
    alarm(timeout_sec);

    while(true) {
        cout << "two numbers and a operation like num op num : ";

        double x, y;
        char c;
        cin >> x >> c >> y;

        if (c == 'q') break;


        switch(c) {
            case '+':
                a.setValue(x, y);
                cout << fixed;
                cout.precision(2);
                cout << a.calculate() << endl;
                break;
            case '-':
                s.setValue(x, y);
                cout << fixed;
                cout.precision(2);
                cout << s.calculate() << endl;
                break;
            case '*':
                m.setValue(x, y);
                cout << fixed;
                cout.precision(2);
                cout << m.calculate() << endl;
                break;
            case '/':
                d.setValue(x, y);
                cout << fixed;
                cout.precision(2);
                cout << d.calculate() << endl;
                break;
            default:
                cout << "operation error!";
        }
    }
    cout << "quit!";

    return 0;
}