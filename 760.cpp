#include<iostream>
#include<string>
#include<cstring>
#include<set>
using namespace std;
char T1[800], T2[400];
int n1, n2, n3;
int RA[800], tempRA[800];        // rank array and temporary rank array
int SA[800], tempSA[800];
int c[800];  

int Phi[800];                      // for computing longest common prefix
int PLCP[800];
int LCP[800]; 

set<string> s;
char stmp[310];

bool flag = true;

bool cmp(int a, int b) { return strcmp(T1 + a, T1 + b) < 0; }      // compare

void countingSort(int k) {                                          // O(n)
  int i, sum, maxi = max(800, n3);   // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c);                          // clear frequency table
  for (i = 0; i < n3; i++) c[i + k < n3 ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n3; i++)          // shuffle the suffix array if necessary
    tempSA[c[SA[i] + k < n3 ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n3; i++)                     // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() {        
    int i, k, r;
    for (i = 0; i < n3; i++) RA[i] = T1[i];                 // initial rankings
    for (i = 0; i < n3; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n3; k <<= 1) {       // repeat sorting process log n times
        countingSort(k);  // actually radix sort: sort based on the second item
        countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n3; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
            (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n3; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n3-1]] == n3 - 1) break;               // nice optimization trick
    } 
}

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;                                         // default value
  for (i = 1; i < n3; i++)                            // compute Phi in O(n)
    Phi[SA[i]] = SA[i - 1];    // remember which suffix is behind this suffix
  for (i = L = 0; i < n3; i++) {             // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
    while (T1[i + L] == T1[Phi[i] + L]) L++;       // L increased max n times
    PLCP[i] = L;
    L = max(L - 1, 0);                             // L decreased max n times
  }
  for (i = 0; i < n3; i++)                            // compute LCP in O(n)
    LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

int main() {
    int R, pos;
    while (gets(T1)) {
        n1 = strlen(T1); T1[n1++] = '$';
        gets(T2); n2 = strlen(T2); T2[n2++] = '#';
        strcat(T1, T2);
        n3 = strlen(T1);
        memset(SA, 0, sizeof(SA));
        memset(LCP, 0, sizeof(LCP));
        memset(RA, 0, sizeof(RA));
        constructSA();
        computeLCP();
        R = 1; pos = 0;
        s.clear();
        for (int i = 1; i < n3; i++) {
            if ((SA[i - 1] < n1 && SA[i] >= n1) || (SA[i] < n1 && SA[i - 1] >= n1)) {
                if (LCP[i] > R) {
                    R = LCP[i]; 
                    s.clear();
                    memset(stmp,0,sizeof(stmp));
                    strncpy(stmp, T1 + SA[i], R);
                    s.insert(string(stmp));
                } else if (LCP[i] == R) {
                    memset(stmp,0,sizeof(stmp));
                    strncpy(stmp, T1 + SA[i], R);
                    s.insert(string(stmp));
                }
            }
        }
        if (flag) {flag = false;} else {printf("\n");}
        if (s.empty()) {
            printf("No common sequence.\n");
        } else {
            for (auto it = s.begin(); it != s.end(); ++it)
                cout << *it << "\n";
        }
        
        memset(T1, 0, sizeof(T1));
        memset(T2, 0, sizeof(T2));
        gets(T1);
    }
    return 0;
}