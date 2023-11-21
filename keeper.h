#pragma once
#include <iostream>
#include <fstream>
#include "group.h"

template <class T>
class Element
{ //  one Element in keeper
public:
    T *value;
    Element<T> *prev;

    Element(T *data, Element<T> *prev = nullptr)
    {
#ifdef DEBUG
        std::cout << "Constructor Element\n";
#endif // DEBUG
        this->value = data;
        this->prev = prev;
    }
    ~Element()
    {
#ifdef DEBUG
        std::cout << "Destructor Element\n";
#endif // DEBUG
        delete this->value;
        // delete this->prev;
    }
};

template <class T>
class Keeper
{

private:
    int elem_count;
    Element<T> *head;
    Element<T> *help;

public:
    Keeper()
    {
#ifdef DEBUG
        std::cout << "Constuctor Keeper\n";
#endif // DEBUG
        elem_count = 0;
        head = nullptr;
        help = nullptr;
    }

    Keeper(Keeper<T> &keep)
    {

        elem_count = keep.elem_count;
        Element<T> *cur = keep.head;
        while (cur != nullptr)
        {

            this->add(cur->value);

            cur = cur->prev;
        }
    }

    ~Keeper()
    {
#ifdef DEBUG
        std::cout << "Destructor Keeper\n";
#endif // DEBUG
        while (head != nullptr && elem_count != 0)
        {
            help = head;
            head = head->prev;
            delete help;
            elem_count--;
        }
        delete head;
    }

    int getCount() { return elem_count; }

    T &operator[](const int index)
    {
        int cnt = getCount();
        Element<T> *cur;
        cur = this->head;

        while (cur != nullptr)
        {
            if (cnt == index)
            {
                return *(cur->value);
            }
            cur = cur->prev;
            cnt--;
        }
    }

    void add(T *x)
    {
        if (head == nullptr)
        {
            head = new Element<T>(x);
            head->value = x;
        }
        else
        {
            help = new Element<T>(x);
            help->prev = head;
            head = help;
            head->value = x;
        }
        elem_count++;
    }

    void remove(const int index)
    { //

        if (getCount() == 1)
        { // 1 elem = head
            delete this->head;
            head = nullptr;
            elem_count--;
        }
        else if (index == getCount())
        { // last
            Element<T> *cur = this->head;
            head = head->prev;
            delete cur;
            elem_count--;
        }
        else
        { // not last and >1 elem
            Element<T> *cur = this->head;
            Element<T> *current1 = this->head;
            int c = getCount();
            bool flag = 0;
            while (flag != 1)
            {
                if (c == index)
                {
                    int r = getCount();
                    while (r != (c + 1))
                    {
                        current1 = current1->prev;
                        r--;
                    }
                    Element<T> *temp = cur;
                    cur = cur->prev;
                    current1->prev = cur;
                    delete temp;
                    flag = 1;
                    elem_count--;
                }
                else
                {
                    cur = cur->prev;
                    c--;
                }
            }
        }
    }

    void sort()
    {

        for (int i = 1; i < getCount() + 1; ++i)
        {
            for (int j = 1; j < getCount(); ++j)
            {

                if (((*this)[j].get_numb()) > ((*this)[j + 1].get_numb()))
                {
                    T temp = (*this)[j];
                    (*this)[j] = (*this)[j + 1];
                    (*this)[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        try
        {
            if (getCount() == 0)
                throw("Keeper is empty\n");
            std::cout << "\nAll Elements in Group" << std::endl;

        for (int i = 1;i < getCount() + 1;i++) {                          //display from 1 to Count //slower
                std::cout << "-------Element # " << i << "-------" << std::endl;
                (*this)[i].getData();
        }
            std::cout << "\nCount of Group elements: " << getCount() << std::endl
                      << std::endl;
        }
        catch (const std::string &str)
        {

            std::cout << str << '\n';
        }
    }

    void editElement(const int index, T* g)
    {   
        std::cout << "\nChange Data\n";
        this->remove(index);
        g->setData();
        this->add(g);
            if (this->getCount() > 1){
                this->sort();
        }
    }

    void showBest(){
        int flag = 0;
        try
        {
            if (getCount() == 0)
                throw("Keeper is empty\n");
            for (int i = 1;i < getCount() + 1;i++) {                        
                    flag += (*this)[i].bestStud();
            }
            if(flag == 0){
                std::cout << "There are no good students :(" << std::endl;
            }
        }
        catch (const std::string &str)
        {
            std::cout << str << '\n';
        }
    }

};