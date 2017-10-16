#include <iostream>

using namespace std;

int main() {
    int money;
    cin>>money;
    
    money = 1000 - money;
    
    int change[6] = {500, 100, 50, 10, 5, 1};
    
    int quotient = 1;
    int cnt = 0;
    int i = 0;
    
    while(1){
        quotient = money/change[i];
        cnt = cnt + quotient;
        
        if(quotient == 0){
            i++;
            continue;
        }
        
        money = money%change[i];
        if(money==0) break;
    }
    
    cout<<cnt;
    
    return 0;
}
