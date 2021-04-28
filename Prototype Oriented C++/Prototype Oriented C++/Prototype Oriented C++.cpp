// Prototype Oriented C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <concepts>
#include <any>
#include <utility>
#include <stdexcept>
#include <initializer_list>
#include <map>
#include <string>
#include <string_view>

class not_implemented : public std::runtime_error {
private:
	
public:
	not_implemented() : std::runtime_error("Feature not implemented") {}
};


class prototype_t {
/// <summary>
/// A class with this class as an object member variable should reference this class's
/// operator overloads and methods.
/// </summary>
private:
	std::map<std::string, std::any> data;
public:
	template<class T>
	void create(std::string_view name, T &&value) {
		this->data.insert({ std::string(name), std::make_any<T>(std::forward(value)) });
	}

	template<class T>
	T &get(const std::string &name) {
		return std::any_cast<T>(this->data[name]);
	}

	std::any operator+(std::any value) {}
	std::any operator+(std::any value) const {}
	std::any operator-(std::any value) {}
	std::any operator-(std::any value) const {}
	std::any operator*(std::any value) {}
	std::any operator*(std::any value) const {}
	std::any operator/(std::any value) {}
	std::any operator/(std::any value) const {}
	std::any operator%(std::any value) {}
	std::any operator%(std::any value) const {}
	std::any operator^(std::any value) {}
	std::any operator^(std::any value) const {}
	std::any operator&(std::any value) {}
	std::any operator&(std::any value) const {}
	std::any operator|(std::any value) {}
	std::any operator|(std::any value) const {}
	std::any operator~() {}
	std::any operator~() const {}
	std::any operator!() {}
	std::any operator!() const {}
	std::any operator=(std::any value) {}
	std::any operator=(std::any value) const {}
	std::any operator<(std::any value) {}
	std::any operator<(std::any value) const {}
	std::any operator>(std::any value) {}
	std::any operator>(std::any value) const {}
	std::any operator+=(std::any value) {}
	std::any operator+=(std::any value) const {}
	std::any operator-=(std::any value) {}
	std::any operator-=(std::any value) const {}
	std::any operator*=(std::any value) {}
	std::any operator*=(std::any value) const {}
	std::any operator/=(std::any value) {}
	std::any operator/=(std::any value) const {}
	std::any operator%=(std::any value) {}
	std::any operator%=(std::any value) const {}
	std::any operator^=(std::any value) {}
	std::any operator^=(std::any value) const {}
	std::any operator&=(std::any value) {}
	std::any operator&=(std::any value) const {}
	std::any operator|=(std::any value) {}
	std::any operator|=(std::any value) const {}
	std::any operator<<(std::any value) {}
	std::any operator>>(std::any value) const {}
	std::any operator>>=(std::any value) {}
	std::any operator<<=(std::any value) const {}
	std::any operator==(std::any value) {}
	std::any operator==(std::any value) const {}
	std::any operator!=(std::any value) {}
	std::any operator!=(std::any value) const {}
	std::any operator<=(std::any value) {}
	std::any operator<=(std::any value) const {}
	std::any operator>=(std::any value) {}
	std::any operator>=(std::any value) const {}
	std::any operator<=>(std::any value) {}
	std::any operator<=>(std::any value) const {}
	std::any operator&&(std::any value) {}
	std::any operator&&(std::any value) const {}
	std::any operator||(std::any value) {}
	std::any operator||(std::any value) const {}
	std::any operator++() {}
	std::any operator++() const {}
	std::any operator++(int) {}
	std::any operator++(int) const {}
	std::any operator--() {}
	std::any operator--() const {}
	std::any operator--(int) {}
	std::any operator--(int) const {}
	std::any operator,(std::any value) {}
	std::any operator,(std::any value) const {}
	std::any operator->*(std::any value) {}
	std::any operator->*(std::any value) const {}
	std::any operator->() {}
	std::any operator->() const {}

	std::any functor_call(std::initializer_list<std::any> params) {}
	std::any functor_call(std::initializer_list<std::any> params) const {}
	std::any index(std::any value) {}
	std::any index(std::any value) const {}

	void *allocate(size_t n) {
		return ::operator new(n);
	}

	void *allocate_array(size_t n) {
		return ::operator new[](n);
	}

	void deallocate(void *ptr) {
		::operator delete(ptr);
	}

	void deallocate_array(void *ptr) {
		::operator delete[](ptr);
	}
};

template<class T>
concept prototypable = requires(T t) {
	std::same_as<decltype(t.prototype), prototype_t>;

	// From https://en.cppreference.com/w/cpp/language/operators
	// 1. operator op -> optionally defined
	// 2. operator type
	t.operator prototype_t();
	// 3. operator new   -> optionally overridden
	//    operator new[] -> optionally overridden
	// 4. operator delete   -> optionally overridden
	//    operator delete[]	-> optionally overridden
	// 5. operator "" suffix-identifier -> not for member function overload
	// 6. operator co_await
	t.operator co_await();
};



class prototypable_test {
private:

public:
	prototype_t prototype;
};

class not_prototypable_test {
private:

public:
	int operator++(int a) {
		std::cout << a << "\n";
	}
};

int main() {
	not_prototypable_test a;

	a++;
	a.operator++(27);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
