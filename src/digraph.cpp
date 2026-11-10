#include "digraph.h"
#include <stdexcept>
#include <utility>

Digraph::Digraph(int _n): n(_n), m(0) {
    if (n < 0) throw std::invalid_argument("Vertex count must be nonnegative.");
    const auto size = static_cast<std::size_t>(n) + 1;
    A.assign(size, std::vector<bool>(size, false));
    out_neighbors.resize(size);
    in_neighbors.resize(size);
}

void Digraph::add_edge(int v, int w){
    if (v < 1 || v > n || w < 1 || w > n)
        throw std::out_of_range("Invalid edge vertex.");
    if (v == w) throw std::invalid_argument("An edge must join distinct vertices.");
    if (A[v][w]) return;

    out_neighbors[v].push_back(w);
    try {
        in_neighbors[w].push_back(v);
    } catch (...) {
        out_neighbors[v].pop_back();
        throw;
    }
    A[v][w] = true;
    ++m;
    parents_map.clear();
}


void Digraph::read(const std::string& file){
    std::ifstream in(file);
    if (!in) throw std::invalid_argument("Cannot access the file...");
    
    std::string line;
    bool is_first_line = true;
    int v, w;
    Digraph parsed;
    
    while (std::getline(in, line)) {
        if (line.find_first_not_of(" \t\r") == std::string::npos) continue;
        std::istringstream iss(line);
        
        if (is_first_line){
            std::string label;
            int vertex_count;
            if (!(iss >> label >> vertex_count) || label != "n" || vertex_count < 0)
                throw std::invalid_argument("Invalid graph header; expected n followed by the vertex count.");
            parsed = Digraph(vertex_count);
            is_first_line = false;
        }
        else{
            if (!(iss >> v >> w))
                throw std::invalid_argument("Invalid graph edge.");
            parsed.add_edge(v, w);
        }   
    }
    if (is_first_line) throw std::invalid_argument("Missing graph header.");
    *this = std::move(parsed);
}


void Digraph::print() const{
    for (int i=1; i<=n; ++i){
        for (int j :  out_neighbors[i]){
            std::cout << "(" << i << ", " << j << ")\n";
        }
    }
}


std::vector<int> Digraph::path(int v, int w) const{
    if (v < 1 || v > n || w < 1 || w > n)
        throw std::out_of_range("Invalid path vertex.");
    if (v == w) return {v};
    
    if (parents_map.find(v) == parents_map.end()){
        // Have not generated the parents map
        BFS(v);
    }
    
    
    const auto& parents = parents_map.at(v);
   
    
    if (std::get<1>(parents[w]) == -1){
        return {};
    }
    
    int node{w};
    int level{std::get<0>(parents[w])};
    std::vector<int> res_path(level, v);
    
    
    while (node != v){
        level --;
        res_path[level] = node;
        node = std::get<1>(parents[node]);
    }
    
    return res_path;
}




void Digraph::BFS(int s0) const {
    if (s0 < 1 || s0 > n) {
        throw std::out_of_range("Invalid start vertex");
    }

    if (parents_map.find(s0) != parents_map.end()) {
        return;
    }
    
    std::vector<std::tuple<int, int>> parents(static_cast<std::size_t>(n) + 1, {-1,-1});
    
    parents[s0] = {1, 0};
    std::vector<bool> visited;
    visited.resize(parents.size(), false);
    
    // Create a queue
    std::list<int> queue;
    queue.push_back(s0);
    
    visited[s0] = true;
    
    while (!queue.empty()){
        // Process the next vertex in BFS order.
        auto s = queue.front();
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        for (auto adjacent : out_neighbors[s]){
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                parents[adjacent] = {std::get<0>(parents[s])+1, s};
                queue.push_back(adjacent);
            }
        }
    }
    
    parents_map.emplace(s0, std::move(parents));
}

