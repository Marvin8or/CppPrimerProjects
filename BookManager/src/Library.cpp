#include <iostream>
#include "Library.hpp"
#include <fstream>


Library::Library(string name)
{
    set_name(name);
}

Library::Library(string name, string path) : Library::Library(name)
{
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
        this->path = new_path;
    }
}

/*void Library::set_default_path()
{
    char temp[256];
    getcwd(temp, sizeof(temp)) ? std::string(temp) : std::string("");
    }
    this->set_path(string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CPPPrimerProjects\\BookManager";)
}*/

//void Library::set_full_path(string new_full_path)
//{
//    if (new_full_path.empty() || new_full_path == " ")
//    {
//        throw invalid_argument("Provided full path is empty...");
//    }
//    else
//    {
//        this->full_path = new_full_path;
//    }
//}

/*void Library::write(Book book)
{

    string book_info;
    book_info += book.get_name() + " ";
    book_info += book.get_isbn() + " ";
    book_info += book.get_price();
    
    ofstream output_file(this->get_full_path());
    output_file << book_info;
    output_file.close();
}*/