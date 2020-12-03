#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
        int v;
        unordered_map<int, vector<int>> adjList;

        graph(int v){
            this->v = v;
        }
        void addEdge(int x, int y, bool bidir){
            adjList[x].push_back(y);
            if(bidir){
                adjList[y].push_back(x);
            }
        } 

        void dfs_helper(int src, bool *visited){
            cout << src <<" ";
            visited[src] = true;
            for(auto element: adjList[src]){
                if(!visited[element])
                    dfs_helper(element, visited);
            }
        }
        void dfs(int src){
            bool *visited = new bool[v];
            for(int i=0;i<v;i++){
                visited[i] = false;
            }

            dfs_helper(src, visited);
            cout <<endl;
        }

        void bfs(int src){
            bool *visited = new bool[v];
            for(int i=0;i<v;i++){
                visited[i] = false;
            }
            
            queue<int> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                int element = q.front();
                q.pop();
                cout << element<<" ";

                for(auto i: adjList[element]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            cout << endl;
        }

        bool dfs_helper_cycle(int src, bool *visited){
           
            visited[src] = true;
            for(auto element: adjList[src]){
                
                if(!visited[element])
                    dfs_helper(element, visited);
                else
                    return true;
            }
            return false;
        }
        void undirected_cycle(){
            int src = 0;
            bool *visited = new bool[v];
            for(int i=0;i<v;i++){
                visited[i] = false;
            }

            bool result = dfs_helper_cycle(src, visited);

            if(result)
                cout <<"Cycle exist" <<endl;
            else
                cout <<"No cycle exist" <<endl;

        }
        //0 -not visited, 1- visited and in current stack, 2- visited but not in cureent stack
        bool directed_cyle_dfs(int src, int  *visited){
            visited[src] = 1;

            for(auto element : adjList[src]){
                if(visited[element] == 1){
                    return true;
                }
                bool cycle_mila = directed_cyle_dfs(element, visited);
                if(cycle_mila)
                    return true;
                
            }

            visited[src] = 2;
            return false;
        }
        void directed_cycle_detect(){
            int src = 0;
            int *visited = new int[v];
            for(int i=0;i<v;i++){
                visited[i] = 0;
            }

            bool result = directed_cyle_dfs(src, visited);

            if(result)
                cout <<"Cycle exist" <<endl;
            else
                cout <<"No cycle exist" <<endl;

        }
        void dfs_helper_topological(int src, bool *visited, list<int> &ordering){
            visited[src] = true;
            for(auto element: adjList[src]){
                if(!visited[element])
                    dfs_helper_topological(element, visited, ordering);
            }
            ordering.push_front(src);
        }
        void topological_sort(){
            bool *visited = new bool[v];
            for(int i=0;i<v;i++){
                visited[i] = false;
            }
            list<int> ordering;
            
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    dfs_helper_topological(i, visited, ordering);
                }
            }
            cout << "Topological Sort:- ";
            for(auto i: ordering){
                cout << i << " ";
            }
            cout <<endl;
        }
};
int main() {
    /*
    graph g(6);
    g.addEdge(0, 1, false);
    g.addEdge(1,2, false);
    g.addEdge(2,3, false);
    //g.addEdge(3,0, true);
    g.addEdge(3,4, false);
    //g.addEdge(4,2, false);

    cout << "DFS of graph is :- ";
    g.dfs(0);

    cout << "BFS of graph is :- ";
    g.bfs(0);
    */
    //g.undirected_cycle();
    //g.directed_cycle_detect();

    

    graph g(6);
    g.addEdge(5, 0, false);
    g.addEdge(4, 0, false);
    g.addEdge(5, 2, false);
    g.addEdge(4, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 1, false);

    g.topological_sort();
}
