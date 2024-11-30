#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {

private:

    unsigned int* data;     // Вказівник на масив
    size_t size;            // Кількість елементів у векторі
    bool state;             // Стан вектора (true = активний, false = неактивний)

    void initialize(unsigned int value) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

public:

    // Конструктор без параметрів
    Vector() : size(1), state(true) {
        data = new unsigned int[1] {0}; // Виділення пам'яті та ініціалізація 0
    }

    // Конструктор з одним параметром (розмір вектора)
    Vector(size_t n) : size(n), state(true) {
        if (n == 0) {
            throw invalid_argument("Розмір вектора не може бути 0.");
        }
        data = new unsigned int[n] {0}; // Виділення пам'яті та ініціалізація 0
    }

    // Конструктор із двома параметрами (розмір та значення ініціалізації)
    Vector(size_t n, unsigned int value) : size(n), state(true) {
        if (n == 0) {
            throw invalid_argument("Розмір вектора не може бути 0.");
        }
        data = new unsigned int[n];
        initialize(value); // Ініціалізація значенням
    }

    // Конструктор копіювання
    Vector(const Vector& other) : size(other.size), state(other.state) {
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this; // Захист від самоприсвоєння
        }
        // Звільнення старої пам'яті
        delete[] data;

        // Копіювання нових значень
        size = other.size;
        state = other.state;
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Функція для присвоєння значення елементу
    void setElement(size_t index, unsigned int value) {
        if (index >= size) {
            throw out_of_range("Індекс виходить за межі вектора.");
        }
        data[index] = value;
    }

    // Функція для отримання значення елементу
    unsigned int getElement(size_t index) const {
        if (index >= size) {
            throw out_of_range("Індекс виходить за межі вектора.");
        }
        return data[index];
    }

    // Функція друку вектора
    void print() const {
        cout << "Вектор (стан: " << (state ? "активний" : "неактивний") << "): [";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i];
            if (i != size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {

    setlocale(LC_ALL, "ukr");

        // Конструктор без параметрів
        Vector v1;
        v1.print();

        // Конструктор з одним параметром
        Vector v2(5);
        v2.print();

        // Конструктор із двома параметрами
        Vector v3(5, 42);
        v3.print();

        // Використання setElement та getElement
        v2.setElement(2, 99);
        cout << "Елемент з індексом 2: " << v2.getElement(2) << endl;

        // Конструктор копіювання
        Vector v4(v3);
        v4.print();

        // Оператор присвоєння
        v1 = v2;
        v1.print();

    return 0;
}
