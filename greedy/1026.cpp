#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N;
	int temp;
	int answer = 0;
	cin >> N;
	
	vector<int> a;
	vector<int> b;
	
	for(int i = 0; i < N; i++){
		cin >> temp;
		a.push_back(temp);
	}
	for(int i = 0; i < N; i++){
		cin >> temp;
		b.push_back(temp);
	}
	
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	
	for(int i = 0; i < N; i++){
		answer += a.at(i) * b.at(i);
	}
	
	cout << answer << endl;
	
	return 0;
	
}
