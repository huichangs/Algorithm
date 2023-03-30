#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	string str[n];
	
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	
	string answer = str[0];
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < answer.length(); j++){
			if(str[0][j] != str[i][j]){
				answer[j] = '?';
			}
		}
	}
	
	cout << answer;
	
	return 0;
}
