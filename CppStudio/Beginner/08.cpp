//compiled with clang (10.0.1)
//8. Напишите программу, запрашивающую имя, фамилия, отчество и номер группы
//студента и выводящую введённые данные в следующем виде:
//Input: 3 strings
//Output:   *******************************
//          * Лабораторная работа № 1     *
//          * Выполнил(а): ст. гр. ЗИ-123 *
//          * Иванов Андрей Петрович      *
//          *******************************

#include <iostream>
#include <string>
using namespace std;


int main()
{
    string name, surname, patronymic, group;
    int studentFullNameSize;
    int numberOfSymbols = 31;
    int sizeOfSecondString;
    cout << "Введите имя студента:";
    cin >> name;
    cout << "Введите фамилию студента:";
    cin >> surname;
    cout << "Введите отчество студента:";
    cin >> patronymic;
    cout << "Введите номер группы студента:";
    cin >> group;
    studentFullNameSize = name.length() + surname.length() + patronymic.length() + 6;
    sizeOfSecondString= group.length() + 25;
    if ((studentFullNameSize > 31) && (studentFullNameSize > sizeOfSecondString))
    {
        numberOfSymbols = studentFullNameSize;
    }
    else if ((sizeOfSecondString > 31) && (sizeOfSecondString > studentFullNameSize))
    {
        numberOfSymbols = sizeOfSecondString;
    }
    for (int i = 0; i < numberOfSymbols; i++)
    {
        cout << "*";
    }
    cout << "\n* Лабораторная работа №1";
    for (int i = 0; i < numberOfSymbols - 25; i++)
    {
        cout << " ";
    }
    cout << "*\n* Выполнил(а): ст. гр. " << group;
    for (int i = 0; i <= numberOfSymbols - sizeOfSecondString; i++)
    {
        cout << " ";
    }
    cout << "*\n* " << surname << " " << name << " " << patronymic;
    for (int i = 0; i <= numberOfSymbols - studentFullNameSize; i++)
    {
        cout << " ";
    }
    cout << "*\n";
    for (int i = 0; i < numberOfSymbols; i++)
    {
        cout << "*";
    }
    cout << endl;
    return 0;
}