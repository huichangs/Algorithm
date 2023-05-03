#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int lan[n];
	for(int i = 0; i < n; i++){
		cin >> lan[i];
	}
	
	sort(lan, lan + n);
	
	int low = 0;
	int high = lan[n - 1];
	int ans;
	
	while(low <= high){
		int mid = (low + high) / 2;
		int count = 0;
		
		for(int i = 0; i < n; i++){
			count += lan[i] / mid;
		}
		
		if(count >= m){
			low = mid + 1;
			if(ans < mid){
				ans = mid;
			}
		}else{
			high = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}
