#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool compare(string s1, string s2){
	if(s1.length() == s2.length()){
		return s1 < s2;
	}else{
		return s1.length() < s2.length();
	}
}

int main(){
	int n;
	cin >> n;
	
	string tmp;
	vector<string> str;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		str.push_back(tmp);	
	}
	
	sort(str.begin(), str.end(), compare);
	str.erase(unique(str.begin(), str.end()), str.end());
	
	for(int i = 0; i < str.size(); i++){
		cout << str.at(i) << '\n';
	}
	
	return 0;
}
