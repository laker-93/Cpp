#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int addNumbers(int firstNum, int secondNum = 0){

       int sum = firstNum + secondNum;
       return sum;
}

int addNumbers(int firstNum, int secondNum, int thirdNum){

       int sum = firstNum + secondNum + thirdNum;
       return sum;
}

int getFactorial(int n){
       if(n == 1)
           return 1;
        else
           return ((n)*(getFactorial(n - 1)));
}

void modifyMe(int *in){
   
       *in+=3;
}
int pointersAndRefs(){

       cout << addNumbers(1) << endl;
       cout << addNumbers(1, 5, 6) << endl;
       int f = getFactorial(5);
       cout << f << endl;
       int stuff = 4;
       cout << &stuff << endl;
       int *intPtr;
       intPtr = &stuff;
       cout << *intPtr << endl;
       int nums[5] = {4, 14, 14, 24, 34};
       int *numArrayPtr = nums;
       cout << numArrayPtr << " has value = " << *numArrayPtr << endl;
       cout << nums << " has value = " << *nums << endl;
       modifyMe(intPtr);
       cout << *intPtr << endl;
       int& stuffRef = stuff;
       int more = 8;
       int& moreRef = more;
       moreRef = stuffRef;
       cout << "with & " << &stuffRef << endl;
       cout << stuffRef << endl;
       modifyMe(&stuffRef);
       cout << stuffRef << endl;
       stuffRef = 5;
       cout << stuffRef << endl;
       cout << moreRef << endl;
       return 0;
}
int vectorstuff(){

       //vectors are like arrays but their size CAN change.
       vector <int> lotterNumVect(10);
       int lotterNumArray[5] = {4, 13, 14, 24, 34};
       lotterNumVect.insert(lotterNumVect.begin(), lotterNumArray,
                            lotterNumArray+3);

       cout << lotterNumVect.at(11) << endl;

       lotterNumVect.insert(lotterNumVect.begin()+5, 44);
}
int stringstuff(){

        string myName;
	myName = "Luke";
        string bigName;
        bigName.assign(myName);
        cout << bigName << endl;
}
int intstuff(){

	cout << "Hello World" << endl;

	const double PI = 3.1415926;

	cout << "Number " << PI << endl;

	char myGrade = 'A';

	float  favNum = 3.1415962;

	double moreAccuracy;
	
	int randInt = 3;
	cout << "Favourite number " << favNum << endl;

	cout << "Size of int " << sizeof(randInt)
	     << endl;
	int five = 5;
	cout << "5++ = " << five++  << endl;
	cout << "++5 = " << ++five  << endl;
	cout << "5-- = " << five--  << endl;
	
	cout << "4/5 = " << (float) 4/5 << endl;
	return 0;
}
class Animal{
    private:
        int height;
        int weight;
        string name;

        static int numOfAnimals;

    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }
        void setHeight(int cm){ height = cm; }
        void setWeight(int kg){ weight = kg; }
        void setName(string animalName){ name = animalName; }

        
	void setAll(int, int, string);

        Animal(int, int, string);

        ~Animal();

        Animal();

        static int getNumOfAnimals() { return numOfAnimals; }

        void toString();
};

int Animal::numOfAnimals = 0;

Animal::Animal(int tallness, int weight, string name){

    height = tallness;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

Animal::~Animal()
{

    cout << "Animal " << this -> name << " destroyed" << endl;

}

Animal::Animal()
{

    Animal::numOfAnimals++;
}

void Animal::toString()
{
    cout << this -> name << " is " << this -> height << " cms tall and " <<
         this -> weight << " kgs in weight" << endl;
} 

class Dog : public Animal {

    private:
        string sound = "woof";
    public:
        void getSound() { cout << sound << endl; }

        Dog(int, int, string, string);

        Dog() : Animal(){};

        void toString();
};

Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name){

    this -> sound = bark;

}

void Dog::toString(){

    cout << this -> getName() << " is " << this -> getHeight() << 
    " cms tall and " << this -> getWeight() << " kgs in weight and says " <<
    this -> sound;
}

class Shape {
    private:
        int perimeter;
        int area;

    public:
        void setPerimeter(int perimeter) { this -> perimeter = perimeter; }
        int getPerimeter() { return perimeter; }
        void setArea(int area){ this -> area = area; }
        int getArea() { return area; }
        Shape();
};

/*Shape::setPerimeter(int perimeter) {*/

	//this -> perimeter = perimeter;
/*}*/
Shape::Shape()
{
    cout << "created a shape" << endl;
}

//Shape::setArea(int area) {

    //this -> area = area;
//}

//Shape::getPerimeter() {

    //return (Shape::perimeter);
//}

//Shape::getArea() {

    //return (Shape::area);
//}

int main()
{
    Animal fred;

    fred.setHeight(33);
    fred.setName("Fred");
    fred.setWeight(10);

    cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
         << fred.getWeight() << " kgs in weight" << endl;

    Animal tom(36, 15, "Tom");

    cout << tom.getName() << " is " << tom.getHeight() << " cms tall and "
         << tom.getWeight() << " kgs in weight" << endl;

    Shape sh1;
    sh1.setArea(5);
    sh1.setPerimeter(2);
    cout << sh1.getArea() << sh1.getPerimeter() << endl;
    
    Dog spot(38, 16, "Spot", "Woof");

    cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

    spot.toString();
    tom.toString();

    spot.Animal::toString();
    return 0;
}
