// COMSC-210 | Lav 12 | Joaquin Felix

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int DAYS = 30;
const string SALES_FILE = "sales.txt";

// Load sales() reads values from a file
// arguments: vector reference, file name
// returns: nothing
bool loadSales(vector<double>& sales, string filename);

// printSales() prints each day's sales
// arguments: const vector reference
// returns: nothing
void printSales(const vector<double>& sales);
void analyzeSales(const vector<double>& sales);

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
void printSales( const vector<double>& sales)
{
    cout << "Daily Sales:\n\n";

    for (int i = 0; i < sales.size(); i++)
    {
        cout << "Day " << (i + 1) << ": $" << sales.at(i) << endl;
    }
    cout << endl;
}

//analyzeSales() uses various std::vector member functions
void analyzeSales(const vector<double>& sales)
{
    cout << "Vector Size: " << sales.size() << endl;
    cout << "First Day's Sales: $" << sales.front() << endl;
    cout << "Last Day's Sales: $" << sales.back() << endl;

    if (!sales.empty())
    {
        cout << "Vector is not empty." << endl;
    }

    vector<double> backup(sales);
    

    backup.swap(sales);

    cout << "After swap, first element in back up: $"
         << backup.front() << endl;
    double* rawPointer = backup.data();
    cout << "Accessing first element using data(): $"
         << rawPointer[0] << endl;
}
