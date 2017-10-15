#include <iostream>
#include <set>


using namespace std;

int main() {
    int N;
    cin>>N;
    
    set<pair<unsigned long, string> > strVector;
    
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        strVector.insert(make_pair(str.length(), str));
    }
    
    set<pair<unsigned long, string> >::iterator iter;
    for (iter = strVector.begin(); iter != strVector.end(); ++iter){
        cout << (*iter).second <<endl;
    }
    
    return 0;
}
