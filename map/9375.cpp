#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		map<string, int> m;
		for(int i = 0; i < n; i++){
			string c_name, c_type;
			cin >> c_name >> c_type;
			m[c_type]++;
		}
		int answer = 1;
		for(map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++){
			answer *= (iter->second + 1);
		}
		
		m.clear();
		cout << answer - 1 << '\n';
	}
	
	
	return 0;
}
