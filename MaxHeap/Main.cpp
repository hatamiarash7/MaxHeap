#include <iostream>
#include <cmath>

class Heaparr {
public:
	Heaparr();
	void insert(int da);
	int getLeft(int i) { return 2 * i + 1; }
	int getRight(int i) { return 2 * i + 2; }
	int getParent(int i) { return (i - 1) / 2; }
	int getMax() { return maxHeap[0]; }
	void print();
	void reheap(int num);
	void makeArray();
	void Build_Max_Heap(int heapArray[], int heap_size);
	void Max_Heapify(int heapArray[], int i, int heap_size);
	void heapSort(int heapArray[], int heap_size);

private:
	int size;
	int* maxHeap;
	int index;
	int i;
};

Heaparr::Heaparr() {
	maxHeap = nullptr;
	size = 0;
}

void Heaparr::insert(int da) {
	size++;
	int* tmp = new int[size];

	for (int i = 0; i < size - 1; i++)
		tmp[i] = maxHeap[i];

	tmp[size - 1] = da;
	delete[] maxHeap;
	maxHeap = tmp;
}

void Heaparr::heapSort(int heapArray[], int heap_size) {
	size = heap_size;
	int n = size;
	Build_Max_Heap(heapArray, heap_size);

	for (int i = n - 1; i >= 1; i--) {
		std::swap(heapArray[0], heapArray[i]);
		heap_size = heap_size - 1;
		Max_Heapify(heapArray, 0, heap_size);
	}
}

void Heaparr::Build_Max_Heap(int heapArray[], int heap_size) {
	int n = size;
	for (int i = floor((n - 1) / 2); i >= 0; i--)
		Max_Heapify(heapArray, i, heap_size);
	return;
}

void Heaparr::Max_Heapify(int heapArray[], int i, int heap_size) {
	// int n = size;
	int largest = 0;
	int l = getLeft(i);
	int r = getRight(i);

	if ((l < heap_size) && (heapArray[l] < heapArray[i]))
		largest = l;
	else 
		largest = i;

	if ((r < heap_size) && (heapArray[r] < heapArray[largest]))
		largest = r;

	if (largest != i) {
		std::swap(heapArray[i], heapArray[largest]);
		Max_Heapify(heapArray, largest, heap_size);
	}
	return;
}

int main(int argc, char* argv[]) {
	int hArray[8] = { 5, 99, 32, 4, 1, 12, 15, 8 };
	Heaparr t;
	t.heapSort(hArray, sizeof(hArray) / sizeof(hArray[0]));
	for (auto v : hArray)
		std::cout << v << ", ";
	std::cout << std::endl;
	system("pause");
	return 0;
}