#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

class group;

template <class T>
class elem
{
public:
    T *data;
    elem *next;
    elem(T *d, elem *n = NULL)
    {
        this->data = d;
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
    void add(T *x);
    void remove(elem<T> *temp);
    void display();
    void change(elem<T> *);
    void sort(list<group>& groups);
    elem<T>* operator[](const int index);
};

class student
{
    std::string name;
    int size;
    int *progress;

public:
    student();
    student(std::string name_, int size_, int* progress_);
    student(student& obj);
    ~student();
    void set_name(std::string _name);
    void set_size(int _size);
    void set_progress(int* _progress);
    std::string get_name();
    int get_size();
    int* get_progress();
    void set();
    void get();
};

class group
{
    int numb;
    float gpa;
    int count;
    std::string *subjects;
    list<student>* students;

public:
    group();
    group(int numb_, float gpa_, int count_, std::string *subjects_, list<student>* students_);
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
