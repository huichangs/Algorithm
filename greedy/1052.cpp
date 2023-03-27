// 1. 한번에 옮길수 있는게 없으면 -1(근데 1개로는 만들수있으므로 K < 1)
// 2. k가 N보다 크면 그냥 다 옮김 : 0출력
// 3. 일단 가지고 있는거(N) 다 합쳐서 몇개가 되는지
// 4. 3에서 한게 K보다 크면 1씩 추가해가면서 K보다 작을때가 될때까지 3을 반복
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
