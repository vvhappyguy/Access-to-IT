//Compile with g++ (ver. 8.1.0)
//Task : Determine how many new strings in the text.
//Output : int

#include <iostream>

using namespace std;


int main (int argc , char* argv[])
{
    int counter = 0;
    int i = 0;
    char text[] =  "Six years ago I had to make an emergency landing in the Sahara.\n"
                   "Something broke in the engine of my aircraft.\n"
                   "I had neither a mechanic nor passengers, and I decided that I would try to fix everything myself, even though it is very difficult.\n"
                   "I had to fix the motor or die.\n"
                   "I’d barely have enough water for a week.\n"
                   "So, on the first night, I fell asleep on the sand in the desert, where for thousands of miles there was no shelter.\n"
                   "The man, shipwrecked and lost on a raft in the middle of the ocean, and he would not be so alone ... #";

    while (text[i] != '#')
    {
        if(text[i] == '\n') 
        {
            ++counter;
        }
        ++i;
    }

    cout << "This text has " << counter << " new string.";

    return 0;
}