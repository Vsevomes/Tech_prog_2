#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

class student
{
    std::string name;
    int size;
    int *progress;

public:
    std::string _name;
    int *_progress;
    student();
    student(std::string name_, int* progress_);
    ~student();
    void set_name();
    void set_progress();
    void set_size();
    void get_name();
    void get_progress();
};

class group
{
    int numb;
    float gpa = 0;
    int count;
    std::string *subjects;

public:
    group();
    group(int numb_, int count_, std::string *subjects);
    ~group();
    void set_numb();
    void set_count();
    void set_subjects();
    void get_numb();
    void get_gpa();
    void get_subjects();
};

template <class T>
class elem
{
public:
    T *data;
    elem *next;
    elem(T &d, elem *n = NULL)
    {
        this->data = &d;
        this->next = n;
    }
};

template <class T>
class list
{
public:
    int elem_count;
    elem<T> *first;
    elem<T> *last;
    list();
    list(list<T> *obj);
    ~list();
    void add(T &x);
    void remove(elem<T> *temp);
    void display();
    void change(elem<T> *);
    elem<T> *operator[](const int index);
};