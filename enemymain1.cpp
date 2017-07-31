#include <iostream>
using namespace std;

class Enemy {
    protected:
        int attack_power;
    public:
        void set_attack_power(int a) {
            attack_power = a;
        }
};

class Monster: public Enemy{
    public:
        void attack()
        {cout << "Monster attack - " << attack_power << endl;}
};
class Ninja: public Enemy{
    public:
        void attack()
        {cout << "Ninja attack - " << attack_power << endl;}
};
int main() {
    Ninja n;
    Monster m;
    
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;

    enemy1->set_attack_power(3);
    
    n.attack();
    m.attack();
    return 0;
}
