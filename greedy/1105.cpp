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
