#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define LEFT 0
#define RIGHT 1
#define DOWN 2

int dx[3] = {-1, 1, 0};
int dy[3] = { 0, 0, 1};

int N, M;

bool isOutside(int y, int x){
    if(y>N-1 || x>M-1 || y<0 || x<0)
        return true;
    else
        return false;
}

int cache[1001][1001][3];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int DP(vector<vector<int> >& map, vector<vector<bool> >&visited,
        int y, int x, int direction){
    
    if(isOutside(y, x)||visited[y][x]){
        return -100000001;
    }
    
    int& ret = cache[y][x][direction];
    if(ret!=-1 )return ret;
    
    if(y==N-1 && x==M-1){
        return ret = map[y][x];
    }
    
    visited[y][x] = true;
    
    switch(direction){
        case LEFT:
            ret = max(DP(map, visited, y, x-1, LEFT), DP(map, visited, y, x-1, DOWN));
            break;
        case RIGHT:
            ret = max(DP(map, visited, y, x+1, RIGHT), DP(map, visited, y, x+1, DOWN));
            break;
        case DOWN:
            ret = max(DP(map, visited, y+1, x, LEFT), DP(map, visited, y+1, x, RIGHT));
            ret = max(ret, DP(map, visited, y+1, x, DOWN));
            break;
        default:
            break;
    }

    visited[y][x] = false;
    
    return ret = ret + map[y][x];
}

int main(){
    cin>>N>>M;
    
    vector<vector<int> > map(N, vector<int>(M, 0));
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    memset(cache, -1, sizeof(cache));
    
    int y=0, x=0;
    
    cout<<max(DP(map, visited, y, x, DOWN), DP(map, visited, y, x, RIGHT));
    
    return 0;
}
