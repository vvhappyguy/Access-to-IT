//compiled with clang (10.0.1)
//21. Программа-тест, оператор switch
//Input: 3 ints
//Output: int 

#include <iostream>
using namespace std; 

int main()
{
    int answer;
    int points = 0;
    cout << "Назовите знаменатель дроби 3/5: " << endl << "Варианты:" << endl << "-> 3" 
    << endl << "-> 5" << endl << "-> 7" << endl << "Ваш ответ: ";
    cin >> answer;
    if (answer == 5) points++;
    cout << "Чему равен корень из 1: " << endl << "Варианты:" << endl << "-> 12" 
    << endl << "-> 91" << endl << "-> 1" << endl << "Ваш ответ: ";
    cin >> answer;
    if (answer == 1) points++;
    cout << "Чему будет равно выражение 2 + 0: " << endl << "Варианты:" << endl << "-> -6" 
    << endl << "-> 2" << endl << "-> 3.5" << endl << "Ваш ответ: ";
    cin >> answer;
    if (answer == 2) points++;
    switch (points)
    {
    case 1: 
    cout << "3 balla" << endl;
    break;
    case 2:
    cout << "4 balla" << endl;
    break;
    case 3:
    cout << "5 ballov" << endl;
    break;
    default : 
    cout << "2 balla";
    break;
    }
    return 0;

}