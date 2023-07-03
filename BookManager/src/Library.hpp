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
    vector<Book> book_buffer;
public:
    Library(string name, string path);
    string get_name();
    void set_name(string new_name);
    void set_path(string new_path);
    vector<Book> get_buffer();
    string get_path();
    void add(Book book);
    void write();
    vector<Book> read();
    //TODO make static or standalone funciton
    bool is_file_exist(const string file_name);
};

