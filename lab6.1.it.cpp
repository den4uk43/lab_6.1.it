#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція-предикат для перевірки критерію (від'ємне парне число)
bool predict(int value) {
    return (value < 0 && value % 2 == 0);
}

// Функція формування масиву генератором випадкових чисел
void F(int* p, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        p[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція виведення масиву у вигляді рядка з форматуванням
void out(const int* p, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << p[i];
    }
    cout << endl;
}

// Функція обчислення кількості елементів, що відповідають критерію
int countElements(const int* p, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (predict(p[i])) {
            count++;
        }
    }
    return count;
}

// Функція обчислення суми елементів, що відповідають критерію
int sumElements(const int* p, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (predict(p[i])) {
            sum += p[i];
        }
    }
    return sum;
}

// Функція заміни нулями елементів, що відповідають критерію
void replaceElements(int* p, const int size) {
    for (int i = 0; i < size; i++) {
        if (predict(p[i])) {
            p[i] = 0;
        }
    }
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 20;
    const int LOW = -20;
    const int HIGH = 34;

    int p[SIZE];

    // 1. Формування масиву
    F(p, SIZE, LOW, HIGH);

    // 2. Виведення початкового масиву
    cout << "start massive:" << endl;
    out(p, SIZE);

    // 3. Обчислення кількості та суми
    int count = countElements(p, SIZE);
    int sum = sumElements(p, SIZE);

    // 4. Виведення результатів обчислення
    cout << endl;
    cout << "count elements: " << count << endl;
    cout << "sum:      " << sum << endl;

    // 5. Заміна відповідних елементів нулями
    replaceElements(p, SIZE);

    // 6. Виведення модифікованого масиву
    cout << endl;
    cout << "mod massive:" << endl;
    out(p, SIZE);

    return 0;
}