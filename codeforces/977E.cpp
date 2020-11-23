#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;

void dfs(int src, bool *visited, vector<int> &currVisited){
    visited[src] = true;
    currVisited.push_back(src);
    for(auto i: graph[src]){
        if(!visited[i]){
            dfs(i, visited, currVisited);
        }
    }
}

bool degree2(vector<int> &v){
    for(auto i : v){
        if(graph[i].size()!=2){
            return false;
        }
    }
    return true;
}

int solve(int v, int e){
    bool *visited = new bool[v+1];
    memset(visited, false, sizeof visited);
    int ans = 0;
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            // v for getting the nodes which are visited
            vector<int> v;
            dfs(i,visited, v);
            // check if all the nodes visited are having degree 2
            // if all the nodes in a connected component are having degree 2 than that is case of cycle 
            if(degree2(v)){
                ans +=1;
            }
        }
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        graph[i];
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << solve(n, m)<<endl;
}
