#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<string> p;
	map<string, int> hidden;
	
	for(int i = 0; i < n + m; i++){
		string tmp;
		cin >> tmp;
		hidden[tmp]++;
		if(hidden[tmp] == 2){
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
