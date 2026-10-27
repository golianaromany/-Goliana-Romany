#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("fruit.txt");
    if(!infile.is_open())
    {
        cout << "Error opening the file";
    }
    string file;
    while (getline(infile, file))
    {
        cout << file << endl;
    }
    infile.close();
    ofstream outfile("fruit.txt", ios::app);
    if (!outfile.is_open())
    {
        cout << "Error opening the file";
    }
    else
    {
        outfile << "Fresh Fruits";
        outfile.close();
    }
    return 0;
}
