#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<int> find[], bool visited[], int x){
    visited[x] = 1;
    cout << x << ' ';
    for(int i = 0; i < find[x - 1].size(); i++){
        if(visited[find[x - 1].at(i)] == 0){
            dfs(find, visited, find[x - 1].at(i));
        }
    }
}

void bfs(vector<int> find[], bool visited[], int x){
	visited[x] = 1;
	queue<int> q;
	q.push(x);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		cout << x << ' ';
		for(int i = 0; i < find[x - 1].size(); i++){
			int tmp = find[x - 1].at(i);
			if(visited[tmp] == 0){
				q.push(tmp);
				visited[tmp] = 1;
			}
		}
	}
	
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> find_d[n];
    bool visited_d[n + 1] = {};
    
    vector<int> find_b[n];
    bool visited_b[n + 1] = {};

    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        find_d[t1 - 1].push_back(t2);
        find_d[t2 - 1].push_back(t1);
        find_b[t1 - 1].push_back(t2);
        find_b[t2 - 1].push_back(t1);
    }
    
    for(int i = 0; i < n; i++){
    	sort(find_d[i].begin(), find_d[i].end());
	}
	
	for(int i = 0; i < n; i++){
    	sort(find_b[i].begin(), find_b[i].end());
	}

    dfs(find_d, visited_d, v);
    cout << '\n';
    bfs(find_b, visited_b, v);

    return 0;
}

