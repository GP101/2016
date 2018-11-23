// The Curiously Recurring Template Pattern (CRTP)
template<class Derived>
class Base
{
	// methods within Base can use template to access members of Derived
};
class Derived : public Base<Derived>
{
	// ...
};

int main()
{
	return 0;
}