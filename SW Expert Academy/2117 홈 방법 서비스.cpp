#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;

//동 서 남 북
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool isOutside(int y, int x){
    if(y>N-1||x>N-1||y<0||x<0){
        return true;
    }else{
        return false;
    }
}

int BFS(vector<vector<int> >& houseInfo, int hereY, int hereX){
    
    vector<vector<int> > distance(N, vector<int>(N, -1));
    vector<int> moneyInfo(N*3, 0);
    
    queue<pair<int, int> > q;
    q.push(make_pair(hereY, hereX));
    
    distance[hereY][hereX] = 1;
    
    while(!q.empty()){
        pair<int, int> here = q.front();
        q.pop();
        int K = distance[here.first][here.second];
        
        if(houseInfo[here.first][here.second]==1){
            moneyInfo[K] = moneyInfo[K] + M;
        }
        
        for(int i=0; i<4; i++){
            int thereY = here.first+dy[i];
            int thereX = here.second+dx[i];
            if(!isOutside(thereY, thereX) && distance[thereY][thereX]==-1){
                q.push(make_pair(thereY, thereX));
                distance[thereY][thereX] = distance[here.first][here.second]+1;
            }
        }
    }
    
    int result = 0;
    
    for(int i=1; i<3*N; i++){
        if(i!=1)
            moneyInfo[i] = moneyInfo[i]+moneyInfo[i-1];
        
        int cri =i * i + (i - 1) * (i - 1);
        
        if(cri<=moneyInfo[i]){
            if(result<i){
                result = i;
            }
        }
    }
    
    return moneyInfo[result]/M;
}

int main(){
    
    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++){
        cin>>N>>M;
        
        vector<vector<int> > houseInfo(N, vector<int>(N, 0));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>houseInfo[i][j];
            }
        }
        
        int max = 0 ;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int temp = BFS(houseInfo, i, j);
                if(max<temp)max = temp;
            }
        }
        cout<<"#"<<t<<" " <<max<<endl;
    }
    
    return 0;
}
