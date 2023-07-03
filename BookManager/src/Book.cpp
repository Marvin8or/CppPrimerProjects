
#include <iostream>
#include <random>
#include "Book.hpp"
#include <string>

Book::Book(string name, string author, string isbn, double price)
{
    set_name(name);
    set_author(author);
    set_isbn(isbn);
    set_price(price);
}

void Book::set_name(string new_name)
{
    // TODO replace return value and logging
    if (new_name.empty() || new_name == " ")
    { 
        throw invalid_argument("Provided name is empty...");
    }
    else
    {
        this->name = new_name;
    }
}

void Book::set_author(string new_author)
{
    // TODO replace return value and logging
    if (new_author.empty() || new_author == " ")
    { 
        throw invalid_argument("Provided authors name is empty...");
    }
    else
    {
        this->author = new_author;
    }
}
void Book::set_isbn(string new_isbn)
{
    // TODO replace method return value and logging
    if (new_isbn.empty()) { throw invalid_argument("Provided isbn code is empty..."); }
    if (check_isbn(new_isbn))
    {
        this->isbn.isbn = new_isbn;
        this->isbn.n = new_isbn.length();
    }
    else
    {
        throw invalid_argument("Provided isbn code is invalid...");
    }
}
bool Book::check_isbn(string new_isbn)
{
    if (new_isbn.empty() || new_isbn == " ") 
    { 
        //TODO should be logged somewhere
        //throw invalid_argument("Provided isbn code is empty...");
        return false;
    }
    else if(new_isbn.length() <= 0) 
    {
        //TODO should be logged somewhere
        //throw invalid_argument("Provided isbn code structure is invalid...");
        return false;
    }

    int sum = 0;
    for (int i = 0; i < new_isbn.length() - 1; i++)
    {
        int digit = new_isbn[i] - '0';
        if (digit < 0 || digit > new_isbn.length() - 1)
        {
            // TODO should be logged
            return false;
        }
        sum += (digit * (new_isbn.length() - i));
    }

    // check last digit
    char last = new_isbn[new_isbn.length() - 1];
    if (last != 'X' && (last < '0' || last > '9'))
    {
        // TODO should be logged
        return false;
    }
       
    //check last digit and add it
    sum += ((last == 'X') ? 10 : last - '0');
    return (sum % 11 == 0);
}

void Book::set_price(double new_price)
{
    // TODO replace return value and logging
    if(new_price <= 0)
    { 
        throw invalid_argument("Price can't be zero or negative number");
    }
    else
    {
        this->price = new_price;
    }
}

bool Book::operator==(const Book& book)
{
    return (this->name == book.name && this->isbn.isbn == book.isbn.isbn && this->price == book.price);
}

string Book::get_name() { return this->name; }
string Book::get_author() { return this->author; }
ISBN Book::get_isbn() { return this->isbn; }
double Book::get_price() { return this->price; }

int generate_random_digit(int min, int max)
{
    static mt19937 rng(random_device{}());
    uniform_int_distribution<mt19937::result_type> dist(min, max);
    return dist(rng);
}

ISBN generate_isbn(int n)
{
    string isbn;
    for (int i = 0; i < n - 1; i++)
    {
        isbn += to_string(generate_random_digit(0, 9));
    }

    // Calculate the check digit
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // If index is even, add the digit to the sum
        if (i % 2 == 0)
        {
            sum += isbn[i] - '0';
        }
        else
        {
            sum += 3 * (isbn[i] - '0');
        }
    }

    int remainder = sum % 11;
    int check_digit = (11 - remainder) % 11;
    isbn += to_string(check_digit);

    ISBN _;
    _.isbn = isbn;
    _.n = isbn.length();
    return _;
}