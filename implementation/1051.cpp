#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	char sqr[n][m + 1];
	int start = min(n, m);
	
	for(int i = 0; i < n; i++){
		cin >> sqr[i];
	}
	
	while(start >= 1){
		for(int i = 0; i <= n - start; i++){
			for(int j = 0; j <= m - start; j++){
				if(sqr[i][j] == sqr[i + start - 1][j] && sqr[i][j] == sqr[i + start - 1][j + start - 1] && sqr[i][j] == sqr[i][j + start - 1]){
					goto end;
				}
			}
		}
		start--;
	}
	
	cout << start << endl;
	
	end:
	cout << start * start;
	
	return 0;
}
