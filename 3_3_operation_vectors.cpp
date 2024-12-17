#include <iostream>
#include <cmath>
using namespace std;
struct vector_c {
    double x;
    double y;
};
void add_vec(vector_c &first, vector_c &second)
{
    first.x += second.x;
    first.y += second.y;
    cout << "Result of operation is vector wuth coordinate " << first.x << " " << first.y << endl;
}
double length_vec(vector_c &first)
{
    double length = sqrt (first.x * first.x + first.y * first.y);
    return length;
}
int main()
{
    cout << "\033[2J\033[1;1H";
    string choice; 
    cout << "This programme helps you operate with vectors " << endl;
    while (true)
    {
        cout << "Enter type of operation: ADD, SUBSTRUCT, SCALE, LENGTH, NORMALIZE or END for finish " << endl;
        cin >> choice;
        cin.ignore ();
        if (choice != "end" & choice != "add" & choice != "substruct" & choice != "scale" & choice != "length" & choice != "normalize") {
            cout << "Incorrect type of operation! Please, repeate...\n";
        }
        else if (choice == "end") break;
        else {
            vector_c first;
            if (choice == "add" || choice == "substruct") {
                cout << "Enter coordinate of first vector: ";
            }
            else {
                cout << "Enter coordinate of your vector: ";
            }
            cin >> first.x;
            cin >> first.y;
            if (choice == "add" || choice == "substruct") {
                vector_c second;
                cout << "Enter coordinate of second vector: ";
                cin >> second.x;
                cin >> second.y;
                if (choice == "add") add_vec(first, second);
                if (choice == "substruct") {
                    second.x = -second.x;
                    second.y = -second.y;
                    add_vec(first, second);
                }
            }
            if (choice == "scale")
            {
                int kf;
                cout << "Enter the scale number ";
                cin >> kf;
                first.x *= kf;
                first.y *= kf;
                cout << "Result of operation is vector wuth coordinate " << first.x << " " << first.y << endl;
            }
            if (choice == "length" || choice == "normalize")
            {
                double length;
                length = length_vec(first);
                if (choice == "length") {
                    length = round (length * 100) / 100;
                    cout << "The length of your vector equels " << length << endl;
                }
                else {
                    first.x = round (first.x / length * 100) / 100;
                    first.y = round (first.y / length * 100) / 100;
                    cout << "Result of operation is vector wuth coordinate (" << first.x << " , " << first.y << ")" << endl;
                }
            }
        }
    }
}