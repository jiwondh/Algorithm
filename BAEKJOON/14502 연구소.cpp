#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

//동 서 남 북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0,  0, 1, -1};

bool isOutside(int y, int x){
    if(y>N-1 || x>M-1 || y<0 || x<0){
        return true;
    }else{
        return false;
    }
}

int BFS(vector<vector<int> >& laboratory, queue<pair<int, int> >& virusQ){
    
    vector<vector<int> > discovered(N, vector<int>(M, -1));
    
    while(!virusQ.empty()){
        queue<pair<int, int> > temp;
        while(!virusQ.empty()){
            pair<int, int> here = virusQ.front();
            if(discovered[here.first][here.second]==-1)
                discovered[here.first][here.second]=0;
            virusQ.pop();
            
            for(int i=0; i<4; i++){
                int thereY = here.first + dy[i];
                int thereX = here.second + dx[i];
                
                if(!isOutside(thereY, thereX) && discovered[thereY][thereX]==-1 && laboratory[thereY][thereX]==0){
                    temp.push(make_pair(thereY, thereX));
                    laboratory[thereY][thereX] = 2;
                    discovered[thereY][thereX] = discovered[here.first][here.second] + 1;
                }
            }
        }
        virusQ = temp;
    }
    
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(laboratory[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>N>>M;
    
    vector<vector<int> > laboratory(N, vector<int>(M, 0));
    queue<pair<int, int> > virusQ;
    vector<pair<int, int> > emptySpace;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>laboratory[i][j];
            if(laboratory[i][j]==2){
                virusQ.push(make_pair(i, j));
            }else if(laboratory[i][j]==0){
                emptySpace.push_back(make_pair(i, j));
            }
        }
    }
    
    int max = 0;
    for(vector<pair<int, int> >::size_type i=0; i<emptySpace.size()-2; i++){
        for(vector<pair<int, int> >::size_type j=i+1; j<emptySpace.size()-1; j++){
            for(vector<pair<int, int> >::size_type k=j+1; k<emptySpace.size(); k++){
                vector<vector<int> > temp = laboratory;
                queue<pair<int, int> > tempQ = virusQ;
                temp[emptySpace[i].first][emptySpace[i].second]=1;
                temp[emptySpace[j].first][emptySpace[j].second]=1;
                temp[emptySpace[k].first][emptySpace[k].second]=1;
                int result = BFS(temp, tempQ);
                if(max<result) max = result;
            }
        }
    }

    cout<<max;
    return 0;
}
