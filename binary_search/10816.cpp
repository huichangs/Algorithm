#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	map<int, int> card;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		card[tmp]++;
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		int tmp;
		cin >> tmp;
		cout << card[tmp] << ' ';
	}
	
	return 0;
}
