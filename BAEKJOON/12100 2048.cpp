#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

int N;

int direc[4] = {UP, DOWN, LEFT, RIGHT};
string direcString[4] = {"UP", "DOWN", "LEFT", "RIGHT"};

int go(vector<vector<int> >& board, int direction, int level){
    
    vector<vector<int> > newBoard(N, vector<int>(N, 0));
    vector<vector<int> > temp(N, vector<int>(N, 0));
    
    int maxNum = 0;

    switch(direction){
        case UP:
            for(int i=0; i<N; i++){
                int cnt = 0;
                int first = -1, second = -1;
                for(int j=0; j<N; j++){
                    if(board[j][i]==0) {
                        if(j==N-1 && first!=-1) newBoard[cnt++][i] = first;
                        continue;
                    }
                    if(first == -1) {
                        first = board[j][i];
                        if(j==N-1) newBoard[cnt++][i] = first;
                        continue;
                    }
                    if(second == -1){
                        second = board[j][i];
                    }
                    if(first==second){
                        newBoard[cnt++][i] = second*2;
                        first = -1;
                        second = -1;
                    }else{
                        newBoard[cnt++][i] = first;
                        if(j==N-1)
                            newBoard[cnt++][i] = second;
                        first = second;
                        second = -1;
                        
                    }
                }
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(newBoard[i][j]>maxNum)
                        maxNum = newBoard[i][j];
                }
            }
            break;
            
        case DOWN:
            for(int i=0; i<N; i++){
                int cnt = N-1;
                int first = -1, second = -1;
                for(int j=N-1; j>=0; j--){
                    if(board[j][i]==0) {
                        if(j==0 && first!=-1) newBoard[cnt--][i] = first;
                        continue;
                    }
                    if(first == -1) {
                        first = board[j][i];
                        if(j==0) newBoard[cnt--][i] = first;
                        continue;
                    }
                    if(second == -1){
                        second = board[j][i];
                    }
                    if(first==second){
                        newBoard[cnt--][i] = second*2;
                        first = -1;
                        second = -1;
                    }else{
                        newBoard[cnt--][i] = first;
                        if(j==0)
                            newBoard[cnt--][i] = second;
                        first = second;
                        second = -1;
                        
                    }
                }
            }
            
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(newBoard[i][j]>maxNum)
                        maxNum = newBoard[i][j];
                }
            }
            break;
            
        case LEFT:
            
            for(int i=0; i<N; i++){
                int cnt = 0;
                int first = -1, second = -1;
                for(int j=0; j<N; j++){
                    if(board[i][j]==0) {
                        if(j==N-1 && first!=-1) newBoard[i][cnt++] = first;
                        continue;
                    }
                    if(first == -1) {
                        first = board[i][j];
                        if(j==N-1) newBoard[i][cnt++] = first;
                        continue;
                    }
                    if(second == -1){
                        second = board[i][j];
                    }
                    if(first==second){
                        newBoard[i][cnt++] = second*2;
                        first = -1;
                        second = -1;
                    }else{
                        newBoard[i][cnt++] = first;
                        if(j==N-1)
                            newBoard[i][cnt++] = second;
                        first = second;
                        second = -1;
                        
                    }
                }
            }
            
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(newBoard[i][j]>maxNum)
                        maxNum = newBoard[i][j];
                }
            }
            
            break;
            
        case RIGHT:
            for(int i=0; i<N; i++){
                int cnt = N-1;
                int first = -1, second = -1;
                for(int j=N-1; j>=0; j--){
                    if(board[i][j]==0) {
                        if(j==0 && first!=-1) newBoard[i][cnt--] = first;
                        continue;
                    }
                    if(first == -1) {
                        first = board[i][j];
                        if(j==0)
                            newBoard[i][cnt--] = first;
                        continue;
                    }
                    if(second == -1){
                        second = board[i][j];
                    }
                    if(first==second){
                        newBoard[i][cnt--] = second*2;
                        first = -1;
                        second = -1;
                    }else{
                        newBoard[i][cnt--] = first;
                        if(j==0)
                            newBoard[i][cnt--] = second;
                        first = second;
                        second = -1;
                    }
                }
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(newBoard[i][j]>maxNum)
                        maxNum = newBoard[i][j];
                }
            }
            
            break;
            
        default:
            break;
    }
    
    if(level == 5){
        return maxNum;
    }
    
    temp = board;
    board = newBoard;
    
    for(int i=0; i<4; i++){
        int temp = go(board, direc[i], level+1);
        if(temp>maxNum)
            maxNum = temp;
    }
    
    board = temp;
    
    return maxNum;
}

int main(){
    cin>>N;
    
    vector<vector<int> > board(N, vector<int>(N, 0));
    
    for(int i=0; i<N ;i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    int max=0;
    for(int i=0; i<4; i++){
        int temp = go(board, direc[i], 1);
        if(max<temp)
            max = temp;
    }
    
    cout<<max;
    
    return 0;
}
