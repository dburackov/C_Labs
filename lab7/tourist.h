#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Sity
{
    string name;
    vector <string> hotels;
    vector <string> relaxations;
    vector <string> monuments;
};
void nameOf(Sity name);
void hotel(vector<string> h);
void relaxation(vector<string> r);
void monument(vector<string> m);
void functions(Sity name);