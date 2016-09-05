#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack { 
  private: 
    vector<T> elems;     // elements 

  public: 
    void push(T const&);  // push element 
    void pop();               // pop element 
    T top() const;            // return top element 
    bool empty() const{       // return true if empty.
        return elems.empty(); 
    } 
}; 

template <class T>
void Stack<T>::push(T const& obj)
{
    elems.push_back(obj);
}

template <class T>
void Stack<T>::pop()
{
    elems.erase(elems.end() -1);
}

template <class T>
T Stack<T>::top() const
{
    return elems.at(elems.size() - 1);
}

int main()
{
    Stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(9);
    cout << s.top() << endl;
    return 0;
}
