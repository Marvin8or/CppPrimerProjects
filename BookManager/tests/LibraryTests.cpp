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
			Book book_list[] = { Book("Little Red Riding Hood", "123-456-789", 29),
								 Book("Peter Pan", "123-456-780", 39),
								 Book("Little Prince", "123-456-791", 15.99),
								 Book("Oz", "123-456-800", 23.15) };

			string book_infos[] = { "Little Red Riding Hood;123-456-789;29.000000",
									"Peter Pan;123-456-780;39.000000",
									"Little Prince;123-456-791;15.990000",
									"Oz;123-456-800;23.150000" };

			string db_name = "TestLibrary.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests";

			Library* library = new Library(db_name, db_path);
			for (int i = 0; i < 4; i++)
			{
				library->add(book_list[i]);
			}
			auto lib_buffer = library->get_buffer();
			int indx = 0;
			for (auto i = lib_buffer.begin(); i != lib_buffer.end(); i++)
			{
				Assert::AreEqual(book_infos[indx], *i);
				indx++;
			}
		}

		TEST_METHOD(TestCorrectDatabaseContent)
		{
			Book book_list[] = { Book("Little Red Riding Hood", "123-456-789", 29),
					 Book("Peter Pan", "123-456-780", 39),
					 Book("Little Prince", "123-456-791", 15.99),
					 Book("Oz", "123-456-800", 23.15) };

			string book_infos[] = { "Little Red Riding Hood;123-456-789;29.000000",
									"Peter Pan;123-456-780;39.000000",
									"Little Prince;123-456-791;15.990000",
									"Oz;123-456-800;23.150000" };

			string db_name = "TestLibrary.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CppPrimerProjects\\BookManager\\tests";

			Library* library = new Library(db_name, db_path);
			for (int i = 0; i < 4; i++)
			{
				library->add(book_list[i]);
			}

			library->write();

			vector<string> library_content = library->read();
			int indx = 0;
			for (auto i = library_content.begin(); i != library_content.end(); i++)
			{
				Assert::AreEqual(book_infos[indx], *i);
				indx++;
			}


		}

	};
}
