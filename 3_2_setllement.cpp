#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct room {
    string type_room = "unknown";
    int space_room = 0;
};

struct floor {
    int floor_number;
    int room_amount;
    double hight = 2.0;
    vector<room> vec_room; // Список комнат на этаже
};

void input_room(vector<room> &vec_room) // Передаем вектор по ссылке
{
    room temp;
    cout << "Enter room type: (l - living, k - kitchen, b - bathroom, s - badroom, c - children)";
    char short_type;
    cin >> short_type;
    cin.ignore();
    if (short_type == 'l') {temp.type_room = "living";}
    else if (short_type == 'k') {temp.type_room = "kitchen";}
    else if (short_type == 'b') {temp.type_room = "bathroom";}
    else if (short_type == 's') {temp.type_room = "badroom";}
    else if (short_type == 'c') {temp.type_room = "children";}
    else {
        cout << "Enter another room type:";
        getline(cin, temp.type_room); // Используем getline для ввода строки
    }
    cout << "Enter room space: ";
    cin >> temp.space_room;   // Вводим число
    cin.ignore();             // Игнорируем символ новой строки после ввода числа
    vec_room.push_back(temp); // Добавляем комнату в вектор
}

void input_floor(vector<floor> &vec_floor) // Передаем вектор по ссылке
{
    floor temp_floor;
    cout << "Enter number of floor: ";
    cin >> temp_floor.floor_number;
    cout << "Enter hight of floor: ";
    cin >> temp_floor.hight;
    cout << "Enter amount room on the floor: ";
    cin >> temp_floor.room_amount;
    cin.ignore();
    for (int i = 0; i < temp_floor.room_amount; i++) {
        input_room(temp_floor.vec_room); // Теперь добавляем комнаты в вектор этажа
    }
    vec_floor.push_back(temp_floor); // Добавляем этаж в вектор этажей
}

int main()
{
    cout << "Here you can make model of settlement!\n";
    vector<floor> vec_floor; 
    input_floor(vec_floor);

    for (const auto &f : vec_floor)
    {
        cout << "Floor_number: " << f.floor_number << ", hight: " << f.hight << ", room_amount: " << f.room_amount << endl;
        int i = 0;
        for (const auto &r : f.vec_room)
        {
            i++;
            cout << "\nRoom number " << i << " information:\n";
            cout << "Type: " << r.type_room << ", Space: " << r.space_room << endl;
        }
    }
}