#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct vedomost
{
    string name = "unknown";
    string surname = "unknown";
    string date = "DD.MM.YYYY";
    int sum = 0;
};
int main()
{
    vector <vedomost> vedomost;
    cout << "\033[2J\033[1;1H";
    cout << "This programme for counting salary sum we pay our workers "<< endl;
    cout << "Input your action: LIST if you want to see the list of payments" << endl;
    cout << "And ADD if you want to add payment to the list" << endl;
    string choice;
    while (choice != "list" && choice != "add") {
        cin >> choice;
        if (choice == "list") {
            cout << "list";
            break;
        }
        else if (choice == "add"){
            cout << "add";
            break;
        }
        else {
            cout << "Incorrect input! Please repeat...";
        }
    }
}