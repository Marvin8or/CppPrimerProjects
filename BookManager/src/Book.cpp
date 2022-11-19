
#include <iostream>
#include "Book.hpp"

Book::Book(string name, string isbn, double price)
{
    set_name(name);
    set_isbn(isbn);
    set_price(price);
}

void Book::set_name(string new_name)
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
void Book::set_isbn(string new_isbn)
{
    if (new_isbn.empty()) { throw invalid_argument("Provided isbn code is empty..."); }
    if (checkValidIsbn(new_isbn, '-')) 
    {
        this->isbn = new_isbn;
    }
    else
    {
        throw invalid_argument("Provided isbn code is invalid...");
    }
}

bool Book::checkValidIsbn(string str, char delimiter)
{
    size_t start = 0, end, del_len = 1;
    string token;
    int token_count = 0;
    while ((end = str.find(delimiter, start)) != string::npos)
    {
        token = str.substr(start, end - start);
        if (token.empty() || token == " ") { return false; }
        start = end + del_len;
        token_count++;
    }
    if (token_count != 2)
    {
        return false;
    }
    return true;
}

void Book::set_price(double new_price)
{
    if(new_price <= 0)
    { 
        throw invalid_argument("Price can't be zero or negative number");
    }
    else
    {
        this->price = new_price;
    }
}

string Book::get_name() { return this->name; }
string Book::get_isbn() { return this->isbn; }
double Book::get_price() { return this->price; }