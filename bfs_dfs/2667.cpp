#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

#define endl '\n';
#define MAX 100

using namespace std;

int n;
int arr[MAX][MAX];
vector<int> v;
bool visited[MAX][MAX] = {0,};

void bfs(int a, int b, int size){
	int count = 1;
	queue<pair<int, int> > q;
	
	visited[a][b] = 1;
	q.push(make_pair(a, b));
	
	int x_move[4] = {-1, 1, 0, 0};
	int y_move[4] = {0, 0, -1, 1};
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];
			
			if((0 <= x_new && x_new < size) && (0 <= y_new && y_new < size) && !visited[x_new][y_new] && arr[x_new][y_new] == 1){
				visited[x_new][y_new] = 1;
				q.push(make_pair(x_new, y_new));
				count++;
			}
		}
	}
	
	v.push_back(count);
}

int main(){
	cin >> n;
	int count = 0;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < n; j++){
			arr[i][j] = tmp[j] - '0';
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 1 && visited[i][j] == 0){
				count++;
				bfs(i, j, n);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << count << endl;
	for(int i = 0; i < v.size(); i++){
		cout << v.at(i) << endl;
	}
	
	
	return 0;
}
