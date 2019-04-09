//Compile with g++ (ver. 8.1.0)
//Task : Find the sum of the numbers totally divisible by 5.
//Input : int
//Output : int

#include <iostream>

using namespace std;


int main (int argc , char* argv[])
{
    int number;

    int summ = 0;
    int temp = 0;

    cout << "Enter a number : ";
    cin >> number;
    

    if(number < 0)
    {
        while (temp >= number)
        {
            summ += temp;
            temp -= 5; 
        }
        
    }
    else
    {
        while (temp <= number)
        {
            summ += temp;
            temp += 5; 
        }
    }
    cout << "Summ = " << summ;
    return 0;
}