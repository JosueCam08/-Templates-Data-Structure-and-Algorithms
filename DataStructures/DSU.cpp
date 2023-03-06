#include <bits/stdc++.h>
using namespace std;

#define fori(N) for(int i = 0; i < N; i++)
#define forj(N) for(int j = 0; j < N; j++)

// Compress paths O(1)
class DSU {
    public:
        DSU(int numNodes);
        void union_(int nodeA, int nodeB);
        void find_(int node);
        vector<int> pnt;
};

DSU::DSU(int numNodes) {
    pnt.resize(numNodes);
    fori(numNodes)
        pnt[i] = i;
}

void DSU::union_(int nodeA, int nodeB) {
    
}

int main() {


    return 0;
}