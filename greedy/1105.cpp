// 1. 두 수가 자릿수가 다르다면 8이 들어갈 이유가 없음. 0 끝.
// 2. 자릿수가 같다면 제일 큰 자리수부터 8인지, 각 자리수가 같은지를 비교함 ex)8088 8608
#include<iostream>
#include<string>

using namespace std;

int main(){
	string eight1, eight2;
	int answer = 0;
	
	cin >> eight1 >> eight2;
	
	int size = min(eight1.size(), eight2.size());
	
	if(eight1.size() != eight2.size()){
		cout << 0;
		return 0;
	}
	
	for(int i = 0; i < size; i++){
		if(eight1[i] == '8' && eight1[i] == eight2[i]){
			answer++;
		}else if(eight1[i] != eight2[i]){
			break;
		}
	}
	
	cout << answer;
	
	return 0;
}
