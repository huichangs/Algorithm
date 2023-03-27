#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, m;
	int answer = 0;

	cin >> n;
	cin >> m;
	
	char arr1[n][m + 1];
	char arr2[n][m + 1];
	
	for(int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin >> arr2[i];
	}
	
	if(n < 3 || m < 3){
		goto check;
	}
	
	for(int i = 0; i < n - 2; i++){
		for(int j = 0; j < m - 2; j++){
			if(arr1[i][j] != arr2[i][j]){
				for(int k = i; k < i + 3; k++){
					for(int l = j; l < j + 3; l++){
						if(arr1[k][l] == '1'){
							arr1[k][l] = '0';
						}else{
							arr1[k][l] = '1';
						}
					}
				}
				answer++;
			}
		}
	}
	
	check:
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
