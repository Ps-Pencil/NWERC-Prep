//https://uva.onlinejudge.org/external/105/10596.pdf
// WA for unknown reason
#include <list>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge;
typedef list<Edge>::iterator iter;

struct Edge
{
  int next_vertex;
  iter reverse_edge;

  Edge(int next_vertex)
    :next_vertex(next_vertex) { }
};

const int max_vertices = 300;
list<Edge> adj[max_vertices];		// adjacency list
vector<int> path;
void find_path(int v)
{
  while(adj[v].size() > 0)
    {
      int vn = adj[v].front().next_vertex;
      adj[vn].erase(adj[v].front().reverse_edge);
      adj[v].pop_front();
      find_path(vn);
    }
  path.push_back(v);
}
void add_edge(int a, int b)
{
  adj[a].push_front(Edge(b));
  iter ita = adj[a].begin();
  adj[b].push_front(Edge(a));
  iter itb = adj[b].begin();
  ita->reverse_edge = itb;
  itb->reverse_edge = ita;
}

int main(){
  int n,m;
  while(scanf("%d %d",&n,&m)!=EOF){
    for(int i=0;i<n;i++) adj[i].clear();
    path.clear();
    int s=0;
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      add_edge(a,b);
      s = a;
    }
    // if(m !=0 )
    find_path(s);
    // vector<int> seen(n,0);
    // int tot= 0;
    // for(int i:path){
    //   if(!seen[i]){
    //     seen[i]=1;
    //     tot++;
    //   }
    // }
    // printf("%d\n",tot);
    if(m!=0 && path.size()-1 == m && path[0] == path[path.size()-1]){
      printf("Possible\n");
    }
    else
      printf("Not Possible\n");
  }
}
