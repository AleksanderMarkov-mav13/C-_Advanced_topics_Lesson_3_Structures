#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct vedomost {
    string surname = "unknown";
    string name = "unknown";
    string date = "DD.MM.YYYY";
    int sum = 0;
};
int main()
{
    vector <vedomost> vec_vedomost;
    cout << "\033[2J\033[1;1H";
    cout << "This programme for counting salary sum we pay our workers "<< endl;
    cout << "Input your action: LIST if you want to see the list of payments" << endl;
    cout << "And ADD if you want to add payment to the list" << endl;
    string choice;
    ifstream file("vedomost_1.txt");
    vedomost temp;
    while (file >> temp.surname, file >> temp.name, file >> temp.date, file >> temp.sum)
    {
        vec_vedomost.push_back(temp);
    }
    file.close();
    while (choice != "list" && choice != "add") {
        cin >> choice;
        if (choice == "list") {
            // Вывод на экран массива:
            for (const auto &v : vec_vedomost) {
                cout << v.surname << " " << v.name << " " << v.date << "  " << v.sum << endl;
            }
            break;
        }
        else if (choice == "add"){
            // string surname, name, date, sum;
            cout << "Input surname: ";
            cin >> temp.surname;
            cout << "Input name: ";
            cin >> temp.name;
            cout << "Input date: ";
            cin >> temp.date;
            cout << "Input sum: ";
            cin >> temp.sum;
            vec_vedomost.push_back(temp);
            ofstream file("vedomost_1.txt", ios::app);
            file << temp.surname << " " << temp.name << " " << temp.date << " " << temp.sum << endl;
            // for (const auto &v : vec_vedomost) {
            //     file >> v.surname >> " " >> v.name >> " " >> v.date >> "  " >> v.sum >> endl;
            // }
            break;
        }
        else {
            cout << "Incorrect input! Please repeat..." << endl;
        }
    }
    
}