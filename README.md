Чтобы добавить русский язык в консоль Qt creator (В моем случае 6.6.1) нужно сделать следующее.
В начале файла .cpp прописываем: 

```
#include <clocale>
#include <fcntl.h>
#include <iostream>
#include <io.h>

```

Далее
```
int main() {
    setlocale(LC_ALL, "Russian"); // Установка локали для работы с русским языком
    _setmode(_fileno(stdout), _O_U16TEXT); // Устанавливаем режим вывода в консоль в режиме Unicode
}
```

Чтобы выводить в консоль текст, вместо привычного cout, используется wcout и перед кавычками ставится префикс L

```
int main() {
  ...
  wcout << L"Привет, мир!" << endl;
}
```

Чтобы работать со строками, необходимо вместо типа данных string использовать тип данных wstring
```
    wstring str = L"Как дела, друг?"; // Используем wstring для работы с широкими символами
    wcout << str << endl;

    wstring str1 = L"Эй, ";
    wstring str2 = L" я работаю на русском!!";
    wstring concatenated = str1 + str2;

```

Использование префикса L перед строкой является способом указать, что строка является широкой строкой (wide string) в C++. 
Широкие строки предназначены для работы с символами Юникода, такими как русские символы, которые требуют больше одного байта для представления.

cout (стандартный поток вывода) является потоком вывода для символов типа char, который используется для вывода обычных строк и символов ASCII.
Он является частью стандартной библиотеки C++ и доступен по умолчанию.

wcout (широкий поток вывода) является потоком вывода для символов типа wchar_t, который используется для работы с широкими строками и символами Юникода. 
Он также является частью стандартной библиотеки C++, но для его использования может потребоваться дополнительная настройка локали и поддержка широких символов.


Заметил странности, что после выполнения кода, даже если оставить только одну библиотеку iostream, русский язык всё равно будет работать в консоли. Также очередное
комментирование строк setlocale и _setmode ничего не меняет. В общем хз как, но оно работает.
