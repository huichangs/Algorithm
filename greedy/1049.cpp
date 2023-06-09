//1. 행 중에서 제일 작은 거 찾기 (set, one)따 로 
//2. 세트랑 낱개(N / 6) * set + (N % 6) * one, 낱개로만N * one, 세트로만 (N / 6 + 1) * set

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, M;
	int set = 1000, one = 1000;
	int result;
	
	cin >> N;
	cin >> M;
	
	for(int i = 0; i < M; i++){
		int tSet, tOne;
		cin >> tSet;
		cin >> tOne;
		
		set = min(set, tSet);
		one = min(one, tOne);
	}
	
	result = min((N / 6) * set + (N % 6) * one, N * one);
	result = min(result, (N / 6 + 1) * set);

	cout << result << endl;
	
	return 0;
}
