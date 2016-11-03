// https://icpcarchive.ecs.baylor.edu/external/74/7423.pdf
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct ppl{
  int start,end;
  ppl(int,int);

  ppl();
};
ppl::ppl(int x,int y):start(x),end(y){}
ppl::ppl(){}

bool compare(ppl a,ppl b){
  return a.start < b.start;
}
ppl ppls[500000];
multiset<int> s;

int main(){
  int M,N,x,y,res;
  while(scanf("%d %d",&M,&N) > 0){
    res = 0;
    s.clear();
    for(int i=0;i<M;i++){
      scanf("%d %d",&x,&y);
      ppls[i] = ppl(x,x+y);
    }
    sort(ppls,ppls+M,compare);
    for(int i=0;i<M;i++){
      set<int>::iterator it = s.lower_bound(ppls[i].start-N);
      if(it != s.end() && ppls[i].start - (*it) <= N && ppls[i].start - (*it) >=0 )
      {
        s.erase(it);
        res ++;
      }
      s.insert(ppls[i].end);
    }
    printf("%d\n",res);
  }
  return 0;
}
