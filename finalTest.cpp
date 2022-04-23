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

class finalTest
{

private:
    adding *toAdd;

    char count;
    bool select = true;

    void added(adding add)
    {
        titl1(" NEW Add ");

        while (select)
        {
            system("cls");
            cout << "\nHow many orders you want to make? --> ";
            cin >> add.order;
            for (int i = 0; i < add.order; i++)
            {
                cout << "\nEnter your order no." << i + 1 << endl;
                cout << "The quantity: ";
                cin >> add.quant;
                cout << "\nThe cost: ";
                cin >> add.cost;
                cout << "\nThe descrption: ";
                std::cin >> std::ws;
                getline(cin, add.desc);
                addfile(add);
            }
            cout << "Would you like to try agein?\n\tPress Y to try again-\n\tPress Y to end-\n\tY or N :";
            cin >> count;
            if (count == 'Y' || count == 'y')
                select = true;
            else
                select = false;
        }
        titl2(" NEW Add ");
    }
    // نهاية الاظافه
    // طباعة اخر عملية
    void LastPr()
    {
        titl1(" The Last Addition Process ");
        fstream inventory(path_File_Iventory);
        cout << inventory.rdbuf();
        inventory.close();
        titl2(" The Last Addition Process ");
    }
    //  نهاية طباعة اخر عملية
    // اخذ البيانات من النسخه الاحتياطيه
    void addfile(adding add)
    {
        fstream back_Up(path_File_BACK_UP, ios::out | ios::app);
        fstream inventory(path_File_Iventory, ios::out | ios::app);

        back_Up << add.quant << add.hsh << add.cost << add.hsh << add.desc << endl;
        inventory << add.quant << "\t\t" << (add.cost * 2.4) << "\t\t" << (add.cost * 2.4) / add.quant << "\t\t" << add.desc << "\n";

        back_Up.close();
        inventory.close();
    }
    //  نهاية اخذ البيانات من النسخه الاحتياطيه
    // طباعة السجلات
    void printHistory()
    {
        titl1(" Transaction History ");
        adding add;
        fstream back_Up(path_File_BACK_UP, ios::in);
        fstream history(path_file_history, ios::out);
        history << "Quantity\tTotal Cost\tPrice@Unit\tItems\n--------\t----------\t----------\t-----\n";
        history.close();
        history.open(path_file_history, ios::app);
        while (!back_Up.eof())
        {
            back_Up >> add.quant >> add.hsh >> add.cost >> add.hsh >> add.desc;
            history << add.quant << "\t\t" << add.cost * 2.4 << "\t\t" << (add.cost * 2.4) / add.quant << "\t\t" << add.desc << "\n";
        }

        back_Up.close();
        history.close();
        history.open(path_file_history);
        cout << history.rdbuf();
        history.close();

        titl2(" Transaction History ");
    }
    // نهاية طباعة السجلات
    // الجماليات
    void header1()
    {
        cout << "======================================================\n\n";
    }

    void header2()
    {
        cout << "\n\n===========================BY Ahmed Hamza===========================\n";
    }
    void titl1(string a)
    {
        cout << "\n\n--------------------- " << a << " ---------------------\n\n";
    }
    void titl2(string a)
    {
        cout << "\n\n--------------------- AND " << a << " ---------------------\n\n";
    }
    // نهاية الجماليات

public:
    finalTest()
    {
        adding add;
        toAdd = new adding;
        *toAdd = add;
        system("cls");
        bool check = true;
        int scel;
        char scel2;
        fstream inventory(path_File_Iventory, ios::out);
        inventory << "Quantity\tTotal Cost\tPrice@Unit\tItems\n--------\t----------\t----------\t-----\n";
        inventory.close();
        while (check)
        {
            system("cls");
            header1();
            cout << "Choose the number to display \n\n";
            cout << "1--> TO Add\n2--> Sho the last addition process\n3--> Sho transaction history  \n\n\tEnter your Choose :";
            cin >> scel;
            switch (scel)
            {
            case 1:
                added(add);
                break;
            case 2:
                LastPr();
                break;
            case 3:
                printHistory();
                break;
            default:
                break;
            }
            header2();
            cout << "For back to main Enter Y \nFor exit Enter N\n\n\tY or N :";
            cin >> scel2;
            if (scel2 == 'Y' || scel2 == 'y')
                check = true;
            else
                check = false;
        }
        system("cls");
        cout << "\n\n\t\tTHANK YOU\n\n";
        header2();
    }

    ~finalTest()
    {
        delete toAdd;
    }
};

int main()
{
    finalTest test;
    system("pause");
    return 0;
}