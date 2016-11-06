#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

struct painter{
  int L, P, S;
  painter(){}
  painter(int L, int P, int S):L(L),P(P),S(S){}
}painters[200];

bool compare(painter p1, painter p2){
  return p1.S < p2.S;
}

int dp[200][20000];
int N,K;
deque<int> q;

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    painters[i] = painter(a,b,c);
  }
  sort(painters, painters+K,compare);
  for(int i = 0 ; i < K ; i ++){
    for(int j= 0 ; j <= N; j++){
      if( i == 0 ){
        int l = min(painters[i].L, j);
        dp[i][j]  = l * painters[i].P;
      }
      else{
        if(j < painters[i].S){
          dp[i][j] = dp[i-1][j];
          if(j >= painters[i].S - painters[i].L){
            while(!q.empty() && (dp[i-1][q.back()] - q.back()*painters[i].P) <= dp[i-1][j] - j*painters[i].P){
              q.pop_back();
            }
            q.push_back(j);
          }
        }
        else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          if(j - painters[i].S + 1 <= painters[i].L){
            while(!q.empty()&&j-q.front() > painters[i].L) q.pop_front();
            dp[i][j] = max(dp[i][j],dp[i-1][q.front()]+(j-q.front())*painters[i].P);
          }
        }
      }
    }
  }
  printf("%d\n",dp[K-1][N]);
  return 0;
}
