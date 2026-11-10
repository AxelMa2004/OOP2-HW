#include "digraph.h"
#include <stdexcept>

Digraph::Digraph(int _n): n(_n), m(0),
    A(n + 1, std::vector<bool>(n + 1, false)),
    out_neighbors(n + 1), in_neighbors(n + 1) {}

void Digraph::add_edge(int v, int w){
    m++;
    out_neighbors[v].push_back(w);
    in_neighbors[w].push_back(v);
    A[v][w] = true;
}


void Digraph::read(const std::string& file){
    std::ifstream in(file);
    if (!in) throw std::invalid_argument("Cannot access the file...");
    
    std::string line;
    bool is_first_line = true;
    int v, w;
    
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        
        if (is_first_line){
            std::string label;
            int vertex_count;
            if (!(iss >> label >> vertex_count) || label != "n" || vertex_count < 0)
                throw std::invalid_argument("Invalid graph header; expected n followed by the vertex count.");
            *this = Digraph(vertex_count);
            is_first_line = false;
        }
        else{
            if (iss >> v >> w) add_edge(v, w);
        }   
    }
}


void Digraph::print() const{
    for (int i=1; i<=n; ++i){
        for (int j :  out_neighbors[i]){
            std::cout << "(" << i << ", " << j << ")\n";
        }
    }
}

/*
std::vector<int> Digraph::path(int v, int w) const{
    
}
*/



void Digraph::BFS(int s0) { // helper to add; path() can reuse this loop
  std::vector<bool> visited;
  // Use n+1 to accommodate node number from 1 to n
  visited.resize(n + 1, false);

  // Create a queue for BFS
  std::list<int> queue;
  queue.push_back(s0);

  // Mark the start node as visited
  visited[s0] = true;

  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    auto s = queue.front();
    std::cout << s << " ";
    queue.pop_front();

    // Get all adjacent vertices of the dequeued
    // vertex s. If an adjacent vertex has not been visited,
    // then mark it visited and enqueue it
    for (auto adjacent : out_neighbors[s]) {
      if (!visited[adjacent]) {
        visited[adjacent] = true;
        queue.push_back(adjacent);
      }
    }
  }
}

