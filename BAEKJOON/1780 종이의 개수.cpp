#include <iostream>
#include <vector>

using namespace std;

int countArr[3];

void go(vector<vector<int> >&arr, int size, int y, int x){
    
    if(size==1){
        countArr[arr[y][x]] = countArr[arr[y][x]] + 1;
        return ;
    }
    
    int before = arr[y][x], after;
    bool onePaper= true;
    
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(i==y && j==x) {
                continue;
            }else{
                after = arr[i][j];
                if(before!=after){
                    onePaper = false;
                    break;
                }
                before = after;
            }
        }
    }
    
    if(onePaper){
        countArr[before] = countArr[before] + 1;
    }else{
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                go(arr, size/3, y+(size/3)*i, x+(size/3)*j);
            }
        }
    }
    return ;
}

int main(){
    int N;
    cin>>N;
    
    vector<vector<int> > arr(N, vector<int> (N, 0));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1) arr[i][j]=2;
        }
    }
    
    go(arr, N, 0, 0);
    
    cout<<countArr[2]<<endl;
    cout<<countArr[0]<<endl;
    cout<<countArr[1]<<endl;

    
    return 0;
}
