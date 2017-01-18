#include <iostream>


namespace MyStd
{
	struct Test
	{
		int a;
	};
	
	/*
	template <class T>
	T myFun(T a, T b)
	{
		return a < b ? a : b;
	}*/
	Test myFun(Test a, Test b)
	{
		return a < b ? a : b;
	}
	

};


bool operator < (const MyStd::Test &a, const MyStd::Test &b)
{
	std::cout << "....." << std::endl;
	return a.a < b.a;
}

int main()
{

	MyStd::Test a;
	MyStd::Test b;
	MyStd::myFun(a, b); // print "......."
	
	return 0;
}