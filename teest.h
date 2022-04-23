#include <iostream>
#include <fstream>
using namespace std;
#define File_Path_emp "emploee.txt"
struct empl
{
    int id;
    string lname;
    char jop;
    double salary;
};
class emploee
{
private:
    empl *newemplee;

public:
    void add(empl emp)
    {
        fstream femp(File_Path_emp, ios::out | ios::app);

        cout << "enter the  name:";
        cin >> emp.lname;
        cout << "enter the ID :";
        cin >> emp.id;
        cout << "enter the salary :";
        cin >> emp.salary;
        cout << "enter the place of jop:\n enter \"M\" For manager\n \"A\" For Cashier\n\t enter your choice :";
        cin >> emp.jop;
        femp << emp.salary << '#' << emp.lname << '#' << emp.jop << '#' << emp.id << endl;
        femp.close();
    }

    void delet(empl emp)
    {
        int i;
        char f;
        fstream nemp("temp.txt", ios::out);
        fstream femp(File_Path_emp, ios::in);
        cout << "enter the ID :";
        cin >> i;

        while (!femp.eof())
        {
            femp >> emp.salary >> f >> emp.lname >> f >> emp.jop >> emp.id;
            if (i == emp.id)
            {
                cout << "delete ok";
                continue;
            }
            nemp << emp.salary << f << emp.lname << f << emp.jop << f << emp.id << endl;
        }

        femp.close();
        nemp.close();
        // femp.open(File_Path_emp, ios::out);
        // femp.close();
        remove("emploee.txt");
        rename("temp.txt", "emploee.txt");
    }

    emploee(empl emp)
    {

        newemplee = new empl;
        *newemplee = emp;
        add(emp);
        delet(emp);
    }
    ~emploee()
    {
        delete newemplee;
    }
};