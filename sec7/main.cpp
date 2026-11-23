#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string names[] =
    {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };
    int n = 4;
    sort(names, names + n);
    cout << "Student names in ascending order:\n";
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << endl;
    }
    return 0;
}
