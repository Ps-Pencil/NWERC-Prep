//http://codeforces.com/problemset/problem/641/B

#include <cstdio>

using namespace std;

int mat[101][101];
int n,m,q;

int qs[10001][5];
void rotateR(int row){
  int t = mat[row][m-1];
  for(int i=m-1;i!=0;i--){
    mat[row][i] = mat[row][i-1];
  }
  mat[row][0] = t;
}
void rotateC(int col){
  int t = mat[n-1][col];
  for(int i=n-1;i!=0;i--){
    mat[i][col] = mat[i-1][col];
  }
  mat[0][col] = t;
}
int main(){
  scanf("%d %d %d",&n,&m,&q);
  for(int i=0;i<q;i++){
    scanf("%d",&qs[i][0]);
    if(qs[i][0] <= 2){
      scanf("%d",&qs[i][1]);
      qs[i][1]--;
    }
    else{
      scanf("%d %d %d",&qs[i][1],&qs[i][2],&qs[i][3]);
      qs[i][1]--;
      qs[i][2]--;
    }
  }
  for(int i=q-1;i>=0;i--){
    if(qs[i][0] == 1){
      rotateR(qs[i][1]);
    }
    if(qs[i][0] == 2){
      rotateC(qs[i][1]);
    }
    if(qs[i][0] == 3){
      mat[qs[i][1]][qs[i][2]]=qs[i][3];
    }
  }
  for(int i=0;i<n;i++){
    printf("%d",mat[i][0]);
    for(int j=1;j<m;j++){
      printf(" %d",mat[i][j]);
    }
    printf("\n");
  }
}
