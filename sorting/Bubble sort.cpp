#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int ar[], int n) {
	for (int step = 0; step < n - 1; step++) {
		for (int i = 1; i < n - step; i++) {
			///Use '<' for ascending & '>' for descending
			if (ar[i] > ar[i - 1]) {
				swap(ar[i], ar[i - 1]);
			}
		}
	}
}

int main() {
	int n; cin >> n;
	int ar[n];
	for (int &x : ar) cin >> x;
	cout << "Before Sorting : ";
	for (int i = 0; i < n; i++)cout << ar[i] << " ";
	cout << endl;
	bubbleSort(ar, n);
	cout << "After Sorting : ";
	for (int i = 0; i < n; i++)cout << ar[i] << " ";
	cout << endl;
}