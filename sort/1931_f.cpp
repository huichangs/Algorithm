#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool startCompare(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){
		return a.second < b.second;
	}else{
		return a.first < b.first;
	}
}

bool endCompare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int find_p(vector<pair<int, int> > v, int a){
	for(int i = 0; i < v.size(); i++){
		if(v.at(i).first >= a){
			return i;
		}	
 	}
 	
 	return v.size();
}

int main(){
	int n, a, b;
	cin >> n;
	int count = 1;
	int room = 0;
	
	vector<pair<int, int> > start_r;
	vector<pair<int, int> > end_r;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		start_r.push_back(pair<int, int>(a, b));
		end_r.push_back(pair<int, int>(a, b));
	}
	
	sort(start_r.begin(), start_r.end(), startCompare);
	sort(end_r.begin(), end_r.end(), endCompare);
	
	for(int i = 0; i < n; i++){
		if(end_r.at(i).second > start_r.at(n - 1).first){
			break;
		}
		int start_p = find_p(start_r, end_r.at(i).second);
		i = find_p(end_r, start_r.at(start_p).first);
		count++;
	}
	
	cout << count;
	
	return 0;
}
