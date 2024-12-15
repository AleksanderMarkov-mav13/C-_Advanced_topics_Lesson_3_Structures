#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct room
{
    string type_room = "unknown";
    int space_room = 0;
};

struct floor
{
    int floor_number;
    int room_amount;
    double hight = 2.0;
    vector<room> vec_room; // Список комнат на этаже
};

struct building
{
    string type_building = "house";
    bool bace = false; // наличие печи
    int space_building;
    int floor_amount;
    vector<floor> vec_floor; // Список этажей
};

struct location
{
    int loc_number;
    int bilding_number;
    vector<building> vec_building; // Список строений
};

void input_room(vector<room> &vec_room)
{
    room temp;
    cout << "Enter room type: (l - living, k - kitchen, b - bathroom, s - badroom, c - children)";
    char short_type;
    cin >> short_type;
    cin.ignore();
    if (short_type == 'l')
    {
        temp.type_room = "living";
    }
    else if (short_type == 'k')
    {
        temp.type_room = "kitchen";
    }
    else if (short_type == 'b')
    {
        temp.type_room = "bathroom";
    }
    else if (short_type == 's')
    {
        temp.type_room = "badroom";
    }
    else if (short_type == 'c')
    {
        temp.type_room = "children";
    }
    else
    {
        cout << "Enter another room type:";
        getline(std::cin, temp.type_room);
    }
    cout << "Enter room space: ";
    cin >> temp.space_room;
    vec_room.push_back(temp); // Добавляем комнату в вектор
}

void input_floor(std::vector<floor> &vec_floor)
{
    floor temp_floor;
    cout << "Enter number of floor: ";
    cin >> temp_floor.floor_number;
    cout << "Enter height of floor: ";
    cin >> temp_floor.hight;
    cout << "Enter amount of rooms on the floor: ";
    cin >> temp_floor.room_amount;
    for (int i = 0; i < temp_floor.room_amount; i++)
    {
        input_room(temp_floor.vec_room); // Теперь добавляем комнаты в вектор этажа
    }
    vec_floor.push_back(temp_floor); // Добавляем этаж в вектор этажей
}

void input_building(vector<building> &vec_building)
{
    building temp_build;
    cout << "Enter building type: (h - house, g - garage, b - bathhouse, s - storage)";
    char short_type;
    cin >> short_type;
    cin.ignore();
    if (short_type == 'h')
        temp_build.type_building = "house";
    else if (short_type == 'g')
        temp_build.type_building = "garage";
    else if (short_type == 'b')
        temp_build.type_building = "bathhouse";
    else if (short_type == 's')
        temp_build.type_building = "storage";
    else
    {
        cout << "Enter another building type:";
        getline(std::cin, temp_build.type_building);
        cin.ignore();
    }
    if (temp_build.type_building == "house" || temp_build.type_building == "bathhouse")
    {
        cout << "Is there a bake in this building? 1 - for Yes or 0 - for No?";
        cin >> temp_build.bace;
    }
    cout << "Enter total space of the building: ";
    cin >> temp_build.space_building;
    if (temp_build.type_building == "house")
    {
        cout << "Enter total amount of floors in the house: ";
        cin >> temp_build.floor_amount;
        for (int i = 0; i < temp_build.floor_amount; ++i)
        {
            input_floor(temp_build.vec_floor);
        }
    }
    else
    {
        temp_build.floor_amount = 1;
    }
    vec_building.push_back(temp_build); // Добавляем строение в соответствующий вектор
}

void input_location(std::vector<location> &vec_location)
{
    location temp_location;
    cout << "Input number of this location ";
    cin >> temp_location.loc_number;
    cout << "How many bildings on this location? ";
    cin >> temp_location.bilding_number;
    for (int i = 0; i < temp_location.bilding_number; i++)
    {
        input_building(temp_location.vec_building);
    }
    vec_location.push_back(temp_location);
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Here you can make a model of a settlement!\n";
    int location_count = 0;
    while (location_count <= 0)
    {
        cout << "How many locations are in the settlement? ";
        cin >> location_count;
        if (location_count <= 0)
            cout << "Incorrect input! Please repeat...\n";
    }
    vector<location> vec_location;
    for (int i = 0; i < location_count; i++)
    {
        input_location(vec_location);
    }

    for (const auto &l : vec_location)
    {
        cout << "\n--------------------------------------------\n";
        cout << "Location № " << l.loc_number << " has " << l.bilding_number << " bildings: \n";
        int bild_count = 0;
        for (const auto &b : l.vec_building)
        {
            bild_count++;
            cout << "Bilding N " << bild_count << ": Type: " << b.type_building << ", Bake: " << (b.bace ? "Yes" : "No") << ", Space: " << b.space_building << ", Floor amount: " << b.floor_amount << std::endl;
            for (const auto &f : b.vec_floor)
            {
                cout << "Floor number: " << f.floor_number << ", Height: " << f.hight << ", Room amount: " << f.room_amount << std::endl;
                int i = 1;
                for (const auto &r : f.vec_room)
                {
                    cout << "\nRoom number " << i++ << " information:\n";
                    cout << "Type: " << r.type_room << ", Space: " << r.space_room << std::endl;
                }
            }
        }
    }
    return 0;
}