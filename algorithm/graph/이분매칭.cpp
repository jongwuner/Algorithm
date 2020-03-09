#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;
 
int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
bool dfs(int a){
    visited[a] = true;
    for(int b: adj[a]){
	if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
 
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int S;
        scanf("%d", &S);
        for(int j=0; j<S; j++){
            int k;
            scanf("%d", &k);
            adj[i].push_back(k-1);
        }
    }
 
    int match = 0;
    fill(A, A+N, -1);
    fill(B, B+M, -1);
    for(int i=0; i<N; i++){
        if(A[i] == -1){
            fill(visited, visited+N, false);
            if(dfs(i)) match++;
        }
    }
    printf("%d\n", match);
}
