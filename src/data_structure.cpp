#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  Graph::Graph(int V) {
    parent = new int[V];

    for (int i = 0; i < V; i++)
      parent[i] = i;

    G.clear();
    T.clear();
  }
  void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
  }
  int Graph::find_set(int i) {
    if (i == parent[i])
      return i;
    else
      return find_set(parent[i]);
  }

  void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
  }
  void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
      uRep = find_set(G[i].second.first);
      vRep = find_set(G[i].second.second);
      if (uRep != vRep) {
        T.push_back(G[i]);
        union_set(uRep, vRep);
      }
    }
  }
  void Graph::print() {
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
      cout << T[i].second.first << " - " << T[i].second.second << " : "
           << T[i].first;
      cout << endl;
    }
  }

}  // namespace itis