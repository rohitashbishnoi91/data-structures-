#include<bits/stdc++.h>
using namespace std;
class Solution
{   
    private:
    class DisJointSet{
        vector<int> rank, parent;
    public:
        DisJointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        int findP(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findP(parent[node]);
        }

        void UnionByRank(int u, int v){
            int ul_u = findP(u);
            int ul_v = findP(v);

            if(ul_u == ul_v) return;
            if(rank[ul_u] < rank[ul_v]){
                parent[ul_u] = ul_v;
            }
            else if(rank[ul_u] > rank[ul_v]){
                parent[ul_v] = ul_u;
            }
            else{
                parent[ul_u] = ul_v;
                rank[ul_v]++;
            }
        }
    };
int main(){
    DisJointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    if(ds.findP(3)==ds.findP(7)){
        cout<<"same component"<<endl;
    }
    else{
        cout<<"different componenrt"<<endl;
    }
    ds.UnionByRank(3,7);
    return 0;
}
