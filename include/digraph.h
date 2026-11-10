#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <tuple>
#include <unordered_map>
using namespace std;

class Digraph {
  int n;  // number of vertices
          // vertices are 1,...,n
  int m;  // number of edges

  // adjacency matrix; A[i][j]=true if and only if
  // (i,j) is an edge. Note that each A and each
  // sub-array A[i] must have length n+1, since
  // vertices are 1,...,n (not 0,...,n-1)
  vector<vector<bool>> A;

  // out_neighbors[i] contains
  // exactly the vertices j  for which (i,j) is an edge
  vector<vector<int>> out_neighbors;

  // in_neighbors[i] contains
  // exactly the vertices j  for which (j,i) is an edge
  vector<vector<int>> in_neighbors;
  
  // Reuse one BFS result for queries with the same starting point.
  // Each record stores the path's vertex count and the previous vertex.
  mutable std::unordered_map<int, std::vector<std::tuple<int, int>>> parents_map;
  
  void BFS(int s0) const;  // Fill the cached parent records.

 public:
  Digraph() : n(0), m(0) {}   // Default constructor
  Digraph(int _n);             // Constructor: set n to n, m to 0,
                              // A an (n+1)x(n+1) array and
  // resize out_neighbors, in_neighbors to length n+1.
  // Initialize all entries of A to false
  // No destructor needed: vector members clean up themselves (Rule of Zero)

  void add_edge(int v, int w);   // add edge (v,w): update A, out_neighbors,
                                 // and in_neighbors accordingly
  void read(const string& file); // initialize all data members from the
                                 // graph data contained in "file"
  inline int vertices() const { return n; };          // returns n
  inline int edges() const { return m; };             // returns m
  void print() const;            // print all edges to the screen
  
  
  vector<int> path(int v, int w) const;
  // return shortest directed path from v to w (if existent);
  // return empty vector if no such path exists
  
};
