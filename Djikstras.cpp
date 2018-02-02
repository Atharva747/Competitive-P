#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>

using namespace std;

struct node {
    int prev;
    int dist = -100000007;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, s, dest, m;
    cin>>n>>m>>s>>dest;
    vector<vector <int> > g(n+1,vector<int>(n+1,-1*100000007));
    for(int i=0;i<m;i++) {
        int a,b, dist;
        cin>>a>>b>>dist;
        g[a][b] = -1*dist;
        g[b][a] = -1*dist;
    }

    unordered_set<int> visited;
    node nodes[n+1];
    nodes[s].dist = 0;
    priority_queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int temp = q.top();
        q.pop();
        visited.insert(temp);
        for(int i = 1; i<=n;i++) {
            if (g[temp][i]!=-100000007&&visited.find(i)==visited.end()) {
                nodes[i].dist = max(nodes[i].dist,nodes[temp].dist+g[i][temp]);
                q.push(i);
            }

        }
    }
    cout<<-1*nodes[dest].dist;
}