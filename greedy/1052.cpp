#include<iostream>

using namespace std;

int main(){
	int N, K;
	int count = 0;
	
	cin >> N;
	cin >> K;
	
	if(K < 1){
		cout << -1;
		return 0;
	}
	
	if(N <= K){
		cout << 0;
		return 0;
	}
	
	while(1){
		int temp = N;
		int waterNum = 0;
		
		while(temp > 0){
			if(temp % 2 == 1){
				waterNum++;
			}
			temp /= 2;
		}
		
		if(waterNum <= K){
			break;
		}else{
			N++;
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}
