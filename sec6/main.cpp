#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    int grade;
    int deleteGrade;
    bool found = false;
    ofstream outfile("grades.txt");
    if (!outfile)
    {
        cout << "Error creating file!" << endl;
    }
    outfile << 85 << endl;
    outfile << 90 << endl;
    outfile << 75 << endl;
    outfile << 95 << endl;
    outfile << 80 << endl;
    outfile.close();
    cout << "Grades saved successfully!" << endl;
    ifstream infile("grades.txt");
    if (!infile)
    {
        cout << "Error opening file!" << endl;
    }
    cout << "\n Grades before deletion:" << endl;
    while (infile >> grade)
    {
        cout << grade << endl;
    }
    infile.close();
    cout << "\n Enter the grade you want to delete: ";
    cin >> deleteGrade;
    ifstream originalfile("grades.txt");
    ofstream tempfile("temp.txt");
    if (!originalfile || !tempfile)
    {
        cout << "Error opening files!" << endl;
    }
    while (originalfile >> grade)
    {
        if (grade == deleteGrade && !found)
        {
            found = true;
        }
        else
        {
            tempfile << grade << endl;
        }
    }
    originalfile.close();
    tempfile.close();
    if (found)
    {
        if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0)
        {
            cout << "\n Grade deleted successfully!" << endl;
        }
        else
        {
            cout << "\n Error replacing file!" << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "\n Grade not found!" << endl;
    }
    ifstream finalfile("grades.txt");
    cout << "\n Grades after deletion:" << endl;
    while (finalfile >> grade)
    {
        cout << grade << endl;
    }
    finalfile.close();
    return 0;
}
