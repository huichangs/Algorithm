#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(vector<int> v[], bool visited[], int a){
	visited[a] = 1;
	queue<int> q;
	q.push(a);
	int count = 0;
	
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		
		for(int i = 0; i < v[temp].size(); i++){
			int tmp = v[temp].at(i);
			if(!visited[tmp]){
				count++;
				visited[tmp] = 1;
				q.push(tmp);
			}
		}
	}
	
	return count;
}

int main(){
	int com, net;
	cin >> com >> net;
	int count;
	
	vector<int> con[com + 1];
	bool visited[com + 1] = {0,};
	
	for(int i = 1; i <= net; i++){
		int t1, t2;
		cin >> t1 >> t2;
		
		con[t1].push_back(t2);
		con[t2].push_back(t1);
	}
	
	cout << bfs(con, visited, 1);
	return 0;
}
