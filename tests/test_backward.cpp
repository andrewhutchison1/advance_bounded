#include <iostream>
#include <string>

#include <cassert>

#include "../advance_bounded.hpp"

// This test ensure that the bounding works as expected (i.e. if the
// distance exceeds the lower bound, the lower bound is returned)
void test_backward_bound()
{
	std::string const s{"0123456789"};
	auto it = s.end();
	advance_bounded(s.begin(), s.end(), it, -100);
	assert((it == s.begin()));
}

// This test ensures that advance_bounded works expected inside the range
// [first, last) (i.e. it behaves exactly like std::advance in this range)
void test_backward_nobound()
{
	std::string const s{"0123456789"};
	auto it = s.end();
	advance_bounded(s.begin(), s.end(), it, -3);
	assert((it == std::find(s.begin(), s.end(), '7')));
}

// This test ensures that attempting to advance an iterator backward will
// have no effect if it the begin iterator of the bounds
void test_backward_begin()
{
	std::string const s{"0123456789"};
	auto it = s.begin();
	advance_bounded(s.begin(), s.end(), it, -1000);
	assert((it == s.begin()));
}

int main()
{
	test_backward_bound();
	test_backward_nobound();
	test_backward_begin();

	// If we get here all the tests have passed
	std::cout << "Tests passed\n";
}
