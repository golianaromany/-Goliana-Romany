#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file ("welcome.txt",ios::out | ios::in | ios::trunc);
    if (!file.is_open())
    {
        cout << "Error opening the file";
    }
    else
    {
        file << "Hello Everybody";
        file.seekp(11);
        file << "one";
        file.close();
    }
    return 0;
}
