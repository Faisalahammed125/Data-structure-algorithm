#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int l, int r) {
	int pivot = arr[l];
	int i = l, j = r;
	while (i < j) {
		while (arr[i] <= pivot)i++;
		while (arr[j] > pivot)j--;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void quick_sort(int *arr, int l, int r) {
	if (l < r) {
		int pos = partition(arr, l, r);
		quick_sort(arr, l, pos);
		quick_sort(arr, pos + 1, r);
	}
}

void display(int *arr, int n) {
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int &x : arr)cin >> x;
	cout << "Display the number before sorting" << endl;
	display(arr, n);
	quick_sort(arr, 0, n-1);
	cout << "Display the number after sorting" << endl;
	display(arr, n);
	return 0;
}

