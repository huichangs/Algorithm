#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define endl '\n'

using namespace std;

bool compare(pair<int, int> n1, pair<int, int> n2){
	if(n1.first == n2.first){
		return n1.second < n2.second;
	}else{
		return n1.first < n2.first;
	}
	
}

int main(){
	int n, a, b;
	cin >> n;
	
	vector<pair<int, int> > arr;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr.push_back(pair<int, int>(a, b));
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i].first << " " << arr[i].second << endl;
	}
	
	return 0;
}
