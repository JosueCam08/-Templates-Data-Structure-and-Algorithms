// Test problem: https://codeforces.com/contest/25/problem/D
#include <bits/stdc++.h>
using namespace std;

#define fori(N) for(int i = 0; i < N; i++)
#define forj(N) for(int j = 0; j < N; j++)

// Compress paths O(1)
class DSU {
    public:
        DSU(int numNodes);
        bool union_(int nodeA, int nodeB);
        int find_(int node);
        vector<int> pnt, sz;
};

DSU::DSU(int numNodes) {
    pnt.resize(numNodes);
    sz.resize(numNodes);

    fori(numNodes)
        pnt[i] = i, sz[i] = 1;
}

int DSU::find_(int node) {
    if (node == pnt[node])
        return node;

    pnt[node] = pnt[pnt[node]];
    return find_(pnt[node]);
}

bool DSU::union_(int nodeA, int nodeB) {
    nodeA = find_(nodeA);
    nodeB = find_(nodeB);

    if (nodeA == nodeB)
        return false;

    if (sz[nodeA] < sz[nodeB]) {
        pnt[nodeA] = nodeB;
        sz[nodeB] += sz[nodeA];
    } else {
        pnt[nodeB] = nodeA;
        sz[nodeA] += sz[nodeB];
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    queue<pair<int, int>> unuseful_edges;
    DSU dsu(N);

    fori(N-1) {
        int a, b; cin >> a >> b;
        a--, b--;

        if (!dsu.union_(a, b))
            unuseful_edges.push({a, b});
    }

    cout << unuseful_edges.size() << '\n';
    
    int repAnt = dsu.find_(0), repAct;
    fori(N) {
        repAct = dsu.find_(i);
        if (repAct != repAnt) {
            int a, b;
            tie(a, b) = unuseful_edges.front();
            unuseful_edges.pop();

            cout << a+1 << " " << b+1 << " " << repAnt+1 << " " << repAct+1 << '\n';
            dsu.union_(repAnt, repAct);
            repAnt = dsu.find_(repAnt);
        }
    }

    return 0;
}