#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myVector;

    cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << endl;

int prevCapacity = myVector.capacity();
for (int i = 0; i < 32; i++)
{
    myVector.push_back(1);
    if (myVector.capacity() != prevCapacity)
    {
       cout << "Capacity increased from " << prevCapacity << " to " << myVector.capacity() << endl;
        prevCapacity = myVector.capacity();
    }
}
    return 0;
}
