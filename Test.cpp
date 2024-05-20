#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}};
    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1, 1},
            {1, 0, 2, 1},
            {1, 2, 0, 1}};
//    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
//    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
TEST_CASE("Graph Addition: Same Size")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 2},
            {1, 0, 3},
            {2, 3, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
            {1, 1, 3},
            {1, 1, 3},
            {3, 3, 1}};
    CHECK(g3.printGraph() == "[1, 1, 3]\n[1, 1, 3]\n[3, 3, 1]");
}

TEST_CASE("Graph Addition: Self Addition")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 + g1;
    vector<vector<int>> expectedGraph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Graph Addition: Different Sizes")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1},
            {1, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 + g2);
}
TEST_CASE("Graph Multiplication: Same Size")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 2},
            {1, 0, 3},
            {2, 3, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
            {2, 0, 2},
            {3, 0, 3},
            {0, 5, 0}};
    CHECK(g3.printGraph() == "[2, 1, 2]\n[4, 0, 4]\n[2, 3, 2]");
}

TEST_CASE("Graph Multiplication: Scalar Multiplication")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 * 2;
    vector<vector<int>> expectedGraph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Graph Multiplication: Different Sizes")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1},
            {1, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 * g2);
}
TEST_CASE("Graph Subtraction: Same Size")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 3, 2},
            {1, 0, 4},
            {2, 3, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
            {-1, 3, 1},
            {1, -1, 4},
            {1, 3, -1}};
    CHECK(g3.printGraph() == "[-1, 3, 1]\n[1, -1, 4]\n[1, 3, -1]");
}

TEST_CASE("Graph Subtraction: Self Subtraction")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 - g1;
    vector<vector<int>> expectedGraph = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK(g2.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Graph Subtraction: Different Sizes")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1},
            {1, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 - g2);
}
TEST_CASE("Graph Addition Assignment: Same Size")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    g1 += g2;
    vector<vector<int>> expectedGraph = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};
    CHECK(g1.printGraph() == "[1, 1, 1]\n[1, 1, 1]\n[1, 1, 1]");
}

TEST_CASE("Graph Addition Assignment: Self Addition")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    g1 += g1;
    vector<vector<int>> expectedGraph = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Graph Addition Assignment: Different Sizes")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1},
            {1, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 += g2);
}
TEST_CASE("Graph Multiplication Assignment: Same Size")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 2},
            {1, 0, 3},
            {2, 3, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    g1 *= g2;
    vector<vector<int>> expectedGraph = {
            {2, 0, 2},
            {3, 0, 3},
            {0, 5, 0}};
    CHECK(g1.printGraph() == "[2, 1, 2]\n[4, 0, 4]\n[2, 3, 2]");
}
TEST_CASE("Graph Subtraction Assignment: Same Size")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 3, 2},
            {1, 0, 4},
            {2, 3, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g2.loadGraph(graph2);

    g1 -= g2;
    vector<vector<int>> expectedGraph = {
            {-1, 3, 1},
            {1, -1, 4},
            {1, 3, -1}};
    CHECK(g1.printGraph() == "[-1, 3, 1]\n[1, -1, 4]\n[1, 3, -1]");
}

TEST_CASE("Graph Subtraction Assignment: Self Subtraction")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    g1 -= g1;
    vector<vector<int>> expectedGraph = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Graph Subtraction Assignment: Different Sizes")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
            {0, 1},
            {1, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 -= g2);
}
TEST_CASE("Graph Scalar Multiplication: Positive Scalar")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 * 3;
    vector<vector<int>> expectedGraph = {
            {0, 6, 3},
            {6, 0, 6},
            {3, 6, 0}};
    CHECK(g2.printGraph() == "[0, 6, 3]\n[6, 0, 6]\n[3, 6, 0]");
}

