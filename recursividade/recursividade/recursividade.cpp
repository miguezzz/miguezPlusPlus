#include <iostream>

int fatorial(int n);
int fibonacci(int n);

int main(void) {

	int n, result, choice;

	std::cout << "Menu:\n";
	std::cout << "1 - fatorial\n2 - fibonacci\n3 - fibonacci printer\n\n";

	std::cin >> choice;

	switch (choice) {
		case 1: 
			std::cout << "\nType a number and see its fatorial: ";
			std::cin >> n;

			result = fatorial(n);

			std::cout << "Fatorial of " << n << " is " << result << ".";
		
		break;


		case 2:
			std::cout << "\nWhich position? ";
			std::cin >> n;

			result = fibonacci(n);

			std::cout << "Position " << n << " = " << result << ".";
		
		break;


		case 3:
			std::cout << "How many terms? ";
			std::cin >> n;

			for (int i = 0; i < n; i++) {
				if (i < (n - 1)) {
					std::cout << fibonacci(i) << ", ";
				}
				else
					std::cout << fibonacci(i) << ".";
			}

			break;
	}

	return 0;
}

int fatorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else
		return n * fatorial(n - 1);
}

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}