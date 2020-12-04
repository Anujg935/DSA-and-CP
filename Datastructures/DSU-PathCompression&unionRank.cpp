#include <iostream>
#include <list>
using namespace std;

class Graph{
    int v;
    list<pair<int, int>> l;

    public:
         Graph(int V){
             this->v = V;
         }

         void adEdge(int u, int v){
             l.push_back(make_pair(u,v));
         }
         //Find with path compression optimization
         //on avg O(logN)
         int findSet(int i, int parent[]){
             if(parent[i]==-1){
                 return i;
             }
             // in this optimiation directly poining to the end node 
             // like if 1->2->3->4 then now 1,2and all will point directly to 4
             return parent[i] = findSet(parent[i], parent);
         }

         //Union O(V)
         //Union Rank optimization
         void Union_set(int x, int y, int parent[], int rank[]){
             int s1 = findSet(x, parent);
             int s2 = findSet(y, parent);

             if(s1!=s2){
                 if(rank[s1]>=rank[s2]){
                     parent[s2] = s1;
                     rank[s1] += rank[s2];
                 }
                 else{
                     parent[s1] = s2;
                     rank[s2] +=rank[s1];
                 }
             }
         }
         bool contains_cycle(){
             //DSU-Disjoint Set Union to check if graph contains cycle or not
             // By using path compressionand union rank optimization
             // time complexity reduces to O(1) on an avg
             int *parent = new int[v];
             int *rank = new int[v];
             for(int i=0;i<v;i++){
                 parent[i] = -1;
                 rank[i] = 1;
             }

             // iterate over the edge list
             for(auto edge : l){
                 int i = edge.first;
                 int j = edge.second;

                 int s1 = findSet(i, parent);
                 int s2 = findSet(j, parent);
                 if(s1!=s2){
                     Union_set(s1, s2, parent, rank);
                 }
                 else{
                     cout << "cycle detected "<<endl;
                     return true;
                 }
             }

             delete []parent;
             cout << "cycle not detected"<<endl;
             return false;
         }
};
int main() {
    Graph g(4);
    g.adEdge(0,1);
    g.adEdge(1,2);
    g.adEdge(2,3);
    g.adEdge(0,3);

    g.contains_cycle();
}
