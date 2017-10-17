#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//동 서 남 북
int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

int N, K;

bool isOutside(int y, int x){
    if(y>N-1||x>N-1||y<0||x<0)
        return true;
    else
        return false;
}

int DFS(vector<vector<int> >& map, vector<vector<bool> >& visited,
        int hereY, int hereX, int level){
    
    visited[hereY][hereX] = true;
    
    int max = -1;
    
    for(int i=0; i<4; i++){
        int thereY = hereY + dy[i];
        int thereX = hereX + dx[i];
        if(!isOutside(thereY, thereX))
            if(!isOutside(thereY, thereX) && !visited[thereY][thereX]
               && map[thereY][thereX] < map[hereY][hereX]){
                int temp = DFS(map, visited, thereY, thereX, level+1) + 1;
                if(max<temp) max = temp;
            }
    }
    
    visited[hereY][hereX] = false;
    
    if(max == -1)
        return 1;
    else
        return max;
}

int main(){
    int T;
    cin>>T;
    for(int times = 1; times<=T; times++){
        cin>>N>>K;
        
        vector<vector<int> > map(N, vector<int>(N, 0));
        vector<vector<pair<int, int> > > heightArr(21);
        
        int max = 0 ;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                heightArr[map[i][j]].push_back(make_pair(i, j));
                if(max<map[i][j])
                    max = map[i][j];
            }
        }
        
        int maxResult = 0;
        
        vector<vector<int> > temp = map;
        
        
        for(vector<vector<pair<int, int> > >::size_type a=0; a<heightArr[max].size(); a++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    for(int k=0; k<K+1; k++){
                        if(i==heightArr[max][a].first&& j==heightArr[max][a].second) break;
                        if(k!=0) temp[i][j] =temp[i][j] - 1;
                        
                        if(temp[i][j]<0) break;
                        
                        vector<vector<bool> > visited(N, vector<bool>(N, false));
                        int tempResult = DFS(temp, visited,
                                             heightArr[max][a].first, heightArr[max][a].second, 1);
                        if(maxResult<tempResult)
                            maxResult = tempResult;
                        
                    }
                    temp = map;
                }
            }
        }
        
        cout<<"#"<<times<<" "<<maxResult<<endl;
    }
    
    return 0;
}
