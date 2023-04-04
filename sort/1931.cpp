#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int n, end, start;
	
	vector<pair<int, int> > schedule;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> start >> end;
		schedule.push_back(pair<int, int>(end, start));
	}
	
	sort(schedule.begin(), schedule.end());
	
	int time = schedule[0].first;
	int count = 1;
	for(int i = 1; i < n; i++){
		if(time <= schedule[i].second){
			count++;
			time = schedule[i].first;
		}
	}
	
	cout << count;
	return 0;
}
