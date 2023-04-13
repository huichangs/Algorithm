#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int tmp_graph[n][m];
	int dist[n][m];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int tmp;
			scanf("%1d", &tmp);
			tmp_graph[i][j] = tmp;
		}
	}
	
	bool visited[n][m] = {};
	vector<pair<int, int> > graph[n][m];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int op = 0; op < 4; op++){
				if(i + 1 != n){
					if(tmp_graph[i + 1][j] == 1){
					graph[i][j].push_back(make_pair(i + 1, j));
					}
				}
				
				if(j + 1 != m){
					if(tmp_graph[i][j + 1] == 1){
						graph[i][j].push_back(make_pair(i, j + 1));
					}
				}
				
				if(i != 0){
					if(tmp_graph[i - 1][j] == 1){
						graph[i][j].push_back(make_pair(i - 1, j));
					}
				}
				
				if(j != 0){
					if(tmp_graph[i][j - 1] == 1){
						graph[i][j].push_back(make_pair(i, j - 1));
					}
				}
			}	
		}
	}
	
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	dist[0][0] = 1;
	
	while(!q.empty()){
		pair<int, int> x = q.front();
		int old_x = q.front().first;
		int old_y = q.front().second;
//		cout << "move : " << x.first << ',' << x.second << '\n';
		q.pop();
		
		for(vector<pair<int, int> >::iterator it = graph[x.first][x.second].begin(); it != graph[x.first][x.second].end(); it++){
			if(visited[it->first][it->second] == 0){
				q.push(make_pair(it->first, it->second));
				visited[it->first][it->second] = 1;
				dist[it->first][it->second] = dist[old_x][old_y] + 1;
			}
		}
	}
	
	cout<< dist[n - 1][m - 1];
	
	return 0;
}
