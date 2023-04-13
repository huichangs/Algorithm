#include<iostream>
#include<vector>
#include<algorithm>

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

int main(){
	int n, m;
	int count = 0;
	cin >> n >> m;
	
	vector<int> find[n];
	bool visited[n + 1];
	
	for(int i = 0; i < m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		find[t1 - 1].push_back(t2);
        find[t2 - 1].push_back(t1);
	}
	
	for(int i = 0; i < n; i++){
		sort(find[i].begin(), find[i].end());
	}
	
	dfs(find, visited, find[0].at(0));
	
	for(int i = 0; i < n + 1; i++){
		if(visited[i] == 1){
			cout << i;
			count++;
		}
	}
	cout << count;
	
	return 0;
}
