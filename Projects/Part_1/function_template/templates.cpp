#include <iostream>

constexpr auto& print = std::cout;

template <typename T, typename C>
auto max(T x, C y){
	return (x > y) ? x : y;
}

int main(){
	print << max(1, 2.9) << '\n';
	return 0;
} 