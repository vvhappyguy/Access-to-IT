//Compile with g++ (ver. 8.1.0)
//Task : Find track of matrix.
//Input : int , int
//Output: int


#include <iostream>
#include <ctime>

using namespace std;

int main (int argc, char* argv[])
{

    srand (time(NULL));

    int cols = 0;
    int rows = 0;
    int track = 0;

    cout << "Enter number of matrix rows(must be positive): ";
    cin >> rows;

    if(rows <= 0)
    {
        cout << "Number of matrix rows incorrect!\n";
        return 1;
    }

    cout << "Enter number of matrix columns(must be positive): ";
    cin >> cols;

    if(cols <= 0)
    {
        cout << "Number of matrix columns incorrect!\n";
        return 1;
    }



    int** mass = new int*[rows];     

    for(int i = 0; i < rows; ++i)
    {
        mass[i] = new int [cols];
    }
    
    for(int i = 0; i < rows; ++i)  
    {
       for(int j = 0; j < cols; ++j)
        {
            mass[i][j] = rand();

            cout << mass[i][j] << " ";

            if(i == j)
            {
                track += mass[i][j];
            }
        }
        cout << endl;
    }

     for(int i = 0; i < rows; ++i)
    {  
        delete mass[i];
    }
    delete[] mass;

    cout << "Track of matrix = " << track;

    return 0;
}