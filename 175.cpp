#include <iostream>

class Parent
{
public:
    virtual void function1() {
        std::cout << "Parent::function1()" << std::endl;
    }
    virtual void function2() {
        std::cout << "Parent::function2()" << std::endl;
    }
};

class C1 : public Parent
{
public:
    virtual void function1() override {
        std::cout << "C1::function1()" << std::endl;
    }
};

class C2 : public Parent
{
public:
    virtual void function2() override {
        std::cout << "C2::function2()" << std::endl;
    }
};

int main()
{
    Parent p;
    C1 c1;
    C2 c2;

    std::cout << "Parent p:" << std::endl;
    Parent* pPtr = &p;
    pPtr->function1(); // Parent::function1()
    pPtr->function2(); // Parent::function2()

    std::cout << "\nC1 c1 (Parent* -> C1):" << std::endl;
    Parent* c1Ptr = &c1;
    c1Ptr->function1(); // C1::function1()
    c1Ptr->function2(); // Parent::function2()

    std::cout << "\nC2 c2 (Parent* -> C2):" << std::endl;
    Parent* c2Ptr = &c2;
    c2Ptr->function1(); // Parent::function1()
    c2Ptr->function2(); // C2::function2()

    return 0;
}
