#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class QuadErr : public invalid_argument {
private:
    double a, b, c;

public:
    QuadErr(const string& msg, double a, double b, double c)
        : invalid_argument(msg), a(a), b(b), c(c) {}

    void print() const {
        cout << "Ошибка: " << what() << endl;
        cout << "Уравнение: "
             << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
};

class QuadEq {
private:
    double a, b, c;

public:
    QuadEq(double a, double b, double c) : a(a), b(b), c(c) {
        if (a == 0) {
            throw QuadErr("a не может быть 0", a, b, c);
        }
    }

    void solve() const {
        double d = b * b - 4 * a * c;
        if (d < 0) {
            throw QuadErr("Нет действительных корней", a, b, c);
        }
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Корни: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
};

int main() {
    try {
        cout << "=== Без ошибки ===" << endl;
        QuadEq eq1(1, -3, 2);
        eq1.solve();
    }
    catch (const QuadErr& e) {
        e.print();
    }
    cout << endl;
    try {
        cout << "=== Нет корней ===" << endl;
        QuadEq eq2(1, 2, 5);
        eq2.solve();
    }
    catch (const QuadErr& e) {
        e.print();
    }
    cout << endl;
    try {
        cout << "=== a = 0 ===" << endl;
        QuadEq eq3(0, 2, 1);
        eq3.solve();
    }
    catch (const QuadErr& e) {
        e.print();
    }
    return 0;
}