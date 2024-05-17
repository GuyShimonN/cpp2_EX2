//guy shimon:
//ID-209306513
//mail:guyguy845@gmail.com
#include "Graph.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        throw std::invalid_argument("The graph cannot be empty");
    }
    // Check if the matrix is square
    size_t size = matrix.size();
    for (const auto& row : matrix) {
        if (row.size() != size) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    directed=this->isDirected();
    // If the matrix is square, load it into the adjacencyMatrix
    this->adjacencyMatrix = matrix;
}
void Graph::printGraph() const {
    size_t numVertices = getNumberOfNodes();
    int numEdges = 0;
    for (const auto &row: adjacencyMatrix) {
        for (const auto &element: row) {
            if (element != 0){
                numEdges++;}
        }
    }
    // If the graph is undirected, each edge is counted twice
    if (getDirected()) {
        numEdges /= 2;
    }

    std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges.\n";

    for (const auto &row: adjacencyMatrix) {
        for (const auto &element: row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

bool Graph::isDirected() const {
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}

size_t Graph::getNumberOfNodes() const {
    return adjacencyMatrix.size();
}

std::vector<std::pair<size_t , std::pair<size_t, int>>> Graph::getEdges() const {
    std::vector<std::pair<size_t , std::pair<size_t , int>>> edges;
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                edges.push_back({i, {j, adjacencyMatrix[i][j]}});
            }
        }
    }
    return edges;
}


std::vector<size_t> Graph::getNeighbors(size_t node) const {
    std::vector<size_t> neighbors;
    if (node >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    for (size_t i = 0; i < adjacencyMatrix[node].size(); ++i) {
        if (adjacencyMatrix[node][i] != 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

int Graph::getEdgeWeight(size_t ver1, size_t ver2) const {
    if ( static_cast<size_t>(ver1) >= adjacencyMatrix.size()  || static_cast<size_t>(ver2) >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    return adjacencyMatrix[static_cast<size_t>(ver1)][static_cast<size_t>(ver2)];
}
Graph Graph::operator+(const Graph& other) const {
    // Check if the graphs are of the same size
    if (this->getNumberOfNodes() != other.getNumberOfNodes()) {
        throw std::invalid_argument("Graphs are not of the same size");
    }

    Graph result;
    std::vector<std::vector<int>> resultMatrix(this->getNumberOfNodes(), std::vector<int>(this->getNumberOfNodes(), 0));

    // Add the adjacency matrices of the two graphs
    for (size_t i = 0; i < this->getNumberOfNodes(); ++i) {
        for (size_t j = 0; j < this->getNumberOfNodes(); ++j) {
            resultMatrix[i][j] = this->adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
        }
    }

    // Load the resulting matrix into the result graph
    result.loadGraph(resultMatrix);

    return result;
}
Graph& Graph::operator+=(const Graph& other) {
    // Check if the graphs are of the same size
    if (this->getNumberOfNodes() != other.getNumberOfNodes()) {
        throw std::invalid_argument("Graphs are not of the same size");
    }

    // Add the adjacency matrices of the two graphs
    for (size_t i = 0; i < this->getNumberOfNodes(); ++i) {
        for (size_t j = 0; j < this->getNumberOfNodes(); ++j) {
            this->adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
        }
    }

    return *this;
}
Graph Graph::operator-(const Graph& other) const {
    // Check if the graphs are of the same size
    if (this->getNumberOfNodes() != other.getNumberOfNodes()) {
        throw std::invalid_argument("Graphs are not of the same size");
    }

    Graph result;
    std::vector<std::vector<int>> resultMatrix(this->getNumberOfNodes(), std::vector<int>(this->getNumberOfNodes(), 0));

    // Subtract the adjacency matrices of the two graphs
    for (size_t i = 0; i < this->getNumberOfNodes(); ++i) {
        for (size_t j = 0; j < this->getNumberOfNodes(); ++j) {
            resultMatrix[i][j] = this->adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
        }
    }

    // Load the resulting matrix into the result graph
    result.loadGraph(resultMatrix);

    return result;
}
Graph& Graph::operator-=(const Graph& other) {
    // Check if the graphs are of the same size
    if (this->getNumberOfNodes() != other.getNumberOfNodes()) {
        throw std::invalid_argument("Graphs are not of the same size");
    }

    // Subtract the adjacency matrices of the two graphs
    for (size_t i = 0; i < this->getNumberOfNodes(); ++i) {
        for (size_t j = 0; j < this->getNumberOfNodes(); ++j) {
            this->adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph Graph::operator*(const Graph& other) const {
    // Check if the two graphs have the same number of nodes
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw std::invalid_argument("The two graphs must have the same number of nodes to perform multiplication.");
    }

    Graph result;
    size_t n = this->adjacencyMatrix.size();
    result.adjacencyMatrix.resize(n, std::vector<int>(n, 0)); // Initialize the result adjacency matrix with zeros

    // Perform matrix multiplication
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result.adjacencyMatrix[i][j] += this->adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
            }
        }
    }

    return result;
}
bool Graph::operator>(const Graph& other) const {
    // Check if the graphs are of the same size
    if (this->getNumberOfNodes() != other.getNumberOfNodes()) {
        return false;
    }

    bool isProperSubset = false;
    bool isOtherProperSubset = false;
    int thisEdgeCount = 0, otherEdgeCount = 0;
    int thisTotalWeight = 0, otherTotalWeight = 0;

    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            int thisWeight = this->adjacencyMatrix[i][j];
            int otherWeight = other.adjacencyMatrix[i][j];

            thisEdgeCount += (thisWeight != 0);
            otherEdgeCount += (otherWeight != 0);

            thisTotalWeight += thisWeight;
            otherTotalWeight += otherWeight;

            if (thisWeight > otherWeight) {
                isOtherProperSubset = true;
            }
            if (thisWeight < otherWeight) {
                isProperSubset = true;
            }
        }
    }

    // Check if this graph is a proper subset of the other graph
    if (isProperSubset && !isOtherProperSubset) {
        return false;
    }

    // Check if the other graph is a proper subset of this graph
    if (isOtherProperSubset && !isProperSubset) {
        return true;
    }

    // If neither graph is a proper subset of the other, compare edge counts
    if (otherEdgeCount > thisEdgeCount) {
        return true;
    } else if (otherEdgeCount < thisEdgeCount) {
        return false;
    }

    // If edge counts are equal, compare the total weight of edges
    return otherTotalWeight > thisTotalWeight;
}

bool Graph::operator==(const Graph& other) const {
    // Check if the sizes of the adjacency matrices are the same
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        return false;
    }

    // Check if the edges and their weights are the same
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            if (this->adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) {
                return !(*this > other) && !(other > *this);
            }
        }
    }

    return true;
}
bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}
Graph& Graph::operator++() {
    // Increment each edge by 1
    for (auto& row : this->adjacencyMatrix) {
        for (auto& edge : row) {
            edge += 1;
        }
    }

    return *this;
}
bool Graph::operator>=(const Graph& other) const {
    return (*this > other) || (*this == other);
}

