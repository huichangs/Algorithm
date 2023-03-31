#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<int> pTime;
	vector<int> wait;
	
	int p, tmp, waitT = 0, answer = 0;
	cin >> p;
	
	for(int i = 0; i < p; i++){
		cin >> tmp;
		pTime.push_back(tmp);
	}
	
	sort(pTime.begin(), pTime.end());
	
	for(int i = 0; i < p; i++){
		waitT = waitT + pTime[i];
		wait.push_back(waitT);
	}
	
	for(int i = 0; i < p; i++){
		answer = answer + wait[i];
	}
	
	cout << answer;
	
	return 0;
}
