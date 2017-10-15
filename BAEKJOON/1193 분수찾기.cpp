#include <iostream>

using namespace std;

int main() {
    int X;
    cin >> X;
    
    int level = 1;
    int sum = level;
    
    while(sum < X){
        level++;
        sum = sum + level;
    }
    
    int dif = sum - X + 1;
    
    // 짝수(위->아래)
    if(level%2==0)
        cout<< level+1-dif << "/" << dif <<endl;

    // 홀수(아래->위)
    else
        cout<< dif << "/" << level+1-dif <<endl;
    
    return 0;
}
