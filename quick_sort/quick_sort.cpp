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

	while (i <= j)//langkah 10
	{
		//search for an element greater then pivot
		while ((arr[i] <= pivot) && (i <= high))//langkah 5
		{
			i++;//langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less then ofr equal to pivot
		while ((arr[j] > pivot) && (j >= low))//langkah 7
		{
			j--;//langkah 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j)//langkah 9
			//if the greater element is on the left of the element
		{
			//swap the element at index i with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the indx of the last element in the soeted list
	if (low < j)//langkah 11
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	q_short(low, j - 1);//langkah 12

	//sort the list on the left of pivot using quick sort
	q_short(j + 1, high);//langkah 13
}

void display() {
	cout << "\n--------------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "----------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	//sort the array using quick sort
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}