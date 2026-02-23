// COMSC-210 | Lav 12 | Joaquin Felix

#include <iostream>
#include <array>
#include <fstream>
using namespace std;

const int DAYS = 30;

// Load sales() reads values from a file
// arguments: array reference, file name
// returns: nothing
bool loadSales(array<double, DAYS>& sales, string filename);

// printSales() prints each day's sales
// arguments: const array reference
// returns: nothing
void printSales(const array<double, DAYS>& sales);
void analyzeSales(const array<double, DAYS>& sales);

int main() 
{
    array<double, DAYS> sales;
    
    if (!loadSales(sales, "sales.txt"))
    {
        cout << "Error: Could not open file." << endl;
        cout << "Make sure the file exists and is in the project folder."
             << endl;
        return 0;
    }

    cout << "STORE SALES SIMULATION" << endl;
    cout << "======================" << endl;

    printSales(sales);
    analyzeSales(sales);

    return 0;

}

// loadSales() reads 30 values from file into array   
bool loadSales(array<double, DAYS>& sales, string filename)
{
    ifstream file(filename);
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
    cout << "Daily Sales:" << endl;

    for (int i = 0; i < sales.size(); i++)
    {
        cout << "Day " << (i + 1) << ": $" << sales.at(i) << endl;
    }
    cout << endl;
}

//analyzeSales() uses various std::array member functions
void analyzeSales(array<double, DAYS>& sales)
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

    backup.swap(sales);

    cout << "after swap, first element in back up: $"
         << backup.front() << endl;
    double* rawPointer = backup.data();
    cout << "Accessing first element using data(): $"
         << rawPointer[0] << endl;
}
