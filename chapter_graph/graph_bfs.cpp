//2026-04-20
#include"../common/common.h"
#include "./graph_adjacency_list.cpp"

/*广度优先遍历*/
vector<Vertex*> graphBFS(GraphAdjList&graph,Vertex*&started){
    //记录顶点遍历序列
    vector<Vertex*> vec;
    //队列实现
    queue<Vertex*> que;
    //visited用来记录访问过的顶点
    unordered_set<Vertex*> visited={started};
    que.push(started);
    while(!que.empty()){
        Vertex* top=que.front();
        que.pop();
        vec.push_back(top); //记录访问顶点
        for(Vertex* adjvertex:graph.adjList[top]){
            if(visited.count(adjvertex))
            continue; //跳过已经访问节点 
            que.push(adjvertex); //邻接表顶点加入队列
            visited.emplace(adjvertex); //将邻接表顶点标记为访问
        }
    }
    //队列为空时,结束循环
    //返回顶点遍历序列
    return vec;
}

int main() {
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]}, {v[1], v[4]},
                                      {v[2], v[5]}, {v[3], v[4]}, {v[3], v[6]}, {v[4], v[5]},
                                      {v[4], v[7]}, {v[5], v[8]}, {v[6], v[7]}, {v[7], v[8]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为\\n";
    graph.print();

    /* 广度优先遍历 */
    vector<Vertex *> res = graphBFS(graph, v[0]);
    cout << "\n广度优先遍历（BFS）顶点序列为" << endl;
    printVector(vetsToVals(res));

    // 释放内存
    for (Vertex *vet : v) {
        delete vet;
    }

    return 0;
}