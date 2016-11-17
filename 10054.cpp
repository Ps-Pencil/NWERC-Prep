//https://uva.onlinejudge.org/external/100/10054.pdf
#include <cstdio>
#include <list>
#include <vector>
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

const int max_vertices = 60;
int num_vertices;
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
  int T;
  scanf("%d",&T);
  int s;
  for(int tc=1;tc<=T;tc++){
    for(int i=0;i<60;i++){
      adj[i].clear();
    }
    path.clear();
    if(tc!=1) printf("\n");
    printf("Case #%d\n",tc);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      s=a;
      add_edge(a,b);
    }
    find_path(s);
    if(path.size()!=n+1 || path[path.size()-1] != path[0]){
      printf("some beads may be lost\n");
    }
    else{
      for(int i=0;i<path.size()-1;i++){
        printf("%d %d\n",path[i],path[i+1]);
      }
    }
  }
}