bool Graph::operator<=(const Graph& other) const {
    return (!(*this > other)||(*this == other));
}
Graph& Graph::operator--() {
    // Decrement each edge by 1
    for (auto& row : this->adjacencyMatrix) {
        for (auto& edge : row) {
            edge -= 1;
        }
    }

    return *this;
}
Graph Graph::operator*(int scalar) const {
    // Create a copy of the current state of the graph
    Graph result = *this;

    // Multiply each edge by the scalar
    for (auto& row : result.adjacencyMatrix) {
        for (auto& edge : row) {
            edge *= scalar;
        }
    }

    // Return the resulting graph
    return result;
}

Graph Graph::operator-() const {
    Graph result = *this;
    return result * -1;
}

Graph Graph::operator+() const {
    Graph result = *this;
    return result;
}
Graph& Graph::operator*=(int scalar) {
    // Multiply each edge by the scalar
    for (auto& row : this->adjacencyMatrix) {
        for (auto& edge : row) {
            edge *= scalar;
        }
    }

    // Return the graph
    return *this;
}
Graph Graph::operator/(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    // Create a copy of the current state of the graph
    Graph result = *this;

    // Divide each edge by the scalar
    for (auto& row : result.adjacencyMatrix) {
        for (auto& edge : row) {
            edge /= scalar;
        }
    }

    // Return the resulting graph
    return result;
}
Graph& Graph::operator/=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    // Divide each edge by the scalar
    for (auto& row : this->adjacencyMatrix) {
        for (auto& edge : row) {
            edge /= scalar;
        }
    }

    // Return the graph
    return *this;
}
Graph& Graph::operator*=(const Graph& other) {
    // Check if the two graphs have the same number of nodes
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw std::invalid_argument("The two graphs must have the same number of nodes to perform multiplication.");
    }

    size_t n = this->adjacencyMatrix.size();
    std::vector<std::vector<int>> resultMatrix(n, std::vector<int>(n, 0)); // Initialize the result adjacency matrix with zeros

    // Perform matrix multiplication
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                resultMatrix[i][j] += this->adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
            }
        }
    }

    // Assign the result back to the graph
    this->adjacencyMatrix = resultMatrix;

    // Return the graph
    return *this;
}



std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (const auto& row : graph.getMatrix()) {
        for (const auto& edge : row) {
            os << edge << ' ';
        }
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, Graph& graph) {
    size_t n; // The number of nodes in the graph
    is >> n;

    // Resize the adjacency matrix
    std::vector<std::vector<int>> newMatrix(n, std::vector<int>(n));

    // Input the adjacency matrix
    for (auto& row : newMatrix) {
        for (auto& edge : row) {
            is >> edge;
        }
    }

    graph.loadGraph(newMatrix);

    return is;
}

Graph operator*(int scalar, const Graph& graph) {
    // Create a copy of the graph
    Graph result = graph;

    // Multiply each edge by the scalar
    for (auto& row : result.getMatrix()) {
        for (auto& edge : row) {
            edge *= scalar;
        }
    }

    // Return the resulting graph
    return result;
}

Graph operator/(int scalar, const Graph& graph) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    // Create a copy of the graph
    Graph result = graph;

    // Divide each edge by the scalar
    for (auto& row : result.getMatrix()) {
        for (auto& edge : row) {
            edge /= scalar;
        }
    }

    // Return the resulting graph
    return result;
}
