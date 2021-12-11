#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int r) {
	int nl = mid - l + 1;
	int nr = r - mid;
	int k = l;
	int left[nl + 1], right[nr + 1];
	int i = 0, j = 0;
	while (l <= mid)left[i++] = arr[l++];
	mid++;
	while (mid <= r)right[j++] = arr[mid++];
	i = 0, j = 0;
	while (i < nl && j < nr) {
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < nl)arr[k++] = left[i++];
	while (j < nr)arr[k++] = right[j++];
}

void merge_sort(int *arr, int l, int r) {
	if (l >= r)return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	merge(arr, l, mid, r);
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
	merge_sort(arr, 0, n);
	cout << "Display the number after sorting" << endl;
	display(arr, n);
	return 0;
}

