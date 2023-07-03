#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Library.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTests
{
	TEST_CLASS(LibraryTests)
	{

	public:



		TEST_METHOD(TestLibraryClassInitailzation)
		{
			string db_name = "LibraryDB.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests";

			string full = db_path + "\\";
			full += db_name;
			Library* library2 = new Library(db_name, db_path);
			Assert::AreEqual(db_name, library2->get_name());
			Assert::AreEqual(full, library2->get_path());
		}

		TEST_METHOD(TestInvalidLibraryNameCtor2)
		{
			auto testcase1 = [] {Library Library("", "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests"); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Library Library(" ", "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests"); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

		TEST_METHOD(TestInvalidLibraryPath)
		{
			auto testcase1 = [] {Library Library("MyLibrary.txt", ""); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Library Library("MyLibrary.txt", " "); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

		TEST_METHOD(TestLibraryBuffer)
		{
			vector<Book> book_list = { Book("To Kill a Mockingbird", "Harper Lee", "0061120081", 9.99),
								 Book("Pride and Prejudice", "Jane Austen", "0141439501", 12.99),
								 Book("The Great Gatsby", "F.Scott Fitzgerald", "0743273567", 7.89),
								 Book("One Hundred Years of Solitude", "Gabriel García Márquez", "0060531045", 10.78),
								 Book("Moby-Dick", "Herman Melville", "0679601755", 9.99) };

			string db_name = "TestLibrary.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests";

			Library* library = new Library(db_name, db_path);
			for (int i = 0; i < 4; i++)
			{
				library->add(book_list[i]);
			}
			auto lib_buffer = library->get_buffer();
			for (std::vector<Book>::size_type i = 0; i < book_list.size(); ++i)
			{
				Assert::AreEqual(book_list[i], lib_buffer[i]);
			}
		}

		TEST_METHOD(TestCorrectDatabaseContent)
		{
			vector<Book> book_list = { Book("To Kill a Mockingbird", "Harper Lee", "0061120081", 9.99),
								 Book("Pride and Prejudice", "Jane Austen", "0141439501", 12.99),
								 Book("The Great Gatsby", "F.Scott Fitzgerald", "0743273567", 7.89),
								 Book("One Hundred Years of Solitude", "Gabriel García Márquez", "0060531045", 10.78),
								 Book("Moby-Dick", "Herman Melville", "0679601755", 9.99) };

			string book_infos[] = { "To Kill a Mockingbird;Harper Lee;0061120081;9.990000;1",
									"Pride and Prejudice;Jane Austen;0141439501;12.990000;1",
									"The Great Gatsby;F.Scott Fitzgerald;0743273567;7.890000;1",
									"One Hundred Years of Solitude;Gabriel García Márquez;0060531045;10.780000;1",
									"Moby-Dick;Herman Melville;0679601755;9.99;1" };

			string db_name = "library_database.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests";

			Library* library = new Library(db_name, db_path);
			for (vector<Book>::size_type i = 0; i < book_list.size(); ++i)
			{
				library->add(book_list[i]);
			}

			library->write();
			vector<Book> library_content = library->read();
			for (vector<Book>::size_type i = 0; i < book_list.size(); ++i)
			{
				Assert::AreEqual(library_content[i], book_list[i]);
			
			}
		}
	};
}
