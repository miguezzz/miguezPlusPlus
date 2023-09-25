#include <iostream>

int binarysearch(int* vect, int front, int rear, int whatuwant);

int main(void) {

	int size;
	int whatuwant;
	int position;

	std::cout << "Enter vector size: ";
	std::cin >> size;
	std::cout << "\n";

	int* vector = new int[size];

	std::cout << "Enter vector numbers (sorted)" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> vector[i];
	}

	std::cout << "Which number do you want to find? ";
	std::cin >> whatuwant;
	std::cout << "\n";

	position = binarysearch(vector, 0, size, whatuwant);

	std::cout << whatuwant << " is at position " << position << std::endl;

	return 0;
}

int binarysearch(int* vect, int front, int rear, int whatuwant)
{
	int mid = (front + rear) / 2;

	if (front > rear)
	{
		std::cout << "Index out of bounds. Item does not exist in vector!" << std::endl;
		return -1;
	}

	if (vect[mid] == whatuwant)
	{
		return mid; // retorna posicao do meio
	}

	if (vect[mid] > whatuwant) // elemento ta na parte da esquerda (meio maior q ele)
	{
		return binarysearch(vect, front, mid - 1, whatuwant);
	}
	else // (vect[mid] < whatuwant -> elemento ta na parte da direita
	{
		return binarysearch(vect, mid + 1, rear, whatuwant);
	}
}