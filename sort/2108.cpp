#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return a.first < b.first;
	}else{
		return a.second > b.second;
	}
}

int avr(vector<int> v){
	double answer = 0;
	for(int i = 0; i < v.size(); i++){
		answer += v.at(i);
	}
	return round(answer / v.size());
}

int mid(vector<int> v){
	sort(v.begin(), v.end());
	int mid_n = (v.size() / 2);
	return v.at(mid_n);
}

int mode (vector<int> v){
	if(v.size() == 1){
		return v.at(0);
	}

	vector<pair<int, int> > m;
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		if(i == 0){
			m.push_back(make_pair(v.at(i), 0));
			continue;
		}
		
		if(m.back().first == v.at(i)){
			m.back().second++;
		}else{
			m.push_back(make_pair(v.at(i), 0));
		}
	}
	
	sort(m.begin(), m.end(), compare);
	
	if(m.at(0).second == m.at(1).second){
		return m.at(1).first;
	}else{
		return m.at(0).first;
	}
}

int range(vector<int> v){
	sort(v.begin(), v.end());
	return v.back() - v.front();
}

int main(){
	int n, tmp;
	cin >> n;
	
	vector<int> num;
	
	for(int i = 0; i < n; i++){
		cin >> tmp;
		num.push_back(tmp);
	}
	
	cout << avr(num) << '\n' << mid(num) << '\n' << mode(num) << '\n' << range(num) << '\n';
	
	
	return 0;
}
