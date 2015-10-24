## advance_bounded

Sometimes when we use `std::advance` we aren't sure if the iterator we
give it will be dereferenceable or not, since dereferencing a *beyond-the
end* iterator is undefined behaviour. In other cases we might want to
advance an iterator a number of places we've determined by some
computation, but we want to keep it in a specific subrange of a
container (such as one returned from `partial_sort`).

`advance_bounded`, as its name implies, is a simple utility to advance an
iterator without exceeding given upper and lower bounds.

#### Usage

`advance_iterator(first, last, iterator, distance)`

* `first` is an `InputIterator` representing the lower bound of the range
* `last` is an `InputIterator` representing the upper bound of the range
* `iterator` is the `InputIterator` you want to advance
* `distance` is the number of places to advance `iterator`

`first` must be strictly less than `last` (so that `[first, last)` is a
valid range). Some examples follow:

```
std::string const s{"0123456789"};
auto it = s.begin();
advance_bounded(s.begin(), s.end(), it, 5);

// At this point, it points to '5'.

advance_bounded(s.begin(), s.end(), it, 100000);

// At this point, it is equal to s.end()
```

#### Installation

Just drop `advance_bounded.hpp` anywhere on your project's include path
and include it.

#### Notes

Like `std::advance`, `distance` can be negative. In this case, the iterator
is decremented by the given number of places, or to `first`. Note that
`iterator` must satisfy `BidirectionalIterator` in this case.

`advance_bounded` is implemented on top of `std::advance`, and has the
same performance characteristics beyond an additional constant-time bounds
check. Importantly, this means that if `iterator` satisfies
`RandomAccessIterator`, it will be constant-time.

The most obvious use case is for `first` and `last` to be the beginning
and end (respectively) of the range you are traversing. However, they can
be any valid range of a container.
