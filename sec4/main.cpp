#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct Person
    {
        string name;
        int age;
    };

int main()
{
    int n;
    cout << "Enter how many persons you want to add :";
    cin >> n;
    ofstream outfile("persons.txt");
    if (!outfile.is_open())
    {
        cout << "Error opening the file";
    }
    for (int i = 0; i < n; i++)
    {
        Person p;
        cout << "Enter name for person " << i + 1 << ": ";
        cin >> p.name;
        cout << "Enter age for person " << i + 1 << ": ";
        cin >> p.age;
        outfile << p.name << " " << p.age << endl;
    }
    outfile.close();
    ifstream infile("persons.txt");
    if (!infile.is_open())
    {
        cout << "Error opening the file";
    }
    vector <Person> PersonsVector;
    Person p;
    while (infile >> p.name >> p.age)
    {
        PersonsVector.push_back(p);
    }
    infile.close();
    if (PersonsVector.empty())
    {
        cout << "No data found!" << endl;
    }
    Person younger = PersonsVector[0];
    Person older = PersonsVector[0];
    for (size_t i = 1; i < PersonsVector.size(); i++)
    {
        if (PersonsVector[i].age < younger.age)
        {
            younger = PersonsVector[i];
        }
         if (PersonsVector[i].age  > older.age)
        {
            older = PersonsVector[i];
        }
    }
    ofstream resultFile("results.txt");
    if (!resultFile)
    {
        cout << "Error opening results file" << endl;
    }
    resultFile << "Younger Person : "<< younger.name << "(" << younger.age << ")" << endl;
    resultFile << "Older Person : "<< older.name << "(" << older.age << ")" << endl;
    resultFile.close();
    cout << "--- Final Results ---" << endl;
    cout << "Younger Person : " << younger.name << "(" << younger.age << ")" << endl;
    cout << "Older Person : "<< older.name << "(" << older.age << ")" << endl;
    cout << "Results successfully saved to 'results.txt'." << endl;
    return 0;
}
