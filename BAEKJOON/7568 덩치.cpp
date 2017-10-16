#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin>>N;
    
    vector<pair<int, int> > body(N), temp;
    map<pair<int, int>, int> rank;
    
    for(int i=0; i<N; i++){
        int weight, height;
        cin>>weight>>height;
        
        pair<int, int> frame = make_pair(weight, height);
        
        body[i] = frame;
        rank.insert(make_pair(frame, 0));
    }
    
    temp = body;
    
    sort(temp.begin(), temp.end());
    
    for(int i=0; i<N; i++){
        int cnt = 0;
        if(i!=N-1){
            for(int j=i+1; j<N; j++){
                if(temp[i].first==temp[j].first) continue;
                
                if(temp[i].second<temp[j].second){
                    cnt++;
                }
            }
        }
        rank[temp[i]] = cnt+1;
    }
    
    for(int i=0; i<N; i++){
        cout<<rank[body[i]]<<" ";
    }
    
    return 0;
}
