#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>

#define BOLD(text) "\033[1m" text "\033[0m"

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
	return (a < b ? a : b);
}
	
template <typename T>
T const &max(T const &a, T const &b) {
	return (a > b ? a : b);
}

#endif