TEST_CASE("Graph Scalar Multiplication: Negative Scalar")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 * -2;
    vector<vector<int>> expectedGraph = {
            {0, -4, -2},
            {-4, 0, -4},
            {-2, -4, 0}};
    CHECK(g2.printGraph() == "[0, -4, -2]\n[-4, 0, -4]\n[-2, -4, 0]");
}

TEST_CASE("Graph Scalar Multiplication: Zero Scalar")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 * 0;
    vector<vector<int>> expectedGraph = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK(g2.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}
TEST_CASE("Graph Scalar Division: Positive Scalar")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 4, 2},
            {4, 0, 4},
            {2, 4, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 / 2;
    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    CHECK(g2.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");
}

TEST_CASE("Graph Scalar Division: Negative Scalar")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 4, 2},
            {4, 0, 4},
            {2, 4, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 / -2;
    vector<vector<int>> expectedGraph = {
            {0, -2, -1},
            {-2, 0, -2},
            {-1, -2, 0}};
    CHECK(g2.printGraph() == "[0, -2, -1]\n[-2, 0, -2]\n[-1, -2, 0]");
}

TEST_CASE("Graph Scalar Division: Division by Zero")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 4, 2},
            {4, 0, 4},
            {2, 4, 0}};
    g1.loadGraph(graph1);

    CHECK_THROWS(g1 / 0);
}
TEST_CASE("Graph Pre-increment: Basic Increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    ++g1;
    vector<vector<int>> expectedGraph = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}};
    CHECK(g1.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
}

TEST_CASE("Graph Pre-increment: Multiple Increments")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    ++(++g1);
    vector<vector<int>> expectedGraph = {
            {2, 3, 2},
            {3, 2, 3},
            {2, 3, 2}};
    CHECK(g1.printGraph() == "[2, 3, 2]\n[3, 2, 3]\n[2, 3, 2]");
}

TEST_CASE("Graph Pre-increment: Large Graph")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}};
    g1.loadGraph(graph1);

    ++g1;
    vector<vector<int>> expectedGraph = {
            {1, 2, 2, 1},
            {2, 1, 1, 2},
            {2, 1, 1, 2},
            {1, 2, 2, 1}};
    CHECK(g1.printGraph() == "[1, 2, 2, 1]\n[2, 1, 1, 2]\n[2, 1, 1, 2]\n[1, 2, 2, 1]");
}
TEST_CASE("Graph Pre-decrement: Basic Decrement")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g1.loadGraph(graph1);

    --g1;
    vector<vector<int>> expectedGraph = {
            {-1, 1, 0},
            {1, -1, 1},
            {0, 1, -1}};
    CHECK(g1.printGraph() == "[-1, 1, 0]\n[1, -1, 1]\n[0, 1, -1]");
}

TEST_CASE("Graph Pre-decrement: Multiple Decrements")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g1.loadGraph(graph1);

    --(--g1);
    vector<vector<int>> expectedGraph = {
            {-2, 0, -1},
            {0, -2, 0},
            {-1, 0, -2}};
    CHECK(g1.printGraph() == "[-2, 0, -1]\n[0, -2, 0]\n[-1, 0, -2]");
}

TEST_CASE("Graph Pre-decrement: Large Graph")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 2, 2, 0},
            {2, 0, 0, 2},
            {2, 0, 0, 2},
            {0, 2, 2, 0}};
    g1.loadGraph(graph1);

    --g1;
    vector<vector<int>> expectedGraph = {
            {-1, 1, 1, -1},
            {1, -1, -1, 1},
            {1, -1, -1, 1},
            {-1, 1, 1, -1}};
    CHECK(g1.printGraph() == "[-1, 1, 1, -1]\n[1, -1, -1, 1]\n[1, -1, -1, 1]\n[-1, 1, 1, -1]");
}
TEST_CASE("Graph Post-increment: Basic Increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);

    g1++;
    vector<vector<int>> expectedGraph = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}};
    CHECK(g1.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
}