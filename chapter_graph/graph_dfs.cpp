//2026-04-20
#include"../common/common.h"
#include "./graph_adjacency_list.cpp"

/*深度优先遍历辅助函数*/
void dfs(GraphAdjList&graph,Vertex* &started,unordered_set<Vertex*>& visited,vector<Vertex*>&vec){
    vec.push_back(started); //记录遍历顶点
    visited.emplace(started); //标记访问顶点
    //对该顶点的每个邻接点递归使用dfs
    for(auto adjvertex:graph.adjList[started]){
        //跳过已经访问过的顶点
        if(visited.count(adjvertex))
        continue;
        dfs(graph,adjvertex,visited,vec);
    }
}

/*深度优先遍历*/
vector<Vertex*> graphDFS(GraphAdjList&graph,Vertex* &started){
    //vec用来记录遍历顶点序列
    vector<Vertex*> vec;
    //visited用来记录访问过的顶点
    unordered_set<Vertex*> visited;
    //调用dfs
    dfs(graph,started,visited,vec);
    //返回遍历序列
    return vec;
}

int main() {
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{0, 1, 2, 3, 4, 5, 6});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[5]}, {v[4], v[5]}, {v[5], v[6]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 深度优先遍历 */
    vector<Vertex *> res = graphDFS(graph, v[0]);
    cout << "\n深度优先遍历（DFS）顶点序列为" << endl;
    printVector(vetsToVals(res));

    // 释放内存
    for (Vertex *vet : v) {
        delete vet;
    }

    return 0;
}
