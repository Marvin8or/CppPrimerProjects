
#include <iostream>
#include "Book.hpp"
#include "Library.hpp"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    Book LittleRedRidingHood = Book("Book1", "123-456-789", 29);
    Library* myLibrary = new Library("path", "name");
    cout << myLibrary->get_database_name() << myLibrary->get_database_path();
    //cout << "LittleRedRidingHood"; //write to file

    /*string file_name = "demo.txt";
    ifstream file_in(file_name, ios::in);
    ofstream file_out(file_name, ios::out);
   

    string demo = "Some stupid string";
    file_out << demo;
    file_out.close();

    string contents;
    while (getline(file_in, contents))
    {   
        cout << contents;
    }

    file_in.close();*/

    return 0;
}
