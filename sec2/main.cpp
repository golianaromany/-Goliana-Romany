#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile("fruit.txt", ios::app);
    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
    }
    outFile << "Fresh Fruits" << endl;
    outFile.close();
    ifstream inFile("fruit.txt");
    if (!inFile)
    {
        cout << "Error opening file for reading!" << endl;
    }
    string line;
    cout << "-- File Contents --" << endl;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
