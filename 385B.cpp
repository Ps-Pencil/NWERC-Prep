//http://codeforces.com/problemset/problem/385/B
#include <cstdio>
#include <cstring>
using namespace std;

char s[6000];
bool appear[6000];
char bear[] = "bear";
int main(){
  scanf("%s",s);
  if(strlen(s)<4) {printf("0\n");return 0;}
  int i = 0, j = 0;
  while(i+j<strlen(s)){
    while(j!=4 && s[i+j] == bear[j]) j++;
    if(j == 4) {
      appear[i] = 1;
      i = i+j;
      j=0;
    }
    else{
      if(j == 0) i++;
      else
        {
          i = i + j;
          j = 0;
        }
    }
  }
  int ans = 0;
  for(int i=0;i!=strlen(s)-3;i++){
    int in = -1;
    for(int j=i;j!=strlen(s);j++){
      if(appear[j] && in == -1) in = j;
      if(in != -1 && j-in+1 >= 4) ans++;
    }
  }
  printf("%d\n",ans);
}
