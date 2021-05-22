#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

namespace itis {

  struct Graph {
   private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T; // mst
    int *parent;
    int V;

   public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
  };

}  // namespace itis
