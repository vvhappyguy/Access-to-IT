// compiled with clang (10.0.1)
// 15. Определить, пройдет ли кирпич в отверстие
// Input: float, float, float, float, float
// Output: string

#include <iostream>
using namespace std;

int main()
{
    float length, width, height, holeLength, holeHeight;
    cout << "Введите длину кирпича: ";
    cin >> length;
    cout << "Введите ширину кирпича: ";
    cin >> width;
    cout << "Введите высоту кирпича: ";
    cin >> height;
    cout << "Введите длину отверстия: ";
    cin >> holeLength;
    cout << "Введите ширину отверстия: ";
    cin >> holeHeight;
    if (length <= 0 || width <= 0 || height <= 0 || holeLength <= 0 || holeHeight <= 0)
    {
        cout << "Введите корректные данные!" << endl;
        return 1;
    }
    switch (((length <= holeLength && width <= holeHeight) || (length <= holeHeight && width <= holeLength))     ? 1
            : ((length <= holeLength && height <= holeHeight) || (length <= holeHeight && height <= holeLength)) ? 2
            : ((height <= holeLength && width <= holeHeight) || (height <= holeHeight && width <= holeLength))   ? 3
                                                                                                                 : -1)
    {
        case 1:
            cout << "Кирпич прошел первой стороной." << endl;
            break;
        case 2:
            cout << "Кирпич прошел второй стороной." << endl;
            break;
        case 3:
            cout << "Кирпич прошел третьей стороной." << endl;
            break;
        case -1:
            cout << "Кирпич не сможет пройти через отверстие." << endl;
            break;
    }

    return 0;
}