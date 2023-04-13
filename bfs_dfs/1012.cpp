#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50
#define endl '\n'

using namespace std;

int arr[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};

void bfs(int a, int b, int m, int n){
	queue<pair<int, int> > q;
	visited[a][b] = 1;
	q.push(make_pair(a, b));
	
	int x_move[] = {-1, 1, 0, 0};
	int y_move[] = {0, 0, -1, 1};
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];
			
			if(x_new >= 0 && y_new >= 0 && x_new < m && y_new < n && !visited[x_new][y_new] && arr[x_new][y_new] == 1){
				visited[x_new][y_new] = 1;
				q.push(make_pair(x_new, y_new));
			}
		}
	}
	
}

int main(){
	int t, m, n, k;
	int count;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> m >> n >> k;
		
		//initialize
		for(int a = 0; a < m; a++){
            for(int b = 0; b < n; b++){
                arr[a][b] = 0;
                visited[a][b] = 0;
            }
        }
		count = 0;
		
		for(int j = 0; j < k; j++){
			int t1, t2;
			cin >> t1 >> t2;
			arr[t1][t2] = 1;
		}
		
		for(int a = 0; a < m; a++){
			for(int b = 0; b < n; b++){
				if(arr[a][b] == 1 && visited[a][b] == 0){
					count++;
					bfs(a, b, m, n);
				}
			}
		}
		
		cout << count << endl;
	}
	
	
	return 0;
}
