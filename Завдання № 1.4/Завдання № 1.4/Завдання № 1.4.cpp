#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class Parallelogram {

private:

    double base;      // Основа
    double height;    // Висота
    double side;      // Бічна сторона
    string color;     // Колір

    // Перевірка на правильність параметрів
    void validatePositive(double value, const string& fieldName) {
        if (value <= 0) {
            throw invalid_argument(fieldName + " повинно бути додатнім числом.");
        }
    }

public:

    // Конструктор за замовчуванням
    Parallelogram() : base(1), height(1), side(1), color("білий") {}

    // Конструктор з параметрами
    Parallelogram(double b, double h, double s, const string& c) {
        setBase(b);
        setHeight(h);
        setSide(s);
        setColor(c);
    }

    // Функції встановлення значень
    void setBase(double b) {
        validatePositive(b, "Основа");
        base = b;
    }

    void setHeight(double h) {
        validatePositive(h, "Висота");
        height = h;
    }

    void setSide(double s) {
        validatePositive(s, "Бічна сторона");
        side = s;
    }

    void setColor(const string& c) {
        if (c.empty()) {
            throw invalid_argument("Колір не може бути порожнім.");
        }
        color = c;
    }

    // Функції отримання значень
    double getBase() const { return base; }
    double getHeight() const { return height; }
    double getSide() const { return side; }
    string getColor() const { return color; }

    // Функція обчислення площі
    double calculateArea() const {
        return base * height;
    }

    // Функція обчислення периметру
    double calculatePerimeter() const {
        return 2 * (base + side);
    }

    // Функція виводу
    void print() const {

        cout << "Паралелограм:\n"
            << "  Основа: " << base << "\n"
            << "  Висота: " << height << "\n"
            << "  Бічна сторона: " << side << "\n"
            << "  Колір: " << color << "\n"
            << "  Площа: " << calculateArea() << "\n"
            << "  Периметр: " << calculatePerimeter() << "\n";
    }
};

int main() {

    setlocale(LC_ALL, "ukr");
        
        // Приклад використання з введенням вручну 
        Parallelogram p1;
        p1.setBase(5.0);
        p1.setHeight(3.0);
        p1.setSide(4.0);
        p1.setColor("синій");
        p1.print();

        cout << endl;

        // Приклад використання з конструктором з параметрами
        Parallelogram p2(6.0, 2.0, 5.0, "червоний");
        p2.print();

        cout << endl;

        // Приклад створення випадкових значень
        srand(static_cast<unsigned>(time(0)));
        double randomBase = rand() % 10 + 1;
        double randomHeight = rand() % 10 + 1;
        double randomSide = rand() % 10 + 1;
        Parallelogram p3(randomBase, randomHeight, randomSide, "зелений");
        cout << "Випадковий паралелограм:" << endl;
        p3.print();

    return 0;
}
