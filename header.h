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
    student(student& obj);
    ~student();
    void set_name(std::string _name);
    void set_progress();
    void set_size();
    void get_name();
    void get_progress();
};

class group
{
    int numb;
    float gpa;
    int count;
    std::string *subjects;

public:
    int _numb, _count;
    float _gpa;
    std::string* _subjects;

    group();
    group(int numb_, float gpa_, int count_, std::string *subjects_);
    group(group& obj);
    ~group();
    void set_numb(int _numb);
    void set_count(int _count);
    void set_subjects(std::string* _subjects);
    int get_numb();
    int get_count();
    float get_gpa();
    std::string* get_subjects();
    void set();
    void get();
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