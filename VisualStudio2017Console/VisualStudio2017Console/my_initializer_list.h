// So, I discovered you can actually iterate over array literals in C++, which is kinda nice,
// but only if you include <initializer_list>. As that will drag in >9K LOC from the standard
// libraries, I tried implementing my own by trimming the MSVC one, and hey, it works. And
// in just 30 LOC (and an stddef.h include I couldn't avoid (for size_t))
// Here it goes, with an example at the end

// ---------------------------------->8----------------------------------
//#include <stddef.h>
namespace std {
	template <class _Elem>
	class initializer_list {
	public:
		initializer_list() throw() : _First(0), _Last(0) {}
		initializer_list(const _Elem *_First_arg, const _Elem *_Last_arg) throw()
			: _First(_First_arg), _Last(_Last_arg) {}

		const _Elem *begin() const throw() { printf("begin\r\n"); return (_First); }
		const _Elem *end() const throw() { return (_Last); }
		size_t size() const throw() { return ((size_t)(_Last - _First)); }

	private:
		const _Elem *_First, *_Last;
	};

	template <class _Elem>
	inline const _Elem *begin(initializer_list<_Elem> _Ilist) throw() {
		return (_Ilist.begin());
	}

	template <class _Elem>
	inline const _Elem *end(initializer_list<_Elem> _Ilist) throw() {
		return (_Ilist.end());
	}
}
