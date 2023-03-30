#include <iostream>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include "LinkedList.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void print_lst(const LinkedList <char >& l)
{
    for (int i = 0; i < l.size(); i++)
    {
        if (i != l.size() - 1)
        {
            cout << l[i] << " -> ";
        }
        else
        {
            cout << l[i];
        }
    }
    cout << endl;
}

int main()
{
    setlocale(0, "Russian");
    LinkedList <char > lst; // ваш список
     std::cout << std::boolalpha << lst.empty() << std::endl;
    
        for (int i = 0; i < 5; i++)
         lst.push_back(char('a' + i));
    
         print_lst(lst);
    
         for (int i = 0; i < 5; i++)
         lst.insert(0, char('z' - i));
     print_lst(lst);
    
         for (size_t i = 0; i != lst.size(); i++)
         lst[i] = char('a' + i);
    
         print_lst(lst);
    
         lst.pop_back();
     lst.pop_front();
   
         print_lst(lst);
 
       lst.remove_at(5);
    lst.insert(3, 'o');
   
        print_lst(lst);
    
       lst.clear();
  
        lst.push_back('q');
    lst.push_back('w');
    
         std::cout << lst.size() << ' ' << std::boolalpha << lst.empty() << std::endl;
  
         LinkedList<int> l;
         l.push_back(3);
         l.push_back(5);
         l.push_back(2);
         l.push_back(7);
         for (auto& i : l) i += 2;
         auto lambda = [&l](int a, int b) { return a + b * 10; };
         std::cout << std::accumulate(l.begin(), l.end(), 0, lambda) << "\n";// 250
} 
