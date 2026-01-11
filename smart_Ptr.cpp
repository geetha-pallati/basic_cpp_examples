#include<iostream>
#include<memory>
#include<vector>

class Sample {
public:
    Sample(int val) : value(val) {
        std::cout << "Sample Constructor: " << value << std::endl;
    }
    ~Sample() {
        std::cout << "Sample Destructor: " << value << std::endl;
    }
    void display() {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};  

int main() {
    // Using std::shared_ptr
    {
        std::shared_ptr<Sample> sp1(new Sample(10));
        // std::shared_ptr<Sample> sp1 = std::make_shared<Sample>(10); // Preferred way to create shared_ptr
        {
            std::shared_ptr<Sample> sp2 = sp1; // Shared ownership
            sp2->display();
            std::cout << "Use count of sp1: " << sp1.use_count() << std::endl;
        } // sp2 goes out of scope here
        std::cout << "Use count of sp1 after sp2 goes out of scope: " << sp1.use_count() << std::endl;
    } // sp1 goes out of scope here, Sample object is deleted

    std::cout << "----------------------------------" << std::endl;

    // Using std::unique_ptr
    {
        std::unique_ptr<Sample> up1(new Sample(20)); //upl function means unique pointer dynamic allocation// 
        //std::unique_ptr<Sample> up1 = std::make_unique<Sample>(20); // Preferred way to create unique_ptr
        up1->display();
        // std::unique_ptr<Sample> up2 = up1; // Error: cannot copy unique_ptr
        std::unique_ptr<Sample> up2 = std::move(up1); // Transfer ownership
        if (!up1) {
            std::cout << "up1 is now null after move." << std::endl;
        }
        up2->display();
    } // up2 goes out of scope here, Sample object is deleted

    std::cout << "----------------------------------" << std::endl;
    // Using std::weak_ptr
    {
        std::shared_ptr<Sample> sp3(new Sample(30));
        std::weak_ptr<Sample> wp1 = sp3; // weak_ptr does not affect reference count
        // std::weak_ptr<Sample> wp1 = sp3; // Preferred way to create weak_ptr

        std::cout << "Use count of sp3: " << sp3.use_count() << std::endl;

        if (auto sp4 = wp1.lock()) { // Try to get shared_ptr from weak_ptr
            sp4->display();
            std::cout << "Use count after locking wp1: " << sp3.use_count() << std::endl;
        } else {
            std::cout << "wp1 is expired." << std::endl;
        }
    } // sp3 goes out of scope here, Sample object is deleted
    return 0;

}
