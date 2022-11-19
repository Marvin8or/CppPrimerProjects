#pragma once
#include "Book.hpp"
using namespace std;
class Library
{
private:
    string name;
    string path;
    //void set_default_path();
public:
    Library(string name);
    Library(string name, string path);
    string get_name();
    void set_name(string new_name);
    void set_path(string new_path);
    //void set_full_path(string new_full_path);
    string get_path();
    //string get_full_path();
    //{
    //    return this->get_path() + this->get_name();
    //}
    //void write(Book book);
};

