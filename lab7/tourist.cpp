#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "tourist.h"

using namespace std;

void nameOf(Sity name)
{
    cout << "Name of sity " << name.name << endl;
}
void hotel(vector<string> h)
{
    for (int i = 0; i < h.size(); i++)
    {
        cout << h[i] << endl;
    }
}
void relaxation(vector<string> r)
{
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
}
void monument(vector<string> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << endl;
    }
}
void functions(Sity name)
{
    int temp=42;
    nameOf(name);
    while (temp)
    {
        cout << "Enter 1 to select view hotels" << endl;
        cout << "Enter 2 to select view relaxations" << endl;
        cout << "Enter 3 to select view monuments" << endl;
        cout << "Enter 0 to go back" << endl;
        cin >> temp;
        switch (temp)
        {
        case 1:
            hotel(name.hotels);
            break;
        case 2:
            relaxation(name.relaxations);
            break;
        case 3:
            monument(name.monuments);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}