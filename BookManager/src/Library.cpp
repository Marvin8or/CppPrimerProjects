#include <iostream>
#include "Library.hpp"
#include <fstream>
#include <string>
#include <algorithm>

Library::Library(string name, string path)
{
    set_name(name);
    set_path(path);

}

string Library::get_name()
{
    return this->name;
}

string Library::get_path()
{
    return this->path;
}

void Library::set_name(string new_name)
{
    if (new_name.empty() || new_name == " ")
    {
        throw invalid_argument("Provided name is empty...");
    }
    else
    {
        this->name = new_name;
    }
}

void Library::set_path(string new_path)
{
    if (new_path.empty() || new_path == " ")
    {
        throw invalid_argument("Provided path is empty...");
    }
    else
    {
        this->path = new_path + "\\";
        this->path += this->name;
    }
}

void Library::add(Book book)
{

    auto it = std::find(this->book_buffer.begin(), this->book_buffer.end(), book);
    if (it != this->book_buffer.end())
    {
        *it.copies_sold++;
    }
        this->book_buffer.push_back(book);
}

vector<Book> Library::get_buffer()
{
    return this->book_buffer;
}

void Library::write()
{
    ofstream output_file(this->get_path());
    auto _buffer = this->get_buffer();
    for (const Book& book : _buffer)
    {
        output_file << book. << endl;
    }
    output_file.close();

    cout << "Books are written to file: " << this->get_path() << endl;
}
bool Library::is_file_exist(const string file_name)
{
    ifstream infile(file_name);
    bool exists = infile.good();
    infile.close();
    return exists;
}

vector<Book> Library::read()
{
    
    string path = this->get_path();
    if (this->is_file_exist(path))
    {
        ifstream file(path);
        string text;
        vector<string> contents;
        for (int i = 0; i < this->book_buffer.size(); i++)
        {
            getline(file, text);
            contents.push_back(text);
        }
        file.close();
        return contents;
    }
    else
    {
        throw invalid_argument("File does not exist!");
    }
    
}