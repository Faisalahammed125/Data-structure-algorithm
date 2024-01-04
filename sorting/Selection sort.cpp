#include<bits/stdc++.h>
using namespace std;

void selectionSort(int ar[], int n) {
	for (int step = 0; step < n - 1; step++) {
		int idx = step;
		for (int i = step + 1; i < n; i++) {
			///Use '<' for ascending & '>' for descending
			if (ar[i] < ar[idx]) {
				idx = i;
			}
		}
		swap(ar[step], ar[idx]);
	}
}
int main() {
	int n; cin >> n;
	int ar[n];
	for (int &x : ar)cin >> x;
	cout << "Before Sorting : ";
	for (int i = 0; i < n; i++)cout << ar[i] << " ";
	cout << endl;
	selectionSort(ar, n);
	cout << "After Sorting : ";
	for (int i = 0; i < n; i++)cout << ar[i] << " ";
	cout << endl;
}