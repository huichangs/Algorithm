#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lower_bound(int key, int a[], int n){
	int low = 0;
	int high = n;
	
	while(low < high){
		int mid = (low + high) / 2;
		if(a[mid] >= key){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	
	return low;
}

int upper_bound(int key, int a[], int n){
	int low = 0;
	int high = n;
	
	while(low < high){
		int mid = (low + high) / 2;
		if(a[mid] > key){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	
	return low;
}

int main(){
	int n, m;
	
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cin >> m;
	int b[m];
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	
	sort(a, a + n);
	
	for(int i = 0; i < m; i++){
		cout << upper_bound(b[i], a, n) - lower_bound(b[i], a, n) << ' ';
	}
	
	return 0;
}
