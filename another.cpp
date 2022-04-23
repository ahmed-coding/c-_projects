#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define path_File_Iventory "inventory.txt"
#define path_File_BACK_UP "backup.txt"
#define path_File_Order "order.txt"
#define path_file_history "history.txt"

struct adding
{
    string desc;
    int quant;
    int order;
    double cost;
    char hsh = '#';
    double prUn = (cost * 2.4) / quant;
    double totalCost = cost / 2.4;
};


int main()
{
    finalTest test;
    system("pause");
    return 0;
}