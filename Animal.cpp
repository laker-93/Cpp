#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Animal{
    private:
        int height;
        int weight;
        std::string name;

    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        std::string getName() const { return name; }
        std::vector<const Animal*> friends;
        void add_friend(const Animal& new_friend);
        void print_friends() {
            for(auto &a : friends) {
                std::cout << a->getName() << std::endl;
            }
        }; 
        Animal(int height, int weight, std::string name) :
        height(height), weight(weight), name(name) {};

};

class Dog : public Animal {

    private:
        std::string sound = "woof";
    public:
        void getSound() { std::cout << sound << std::endl; }
        Dog(int h, int w, std::string n): Animal(h, w, n) {};
};

void make_friends(Animal& d1, Animal& d2) {
    d1.add_friend(d2);
    d2.add_friend(d1);
}

void Animal::add_friend(const Animal& new_friend) {
    friends.push_back(&new_friend);
    /* remove friend:
     * remove description:
     * Transforms the range [first,last) into a range with all the elements 
     * that compare equal to val removed, and returns an iterator to the new end
     * of that range.
     */
    auto it = std::remove(friends.begin(), friends.end(), &new_friend);
    friends.erase(it , friends.end());
}



int main()
{
    Dog d(1, 2, "doggy");
    Dog d2(1, 2, "chase");
    make_friends(d, d2);
    d.print_friends();
    d2.print_friends();
    return 0;
}
