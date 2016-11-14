#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
typedef vector<int> vi;
int n, a, b;
char c;
string S;
class UnionFind {                                             
private:
  vi p, rank, setSize;                      
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N + 1, 1); 
    numSets = N; 
    rank.assign(N + 1, 0);
    p.assign(N + 1, 0); 
    for (int i = 0; i <= N; i++) p[i] = i; 
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
        numSets--; 
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) { 
            p[y] = x; 
            setSize[x] += setSize[y]; 
        } else { 
            p[x] = y; 
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++; 
        } 
    } 
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main() {
    istringstream ist;
    int T; cin >> T;
    int s,us;
    for(int ca = 0; ca < T; ++ca) {
        cin >> n;
        UnionFind u = UnionFind(n);
        s = us = 0;
        cin.ignore();
        while (getline(cin, S)) {
            if (S == "") break;
            ist.clear();
            ist.str(S); 
            ist >> c >> a >> b;
            if (c == 'c') {
                u.unionSet(a, b);
            } else {
                u.isSameSet(a, b) ? ++s : ++us;
            }
        }
        if (ca > 0) cout << endl;
        cout << s << ',' << us << endl;
    }
}