#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;

void DFS(vector<vector<int> >& adj, vector<bool>& visited, int here){
    
    visited[here] = true;
    
    cout<<here<<" ";
    
    for(size_t i=0; i<adj[here].size(); i++){
        int there = adj[here][i];
        if(visited[there]==false){
            DFS(adj, visited, there);
        }
    }
}

void BFS(vector<vector<int> >& adj, int start){
    vector<int> distance(N+1, -1);
    distance[start] = 1;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int here = q.front();
        q.pop();
        
        cout<<here<<" ";
        
        for(size_t i=0; i<adj[here].size(); i++){
            int there = adj[here][i];
            if(distance[there]==-1){
                distance[there] = distance[here]+1;
                q.push(there);
            }
        }
    }
    cout<<endl;
}

int main(){
    cin>>N>>M>>V;
    
    vector<vector<int> > adj(N+1);
    
    for(int i=0; i<M; i++){
        int from, to;
        cin>>from>>to;
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    
    for(size_t i=0; i<adj.size(); i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<bool> visited(N+1, false);
    DFS(adj, visited, V);
    cout<<endl;
    
    BFS(adj, V);
    
    return 0;
}
