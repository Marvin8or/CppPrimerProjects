#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Book.hpp"
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BookTests
{
	TEST_CLASS(BookTests)
	{

	public:
		TEST_METHOD(TestISBNGeneration)
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

			for (std::map<string, bool>::iterator it = expected_all_valid.begin(); it != expected_all_valid.end(); ++it)
			{
				string actual = it->first;
				Assert::AreEqual(book->check_isbn(actual), it->second );
			}

			std::map<string, bool> expected_all_invalid{
				{"3957553940", false},
				{"6000521333", false},
				{"1722541647", false},
				{"6238991330", false},
				{"8996121674", false},
				{"3777870381", false},
				{"0829650643", false}
			};

			for (std::map<string, bool>::iterator it = expected_all_invalid.begin(); it != expected_all_invalid.end(); ++it)
			{
				Assert::AreEqual(book->check_isbn(it->first), it->second);
			}
			std::map<string, bool> expected_invalid_characters{
				{"395755394A", false},
				{"60005B1333", false},
				{"172254c647", false},
				{"62W8991330", false},
				{"89!6121674", false},
				{"3777%70381", false},
				{"08!?650643", false}
			};
			for (std::map<string, bool>::iterator it = expected_invalid_characters.begin(); it != expected_invalid_characters.end(); ++it)
			{
				Assert::AreEqual(book->check_isbn(it->first), it->second);
			}
			std::map<string, bool> expected_invalid_length{
				{"", false},
				{" ", false},
				{"1", false},
				{"60", false},
				{"874", false},
				{"3381", false},
				{"00643", false}
			};
			for (std::map<string, bool>::iterator it = expected_invalid_length.begin(); it != expected_invalid_length.end(); ++it)
			{
				Assert::AreEqual(book->check_isbn(it->first), it->second);
			}
			std::map<string, bool> expected_invalid_checksum{
				{"1234567890", false},
				{"2345678901", false},
				{"3456789012", false},
				{"4567890123", false},
				{"5678901234", false},
				{"6789012345", false},
				{"7890123456", false}
			};
			for (std::map<string, bool>::iterator it = expected_invalid_checksum.begin(); it != expected_invalid_checksum.end(); ++it)
			{
				Assert::AreEqual(book->check_isbn(it->first), it->second);
			}
			std::map<string, bool> expected_valid_boundary_values{
				{"0000000000", true},
				{"9999999999", true},
				{"1234567890", false},
				{"9876543210", true},
				{"0123456789", true},
				{"8901234567", false},
				{"0000000001", false}
			};
			for (std::map<string, bool>::iterator it = expected_valid_boundary_values.begin(); it != expected_valid_boundary_values.end(); ++it)
			{
				Assert::AreEqual(book->check_isbn(it->first), it->second);
			}
			
		}

		TEST_METHOD(TestBookClassInitailzation)
		{
			string title = "Little Red Riding Hood";
			string isbn = "097522980X";
			double price = 29.99;
			Book* book = new Book(title, isbn, price);
			Assert::AreEqual(title, book->get_name());
			Assert::AreEqual(isbn, book->get_isbn().isbn);
			Assert::AreEqual(price, book->get_price());
		}

		TEST_METHOD(TestInvalidValidBookName)
		{
			auto empty_name_lambda = [] {Book Book("", "097522980X", 29.99); };
			Assert::ExpectException<invalid_argument>(empty_name_lambda);

			auto name_is_space_lambda = [] {Book Book(" ", "097522980X", 29.99); };
			Assert::ExpectException<invalid_argument>(name_is_space_lambda);

		}
		
		TEST_METHOD(TestInvalidIsbnNumber)
		{
			auto testcase1 = [] {Book Book("Little Red Riding Hood", "", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Book Book("Little Red Riding Hood", " ", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase2);

			auto testcase3 = [] {Book Book("Little Red Riding Hood", "1234567890", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase3);
			
			auto testcase4 = [] {Book Book("Little Red Riding Hood", "1234567890", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase4);

			auto testcase5 = [] {Book Book("Little Red Riding Hood", "0000000001", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase5);

			auto testcase6 = [] {Book Book("Little Red Riding Hood", "08!?650643", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase6);

			auto testcase7 = [] {Book Book("Little Red Riding Hood", "3777870381", 29.99); };
			Assert::ExpectException<invalid_argument>(testcase7);

		}
		
		TEST_METHOD(TestInvalidBookPrice)
		{

			auto testcase1 = [] {Book Book("Little Red Riding Hood", "0123456789", 0); };
			Assert::ExpectException<invalid_argument>(testcase1);

			auto testcase2 = [] {Book Book("Little Red Riding Hood", "0123456789", -29.99); };
			Assert::ExpectException<invalid_argument>(testcase2);
		}

	};
}
