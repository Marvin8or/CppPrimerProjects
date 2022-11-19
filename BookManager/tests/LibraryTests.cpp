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
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CPPPrimerProjects\\BookManager";
			Library* library1 = new Library(db_name);
			Assert::AreEqual(db_name, library1->get_name());
			Assert::AreEqual(db_path, library1->get_path());


			Library* library2 = new Library(db_name, db_path);
			Assert::AreEqual(db_name, library2->get_name());
			Assert::AreEqual(db_path, library2->get_path());
		}

		TEST_METHOD(TestInvalidLibraryNameCtor1)
		{
			auto testcase1 = [] {Library Library(""); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Library Library(" "); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

		TEST_METHOD(TestInvalidLibraryNameCtor2)
		{
			auto testcase1 = [] {Library Library("", "C:\\Users\\Gabriel\\Documents\\Projects\\CPPPrimerProjects\\BookManager\\TestForLibraryPathCreation"); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Library Library(" ", "C:\\Users\\Gabriel\\Documents\\Projects\\CPPPrimerProjects\\BookManager\\TestForLibraryPathCreation"); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

		TEST_METHOD(TestInvalidLibraryPath)
		{
			auto testcase1 = [] {Library Library("MyLibrary.txt", ""); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Library Library("MyLibrary.txt", " "); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

		TEST_METHOD(TestInvalidFullLibraryPath)
		{
			string db_name = "LibraryDB.txt";
			string db_path = "C:\\Users\\Gabriel\\Documents\\Projects\\CPPPrimerProjects\\BookManager";
			string full_path = db_name + "\\";
			full_path += db_path;
			Library* library1 = new Library(db_name, db_path);
			//Assert::AreEqual(full_path, library1->get_full_path());

		}
	};
}
