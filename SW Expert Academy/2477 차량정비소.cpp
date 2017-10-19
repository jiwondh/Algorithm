#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, K, A, B;

int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        
        cin>>N>>M>>K>>A>>B;
        
        vector<int> receipt(N, 0);
        vector<bool> isEmptyreceipt(N, true);
        for(int i=0; i<N; i++){
            cin>>receipt[i];
        }
        
        vector<int> modify(M, 0);
        vector<bool> isEmptyModify(N, true);
        for(int i=0; i<M; i++){
            cin>>modify[i];
        }
        
        queue<int> customerArriveTimeQ;
        vector<vector<int> > customerInfo(K+1, vector<int>(2, -1));
        
        for(int i=0; i<K; i++){
            int time;
            cin>>time;
            customerArriveTimeQ.push(time);
        }
        
        queue<int> waitReceipt;
        queue<int> waitModify;
        
        vector<queue<pair<int, int> > > receipting(N);
        vector<queue<pair<int, int> > > modifying(M);
        
        int totalPeopleCnt = 1;
        
        int time =0;
        int ingFlag = true;
        
        while(ingFlag){
            
            int customerArriveTime;
            do{
                customerArriveTime = customerArriveTimeQ.front();
                if(customerArriveTime == time){
                    waitReceipt.push(totalPeopleCnt++);
                    customerArriveTimeQ.pop();
                }
            }while(customerArriveTime == time);
            
            ingFlag = false;
            
            for(int receiptID=0; receiptID<N; receiptID++){
                if(isEmptyreceipt[receiptID]){
                    
                    if(!waitReceipt.empty()){
                        int waitReceiptCustomerID = waitReceipt.front();
                        waitReceipt.pop();
                        
                        customerInfo[waitReceiptCustomerID][0] = receiptID+1;
                        ingFlag = true;
                        receipting[receiptID].push(make_pair(waitReceiptCustomerID, time));
                        
                        isEmptyreceipt[receiptID] = false;
                    }
                }
                else{
                    if(!receipting[receiptID].empty()){
                        int receiptingCustomerID =receipting[receiptID].front().first;
                        int receiptCustomerArriveTime =receipting[receiptID].front().second;
                        if(receiptCustomerArriveTime+receipt[receiptID] == time){
                            receipting[receiptID].pop();
                            waitModify.push(receiptingCustomerID);
                            isEmptyreceipt[receiptID] = true;
                            receiptID--;
                            
                        }else{
                            ingFlag = true;
                        }
                    }
                }
            }
            
            for(int modifyID=0; modifyID<M; modifyID++){
                if(isEmptyModify[modifyID]){
                    
                    if(!waitModify.empty()){
                        int waitModifyCustomerID = waitModify.front();
                        waitModify.pop();
                        
                        customerInfo[waitModifyCustomerID][1] = modifyID+1;
                        ingFlag = true;
                        
                        modifying[modifyID].push(make_pair(waitModifyCustomerID, time));
                        
                        isEmptyModify[modifyID] = false;
                    }
                }
                else{
                    if(!modifying[modifyID].empty()){
                        int modifyingCustomerID =modifying[modifyID].front().first;
                        int modifyCustomerArriveTime =modifying[modifyID].front().second;
                        if(modifyCustomerArriveTime+modify[modifyID] == time){
                            modifying[modifyID].pop();
                            isEmptyModify[modifyID] = true;
                            modifyID--;
                            
                        }else{
                            ingFlag = true;
                        }
                    }
                }
            }
            time++;
            
            if(!customerArriveTimeQ.empty())
                ingFlag=true;
        }
        
        int result = 0;
        
        for(int i=1 ;i<=K; i++){
            if(customerInfo[i][0]==A && customerInfo[i][1]==B)
                result = result + i;
        }
        
        if(result ==0) cout<<"#"<<t<<" "<< -1<<endl;
        else
            cout<<"#"<<t<<" "<<result<<endl;
    }
    return 0;
}
