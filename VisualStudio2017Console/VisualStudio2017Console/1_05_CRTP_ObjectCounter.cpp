template <typename T>
struct counter
{
	static int objects_created;
	static int objects_alive;

	counter()
	{
		++objects_created;
		++objects_alive;
	}
protected:
	~counter() // objects should never be removed through pointers of this type
	{
		--objects_alive;
	}
};
template <typename T> int counter<T>::objects_created( 0 );
template <typename T> int counter<T>::objects_alive( 0 );

class X : counter<X>
{
	// ...
};

class Y : counter<Y>
{
	// ...
};

int main()
{
	return 0;
}
