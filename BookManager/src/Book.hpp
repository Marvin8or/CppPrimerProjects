#pragma once
using namespace std;

struct ISBN
{
    string isbn;
    int n;
};

class Book
{
private:
    string name;
    string author;
    struct ISBN isbn;
    double price;
    void set_name(string new_name);
    void set_author(string new_author);
    void set_isbn(string new_isbn);
    void set_price(double new_price);
public:
    Book(string name, string author, string isbn, double price);
    int copies_sold = 1;
    static bool check_isbn(string new_isbn);
    string get_name();
    ISBN get_isbn();
    double get_price();
    string get_author();
    bool operator == (const Book& book);
};

ISBN generate_isbn(int n);
