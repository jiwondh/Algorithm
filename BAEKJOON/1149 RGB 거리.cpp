#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define R 0
#define G 1
#define B 2

int N;
vector<vector<int> > cost(1000, vector<int>(3, 0));

int cache[1001][3];

int DP(int level, int color){
    
    int& ret = cache[level][color];
    if(ret!=-1) return ret;
    
    if(level==N)
        return ret = cost[level-1][color];
    
    int min = 0;
    for(int i=0; i<3; i++){
        if(i!=color){
            if(min == 0) min = DP(level+1, i);
            else{
                int temp = DP(level+1, i);
                if(min>temp) min = temp;
            }
        }
    }
    
    return ret = cost[level-1][color] + min;
    
}
int main(){
    cin>>N;
    
    for(int i=0 ;i<N; i++){
        for(int j=0; j<3; j++){
            cin>>cost[i][j];
        }
    }
    
    memset(cache, -1, sizeof(cache));
    
    int min = 0;
    for(int i=0; i<3; i++){
        if(min == 0) min = DP(1, i);
        else{
            int temp = DP(1, i);
            if(min>temp) min = temp;
        }
    }
    cout<<min;
    
    return 0;
}
