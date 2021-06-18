# BFS and DFS Directed Graph Traversal Program in C++

## 16520373 - Farrel Ahmad
### 8 June 2021
<p>&nbsp;</p>

## Introduction
BFS is an abbreviation for Breadth First Search. Breadth First Search is a traversal technique which implements queue data structure that follows FIFO (First In First Out) rule. One of the common usage of BFS is to find the shortest path in graph. On the other hand, DFS is an abbreviation for Depth First Search. Depth First search is another traversal technique but this implements stack data structure that follows LIFO (Last In First Out) rule. One of the common usage of DFS is to find cycle within graph.

In BFS, after the starting node is printed, all neighbors of the starting node are printed first, then it continues to each neighbor and print all neighbors in each starting node's neighbor. The algorithm continues until there's no more neighbors. This is what FIFO is about. The neighbor of starting node (First In) will be printed first (First Out).

On the other hand in DFS, after the starting node is printed, only one of the neighbors will be printed. After that it continues to the printed neighbor to find its' neighbors, then print one of them. This algorithm continues until there's no more neighbors. Once there's no more neighbors on the edge, it will go back to the previous node and print the other neighbors that has not been visited. The LIFO concept is used when traversing one of the neighbors.

![](https://www.freelancinggig.com/blog/wp-content/uploads/2019/02/BFS-and-DFS-Algorithms.png)

Illustration of BFS and DFS Algorithm. Source : FreelancingGig

<p>&nbsp;</p>

![](https://4cawmi2va33i3w6dek1d7y1m-wpengine.netdna-ssl.com/wp-content/uploads/2018/07/Computer-science-fundamentals_6.1.png)

Difference Between Stack (LIFO) and Queue (FIFO). Source : HIGHBROW

On this implementation of BFS and DFS in C++. The program is used only to traverse **directed graph**

<p>&nbsp;</p>

## Compiling The Program
1. Clone this repository into your local computer by running this command in the terminal
```
git clone https://gitlab.com/dagozilla/academy/2021-internship1/16520373/day-4.git
```
2. After it has been successfully cloned, there should be a directorey called `day-4`, then change to that directory

3. Change the branch to `development` by running this command
```
git checkout development
```

4. After changing the branch, there should be a directory called `16520373`, use `ls` to check and cd to that directory

5. After changing to `/16520373` directory, there should be a main file called `bfs_dfs.cpp` and header file called `bfs_dfs.hpp`, use `ls` to check the presence of these files

6. Compile the program by running this command
```
g++ bfs_dfs.cpp bfs_dfs.hpp -o bfs_dfs
```

7. After the program is successfully compiled, use this command to run the program
```
./bfs_dfs
```
<p>&nbsp;</p>

## Code Implementation and Explanation
1. Once the program is running, the user is asked for some inputs. The first line is the input for variable `N` as number of nodes. Nodes will be marked from 0 to (N-1). For example, if we input 6 then there will be 6 nodes containing node 0, node 1, node 2, node 3, node 4, and node 5 in the graph

2. The second line is the input for number of edges. The input is stored in variable `M`. For example, if we input 5, then there will be 5 edges in the graph.

3. After it receives the input in first and second line, the program will define an adjacency matrix with the size of N x N and initialize all the element in the matrix with 0. This matrix is stored in matrix variable called `mat`

4. The program will ask for another input `M` times to fill the edges in the graph in the form of adjacency matrix. Each `M` input is concatenated. It means that the input must be two numbers separated by a whitespace each line. Each number must be one of the nodes that has been defined before. The first number will be stored in variable `a` and the second number in `b`. For example, if we input `3 4` it means that there is an edge from 3 to 4 and 3 is stored in variable `a` and 4 in `b`. After that the program will mark the edge in adjacency matrix in index `mat[a][b]` by changing the value to 1. Indicating that there is an edge in row a column b or from a to b. This process will be repeated `M` times`

5. After the user input the edges `M` times, the program will ask for a starting node. The number must be one of the nodes that has been defined. The starting node is stored in variable `start`

6. The last line is for input mode. Input `BFS` for BFS traversal mode or input `DFS` for DFS traversal mode.

Take a look at this directed graph from the assignment's specification.

![](https://i.ibb.co/MBf2xzQ/graph.png)

Graph Example 1. Source : Dagozilla Day-4 `README.md` Assignment Specification

From the Graph Example 1. There are 6 nodes from 0 to 5 and there are 5 edges. These edges are 0->1, 0->2, 0->3, 2->4, and 2->5. In adjacency matrix, it will be illustrated like this

```
   |0 1 2 3 4 5
|0  0 1 1 1 0 0
|1  0 0 0 0 0 0
|2  0 0 0 0 1 1
|3  0 0 0 0 0 0
|4  0 0 0 0 0 0
|5  0 0 0 0 0 0
```

Because from 0 to 1 there is an edge, the element of row 0 column 1 has the value of 1. While between 0 to 4 there is no edge, thus the value is 0. The program will read the graph as adjacency matrix.

<p>&nbsp;</p>

## BFS in The Program and BFS Test Cases
As an example of using BFS in the program and also to test this program's BFS capability, there are several BFS test cases to be carried out by this program.
<p>&nbsp;</p>

### BFS Test Case 1
Let's try this program to BFS traverse the Graph Example 1 above with 0 as the starting node

Adjacency Matrix : 
```
   |0 1 2 3 4 5
|0  0 1 1 1 0 0
|1  0 0 0 0 0 0
|2  0 0 0 0 1 1
|3  0 0 0 0 0 0
|4  0 0 0 0 0 0
|5  0 0 0 0 0 0
```
Program Input : 

```
6
5
0 1
0 2
0 3
2 4
2 5 
0
BFS
0 1 2 3 4 5
```
- Starting Node : 0
- Program Output : 0 1 2 3 4 5
- Answer Key : 0 1 2 3 4 5
<p>&nbsp;</p>

This BFS program works as follows:

Test Case 1 as the example :
1. The starting node in variable `start` will be stored as the first element in `arr` which is a vector dynamic array of integer.
```
arr = [0]
```

2. Then it will find all index column in row 0 that has the value of 1 and then push it to the arr.
```
arr = [0, 1, 2, 3]
```
3. It continues to next element which is 1 and then find all element that has value of 1 in row 1 and push the column index (or node) to arr. Then it will continue to element 2 and so on until final element in the arr.

```
arr = [0, 1, 2, 3, 4, 5]
```

4. Each element in `arr` will be printed to the screen from the first element to the last element as the BFS traversal result. Notice that 0 is the First In in the beginning and also the First Out (first printed). This algorithm follows FIFO (First In First Out)/Queue rule.

<p>&nbsp;</p>


### BFS Test Case 2
Take a look at this directed graph that is taken from GeeksforGeeks. 

![](https://media.geeksforgeeks.org/wp-content/uploads/bfs-5.png)

Graph Example 2. Source : GeeksforGeeks

Adjacency Matrix  :
```
   |0 1 2 3
|0  0 1 1 0  
|1  0 0 1 0
|2  1 0 0 1
|3  0 0 0 1
```
Program Input  :
```
4
6
0 1
0 2
1 2
2 0
2 3
3 3
2
BFS
2 0 3 1
```
- Starting Node : 2
- Program Output : 2 0 3 1
- Answer Key : 2 0 3 1

<p>&nbsp;</p>

### BFS Test Case 3
![](https://i2.wp.com/algorithms.tutorialhorizon.com/files/2015/05/Graph-BFS.png)

Graph Example 3. Source : Tutorial Horizon

Adjacency Matrix :
```
   |0 1 2 3 4 5
|0  0 1 1 0 0 0
|1  0 0 1 1 0 0
|2  0 0 0 1 0 0 
|3  0 0 0 0 1 0
|4  1 1 0 0 0 1
|5  0 0 0 0 0 0
```

Program Input
```
6
9
0 1
0 2
1 2
1 3
2 3
3 4
4 0
4 1
4 5
0
BFS
0 1 2 3 4 5
```
- Starting Node : 0
- Program Output : 0 1 2 3 4 5
- Answer Key : 0 2 1 3 4 5
- Note : both answers are correct because it can go from 0 to 1 first and then 2 or 0 to 2 first then 1. The program output is ordered because it has been programmed to do so. 
<p>&nbsp;</p>

## BFS Test Case 4
![](https://www.thecrazyprogrammer.com/wp-content/uploads/2015/09/Breadth-First-Search-BFS-Program-in-C-2.jpg?ezimgfmt=rs:223x183/rscb1/ng:webp/ngcb1)

Graph Example 4. Source : The Crazy Programmer

Adjacency Matrix : 
```
   |0 1 2 3 4 5 6 7 8
|0  0 1 0 1 1 0 0 0 0
|1  0 0 1 0 1 0 0 0 0
|2  0 0 0 0 0 1 0 0 0
|3  0 0 0 0 1 0 1 0 0
|4  0 0 0 0 0 1 0 1 0 
|5  0 0 0 0 0 0 0 0 0
|6  0 0 0 0 1 0 0 1 0
|7  0 0 0 0 0 1 0 0 1
|8  0 0 0 0 0 0 0 0 0
```

Program Input
```
9
14
0 1
0 3
0 4
1 2
1 4
2 5
3 4
3 6
4 5
4 7
6 4
6 7
7 5
7 8
0
BFS
0 1 3 4 2 6 5 7 8
```

- Starting Node : 0
- Program Output : 0 1 3 4 2 6 5 7 8
- Answer Key : 0 1 3 4 2 6 5 7 8

<p>&nbsp;</p>

## DFS in The Program and DFS Test Cases
As an example of using DFS in the program and also to test this program's DFS capability, there are several DFS test cases to be carried out by this program.
<p>&nbsp;</p>

### DFS Test Case 1
Let's try this program to DFS traverse the Graph Example 1 above with 0 as the starting node.

Adjacency Matrix : 
```
   |0 1 2 3 4 5
|0  0 1 1 1 0 0
|1  0 0 0 0 0 0
|2  0 0 0 0 1 1
|3  0 0 0 0 0 0
|4  0 0 0 0 0 0
|5  0 0 0 0 0 0
```

Program Input :
```
6
5
0 1
0 2
0 3
2 4
2 5
0
DFS
0 1 2 4 5 3
```
- Starting Node : 0
- Program Output : 0 1 2 4 5 3
- Answer Key : 0 1 2 4 5 3

<p>&nbsp;</p>
This DFS Program works as follows :

Using Graph Example 1 as an example

1. The program will initialize `S` as a stack variable, the program also initialize `m_visited` an array of boolean with the size of `N` that stores boolean value of whether the member has been visited or not. Initially all `m_visited` elements are `false`. After that, the program will push `start` element or starting node to `S` and then element `start` in `m_visited` will be marked as `true`

```
m_visited = [true, false, false, false, false]
S = [0]
```

2. After that the program will store top element in variable `u`, pop top element, and print `u` to the screen
```
m_visited = [true, false, false, false, false]
u = 0
S = []

0
```

3. The program will find all elements in the adjacency matrix that has a value of 1 in row `u`, if the node has not been visited, it will be pushed into `S` and will be marked as visited. The search is traversed in row `u` from last index column to the first index column because of LIFO rule, while the program is intended traverse DFS in ordered manner so the search traverse must be backwards.
```
m_visited = [true, true, true, true, false, false]
u = 0
S = [3,2,1]

0
```

4. The process is repeated until `S` is empty (using while loop)
```
m_visited = [true, true, true, true, false, false]
u = 1
S = [3,2]

0 1
```

5. Next step
```
m_visited = [true, true, true, true, false, false]
u = 2
S = [3]

0 1 2
```

6. Next step
```
m_visited = [true, true, true, true, true, true]
u = 2
S = [3,5,4]

0 1 2
```

7. Next step
```
m_visited = [true, true, true, true, true, true]
u = 4
S = [3,5]

0 1 2 4
```

8. Next step

```
m_visited = [true, true, true, true, true, true]
u = 5
S = [3]

0 1 2 4 5
```

9. Next step
```
m_visited = [true, true, true, true, true, true]
u = 3
S = []

0 1 2 4 5 3
```

10. After `S` is empty, the loop stops and all the DFS traverse will be showed on screen

Notice that in step No.3 and step No.4, Node 1 is the last one that is pushed to `S` (Last In) but the first one that is popped, printed, and stored in `u` (First Out). The process is repeatedly processed until `S` is empty. This is because DFS follows LIFO (Last In First Out)/Stack rule.

<p>&nbsp;</p>

### DFS Test Case 2
![](https://i1.wp.com/algorithms.tutorialhorizon.com/files/2018/02/Graph-DFS-1.png?w=672&ssl=1)

DFS Graph Example 2. Source : Tutorial Horizon

Adjacency Matrix :
```
   |0 1 2 3 4 5
|0  0 1 1 0 0 0
|1  0 0 1 1 0 0
|2  0 0 0 1 0 0 
|3  0 0 0 0 1 0
|4  1 1 0 0 0 1
|5  0 0 0 0 0 0
```

Program Input :
```
6
9
0 1
0 2
1 2
1 3
2 3
3 4
4 0
4 1
4 5
0
DFS
0 1 3 4 5 2
```
- Starting Node : 0
- Program Output : 0 1 3 4 5 2
- Answer Key : 0 1 3 4 5 2

<p>&nbsp;</p>

### DFS Test Case 3
![](https://i.ibb.co/86RH7wj/graph2.jpg)

DFS Graph Example 3. Source : Algo Coding

Adjacency Matrix :
```
   |0 1 2 3 4 5 6
|0  0 1 1 1 0 0 0 
|1  0 0 0 0 0 1 1
|2  0 0 0 0 1 0 0
|3  0 0 1 0 1 0 0
|4  0 1 0 0 0 0 0
|5  0 0 0 0 0 0 0
|6  0 0 0 0 1 0 0
```

Program Input
```
7  
10
0 1
0 2
0 3
1 5
1 6
2 4
3 2
3 4
4 1
6 4
0
DFS
0 1 5 6 4 2 3
```
- Starting Node : 0
- Program Output : 0 1 5 6 4 2 3
- Answer Key : 0 1 5 6 4 2 3

<p>&nbsp;</p>

## Conclusion
BFS and DFS have their own advantages and disadvantages. Both are used according to what the user needs. BFS is commonly used to find the shortest path in the graph while DFS is commonly used to detect loops in the graph. The implemented algorithm in C++ might not be efficient. The program actually can be decomposed into several procedures and functions. Despite the inefficiency in the code writing, the program and algorithm work fully functional and work as expected. 

<p>&nbsp;</p>

## Reference
- GeeksforGeeks. 2020. *Difference between BFS and DFS*. https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/. Accessed on 7 June 2021.

- GeeksforGeeks. 2020. *Breadth First Search or BFS for a Graph*. https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/. Accessed on 6 June 2021.

- GeeksforGeeks. 2021. *Depth First Search or DFS for a Graph*. https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/. Accessed on 7 June 2021.

- Knowledge Center. 2020. *Iterative Depth First Search in Data Structure | DFS (Iterative) | C++ Java Python*. https://www.youtube.com/watch?v=TOwcZYkJ2ys&t=695s. Accessed on 7 June 2021.

- AlgoCoding.  2014. *Depth First Search – Java and Python implementation*. https://algocoding.wordpress.com/2014/08/25/depth-first-search-java-and-python-implementation/. Accessed on 8 June 2021.

- Tutorial Horizon. 2018. *Graph – Depth First Traversal*. https://algorithms.tutorialhorizon.com/graph-depth-first-traversal/. Accessed on 7 June 2021.

- cplusplus.com.  *Reference Stack*. https://www.cplusplus.com/reference/stack/stack/pop/. Accessed on 7 June 2021.

- Tutorial Horizon. 2015. *Breadth-First Search/Traversal in a Graph*. https://algorithms.tutorialhorizon.com/breadth-first-searchtraversal-in-a-graph/. Accessed on 7 June 2021.

- The Crazy Programmer. 2021. *Breadth First Search (BFS) Program in C*. https://www.thecrazyprogrammer.com/2015/09/breadth-first-search-bfs-program-in-c.html. Accessed on 7 June 2021.

- tutorialspoint. 2021. *Applications of DFS and BFS in Data Structures*. https://www.tutorialspoint.com/applications-of-dfs-and-bfs-in-data-structures*. Accessed on 8 June 2021.

- HIGHBROW. 2020. *Stacks And Queues*. https://gohighbrow.com/stacks-and-queues/. Accessed on 8 June 2021.

- FreelancingGig. 2019. *WHAT IS THE DIFFERENCE BETWEEN BFS AND DFS ALGORITHMS*. https://www.freelancinggig.com/blog/2019/02/06/what-is-the-difference-between-bfs-and-dfs-algorithms/. Accessed on 8 June 2021.
