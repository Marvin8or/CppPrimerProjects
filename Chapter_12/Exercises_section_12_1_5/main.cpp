#include <iostream>
#include <utility>

using namespace std;
typedef unique_ptr<int> IntP;
int main()
{
	unique_ptr<int> up(new int(32));
	//unique_ptr<int> up1(up);
	//unique_ptr<int> up1;
	//up1 = up;

	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
	//IntP p0(ix); // (a) Illegal. `ix` is not a pointer.
	//IntP p1(pi); // (b) Illegal. The memory pointed by `pi` is not dynamically allocated in heap, thus cannot be freed by a smart pointer.
	IntP p2(pi2);  // (c) Legal
	///IntP p3(&ix); // (d) Illegal, same reaseon as (b)
	IntP p4(new int(2048)); // (e) Legall
	IntP p5(p2.get()); // Illegal, two uniqe_ptrs point to same memory.
	return 0;
}