// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
 private:
     struct Item {
        T value;
        Item* next;
     };
     T result;
     Item* head;
     TPQueue::Item* create(const T&);
 public:
     TPQueue() : head(nullptr) {}
     bool isEmpty() const;
     void push(const T&);
     const T& pop();
     ~TPQueue() {}
};
template <typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& value) {
    Item* temp = new Item;
    temp->value = value;
    temp->next = nullptr;
    return temp;
}
template <typename T>
bool TPQueue<T>::isEmpty() const {
    return head == nullptr;
}
template <typename T>
const T& TPQueue<T>::pop() {
    if (isEmpty()) {
        throw std::string("Empty!");
    } else {
        result = head->value;
        Item* temp = head->next;
        delete head;
        head = temp;
        return result;
    }
}
template <typename T>
void TPQueue<T>::push(const T& value) {
    Item* current = create(value);
    Item* prev = nullptr;
    Item* tmp = head;
    while (tmp != nullptr && current->value.prior <= tmp->value.prior) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == nullptr) {
        current->next = head;
        head = current;
    } else {
        prev->next = current;
        current->next = tmp;
    }
}
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
