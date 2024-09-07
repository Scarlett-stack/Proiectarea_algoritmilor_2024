#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> graph, transpose;

stack <int> s;
vector<bool> viz;
ifstream f("kosa.in");
int n, m;
void read_input()
{
    f>>n>>m;
    viz.resize(n, false);
    for(int i = 0; i < n; ++i) {
        // daca faci cu map e posibil sa nu puna nodurile care nu au copii 
        graph[i] = vector<int>();
        transpose[i] = vector<int>();
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        f >> u >> v;
        cout<<"u si v : "<< u<<' '<<v<<endl;
        graph[u].push_back(v);
        transpose[v].push_back(u); // e invers
    }
}
void dfs_first(int node)
{
    viz[node] = true;
    for (auto neigh : graph[node]){
        if (!viz[neigh])
        {
            dfs_first(neigh);
        }
    }
    //cand ne intoarcem adaugam in stiva
    cout<<"ce pushuiesc: "<<node<<endl;
    s.push(node);
}
void dfs_Second(int node)
{
    cout<<"nod din dfs_Sec (adica un scc) "<< node<<endl;
    viz[node] = true;
    for (int neigh : transpose[node])
    {
        if (!viz[neigh])
            dfs_Second(neigh);
    }
}
int main()
{      read_input();
     for(auto &p : graph) {
        cout << "Node " << p.first << ": ";
        for(int v : p.second) {
            cout << v << " ";
        }
        cout << endl;
    }
    for (int i = 0; i<n; i++)
        if (!viz[i]) //IMPORTANT!!!
        dfs_first(i);

    //acum transpunem graful lam facut in citire
    fill(viz.begin(), viz.end(), false); //resetam viz khalifa


    //ok acuma dfs pe transpusa incepand cu pop stiva
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!viz[node]){
            dfs_Second(node);
            cout<<endl;
        }
            
    }
    return 0;
}