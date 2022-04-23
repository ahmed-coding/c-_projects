#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
struct emp
{
    double sal;
    int id;
    string name;
};
int main(int argc, char const *argv[])
{
    emp a;
    vector<emp *> a33;
    a.id = 11;
    a.name = "ahmed";
    a.sal = 11;
    a33.push_back(&a);
    vector<string>
        a2;
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");
    a2.push_back("ahmed");

    ofstream file2("theTemp.bin", ios::out, ios::app | ios::binary);

    ostream_iterator<emp *> out(file2, "\n");
    copy(a33.begin(), a33.end(), out);
    file2.close();
    // ifstream file("theTemp.bin", ios::in | ios::binary);
    ifstream file("theTemp.bin");
    cout << file.rdbuf();
    while (!file.end)
    {
        emp a4;
        file >> a4.id >> a4.name >> a4.sal;

        cout << a4.id << endl
             << a4.name << endl
             << a4.sal
             << endl;
    }

    file.close();
    return 0;
}
