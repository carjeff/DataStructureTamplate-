// 邻接矩阵的深度和广度优先遍历
#include <iostream>
#include "Queue.h"
using namespace std;

#define MAXSIZE 9  // 队列储存空间初始分配量
#define MAXVEX 100 // 最大顶点数

// 邻接矩阵结构（无向图）
typedef struct
{
    char vexs[MAXVEX];       // 顶点表
    int arc[MAXVEX][MAXVEX]; // 边表
    int numNodes, numEdges;  // 图的顶点数、边数
} MGraph;

//生成邻接矩阵
void CreateMGraph(MGraph *G)
{
    int i, j; // 用于遍历元素
    int n;
    cout << "Please input the number of the nodes: " << endl;
    cin >> n;
    G->numNodes = n; //设置有n个顶点
    cout << "Please input the MGraph: " << endl;

    // 初始化图的边
    for (i = 0; i < G->numNodes; i++)
    {
        for (j = 0; j < G->numNodes; j++)
        {
            cin >> G->arc[i][j]; // 设置所有边的值都为0
        }
    }
}

//邻接矩阵广度优先算法
void BFSTraverse(MGraph G)
{
    int i, j;          // 用于遍历元素
    Queue<int> Q(100); // 队列
    // 访问标志的数组
    int visited[MAXVEX];
    // 初始设置图的所有顶点都没被访问过
    for (i = 0; i < G.numNodes; i++)
    {
        visited[i] = 0;
    }

    // 对每一个顶点做循环
    for (i = 0; i < G.numNodes; i++)
    {
        if (!visited[i])
        {                   // 该顶点未被访问过，进行处理
            visited[i] = 1; // 设置该顶点i已被访问
            cout << i << " ";

            Q.In(i); // 将该顶点i入队

            // 当队列非空时，进行循环
            while (!Q.IsEmpty())
            {
                i = Q.Out(); // 将队头元素出队，赋值给i

                // 遍历当前节点以外的节点j
                for (j = 0; j < G.numNodes; j++)
                {
                    // 若顶点j与当前节点存在边，并且未被访问过
                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = 1;   // 设置顶点j已被访问
                        cout << j << " "; // 打印顶点j的值

                        Q.In(j); // 将顶点j入队
                    }
                }
            }
        }
    }
}

int main()
{
    MGraph G;         // 邻接矩阵
    CreateMGraph(&G); // 创建邻接矩阵

    printf("\n BFS: ");
    BFSTraverse(G); // 广度遍历邻接矩阵

    return 0;
}