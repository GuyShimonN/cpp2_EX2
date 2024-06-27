//guy shimon:
//mail:guyguy845@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
namespace ariel {
    class Graph {
    private:
        bool directed;
        std::vector<std::vector<int>> adjacencyMatrix;


    public:
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        bool getDirected()const{return directed;}
        std::string printGraph() const;
        bool isDirected() const;
        std::size_t getNumberOfNodes() const;
        std::vector<std::pair<size_t , std::pair<size_t , int>>> getEdges() const;
        std::vector<std::size_t> getNeighbors(std::size_t node) const ;
        int getEdgeWeight(size_t ver1, size_t ver2) const ;
        bool isEdge(size_t from, size_t to) const {
            return adjacencyMatrix[from][to] != 0;
        }
        std::vector<std::vector<int>> getMatrix() const {
            return adjacencyMatrix;
        }
        // אופרטורים חשבוניים
        Graph operator+(const Graph& other) const; // חיבור
        Graph& operator+=(const Graph& other); // הוספה
        Graph operator+() const; // פלוס אונרי
        Graph operator-(const Graph& other) const; // חיסור
        Graph& operator-=(const Graph& other); // חיסור
        Graph operator-() const; // מינוס אונרי

        // אופרטורים להשוואה
        bool operator>(const Graph& other) const; // גדול
        bool operator>=(const Graph& other) const; // גדול או שווה
        bool operator<(const Graph& other) const; // קטן
        bool operator<=(const Graph& other) const; // קטן או שווה
        bool operator==(const Graph& other) const; // שווה
        bool operator!=(const Graph& other) const; // לא שווה

        // אופרטורים אחרים
        Graph& operator++(); // הגדלה ב-1 (לפני)
        Graph operator++(int); // הגדלה ב-1 (אחרי)
        Graph& operator--(); // הקטנה ב-1 (לפני)
        Graph operator--(int); // הקטנה ב-1 (אחרי)
        Graph operator*(int scalar) const; // הכפלה בסקלר
        Graph& operator*=(int scalar); // הכפלה בסקלר
        Graph operator/(int scalar) const; // חלוקה בסקלר
        Graph& operator/=(int scalar); // חלוקה בסקלר

        Graph operator*(const Graph& other) const; // הכפלת גרפים
        Graph& operator*=(const Graph& other); // הכפלת גרפים
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
        friend std::istream& operator>>(std::istream& is, Graph& graph);
        friend Graph operator*(int scalar, const Graph& graph);
        friend Graph operator/(int scalar, const Graph& graph);

    };
    using StartNode = size_t;
    using EndNode = size_t;
}

#endif // GRAPH_HPP