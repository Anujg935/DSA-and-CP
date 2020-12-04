#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

class Graph{
    int v;
    list<int> * adjList;
    public:
    Graph(int v){
        this->v = v;
        adjList = new list<int>[v];
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    void topologicalSortBFS(){
        int *indegree = new int[v];
        
        for(int i=0;i<v;i++){
            indegree[i] = 0;
        }

        for(int i=0;i<v;i++){
            for(auto nbr:adjList[i]){
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        cout <<"TopologicalSort BFS : ";
        while(!q.empty()){
            int node = q.front();
            cout << node<<" ";
            q.pop();
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }

    void dfs_helper(int src, bool *visited, list<int>&ordering){
		visited[src] = true;
		
		for(auto nbrs:adjList[src]){
			if(!visited[nbrs]){
				dfs_helper(nbrs, visited, ordering);
			}
		}
		
		ordering.push_front(src);
		
	}
	
	void topologicalSortDFS(){
		bool *visited = new bool[v];
		list<int> ordering;
		
		for(int i=0;i<v;i++){
			visited[i] =  false;
		}
		
		for(int i=0;i<v;i++){
			if(!visited[i]){
				dfs_helper(i, visited, ordering);
			}
		}
		cout <<"TopologicalSort DFS : ";
		for(auto i:ordering){
			cout << i<<" ";
		}
	}

    void topologicalSortBFS

};

using namespace std;
int main() {
    Graph g(6);

    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);

    //g.topologicalSortBFS();
    cout <<endl;
    g.topologicalSortDFS();
}
