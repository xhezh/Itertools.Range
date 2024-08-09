Itertools.Range

    Ограничение времени	1 секунда
    Ограничение памяти	64.0 Мб
    Ввод	стандартный ввод или input.txt
    Вывод	стандартный вывод или output.txt

Itertools

Одним из минусов языка C++ является отсутствие удобного интерфейса работы с последовательностями и промежутками значений, который, по большому счету сводится к ручному написанию циклов и работе со встроенными итераторами. С введением библиотеки в C++20 ситуация заметно улучшилась. В этом цикле задач мы попытаемся решить заявленную проблему средствами C++17.

Range

Для написания цикла по целым значениям в C++ необходимо написать следующий код:


for (int i = 0; i < end; ++i) {
    // ...
}

for (int i = begin; i < end; ++i) {
    // ...
}

for (int i = begin; i < end; i += step) {
    // ...
}

Сравните, например, с языком Python:


for i in range(end):
    # ...

for i in range(begin, end):
    # ...

for i in range(begin, end, step):
    # ...

Хотелось бы иметь подобный лаконичный код и в C++ (благо range-based for завезли в C++11):


for (int i : range(end)) {
    // ...
}

for (int i : range(begin, end)) {
    // ...
}

for (int i : range(begin, end, step)) {
    // ...
}

Проблема в том, что в стандартной библиотеке (до C++20) нет сущности range, которую можно было использовать в подобном контексте. Ну а раз так - надо ее реализовать самостоятельно!


Детали реализации
Необходимо реализовать Range (класс или функцию), который возвращает объект некоторого класса (вам нужно его реализовать) с определенными методами begin и end. Эти методы должны возвращать итератор (его тоже нужно реализовать), который при разыменовывании возвращает соответствующее целое значение, а при инкрементировании увеличивает свое состояние на step (по умолчанию step == 1).

Примеры: (больше примеров см. в тестах)

for (int i : Range(3)) { ... }  // i in [0, 1, 2]

for (int i : Range(3, 6)) { ... }  // i in [3, 4, 5]

for (int i : Range(3, 6, 2)) { ... }  // i in [3, 5]

for (int i : Range(6, 1, -2)) { ... }  // i in [6, 4, 2]

Указание: вспомните как работает range-based for в C++.

Дополнительное задание (0.5 балла)

Поддержать обратные итераторы (см. примеры в тестах). Добавьте директиву #define REVERSE_RANGE_IMPLEMENTED в файл с решением для проверки дополнительного задания.
