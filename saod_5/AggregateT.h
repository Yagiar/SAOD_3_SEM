#include <iostream>

template<typename T>
class AggregateT {
public:
    AggregateT() {
        std::cout << "Create_AggreagateT_Object" << std::endl;
        m_objTest = new T();
    }

    ~AggregateT() {
        std::cout << "Delete_AggreagateT_Object" << std::endl;
        delete m_objTest;
    }

private:
    T* m_objTest;
};