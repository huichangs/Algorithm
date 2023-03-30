#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int valueTable(string r){
	if(r == "black"){
		return 0;	
	}else if(r == "brown"){
		return 1;
	}else if(r == "red"){
		return 2;
	}else if(r == "orange"){
		return 3;
	}else if(r == "yellow"){
		return 4;
	}else if(r == "green"){
		return 5;
	}else if(r == "blue"){
		return 6;
	}else if(r == "violet"){
		return 7;
	}else if(r == "grey"){
		return 8;
	}else if(r == "white"){
		return 9;
	}
	
}

int main(){
	string r1, r2, r3;
	long long answer = 0;
	cin >> r1 >> r2 >> r3;
	
	answer = (10 * valueTable(r1) + valueTable(r2)) * pow(10, valueTable(r3));
	
	cout << answer;
	
	return 0;
}
