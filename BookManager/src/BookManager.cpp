
#include <iostream>
#include "Book.hpp"
#include "Library.hpp"
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{

    Book* book = new Book("Little Red Riding Hood", "0389756288", 29.99);

    std::map<string, bool> expected_all_valid{
        {"0471958697", true},
        {"1885593155", true},
        {"1680502395", true},
        {"0321563840", true},
        {"097522980X", true},
        {"0385528221", true},
        {"0142000280", true}
    };

    for (const auto& item : expected_all_valid)
    {
        auto at = item.first;
        bool actual = book->check_isbn(item.first);
        bool expected = item.second;
        //Assert::AreEqual(book->check_isbn(actual), it->second);
    }
    //Book LittleRedRidingHood = Book("Little Red Riding Hood", "123-456-789", 29);
    //Book PeterPan = Book("Peter Pan", "123-456-780", 39);
    //Book LittlePrince = Book("Little Prince", "123-456-791", 15.99);
    //string path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\";
    //string name = "test.txt";
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
