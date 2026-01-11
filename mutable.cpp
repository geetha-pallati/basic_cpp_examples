#include<iostream>
#include<memory>
#include<vector>    


// Mutable kewword is mainly used in the context of const member functions in C++.
//  Const member functions are not allowed to modify any member variables of the class.
//  However, there are scenarios where you might want to allow certain member variables 
// to be modified even in const member functions. This is where the mutable keyword comes into play.
class Muatble{
    public:
    Muatble(){
        std::cout<<"Constructor called"<<std::endl;
        std::cout<<"data = "<<data<<std::endl;
    } 
    void display() const {
        std::cout<<"Display function called"<<std::endl;
        std::cout<<"data = "<<data<<std::endl;
    } 
    void modify() const {
        data = 20; // Modifying mutable member
        std::cout<<"Modify function called, data = "<<data<<std::endl;
    } 
    private:
    mutable int data = 10; // Mutable member variable
};

int main(){
    const Muatble obj; // const object
    obj.display(); // Allowed
    obj.modify(); // Allowed due to mutable member
    return 0;
}



