#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Person
{
    string name;
    int life;
    int armor;
    int damage;
    int pos_x;
    int pos_y;
};
int main()
{
    cout << "\033[2J\033[1;1H";
    std::srand(static_cast<unsigned int>(std::time(0)));
    cout << "Here you can play role game on our play field!\n";
    vector<Person> vec_user;
    Person temp;
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            temp.name = "Player";
            temp.life = 500;
            temp.armor = 50;
            temp.damage = 30;
            temp.pos_x = 10;
            temp.pos_y = 10;
        }
         else {
            temp.name = "Enemy # " + to_string (i);
            temp.life = rand () % 101 + 50;
            temp.armor = rand () % 51;
            temp.damage = rand () % 16 + 15;
            do {
                temp.pos_x = rand() % 21;
                temp.pos_y = rand() % 21;
            } while (temp.pos_x == 10 && temp.pos_y == 10);
        }
        vec_user.push_back (temp);
    }
    for (const auto &v : vec_user)
    {
        cout << v.name << " " << v.life << " " << v.armor << "  " << v.damage << "  " << v.pos_x << " " << v.pos_y << endl;
    }
}