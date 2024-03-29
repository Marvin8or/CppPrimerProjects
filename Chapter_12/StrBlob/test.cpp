#include "test.h"

void testStrBlob(StrBlob &sb)
{
	try
	{
		sb.push_back("abs");
		std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
		sb.pop_back();
		std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
		sb.begin().deref() = "Change";
		for (auto p = sb.begin(); ; p.incr())
		{
			std::cout << "deref: " << p.deref() << std::endl;
		}

	}catch(std::out_of_range err)
	{
		std::cerr << err.what() << " out of range" << std::endl;
	}catch(std::exception err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void testStrBlob(const StrBlob& sb) {
	try {
		std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
	}
	catch (std::out_of_range err) {
		std::cerr << err.what() << " out of range" << std::endl;
	}
	catch (std::exception err) {
		std::cerr << err.what() << std::endl;
	}
}

void testStrBlobPtr(StrBlobPtr& sbp) {
	try {
		sbp.deref() = "Change2";
		for (auto p = sbp; ; p.incr())
			std::cout << "deref: " << p.deref() << std::endl;
	}
	catch (std::out_of_range err) {
		std::cerr << err.what() << " out of range" << std::endl;
	}
	catch (std::exception err) {
		std::cerr << err.what() << std::endl;
	}
}

void testAllBlob()
{
	StrBlob sb1;
	testStrBlob(sb1);
	std::cout << std::endl;

	StrBlob sb2{ "Hello", "World" };
	testStrBlob(sb2);
	std::cout << std::endl;

	const StrBlob csb1;
	testStrBlob(csb1);
	std::cout << std::endl;

	const StrBlob csb2{ "This", "Blob" };
	testStrBlob(csb2);
	std::cout << std::endl;

	testStrBlob({ "ppp", "qqq" });
	std::cout << std::endl;

	//testStrBlob({"mm", 1});  // Error

	StrBlobPtr sbp1;
	testStrBlobPtr(sbp1);
	std::cout << std::endl;

	StrBlobPtr sbp2(sb1);
	testStrBlobPtr(sbp2);
	std::cout << std::endl;

	StrBlobPtr sbp3(sb1, sb1.size());
	testStrBlobPtr(sbp3);
	std::cout << std::endl;

	StrBlobPtr sbp4(sb2);
	testStrBlobPtr(sbp4);
	std::cout << std::endl;

	StrBlobPtr sbp5(sb2, sb2.size());
	testStrBlobPtr(sbp5);
	std::cout << std::endl;
}