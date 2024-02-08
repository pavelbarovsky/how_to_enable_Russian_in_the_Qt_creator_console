Чтобы добавить русский язык в консоль Qt creator (В моем случае 6.6.1) нужно сделать следующее.
В начале файла прописываем:
#include <clocale>

Далее
int main() {
  setlocale(LC_ALL, "Russian"); // Установка локали для работы с русским языком
  ...
}

Чтобы выводить в консоль текст, вместо привычного cout, используется wcout
int main() {
  setlocale(LC_ALL, "Russian"); // Установка локали для работы с русским языком

    wcout << L"Введи первое число: ";
    cin >> num1;
}

Использование префикса L перед строкой является способом указать, что строка является широкой строкой (wide string) в C++. 
Широкие строки предназначены для работы с символами Юникода, такими как русские символы, которые требуют больше одного байта для представления.

cout (стандартный поток вывода) является потоком вывода для символов типа char, который используется для вывода обычных строк и символов ASCII.
Он является частью стандартной библиотеки C++ и доступен по умолчанию.

wcout (широкий поток вывода) является потоком вывода для символов типа wchar_t, который используется для работы с широкими строками и символами Юникода. 
Он также является частью стандартной библиотеки C++, но для его использования может потребоваться дополнительная настройка локали и поддержка широких символов.