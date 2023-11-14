#include "header.h"

template <class T>
list<T>::list(){
    first = NULL;
    last = NULL;
    elem_count = 0;
    std::cout << "List created\n";
}

template <class T>
list<T>::list(list<T>* obj){
        if (obj->first != NULL){
            elem<T>* temp = obj->first;
            while (temp != NULL) {
                this->add(*(temp->data));
                temp = temp->next;
            }
            std::cout << "List was copied!" << std::endl;
        }
        else{
            std::cout << "Original list is empty!" << std::endl;
        }
}

template <class T>
list<T>::~list(){
    if (first == NULL) return;
    if (first == last) {
            delete first;
            delete last;
        }
    else{
        while (first != last){
            elem<T>* temp = first;
            first = first->next;
            delete temp;
        }
        delete first;
        delete last;
    }
    std::cout << "List deleted\n";
}

template <class T>
void list<T>::add(T& x){
        elem<T>* temp = new elem<T>(x);
        if (first == NULL && last == NULL){
            first = last = temp;
            first->data=last->data=&x;
        }
        else {
            last->next = temp;
            last = temp;
            last->data=&x;
        }
        elem_count ++;
}

template <class T>
void list<T>::remove(elem<T>* x){
        if (first == NULL) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        if (first == last) {
            elem<T> *temp = first;
            first = last = NULL;
            delete temp;
            std::cout << "Element removed!" << std::endl;
        }
        else if(x == first){
            elem<T> *temp = first;
            first = first->next;
            delete temp;
            std::cout << "Element removed!" << std::endl;
        }
        else if(x == last){
            elem<T> *temp = first;
            while (temp->next != last) temp = temp->next;
            temp->next = NULL;
            delete last;
            last = temp;
            std::cout << "Element removed!" << std::endl;
        }
        else {
            elem<T>* slow = first;
            elem<T>* fast = first->next;
            while (fast && fast != x) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = fast->next;
            delete fast;
        }
        elem_count --;
}

template <class T>
void list<T>::display(){
        elem<T>* temp = first;
        int i = 1;
        if (first == NULL) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        else {
            while(temp->next != NULL){ 
                std::cout << "Element " << i << " - ";
                (temp->data)->get();
                temp = temp->next;
                i++;
            }
            std::cout << "Element " << i << " - ";
            (temp->data)->get();
            std::cout << std::endl;
        }
}

template <class T>
void list<T>::change(elem<T>* x){
    T* temp= x->data;
    temp->set();
    x->data = temp;
}

template <class T>
elem<T>* list<T>::operator[] (const int index) {
    if (first == NULL && last == NULL) return nullptr;
    elem<T>* temp = first;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
        if (!temp) return nullptr;
    }
    return temp;
}

template class list<student>;
template class list<group>;