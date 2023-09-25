#include <iostream>

void mergeSort(int* vect, int front, int rear);
void merge(int* vect, int front, int mid, int rear);

int comp_counter = 0;

int main(void) {

	int n;
	std::cout << "Enter vector size: ";
	std::cin >> n;
	
	int *vect = new int[n];

	// get values
	for (int i = 0; i < n; i++) {
		std::cin >> vect[i];
	}

	//print values before merge sort
	std::cout << "\nbefore Merge Sort: ";
	for (int i = 0; i < n; i++) {
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";

	mergeSort(vect, 0, n - 1);

	//print values after merge sort
	std::cout << "After Merge Sort: ";
	for (int i = 0; i < n; i++) {
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";

	std::cout << comp_counter << " comparisons\n" << std::endl;

	return 0;
}

void mergeSort(int* vect, int front, int rear) 
{
	
	if (front < rear)
	{ 
		int mid = (front + rear) / 2;
		mergeSort(vect, front, mid);
		mergeSort(vect, mid + 1, rear);
		merge(vect, front, mid, rear);
	}
}

void merge(int* vect, int front, int mid, int rear) 
{
	int n1 = mid - front + 1; //adicionamos + 1 para contabilizar o elemnto do meio
	int n2 = rear - mid;

	//criamos 2 sublistas (esq e dir)
	int *leftList = new int[n1];
	int *rightList = new int[n2];

	//passamos os elementos para as sublistas
	for (int i = 0; i < n1; i++)
	{
		leftList[i] = vect[front + i];
	}

	for (int i = 0; i < n2; i++)
	{
		rightList[i] = vect[mid + 1 + i];
	}
	
	int i = 0, j = 0, k = front;

	// Mesclar as sub-listas temporárias de volta na lista original arr[] (ordenando)
	while (i < n1 && j < n2)
	{
		if (leftList[i] <= rightList[j])
		{
			vect[k] = leftList[i];
			i++;
			comp_counter++;
		}
		else
		{
			vect[k] = rightList[j];
			j++;
			comp_counter++;
		}
		k++;
	}

	//copiaremos os elementos que sobrarem da lista da esq OU da lista da dir
	while (i < n1)
	{
		vect[k] = leftList[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vect[k] = rightList[j];
		j++;
		k++;
	}
}