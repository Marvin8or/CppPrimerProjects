
#include <iostream>
#include "Book.hpp"
#include "Library.hpp"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Book LittleRedRidingHood = Book("Little Red Riding Hood", "123-456-789", 29);
    //Book PeterPan = Book("Peter Pan", "123-456-780", 39);
    //Book LittlePrince = Book("Little Prince", "123-456-791", 15.99);
    string path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\";
    string name = "test.txt";
    //Library* myLibrary = new Library(name, path);
    //myLibrary->add(LittleRedRidingHood);
    //myLibrary->add(PeterPan);
    //myLibrary->add(LittlePrince);
    //auto lib_buffer = myLibrary->get_buffer();
    //for (auto i = lib_buffer.begin(); i != lib_buffer.end(); i++)
    //{
    //    cout << *i << endl;
    //}

    //myLibrary->write();


    return 0;
}
