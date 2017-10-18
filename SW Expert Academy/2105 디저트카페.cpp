#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;

// 시계방향
int dx[4] = {1, -1, -1,  1};
int dy[4] = {1,  1, -1, -1};

set<int, greater<int> > maxLength;

bool isOutside(int y, int x){
    if( y>N-1 || x>N-1 || y<0 || x<0 )
        return true;
    else
        return false;
}

bool isDirectionCorrect(int type, vector<int>&roadLength){
    
    int ret = true;
    
    for(int i=0; i<type; i++){
        if(roadLength[i]==0)
            ret = false;
    }
    
    for(int i=type+1; i<4; i++){
        if(roadLength[i]!=0)
            ret = false;
    }
    
    return ret;
}

bool isCorrectCase(vector<int>& roadLength){
    if(roadLength[0]!=0 && roadLength[0] == roadLength[2]
       && roadLength[1]==roadLength[3]+1)
        return true;
    else
        return false;
}

void DFS(vector<vector<int> >& map, vector<vector<bool> >& visited,
         vector<int>&roadLength, vector<bool>& isSameDesert,
         int hereY, int hereX){
    
    visited[hereY][hereX] = true;
    isSameDesert[map[hereY][hereX]] = true;

    for(int i=0; i<4; i++){
        
        if(!isDirectionCorrect(i, roadLength)) continue;
        
        int thereY = hereY + dy[i];
        int thereX = hereX + dx[i];
        
        if(!isOutside(thereY, thereX) && !visited[thereY][thereX]
           && !isSameDesert[map[thereY][thereX]]){
            roadLength[i] = roadLength[i]+1;
            DFS(map, visited, roadLength, isSameDesert, thereY, thereX);
            roadLength[i] = roadLength[i]-1;
        }
    }
    
    visited[hereY][hereX] = false;
    isSameDesert[map[hereY][hereX]] = false;
    
    if(isCorrectCase(roadLength)){
        maxLength.insert((roadLength[0]+roadLength[1])*2);
    }
}

int main(){
    
    int T;
    cin>>T;
    
    for(int times = 1; times<=T; times++){
        cin>>N;
        vector<vector<int> > map(N, vector<int> (N, 0));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
            }
        }
        
        maxLength.clear();
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                vector<int> roadLength(4, 0);
                vector<vector<bool> > visited(N, vector<bool> (N, false));
                vector<bool> isSameDesert(101, false);
                
                DFS(map, visited, roadLength, isSameDesert, i, j);
            }
        }
        
        set<int, greater<int> >::iterator iter= maxLength.begin();
        
        if(*iter == 0)
            cout<<"#"<<times<<" "<<-1<<endl;
        else
            cout<<"#"<<times<<" "<<*iter<<endl;
    }
    
    return 0;
}
