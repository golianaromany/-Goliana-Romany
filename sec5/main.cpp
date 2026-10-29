#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outfile("students.txt",ios::app);
    if (!outfile.is_open())
    {
        cout << "Error opening the file" << endl;
    }
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        char name[20];
        int id;
        float grade;
        cout << "Enter student name : ";
        cin >> name;
        cout << "Enter student ID : ";
        cin >> id;
        cout << "Enter student grade : ";
        cin >> grade;
        outfile << name << ", " << id << ", " << grade << " $ ";
        cout << "Do you want to add another record ? (y/n):";
        cin >> choice;
    }
    outfile.close();
    cout << "Records have been successfully saved to students.txt" << endl;
    return 0;
}
