#include <iostream>
#include "timer.h"
long fib(unsigned n)
{

    if(n<2)
       {
        return n;
       }
    else
    return fib(n-1)+fib(n-2);
}
int main() {
    Timer<double>::reset();
    std::cout << "f(42) = " << fib(42) << '\n';
    std::cout << Timer<double>::elapsed_seconds() << std::endl;
    return 0;
}
