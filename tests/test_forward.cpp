#include <iostream>
#include <string>

#include <cassert>

#include "../advance_bounded.hpp"

using namespace ah1;

// This test ensures that the bounding works as expected
void test_forward_bound()
{
	std::string const s{"0123456789"};
	auto it = s.begin();
	advance_bounded(s.begin(), s.end(), it, 100);
	assert((it == s.end()));
}

// This test ensures that a distance which does not exceed the bound works
// as expected
void test_forward_nobound()
{
	std::string const s{"0123456789"};
	auto it = s.begin();
	advance_bounded(s.begin(), s.end(), it, 3);
	assert((it == std::find(s.begin(), s.end(), '3')));
}

// This test ensures that the end iterator is not advanced, regardless of
// the input distance
void test_forward_end()
{
	std::string const s{"0123456789"};
	auto it = s.end();
	advance_bounded(s.begin(), s.end(), it, 1000);
	assert((it == s.end()));
}

int main()
{
	test_forward_bound();
	test_forward_nobound();
	test_forward_end();

	// If we get here all tests have passed
	std::cout << "Tests succeeded\n";
}
