#include<iostream>
#include<memory>


// Deep Copy vs Shallow Copy in C++
// Shallow Copy: Copies the reference of the resource, leading to multiple objects sharing the same resource.
// Deep Copy: Creates a new copy of the resource for each object, ensuring independent resources.
// Example demonstrating Deep Copy in this code i am using dynamic memory allocation.
// and copy constructor and copy assignment operator to achieve deep copy.
// why we need deep copy because when we have dynamic memory allocation
// if we don't implement deep copy then we will face issues like double deletion
// dangling pointer etc.

 
class DeepCopy{
    public:
    DeepCopy(int size){  // Constructor
        this->size = size;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = i;    
        }
    }
    // Deep Copy Constructor
    DeepCopy(const DeepCopy &source){  // why we are using const here because to prevent 
    // modification of source object. calling copy constructor with const object. why because
    // if we don't use const then we can't pass temporary objects or literals to the constructor.
    // it also helps to avoid accidental changes to the source object inside the constructor.
    // is this twwo different constructors one is default and another is copy constructor.
        size = source.size;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = source.data[i];   
        }   
        }
    // Deep Copy Assignment Operator
    DeepCopy& operator=(const DeepCopy &source){
        if(this == &source)
            return *this;
        delete[] data; // Free existing resource
        size = source.size;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = source.data[i];       
        }
        return *this;
    }
    void display(){
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
    ~DeepCopy(){  // Destructor
        delete[] data;
    }
    private:
        int *data;
        int size; 
};
class SallowCopy{
    public:

    SallowCopy(int size){  // Constructor
        this->size = size;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = i;    
        }
    }
    // Shallow Copy Constructor
    SallowCopy(const SallowCopy &source){  
        size = source.size;
        data = source.data; // Shallow copy: copying the pointer
    }
    void display(){
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
    ~SallowCopy(){  // Destructor
        delete[] data; // This will cause double deletion if multiple objects share the same data
    }
    private:
        int *data;
        int size; 

}
int main(){
    DeepCopy obj1(5); // Create object
    std::cout<<"Object 1 data: ";
    obj1.display();

    DeepCopy obj2 = obj1; // Calls Deep Copy Constructor
    std::cout<<"Object 2 data (after copy construction from obj1): ";
    obj2.display();

    DeepCopy obj3(3); // Create another object
    obj3 = obj1; // Calls Deep Copy Assignment Operator
    std::cout<<"Object 3 data (after assignment from obj1): ";
    obj3.display();

    return 0;
}