#pragma once
using namespace std;
class Book
{
private:
    string name;
    string isbn;
    double price;
    void set_name(string new_name);
    void set_isbn(string new_isbn);
    void set_price(double new_price);
public:
    Book(string name, string isbn, double price);
    static bool checkValidIsbn(string str, char delimiter);
    string get_name();
    string get_isbn();
    double get_price();
};
