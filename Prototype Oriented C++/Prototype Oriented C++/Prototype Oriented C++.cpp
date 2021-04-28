// Prototype Oriented C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <concepts>
#include <any>
#include <utility>
#include <stdexcept>

class not_implemented : public std::runtime_error {
private:
	
public:
	not_implemented() : std::runtime_error("Feature not implemented") {}
};

class prototype_t {
private:

public:
	
};

class prototypable_test {
private:

public:
	prototype_t prototype;
};

class not_prototypable_test {
private:

public:
	
};

template<class T>
concept prototype_base = std::is_base_of_v<prototype_t, T> || std::is_same_v<prototype_t, T>;

template<class T>
concept prototype_base_container = requires(T t) {
	t.prototype;
} && prototype_base<decltype(std::declval<T>().prototype)>;

template<class T>
concept prototypable = prototype_base_container<T> && requires(T t) {
	// Must be implicitly convertible to prototype_t
	t.operator prototype_t();

	// All operators must work - (TODO): they should be defined in prototype_t
	//     - basic operators
	t.prototype.operator+(std::any());
	t.prototype.operator-(std::any());
	t.prototype.operator*(std::any());
	t.prototype.operator*();
	t.prototype.operator/(std::any());
	t.prototype.operator%(std::any());
	t.prototype.operator^(std::any());
	t.prototype.operator&(std::any());
	t.prototype.operator&();
	t.prototype.operator|(std::any());
	t.prototype.operator~(std::any());
	t.prototype.operator!();
	t.prototype.operator=(std::any());
	t.prototype.operator<(std::any());
	t.prototype.operator>(std::any());
	t.prototype.operator+=(std::any());
	t.prototype.operator-=(std::any());
	t.prototype.operator*=(std::any());
	t.prototype.operator/=(std::any());
	t.prototype.operator%=(std::any());
	t.prototype.operator^=(std::any());
	t.prototype.operator&=(std::any());
	t.prototype.operator|=(std::any());
	t.prototype.operator<<(std::any());
	t.prototype.operator>>(std::any());
	t.prototype.operator<<=(std::any());
	t.prototype.operator>>=(std::any());
	t.prototype.operator==(std::any());
	t.prototype.operator!=(std::any());
	t.prototype.operator<=(std::any());
	t.prototype.operator>=(std::any());
	t.prototype.operator<=>(std::any());
	t.prototype.operator&&(std::any());
	t.prototype.operator||(std::any());
	t.prototype.operator++();
	t.prototype.operator--();
	t.prototype.operator++(0);
	t.prototype.operator--(0);
	t.prototype.operator,(std::any());
	t.prototype.operator->*(std::any());
	t.prototype.operator->();
	t.prototype.operator()(std::any());
	t.prototype.operator[](std::any());

	//     - memory allocation operators
	decltype(t.prototype)::allocate(1U);
	decltype(t.prototype)::allocate_array(1U);
	decltype(t.prototype)::deallocate(new T());
	decltype(t.prototype)::deallocate_array(new T[1]);

	//     - co_await
	t.prototype.operator co_await();
};

int main() {
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
