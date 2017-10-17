#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ONEDAY 0
#define ONEMONTH 1
#define THREEMONTH 2
#define ONEYEAR 3

#define MAXFEE 3000*31*12

int cache[13][4];

int DP(vector<int>& fee, vector<int>& plan, int month, int type){
    
    if(month>12){
        return 0;
    }
    
    int& ret = cache[month][type];
    if(ret!=-1) return ret;
    
    int min = MAXFEE;
    
    switch(type){
        case ONEDAY:
            for(int i=0; i<4; i++){
                int temp = DP(fee, plan, month+1, i);
                if(min>temp) min = temp;
            }
            return ret = fee[ONEDAY]*plan[month] + min;
            
        case ONEMONTH:
            for(int i=0; i<4; i++){
                int temp = DP(fee, plan, month+1, i);
                if(min>temp) min = temp;
            }
            return ret = fee[ONEMONTH] + min;
            break;
        case THREEMONTH:
            for(int i=0; i<4; i++){
                int temp = DP(fee, plan, month+3, i);
                if(min>temp) min = temp;
            }
            return ret = fee[THREEMONTH] + min;
            break;
        case ONEYEAR:
            return ret = fee[ONEYEAR];
        default:
            return 0;
            break;
    }
}

int main(){
    int T;
    cin>>T;
    
    for(int t=1; t<=T; t++){
        
        vector<int> fee(4, 0);
        for(int i=0; i<4; i++){
            cin>>fee[i];
        }
        
        vector<int> plan(13, 0);
        for(int i=1; i<=12; i++){
            cin>>plan[i];
        }
        
        
        int min = MAXFEE;
        
        for(int i=0; i<4; i++){
            memset(cache, -1, sizeof(cache));
            int temp = DP(fee, plan, 1, i);
            if(min>temp) min = temp;
        }
        
        cout<<"#"<<t<<" "<<min<<endl;
    }
    
    return 0;
}
