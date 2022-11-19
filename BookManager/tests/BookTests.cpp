#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Book.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BookTests
{
	TEST_CLASS(BookTests)
	{

	public:

		TEST_METHOD(TestBookClassInitailzation)
		{
			string title = "Little Red Riding Hood";
			string isbn = "123-456-789";
			double price = 29.99;
			Book* book = new Book(title, isbn, price);
			Assert::AreEqual(title, book->get_name());
			Assert::AreEqual(isbn, book->get_isbn());
			Assert::AreEqual(price, book->get_price());
		}

		TEST_METHOD(TestInvalidValidBookName)
		{
			auto empty_name_lambda = [] {Book Book("", "123-456-789", 29.99); };
			Assert::ExpectException<invalid_argument>(empty_name_lambda);

			auto name_is_space_lambda = [] {Book Book(" ", "123-456-789", 29.99); };
			Assert::ExpectException<invalid_argument>(name_is_space_lambda);

		}

		TEST_METHOD(TestInvalidIsbnNumber)
		{
			auto testcase1 = [] {Book Book("Little Red Riding Hood", "", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Book Book("Little Red Riding Hood", " ", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase2);

			auto testcase3 = [] {Book Book("Little Red Riding Hood", "-123-4566-78", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase3);
			
			auto testcase4 = [] {Book Book("Little Red Riding Hood", "123--4566-78", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase4);

			auto testcase5 = [] {Book Book("Little Red Riding Hood", "123-4566-78-", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase5);

			auto testcase6 = [] {Book Book("Little Red Riding Hood", "123-4566--78", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase6);

			auto testcase7 = [] {Book Book("Little Red Riding Hood", "123-4566", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase7);

		}

		TEST_METHOD(TestInvalidBookPrice)
		{

			auto testcase1 = [] {Book Book("Little Red Riding Hood", "123-4567-89", 0); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Book Book("Little Red Riding Hood", "123-4567-89", -29.99); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

	};
}
