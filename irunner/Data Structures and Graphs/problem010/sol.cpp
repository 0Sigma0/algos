#include <fstream>
#include <vector>

int Dijkstra(std::vector<std::vector<std::pair<int, int>>>& Graph, int numOfNodes) {
    std::vector<int> dist(numOfNodes+1, INT32_MAX);
    std::vector<bool> mark(numOfNodes+1, 0);
    dist[1] = 0;
    for(int i=1; i<numOfNodes+1; i++) {
        int v = -1;
        for(int j=1; j<numOfNodes+1; j++) if(!mark[j] && (v == -1 || dist[j] < dist[v])) v = j;
        mark[v] = true;
        for(int j=0; j<Graph[v].size(); j++) {
            int nodeToVisit = Graph[v][j].first;
            int length = Graph[v][j].second;
            if(dist[v] + length < dist[nodeToVisit]) dist[nodeToVisit] = dist[v] + length;
        }
    }
    return dist[numOfNodes];
}

int main() {
    int numOfNodes, numOfEdges;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> numOfNodes >> numOfEdges;
    std::vector<std::vector<std::pair<int, int>>> AdjList(numOfNodes+1);
    for(int i=1; i<numOfEdges+1; i++) {
        int u, v, w;
        input >> u >> v >> w;
        std::pair<int, int> vw = {v, w};
        AdjList[u].push_back(vw);
    }
    output << Dijkstra(AdjList, numOfNodes);
}
