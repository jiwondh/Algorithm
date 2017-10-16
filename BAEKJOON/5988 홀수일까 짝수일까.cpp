#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        string K;
        cin>>K;
        
        if(K[K.length()-1]%2==0) cout<<"even"<<endl;
        else cout<<"odd"<<endl;
    }
    
    return 0;
}
