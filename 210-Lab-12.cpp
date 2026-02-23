// COMSC-210 | Lav 12 | Joaquin Felix

#include <iostream>
#include <array>
#include <fstream>
using namespace std;

const int DAYS = 30;

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

//analyzeSales() uses various std::array member functions
void analyzeSales(const array<double, DAYS>& sales)
{
    cout << "Array Size: " << sales.size() << endl;
    cout << "First Day's Sales: $" << sales.front() << endl;
    cout << "Last Day's Sales: $" << sales.back() << endl;

    if (!sales.empty())
    {
        cout << "Array is not empty." << endl;
    }

    array<double, DAYS> backup;
    backup.fill(0.0);

    backup.swap(const_cast<array<double, DAYS>&>(sales));

    cout << "after swap, first element in back up: $"
         << backup.front() << endl;
    double* rawPointer = backup.data();
    cout << "Accessing first element using data(): $"
         << rawPointer[0] << endl;
}
