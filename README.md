guy shimon:

ID-209306513

mail:guyguy845@gmail.com

for run the progrem you need to use g++ compiler and run the following command:

1. **Clone the Repository**: First, you need to clone the repository to your local machine. Open a terminal and run the following command:

```bash
git clone https://github.com/GuyShimonN/CPP2_EX1.git
```

2. **Navigate to the Project Directory**: Change your current directory to the project directory:

```bash
cd CPP2_EX1
```

3. **Build the Project**: According to the `README.md` file, you can build the project using the `make` command:

```bash
make
```

4. **Run the Tests**: If you want to run the tests, you can use the following commands:

```bash
make test
./test
```

5. **Clean the Project**: If you want to clean the project (remove all the build files), you can use the following command:

```bash
make clean
```

6. **Run the Tidy Test**: If you want to run the tidy test, you can use the following command:

```bash
make tidy
```

7. **Run the Valgrind Test**: If you want to run the valgrind test, you can use the following command:

```bash
make valgrind
```
Graph Graph::operator+(const Graph &other) const: This function overloads the + operator to add two graphs together. It adds the adjacency matrices of the two graphs.  
Graph &Graph::operator+=(const Graph &other): This function overloads the += operator to add another graph to the current graph. It adds the adjacency matrix of the other graph to the adjacency matrix of the current graph.  
Graph Graph::operator-(const Graph &other) const: This function overloads the - operator to subtract another graph from the current graph. It subtracts the adjacency matrix of the other graph from the adjacency matrix of the current graph.  
Graph &Graph::operator-=(const Graph &other): This function overloads the -= operator to subtract another graph from the current graph and assign the result to the current graph.  
Graph Graph::operator*(const Graph &other) const: This function overloads the * operator to perform matrix multiplication on the adjacency matrices of two graphs.  
bool Graph::operator>(const Graph &other) const: This function overloads the > operator to compare two graphs. It checks if the current graph is greater than the other graph.  
bool Graph::operator==(const Graph &other) const: This function overloads the == operator to check if two graphs are equal. It checks if the adjacency matrices of the two graphs are equal.  
bool Graph::operator!=(const Graph &other) const: This function overloads the != operator to check if two graphs are not equal.  
Graph &Graph::operator++(): This function overloads the ++ operator to increment the weight of all edges in the graph by 1. 

bool Graph::operator>=(const Graph &other) const: This function overloads the >= operator to check if the current graph is greater than or equal to the other graph.  
bool Graph::operator<=(const Graph &other) const: This function overloads the <= operator to check if the current graph is less than or equal to the other graph.  
Graph &Graph::operator--(): This function overloads the -- operator to decrement the weight of all edges in the graph by 1.  
Graph Graph::operator*(int scalar) const: This function overloads the * operator to multiply the weight of all edges in the graph by a scalar.  
Graph &Graph::operator*=(int scalar): This function overloads the *= operator to multiply the weight of all edges in the graph by a scalar and assign the result to the current graph.  
Graph Graph::operator/(int scalar) const: This function overloads the / operator to divide the weight of all edges in the graph by a scalar.  
Graph &Graph::operator/=(int scalar): This function overloads the /= operator to divide the weight of all edges in the graph by a scalar and assign the result to the current graph.  
Graph &Graph::operator*=(const Graph &other): This function overloads the *= operator to perform matrix multiplication on the adjacency matrices of two graphs and assign the result to the current graph.  
Graph Graph::operator++(int): This function overloads the ++ operator (postfix version) to increment the weight of all edges in the graph by 1 and return the graph before the increment.  
Graph Graph::operator--(int): This function overloads the -- operator (postfix version) to decrement the weight of all edges in the graph by 1 and return the graph before the decrement.  
bool Graph::operator<(const Graph &other) const: This function overloads the < operator to check if the current graph is less than the other graph.