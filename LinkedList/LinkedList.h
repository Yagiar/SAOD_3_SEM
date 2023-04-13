#include <iostream>
#include <exception>
#include <stdexcept>
#include <numeric>
 
using namespace std;
 
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
 
    Node(T data = T(), Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};
 
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;
 
public:
    LinkedList() {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        length = 0;
    }
 
    ~LinkedList() {
				clear();
        delete tail;
        delete head;
    }
 
    void push_back(T value) {
        Node<T>* new_node = new Node<T>(value);
        if (length == 0) {
					  new_node->next = tail;
            head->next = new_node;
 
        }
        else {
					  auto c = head->next;
					  while(c->next != tail)
							c = c->next;
 
            new_node->next = tail;
            c->next = new_node;
        }
        //tail = new_node;
        length++;
    }
 
    void push_front(T value) {
        Node<T>* temp = new Node<T>(value, head->next);
        head->next = temp;
        if (length == 0) {
            tail = temp;
        }
        length++;
    }
 
    void insert(size_t idx, T value) {
        if (idx < 0 || idx > length) {
            throw out_of_range("Out Of range");
            return;
        }
        if (idx == 0) {
            push_front(value);
            return;
        }
        if (idx == length) {
            push_back(value);
            return;
        }
        Node<T>* prev = head;
        for (size_t i = 0; i < idx; i++) {
            prev = prev->next;
        }
        Node<T>* temp = new Node<T>(value, prev->next);
        prev->next = temp;
        length++;
    }
 
    void pop_back() {
        if (length == 0) {
            throw length_error("List is Empty");
            return;
        }
        if (length == 1) {
            delete tail;
            head->next = tail;
            length--;
            return;
        }
        Node<T>* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        tail->next = nullptr;
        length--;
    }
 
    void pop_front() {
        if (length == 0) {
            throw length_error("List is Empty");
            return;
        }
        Node<T>* temp = head->next;
        head->next = temp->next;
        delete temp;
        length--;
        if (length == 0) {
            //tail = head;
        }
    }
 
    void remove_at(size_t index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Out Of range");
            return;
        }
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == length - 1) {
            pop_back();
            return;
        }
        Node<T>* prev = head;
        for (size_t i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node<T>* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }
 
    T& operator[](const size_t index) {
        Node<T>* curr = head->next;
        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
 
    T const& operator[](const size_t index) const {
        Node<T>* curr = head->next;
        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
 
    size_t size() const {
        return length;
    }
 
    bool empty() const {
        return length == 0;
    }
 
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
 
    T front() const {
        if (length == 0) {
            throw out_of_range("Out Of range");
            return T();
        }
        return head->next->data;
    }
 
    T back() const {
        if (length == 0) {
            throw out_of_range("Out Of range");
            return T();
        }
        return tail->data;
    }
 
    class ListIterator {
    private:
        Node<T>* curr;
    public:
        ListIterator(Node<T>* node = nullptr) {
            curr = node;
        }
        ListIterator& operator++() {
            curr = curr->next;
            return *this;
        }
        T& operator*() const {
            return curr->data;
        }
        bool operator==(const ListIterator& other) const {
            return curr == other.curr;
        }
        bool operator!=(const ListIterator& other) const {
            return curr != other.curr;
        }
    };
 
    ListIterator begin() const {
        return ListIterator(head->next);
    }
 
    ListIterator end() const {
        return ListIterator(tail->next);
    }
};
