#include <iostream>
#include <string>
#include <memory>

using std::string;
struct connection
{
	string msg;
	int id;
};

struct destination
{
	string msg;
	int id;
};

connection connect(destination* dest)
{
	std::cout << "connected to destination with ID: " << dest->id << std::endl;
	std::cout << dest->msg << std::endl;
	connection con;
	con.msg = dest->msg;
	con.id = dest->id;
	return con;
}

void disconnect(connection* c)
{
	std::cout << "Disconnected " << std::endl;
};

void end_connection(connection* con)
{
	std::cout << "calling destructor (end_connection)" << std::endl;
	disconnect(con);
}

void processV1(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
}
//
//void processV2(destination& d)
//{
//	connection c = connect(&d);
//	std::shared_ptr<connection> p(&c, []{});
//}
int main()
{
	destination d;
	d.msg = "web server";
	d.id = 1;
	processV1(d);
	return 0;
}