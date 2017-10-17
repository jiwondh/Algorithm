#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D;

int find(int cur, int curDistance, vector<vector<pair<int, int> > >& road){
    
    if(cur == D)
        return curDistance;
    if(cur>D)
        return 10000;
    
    int min = 10000;
    
    for(vector<pair<int, int> >::size_type i=0; i<road[cur].size(); i++){
        int to = road[cur][i].first;
        int distance =road[cur][i].second;
        int temp = find(to, curDistance+distance, road);
        if(min>temp) min = temp;
    }
    
    int temp = find(cur+1, curDistance+1, road);
    if(min>temp) min = temp;
    
    return min;
}

int main(){
    cin>>N>>D;
    
    vector<vector<pair<int, int> > > road(D);
    
    for(int i=0; i<N; i++){
        int from, to, distance;
        cin>>from>>to>>distance;
        road[from].push_back(make_pair(to, distance));
    }
    
    for(vector<vector<pair<int, int> > >::size_type i=0; i<road.size(); i++)
    {
        sort(road[i].begin(), road[i].end());
    }
    
    cout<<find(0, 0, road);
    
    return 0;
}
