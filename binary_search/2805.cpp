#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int num, int low, int high){
	int height;
	
	while(low <= high){
		int mid = (low + high) / 2;
		long long t_size = 0;
		
		for(int i = v.size() - 1; i >= 0; i--){
			if(v[i] <= mid){
				break;
			}
			
			t_size += v[i] - mid;
		}
		
		if(t_size == num){
			height = mid;
			return height;
		}
		if(t_size >= num){
			height = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	
	return height;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<int> tree;
	
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		tree.push_back(tmp);
	}
	
	sort(tree.begin(), tree.end());
	
	cout << binary_search(tree, m, 0, tree.back());
	
	return 0;
}
