#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    string id;
    double grade;
    cout << "Enter Student Full Name : ";
    getline(cin, fullName);
    cout << "Enter Student ID : ";
    cin >> id;
    cout << "Enter Student Grade : ";
    cin >> grade;
    ofstream myfile("Student.txt");
    if (!myfile.is_open())
    {
        cout << "Error, file is not opened";
    }
    else
    {
        cout << "file opened successfully";
    }
    myfile << "Full Name : " << fullName << endl;
    myfile << "ID : " << id << endl;
    myfile << "Grade : " << grade << endl;
    myfile.close();
    return 0;
}
