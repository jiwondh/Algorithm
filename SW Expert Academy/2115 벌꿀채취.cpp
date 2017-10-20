#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, C;

set<int, greater<int> > moneySet;
set<int, greater<int> > resultMoneySet;

bool isOutside(int y, int x){
    if(y>N-1||x>N-1||y<0||x<0)
        return true;
    else
        return false;
}

void moneyDP(vector<int>& allHoney, vector<bool>& visited, int index, int sum, int resultSum){
    
    if(index>N-1)
        return ;
    
    visited[index] = true;
    
    moneySet.insert(allHoney[index]*allHoney[index]);
    
    sum = sum + allHoney[index];
    resultSum = resultSum + allHoney[index]*allHoney[index];
    
    if(sum<=C){
        
        moneySet.insert(resultSum);
    }
    
    for(int i=index+1; i<M; i++){
        if(!visited[i]){
            moneyDP(allHoney, visited, i, sum, resultSum);
        }
    }
    
    visited[index] = false;
}

int calculateMax(vector<int>& allHoney){
    
    moneySet.clear();
    
    for(int i=0; i<M; i++){
        vector<bool> visited(M, false);
        moneyDP(allHoney, visited, i, 0, 0);
    }
    
    return *(moneySet.begin());
}

int DP(vector<vector<int> >& honeyInfo, vector<vector<bool> >& visited,
       int y, int x, int level, int maxSum){
    
    for(int i=0; i<M; i++){
        if(isOutside(y, x+i))
            return 0;
        if(visited[y][x+i])
            return 0;
    }
    
    vector<int> allHoney(M, 0);
    
    for(int i=0; i<M; i++){
        visited[y][x+i] = true;
        allHoney[i] = honeyInfo[y][x+i];
    }
    
    int maxMoneyResult =calculateMax(allHoney);
    
    if(level == 2){
        
        resultMoneySet.insert(maxSum+maxMoneyResult);
        
        for(int i=0; i<M; i++){
            visited[y][x+i] = false;
        }
        return 0;
    }
    
    int levelTwoCnt = 0;
    for(int i=y; i<N; i++){
        int start = 0;
        if(i==y) start = x;
        for(int j=start; j<N; j++){
            if(i==y && j==x){
                j = j+M-1;
            }
            else{
                DP(honeyInfo, visited, i, j, level+1, maxMoneyResult);
                levelTwoCnt++;
            }
        }
    }
    
    for(int i=0; i<M; i++){
        visited[y][x+i] = false;
    }
    
    return 0;
}

int main(){
    
    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++){
        cin>>N>>M>>C;
        
        vector<vector<int> > honeyInfo(N, vector<int>(N, 0));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>honeyInfo[i][j];
            }
        }
        
        resultMoneySet.clear();
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                vector<vector<bool> > visited (N, vector<bool>(N, false));
                DP(honeyInfo, visited, i, j, 1, 0);
            }
        }
        cout<<"#"<<t<<" "<<*(resultMoneySet.begin())<<endl;
    }
    
    return 0;
}
