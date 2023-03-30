#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int t, a, b;
	int answer = 1;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> a >> b;
	
		for(int j = 0; j < b; j++){
			answer = (answer % 10) * a;
		}
		
		answer = answer % 10;
		if(answer == 0){
			answer = 10;
		}
		
		cout << answer << endl;
		answer = 1;
	}
	
	
	return 0;
}
