#include<iostream>
#include<algorithm>

using namespace std;

//void quickSort(int* data, int start, int end){
//	if(start >= end){
//		return;
//	}
//	
//	int key = start;
//	int i = start + 1;
//	int j = end;
//	int temp;
//	
//	while(i <= j){
//		while(i <= end && data[i] <= data[key]){
//			i++;
//		}
//		while(j > start && data[j] >= data[key]){
//			j--;
//		}
//		
//		if(i > j){
//			temp = data[j];
//			data[j] = data[key];
//			data[key] = temp;
//		}else{
//			temp = data[i];
//			data[i] = data[j];
//			data[j] = temp;
//		}
//	}
//	
//	quickSort(data, start, j - 1);
//	quickSort(data, j + 1, end);
//}

int main(){
	int n, tmp;
	cin >> n;
	
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << '\n';
	}
	
	return 0;
}
