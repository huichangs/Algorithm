#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	string king, stone, tempKing;
	cin >> king >> stone;
	
	int n;
	cin >> n;
	
	string moveTable[n];
	
	for(int i = 0; i < n; i++){
		cin >> moveTable[i];
	}
	
	for(int i = 0; i < n; i++){
		tempKing = king;
		//king check
		if(moveTable[i] == "R"){
			if(king[0] + 1 > 'H'){
				continue;
			}
			tempKing[0] += 1;
		}else if(moveTable[i] == "L"){
			if(king[0] - 1 < 'A'){
				continue;
			}
			tempKing[0] -= 1;
		}else if(moveTable[i] == "B"){
			if(king[1] - 1 < '1'){
				continue;
			}
			tempKing[1] -= 1;
		}else if(moveTable[i] == "T"){
			if(king[1] + 1 > '8'){
				continue;
			}
			tempKing[1] += 1;
		}else if(moveTable[i] == "RT"){
			if(king[0] + 1 > 'H' || king[1] + 1 > '8'){
				continue;
			}
			tempKing[0] += 1;
			tempKing[1] += 1;
		}else if(moveTable[i] == "LT"){
			if(king[0] - 1 < 'A' || king[1] + 1 > '8'){
				continue;
			}
			tempKing[0] -= 1;
			tempKing[1] += 1;
		}else if(moveTable[i] == "RB"){
			if(king[0] + 1 > 'H' || king[1] - 1 < '1'){
				continue;
			}
			tempKing[0] += 1;
			tempKing[1] -= 1;
		}else if(moveTable[i] == "LB"){
			if(king[0] - 1 < 'A' || king[1] - 1 < '1'){
				continue;
			}
			tempKing[0] -= 1;
			tempKing[1] -= 1;
		}
		
		//stone check
		if(tempKing == stone){
			if(moveTable[i] == "R"){
			if(stone[0] + 1 > 'H'){
				continue;
			}
			stone[0] += 1;
			}else if(moveTable[i] == "L"){
				if(stone[0] - 1 < 'A'){
					continue;
				}
				stone[0] -= 1;
			}else if(moveTable[i] == "B"){
				if(stone[1] - 1 < '1'){
					continue;
				}
				stone[1] -= 1;
			}else if(moveTable[i] == "T"){
				if(stone[1] + 1 > '8'){
					continue;
				}
				stone[1] += 1;
			}else if(moveTable[i] == "RT"){
				if(stone[0] + 1 > 'H' || stone[1] + 1 > '8'){
					continue;
				}
				stone[0] += 1;
				stone[1] += 1;
			}else if(moveTable[i] == "LT"){
				if(stone[0] - 1 < 'A' || stone[1] + 1 > '8'){
					continue;
				}
				stone[0] -= 1;
				stone[1] += 1;
			}else if(moveTable[i] == "RB"){
				if(stone[0] + 1 > 'H' || stone[1] - 1 < '1'){
					continue;
				}
				stone[0] += 1;
				stone[1] -= 1;
			}else if(moveTable[i] == "LB"){
				if(stone[0] - 1 < 'A' || stone[1] - 1 < '1'){
					continue;
				}
				stone[0] -= 1;
				stone[1] -= 1;
			}
		}
		king = tempKing;
	}
	
	cout << king << endl;
	cout << stone << endl;
	
	return 0;
}
