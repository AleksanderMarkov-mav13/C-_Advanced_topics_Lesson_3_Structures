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
    string choice;
    vedomost temp;
    while (choice != "end") {
        cout << "Input your action: LIST or ADD or END to finish: ";
        cin >> choice;
        if (choice == "list") {
            ifstream file("vedomost_1.txt");
            while (!file.eof())
            {
                file >> temp.surname, file >> temp.name, file >> temp.date, file >> temp.sum;
                vec_vedomost.push_back(temp);
            }
            file.close();
            // Вывод на экран массива:
            for (const auto &v : vec_vedomost) {
                cout << v.surname << " " << v.name << " " << v.date << "  " << v.sum << endl;
            }
        }
        else if (choice == "add"){
            cout << "Input surname: ";
            cin >> temp.surname;
            cout << "Input name: ";
            cin >> temp.name;
            cout << "Input date: ";
            cin >> temp.date;
            cout << "Input sum: ";
            cin >> temp.sum;
            ofstream file("vedomost_1.txt", ios::app);
            file << endl << temp.surname << " " << temp.name << " " << temp.date << " " << temp.sum;
            file.close();
        }
        else if (choice == "end") break;
        else {
            cout << "Incorrect input! Please repeat..." << endl;
        }
    }
    
}