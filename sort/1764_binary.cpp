#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
	int n, m;
	string tmp;
	cin >> n >> m;
	
	vector<string> p;
	vector<string> hidden;
	
	for(int i = 0; i < n; i++){
		cin >> tmp;
		hidden.push_back(tmp);
	}
	
	sort(hidden.begin(), hidden.end());
	for(int i = 0; i < m; i++){
		cin >> tmp;
		if(binary_search(hidden.begin(), hidden.end(), tmp)){
			p.push_back(tmp);
		}
	}
	
	cout << p.size() << '\n';
	sort(p.begin(), p.end());
	for(int i = 0; i < p.size(); i++){
		cout << p[i] << '\n';
	}
	return 0;
}
