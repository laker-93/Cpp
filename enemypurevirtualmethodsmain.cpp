#include <iostream>
using namespace std;

class Enemy {
    public:
        virtual void attack(){
            cout << "Enemy class" << endl;}
        virtual void pure_attack() = 0; // must be implemented.

};

class Monster: public Enemy{
    public:
        void attack()
        {cout << "Monster attack - " << endl;}
        void pure_attack()
        {cout << "Monster pure attack - " << endl;}

};
class Ninja: public Enemy{
    public:
        void pure_attack()
        {cout << "Ninja pure attack - " << endl;}

        void attack()
        {cout << "Ninja attack - " << endl;}
};
int main() {
    Ninja n;
    Monster m;
    
    //Enemy *enemy1 = new Enemy;
    /*enemy1->attack();*/
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;

    
    enemy1->pure_attack();
    n.attack();
    enemy2->attack();
    m.attack();
    return 0;
}
