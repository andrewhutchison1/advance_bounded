#ifndef ADVANCE_BOUNDED_HPP_
#define ADVANCE_BOUNDED_HPP_

#include <iterator>

// Advances an iterator n places, not exceeding last (if n is positive) or
// first (if n is negative). If n is negative, then InIt must meet the
// requirements of BidirectionalIterator. Additionally, first must be
// less than last.
template <typename InIt, typename Distance>
//	requires InputIterator<InIt>
inline void advance_bounded(InIt first, InIt last, InIt& it, Distance n)
{
	// The comparison type. This allows any distance n to be compared with
	// the bound (result of std::distance)
	using comp_type = typename std::iterator_traits<InIt>::difference_type;

	if (n > 0) {
		auto const bound  = std::distance(it, last);
		std::advance(it, std::min(static_cast<comp_type>(n), bound));
	} else if (n < 0) {
		auto const bound = std::distance(it, first);
		std::advance(it, std::max(static_cast<comp_type>(n), bound));
	}
}

#endif // ADVANCE_BOUNDED_HPP_
