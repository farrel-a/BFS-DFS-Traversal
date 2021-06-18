//16520373 - Farrel Ahmad
//BFS-DFS Program
//Internship Day-4 Dagozilla

#include <iostream>
#include "bfs_dfs.hpp"
#include <string>
#include <stack>
#include <vector>

bool isExist(std::vector <int> a, int n, int x)
{
    for (int i=0;i<n;i++)
    {
        if (a.at(i)==x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //N = Number of Nodes (0 - N-1) ; M = Edges ; i,j = iterator row, column ; start = starting node; mode = BFS or DFS
    int N; int M; int i; int j;int start; std::string mode;
    int a; int b; //variable edge from a to b
    std::cin>>N;
    std::cin>>M;
    int mat[N][N];    //adjacency matrix definition
    std::vector <int> arr;       //vector dynamic array of traversed result for BFS
    for (i=0;i<N;i++) //adjacency matrix initialization (all elements are set to 0)
    {
        for (j=0;j<N;j++)
        {
            mat[i][j] = 0;
        }
    }
    for (i=0;i<M;i++)
    {
        std::cin>>a>>b; //add edges
        mat[a][b]=1;    //edge from a to b is set to 1 in adjacency matrix
    }
    std::cin>>start;  //starting node input
    std::cin>>mode;   //mode input (BFS or DFS)

    if (mode == "BFS")  //BFS mode
    {
        // curr = current row
        // k = index to access arr sequentially, flag = while loop flag
        int curr; int k; bool flag;
        curr = start; flag = true; k = 0;
        arr.push_back(start); //set starting node as first element
        while (flag)
        {
            for (j=0;j<N;j++)
            {
                if (mat[curr][j] == 1) //find all edges in curr
                {
                    if (!(isExist(arr, arr.size(), j))) // if j is not exist in arr
                    {
                        arr.push_back(j); //push j to arr
                    }
                }
            }
            if (k==(arr.size()-1)) //k at final element in arr, traverse ended
            {
                flag = false;
            }
            else
            {k++;                   //next element in arr
            curr = arr.at(k);}      //current row in arr[k]
        }
        for (i=0;i<arr.size();i++)  //print BFS traversal to screen
        {
            std::cout<<arr.at(i);
            if (i!=(arr.size()-1))  //whitespace is not added after last element
            {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;     //endline after last element
    }

    else if (mode == "DFS")
    {
        bool m_visited[N]; int u;
        for (i=0;i<N;i++)  //initialize all member_visited element as false
        {
            m_visited[i] = false;
        }
        std::stack <int> S; //initialize stack S
        S.push(start);      //set first S element as start
        m_visited[start] = true; //mark element start as visited
        while (!S.empty())
        {
            u = S.top();  //store top element in u
            S.pop();      //pop top element
            std::cout<<u; //print popped element to screen
            for (j=(N-1);j>=0;j--) //find neighbor element of u and push to S if neighbor element has not been visited
            {
                if (mat[u][j]==1 && !m_visited[j])
                {
                    S.push(j);            //push j to S
                    m_visited[j] = true;  //mark j as visited
                }
            }
            if (!S.empty())  //whitespace is not added after last element
            {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl; //endline after last element
    }
    return 0;
}
