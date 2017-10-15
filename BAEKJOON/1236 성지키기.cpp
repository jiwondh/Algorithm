#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> countI(N);
    vector<int> countJ(M);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char state;
            cin>>state;
            
            if(state=='X'){
                countI[i]++;
                countJ[j]++;
            }
        }
    }
    
    int cntI=0, cntJ=0;
    
    for(int i=0; i<N; i++)
        if(countI[i]==0) cntI++;
    
    for(int i=0; i<M; i++)
        if(countJ[i]==0) cntJ++;
    
    if(cntI>cntJ) cout<<cntI;
    else cout<<cntJ;
    
    return 0;
}
