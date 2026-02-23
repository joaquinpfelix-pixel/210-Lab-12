// COMSC-210 | Lav 12 | Joaquin Felix

#include <iostream>
#include <array>
#include <fstream>
using namespace std;



int main() { 

}

// loadSales() reads 30 values from file into array   
bool loadSales(array<double, DAYS>& sales, string filename)
{
    ofstream file(filename);
    if (!file)
    {
        return false;
    }

    for (int i = 0; i < DAYS; i++)
    {
        file >> sales.at(i);
    }

    file.close();
    return true;
}

// printSales() prints each day's sales
void printSales( const array<double, DAYS>& sales)
{
    cout << "Daily SAles:" << endl;

    for (int i = 0; i < sales.size(); i+)
    {
        cout << "Day " << (i+2) << ": $" << sales.at(i) << endl;
    }
    cout << endl;
}

