#include <iostream>

struct Person {
    std::string name;
};
class Car {
    public:
        Car(): owner() {}
        void setOwner(Person *o) { owner = o; }
        Person *getOwner() const {return owner; }
        void info() const;
    private:
        Car(const Car&);
        Car& operator = (const Car&);
        Person *owner;
};

void Car::info() const
{
    if (owner) {
        std::cout << "Owner is " << owner -> name << std::endl;
    } else {
        std::cout << "No Owner" << std::endl;
    }
}

int main()
{
    Car c;
    struct Person *p1 = new(struct Person);
    p1->name = "Jared";
    c.setOwner(p1);
    c.info();
    Car c2 = c;
    c2.info();
}
