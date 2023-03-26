#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, m;
	int answer = 0;

	cin >> n;
	cin >> m;
	
	if(n < 3 || m < 3){
		cout << -1;
		return 0;
	}
	
	char arr1[n][m + 1];
	char arr2[n][m + 1];
	
	for(int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin >> arr2[i];
	}
	
	if(n < 3 || m < 3){
		cout << -1;
		return 0;
	}
	
	for(int i = 0; i <= n - 3; i++){
		for(int j = 0; j <= m - 3; j++){
			if(arr1[i][j] != arr2[i][j]){
				answer++;
				for(int k = i; k <= i + 2; k++){
					for(int l = j; l <= j + 2; l++){
						if(arr1[k][l] == '1'){
							arr1[k][l] = '0';
						}else{
							arr1[k][l] = '1';
						}
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr1[i][j] != arr2[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}
