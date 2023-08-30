#include <iostream>

int main() {

	std::cout << "Hello world!\n"; // seta pra esquerda qd for out

	int x;
	std::cin >> x; // seta pra direita qd for in

	if (x < 0) {
		std::cout << "x eh menor que zero!";
	}
	else if (x > 0) {
		std::cout << "x eh maior que zero!";
	}
	else {
		std::cout << "x eh zero!";
	}

	return 0;
}