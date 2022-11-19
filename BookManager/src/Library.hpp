#pragma once
#include "Book.hpp"
#include <fstream>
#include <vector>
using namespace std;
class Library
{
private:
    string name;
    string path;
    vector<string> book_buffer;
    //void set_default_path();
public:
    //Library(string name);
    Library(string name, string path);
    //~Library();
    string get_name();
    void set_name(string new_name);
    void set_path(string new_path);
    vector<string> get_buffer();
    //void set_full_path(string new_full_path);
    string get_path();
    void add(Book book);
    void write();
};

