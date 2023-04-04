#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
	int n, tmp;
	cin >> n;
	vector<int> rope;
	vector<int> weight;
	
	for(int i = 0; i < n; i++){
		cin >> tmp;
		rope.push_back(tmp);
	}
	
	sort(rope.begin(), rope.end());
	
	for(int i = 0; i < n; i++){
		int tmp = rope[i] * (n-i);
		weight.push_back(tmp);
	}
	
	sort(weight.begin(), weight.end());
	cout << weight.back();
	
	return 0;
}
