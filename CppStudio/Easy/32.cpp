// Compile with g++ (gcc ver. 8.2.0)
// 32. Шесть равнобедренных треугольников
// Требуется вывести в консоль от 1-го до 6-ти равнобедренных треугольников, 
// в зависимости от того какое число введет пользователь.
// Input: n (from 1 to 6)
// Output: console picture (n triangles in line)

#include <iostream>
 
using namespace std;
 
int main()
{
    cout<<"Enter number of triangles(1-6): ";
    int number;
    cin>>number;

    if(number < 1 || number > 6)
    {
        cout << "Incorrent value!" << endl;
        return 1;
    }

    for(int y=1;y<=number;++y)
    {
        for(int i=1;i<=number;++i)
        {
            for(int x=1;x<=number-y;++x)
            {
                cout<<" ";
            }
            if(y==1)
            {
                cout<<"*";
            }
            else
            {
                for(int x=(-1)*y;x<y-1;++x)
                {
                    cout<<"*";
                }
            }
            for(int x=1;x<=number-y;++x)
            {
                cout<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}