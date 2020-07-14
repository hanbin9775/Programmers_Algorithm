#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> dp = {{N},{N*N, N/N, N+N, 10*N+N}};
    set<int> outcomes;
    set<int>::iterator it;
    outcomes.insert(0);
    outcomes.insert(N);
    outcomes.insert(N*N);
    outcomes.insert(N/N);
    outcomes.insert(N+N);
    outcomes.insert(10*N+N);
    int cnt=0;
    
    for(cnt=0; cnt<2; cnt++){
        for(int j=0; j<dp[cnt].size(); j++){
            if(dp[cnt][j]==number) return cnt+1;
        }
    }
    
    vector<int> temp;
    while(cnt<8){
        int num =0;
        for(int i=0; i<=cnt; i++){
            num *= 10;
            num += N;
        }
        if(num == number) return cnt+1;
        else {
            temp.push_back(num);
            outcomes.insert(num);
        }
        for(int i=0; i<(cnt+1)/2; i++){
            for(int j=0; j<dp[cnt-i-1].size(); j++){
                for(int k=0; k<dp[i].size(); k++){
                    if(dp[cnt-i-1][j]*dp[i][k]==number) return cnt+1;
                    else{
                        it = outcomes.find(dp[cnt-i-1][j]*dp[i][k]);
                        if(it==outcomes.end()) {temp.push_back(dp[cnt-i-1][j]*dp[i][k]);               
                                                outcomes.insert(dp[cnt-i-1][j]*dp[i][k]);
                        }
                    }
                    if(dp[cnt-i-1][j]+dp[i][k]==number) return cnt+1;
                    else{
                        it = outcomes.find(dp[cnt-i-1][j]+dp[i][k]);
                        if(it==outcomes.end()) {temp.push_back(dp[cnt-i-1][j]+dp[i][k]);               
                                                outcomes.insert(dp[cnt-i-1][j]+dp[i][k]);
                        } 
                    }
                    if(dp[cnt-i-1][j]-dp[i][k]==number) return cnt+1;
                    else{
                        it = outcomes.find(dp[cnt-i-1][j]-dp[i][k]);
                        if(it==outcomes.end()) {temp.push_back(dp[cnt-i-1][j]-dp[i][k]);               
                                                outcomes.insert(dp[cnt-i-1][j]-dp[i][k]);
                        }   
                    }
                    if(dp[cnt-i-1][j]/dp[i][k]==number) return cnt+1;
                    else{
                        it = outcomes.find(dp[cnt-i-1][j]/dp[i][k]);
                        if(it==outcomes.end()) {temp.push_back(dp[cnt-i-1][j]/dp[i][k]);               
                                                outcomes.insert(dp[cnt-i-1][j]/dp[i][k]);
                        }    
                    }
                }
            }
        }
        
        dp.push_back(temp);
        temp.clear();
        cnt++;
    }
    
    return -1;
}