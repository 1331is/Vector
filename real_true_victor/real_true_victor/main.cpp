#include <iostream>
using namespace std;

class victor
{
public:
	victor();
	~victor();
	void push_front(int element) {
		size++;
		if (capasity == 0) {
			capasity++;
		}
		int* newarr = new int[size];
		if (size > capasity) {
			capasity *= 2;
		}
		if (size == 1) {
			newarr[0] = element;
			arr = newarr;
			return;
		}
		for (int i = 0; i < size; i++) {
			newarr[i+1] = arr[i];
		}
		newarr[0] = element;
		delete[] arr;
		arr = newarr;
	}
	void push_back(int element) {
	size++;
	if (capasity == 0) {
		capasity++;
	}
	int *newarr = new int[size];
	if (size > capasity) {
		capasity *= 2;
	}
	if (size == 1) {
		newarr[0] = element;
		arr = newarr;
		return;
	}
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size - 1] = element;
	delete[] arr;
	arr = newarr;
	}
	void pop_front() {
		size--;
		int* newarr = new int[size];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		arr = newarr;

	}
	void pop_back() {
		size--;
		int* newarr = new int[size];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i+1];
		}
		arr = newarr;
	}
	int get_size() {
		return size;
	}
	int get_capasity() {
		return capasity;
	}
	void reserve() {
		capasity = size;
	}
	int get_by_value(int element) {
		for (int i = 0;i < size; i++) {
			if (arr[i] == element) {
				return i;
			}
		}
		return 0;
	}
	int get_by_index(int index) {
		if (size > index) return arr[index];
		return 0;
	}
	void print_all() {
		
		for (int i = 0; i < size; i++) {
			cout << arr[i] << "\t";
			cout << arr + i << "\n";
		}
	}

private:
	int* arr;
	unsigned int size = 0;
	unsigned int capasity = 0;
};

victor::victor()
{
}

victor::~victor()
{
}

int main() {
	victor a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_front(1);
	a.push_front(0);
	a.pop_front();
	a.pop_back();
	cout << "Саиз " << a.get_size() << "\n";
	cout << "Капсулити " << a.get_capasity() << "\n";
	cout << "Индекс от Валуев " << a.get_by_value(3) << "\n";
	cout << "Валуев от индекса " << a.get_by_index(3) << "\n";
	a.print_all();
}