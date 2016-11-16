//https://uva.onlinejudge.org/external/3/334.pdf

#include <vector>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string,int> s2i;
vector<string> i2s;
vector<vector<int> > adj;
vector<vector<int> > mat;
vector<vector<int> > events;
int main(){
  int n,tc=1;
  while(scanf("%d",&n),n){
    events.clear();
    adj.clear();
    mat.clear();
    i2s.clear();
    s2i.clear();
    events.resize(n);
    int counter = 0;
    printf("Case %d, ",tc++);
    for(int i=0;i<n;i++){
      int m;
      scanf("%d",&m);
      while(m--){
        string s;
        cin>>s;
        events[i].push_back(counter);
        i2s.push_back(s);
        s2i[s]=counter++;
      }
    }
    adj.assign(counter,vector<int>(counter,0));
    mat.assign(counter,vector<int>(counter,0));
    for(auto seq : events){
      if(seq.size()<2) continue;
      for(int i=1;i<seq.size();i++){
        adj[seq[i-1]][seq[i]]=1;
        mat[seq[i-1]][seq[i]]=1;
      }
    }
    int m;
    scanf("%d",&m);
    while(m--){
      string s1,s2;
      cin>>s1>>s2;
      adj[s2i[s1]][s2i[s2]]=1;
      mat[s2i[s1]][s2i[s2]]=1;
    }
    // for(int i=0;i<adj.size();i++){for(int j=0;j<adj[i].size();j++)printf("%d ",mat[i][j]);putchar('\n');}
    int changed = true;
    while(changed){
      changed=false;
      for(int i=0;i<counter;i++){
        for(int j=0;j<counter;j++){
          int ans = mat[i][j];
          for(int k=0;k<counter;k++){
            ans |= (mat[i][k] & adj[k][j]);
          }
          if(ans != mat[i][j]){
            mat[i][j] = ans;
            changed = true;
          }
        }
      }
    }
    vector<pair<int,int> > result;
    int num = 0;
    for(int i=0;i<counter;i++){
      for(int j=i+1;j<counter;j++){
        if(mat[i][j] == 0 && mat[j][i] == 0){
          num ++;
          if(result.size()<2) result.push_back(make_pair(i,j));
        }
      }
    }
    if(num == 0) printf("no concurrent events.\n");
    else {
      printf("%d concurrent events:\n",num);
      for(int i=0;i<result.size();i++){
        // if(i!=0) printf(" ");
        printf("(%s,%s) ",i2s[result[i].first].c_str(),i2s[result[i].second].c_str());
      }
      printf("\n");
    }
  }
}
