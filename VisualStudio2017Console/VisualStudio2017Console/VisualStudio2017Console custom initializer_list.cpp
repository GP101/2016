#include <stdio.h>
//#include "my_initializer_list.h"

namespace std {
	template <class T>
	class initializer_list {
	public:
		initializer_list() throw() : _first(0), _last(0) {}
		initializer_list(const T* first_arg_, const T* last_arg_) throw()
			: _first(first_arg_), _last(last_arg_) {}

		const T* begin() const throw() { printf("begin\r\n"); return (_first); }
		const T* end() const throw() { printf("end\r\n"); return (_last); }
		size_t size() const throw() { return ((size_t)(_last - _first)); }

	private:
		const T* _first;
		const T* _last;
	};

	template <class T>
	inline const T* begin(initializer_list<T> ilist_) throw() {
		printf("fbegin\r\n");
		return (ilist_.begin());
	}

	template <class T>
	inline const T* end(initializer_list<T> ilist_) throw() {
		printf("fend\r\n");
		return (ilist_.end());
	}
}

class MyType {
public:
	MyType(std::initializer_list<int> init_list) {
		for (int i : init_list) append(i);
		printf("\r\n");
	}
	MyType& operator=(std::initializer_list<int> init_list) {
		clear();
		for (int i : init_list) append(i);
		printf("\r\n");
		return *this;
	}
	void clear() {}
	void append(int i) {
		printf("%i,", i);
	}
};


int main() {
	for (int a : {1, 20, 300, 4000, 50000}) {
		printf("%d,", a);
	}
	printf("\r\n");
	MyType m{ 2, 3, 5, 7 };
	m = { 8,9 };
}
/*	output:
	begin
	end
	1,20,300,4000,50000,
	begin
	end
	2,3,5,7,
	begin
	end
	8,9,
*/
