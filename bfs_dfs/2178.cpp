#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int n, m;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

queue<pair<int, int> > q;

void bfs(int start_x, int start_y){
	visited[start_x][start_y] = 1;
	q.push(make_pair(start_x, start_y));
	dist[start_x][start_y]++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x_new = x + x_dir[i];
			int y_new = y + y_dir[i];
			
			if((0 <= x_new && x_new < n) && (0 <= y_new && y_new < m) && !visited[x_new][y_new] && maze[x_new][y_new] == 1){
				visited[x_new][y_new] = 1;
				q.push(make_pair(x_new, y_new));
				dist[x_new][y_new] = dist[x][y] + 1;
			}
		}
	}
}


int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < m; j++){
			maze[i][j] = tmp[j] - '0';
		}
	}
	
	bfs(0, 0);
	
	cout << dist[n - 1][m - 1];
}
