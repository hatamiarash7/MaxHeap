#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> nodes;
	void my_swap(vector<int>&, int, int);
	int find_index(int);
public:
	Heap();
	vector<int> getHeap();
	void insert(int);
	int top();
	void pop_at(int);
	void pop(int);
	bool search(int);
	void show_items();
}myHeap;

Heap::Heap() {
	nodes.push_back(0); // default root
}

vector<int> Heap::getHeap() {
	// return every value (except first : default root)
	return vector<int>(nodes.begin() + 1, nodes.end());
}

void Heap::insert(int value) {
	bool done = false;
	// new node will be inserted at the size of the vector ( end )
	unsigned long currentLoc = nodes.size();
	// Add value to end of vector
	nodes.push_back(value);
	// move up value, if need
	while (!done)
	{
		// not the root node and Value greater than parent
		if (currentLoc > 1 && nodes[currentLoc] > nodes[currentLoc / 2])
		{
			swap(nodes[currentLoc], nodes[currentLoc / 2]);
			currentLoc /= 2;
		}
		else
			done = true;
	}
}

int Heap::top() {
	return nodes[1];
}

void Heap::pop_at(int index) {
	bool done = false;
	unsigned long currentLoc = index;          // current location of item in vector
	swap(nodes[currentLoc], nodes.back());     // first and last item swaped
	nodes.pop_back();                          // remove last element

	while (!done)
	{
		// possible children location is within the heap and one of the children is greater
		if (2 * currentLoc + 1 < nodes.size() &&            
			(nodes[currentLoc] < nodes[2 * currentLoc] ||   
				nodes[currentLoc] < nodes[2 * currentLoc + 1]))
		{
			// Left child is greater than right
			if (nodes[2 * currentLoc] > nodes[2 * currentLoc + 1])
			{
				swap(nodes[currentLoc], nodes[2 * currentLoc]);
				currentLoc = 2 * currentLoc;
			}
			// Right child is greater than left
			else   
			{
				swap(nodes[currentLoc], nodes[2 * currentLoc + 1]);
				currentLoc = 2 * currentLoc + 1;
			}
		}
		else
			done = true;
	}
}

int Heap::find_index(int value) {
	for (int i = 1; i < nodes.size(); i++)
		if (nodes[i] == value)
			// return index of curent item
			return i;
	return -1;
}

void Heap::pop(int value) {
	// find index first
	int index = find_index(value);
	if (index == -1) return; // not found
	pop_at(index);
}

bool Heap::search(int value) {
	for (int i = 1; i < nodes.size(); i++)
		if (nodes[i] == value)
			return true;
	return false;
}

void Heap::my_swap(vector<int> & data, int i, int j)
{
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void Heap::show_items() {
	vector<int> temp = nodes;

	int length = temp.size();
	// bubble sort
	for (int i = 0; i < length; ++i)
	{
		bool swapped = false;
		for (int j = 0; j < length - (i + 1); ++j)
		{
			if (temp[j] > temp[j + 1])
			{
				my_swap(temp, j, j + 1);
				swapped = true;
			}
		}

		if (!swapped) break;
	}

	cout << "\n Heap : ";
	// print reverse
	for (int i = length - 1; i > 0; i--)
		cout << temp[i] << " ";
	cout << endl;
}

int menu() {
	system("cls");
	cout << "\n 1. Show Heap\n";
	cout << "\n 2. Insert Item\n";
	cout << "\n 3. Remove Item\n";
	cout << "\n 4. Sort And Show\n";
	cout << "\n 5. Remove Root\n";
	cout << "\n 6. Search An Item\n";
	cout << "\n 7. Exit\n\n";
	cout << "\n Wich One ? ";
	int op;
	cin >> op;
	system("cls");
	return op;
}

int main() {
	while (true) {
		switch (menu()) {
		case 1: {
			cout << "\n Heap : ";
			for (auto& x : myHeap.getHeap())
				cout << x << " ";
			break;
		}
		case 2: {
			int item;
			cout << "\n Enter Number : ";
			cin >> item;
			myHeap.insert(item);
			break;
		}
		case 3: {
			int item;
			cout << "\n Enter Number : ";
			cin >> item;
			myHeap.pop(item);
			cout << "\n " << item << " Removed !";
			break;
		}
		case 4: {
			myHeap.show_items();
			break;
		}
		case 5: {
			myHeap.pop_at(1);
			cout << "\n Root Removed !";
			break;
		}
		case 6: {
			int item;
			cout << "\n Enter Number : ";
			cin >> item;
			cout << "\n " << item;
			myHeap.search(item) ? cout << " Exists !!" : cout << " Not Exists !!";
			break;
		}
		case 7: {
			exit(1);
			break;
		}
		}
		cout << "\n\n ";
		system("pause");
	}
}