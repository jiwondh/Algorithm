#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, R, C, L;

//상 하 좌 우
int dx[4] = {0,  0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

vector<int> direction(int type){
    
    vector<int> direc;
    
    switch(type){
        case 1:
            for(int i=0; i<4; i++){
                direc.push_back(i);
            }
            break;
        case 2:
            for(int i=0; i<2; i++){
                direc.push_back(i);
            }
            break;
        case 3:
            for(int i=2; i<4; i++){
                direc.push_back(i);
            }
            break;
        case 4:
            direc.push_back(0);
            direc.push_back(3);
            break;
        case 5:
            direc.push_back(1);
            direc.push_back(3);
            break;
        case 6:
            direc.push_back(1);
            direc.push_back(2);
            break;
        case 7:
            direc.push_back(0);
            direc.push_back(2);
            break;
    }
    
    return direc;
}

bool isOutside(int y, int x){
    if( y>N-1 || x>M-1 || y<0 || x<0){
        return true;
    }else{
        return false;
    }
}

bool isConnected(vector<int>&nextDirection, int thisDirection){
    
    int findDirection;
    switch(thisDirection){
        case 0:
            findDirection = 1;
            break;
        case 1:
            findDirection = 0;
            break;
        case 2:
            findDirection = 3;
            break;
        case 3:
            findDirection = 2;
            break;
        default:
            findDirection = -1;
            break;
    }
    
    bool flag = false;
    for(vector<int>::size_type i=0; i<nextDirection.size(); i++){
        if(nextDirection[i] == findDirection)
            flag = true;
    }
    
    if(flag)
        return true;
    else
        return false;
}
int BFS(vector<vector<int> >& map, int y, int x, int times){
    
    vector<vector<int> > distance(N, vector<int>(M, -1));
    queue<pair<int, int> > q;
    
    distance[y][x] = 1;
    q.push(make_pair(y, x));
    
    int cnt = 1;
    
    while(!q.empty()){
        pair<int, int> here = q.front();
        q.pop();
        
        if(distance[here.first][here.second]==times)
            break;
        
        vector<int> direc = direction(map[here.first][here.second]);
        
        for(vector<int>::size_type i=0; i<direc.size(); i++){
            int thereY = here.first + dy[direc[i]];
            int thereX = here.second + dx[direc[i]];
            
            if(!isOutside(thereY, thereX) && distance[thereY][thereX]==-1
               && map[thereY][thereX]!=0){
                
                vector<int> thereDirec = direction(map[thereY][thereX]);
                
                if(!isConnected(thereDirec, direc[i])) continue;
                
                q.push(make_pair(thereY, thereX));
                distance[thereY][thereX] = distance[here.first][here.second]+1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int T;
    cin>>T;
    
    for(int times=1; times<=T; times++){
        
        cin>>N>>M>>R>>C>>L;
        
        vector<vector<int> > map(N, vector<int>(M, 0));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>map[i][j];
            }
        }
        
        cout<<"#"<<times<<" "<<BFS(map, R, C, L)<<endl;
    }
    
    return 0;
}
