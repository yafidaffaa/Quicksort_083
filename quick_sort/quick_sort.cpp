#include <iostream>
using namespace std;

//array of integers to hold value
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movment
int n;

void input() {
	while (true) 
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMasukan panjang array adalah 0" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++) 
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swap the elemet at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)//langkah 1
		return;

	//partition  the list into two parts:
	//one containning elements less that or equal to pivot
	//outher containning elements greather then  pivot

	pivot = arr[low];//langkah 2

	i = low + 1;//langkah 3
	j = high;//langkah 4

	
}