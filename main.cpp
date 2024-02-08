#include <iostream>
using namespace std;
#include <clocale>


int main() {
    setlocale(LC_ALL, "Russian"); // Установка локали для работы с русским языком

    // Объявляем переменные для хранения чисел и оператора
    double num1, num2, result;
    char op;

    wcout << L"Введи первое число: ";
    cin >> num1;
    cout << endl;

    wcout << L"Введите оператор (+, -, *, /): ";
    cin >> op;
    cout << endl;

    wcout << L"Введите второе число: ";
    cin >> num2;
    cout << endl;

    switch (op) {
    case '+':
        result = num1 + num2; // Сложение
        break;
    case '-':
        result = num1 - num2; // Вычитание
        break;
    case '*':
        result = num1 * num2; // Умножение
        break;
    case '/':
        // Деление
        // Проверяем, что второе число не равно нулю
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            wcout << L"Ошибка: нельзя делить на ноль" << endl;
            return 0; // Завершаем программу
        }
        break;
    default:
        wcout << L"Ошибка: неверный оператор" << endl;
        return 0; // Завершаем программу
    }

    wcout << L"Результат: " << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0; // Завершаем программу
}
