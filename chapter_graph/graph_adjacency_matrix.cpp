//2026-04-19
#include"../common/common.h"

/* 基于邻接矩阵实现的无向图类 */
typedef int vertex; //区分顶点和整型
class GraphAdjMat
{
 private:
  vector<int> vertices; //顶点列表
  vector<vector<int>> martix; //邻接矩阵

 public:
 /*构造函数*/
 //传入顶点和边
 GraphAdjMat(const vector<int> &vertices,const vector<vector<int>> &edges){
    //添加顶点
    for(int i=0;i<(int)vertices.size();i++){
        addVertex(vertices[i]);
    } 
    //添加边
    //edges元素为顶点索引
    for(int i=0;i<(int)edges.size();i++){
        addEdge(edges[i][0],edges[i][1]);
    }
 }

 /*获取顶点数量*/
 int size() const {
    return vertices.size();
 }

 /*添加顶点*/
 void addVertex(vertex v){ //此处vertex为顶点数据
    int n=size();
    //把该顶点值传入顶点列表
    vertices.push_back(v);
    //处理邻接矩阵
    //先添加一行0
    martix.emplace_back(vector<int>(n,0)); //emplace_back可以直接传构造参数
    //在添加一列0
    for(int i=0;i<n+1;i++)
    martix[i].push_back(0);
 }

 /*添加边*/
 void addEdge(int v1,int v2){ //此处为顶点索引
    //无向图需要同时更新
    martix[v1][v2]=1;
    martix[v2][v1]=1;
 }

 /*删除顶点*/
 void removeVertex(int k){ //此处为顶点索引
    //删除顶点列表中的该顶点
    vertices.erase(vertices.begin()+k);
    //删除邻接矩阵中该顶点位于的行和列
    //先删除该顶点位于的行
    martix.erase(martix.begin()+k);
    //再对每一行删除该顶点位于的列
    for(auto &row:martix){
    row.erase(row.begin()+k);
    }
 }
 
 /*删除边*/
 void removeEdge(int v1,int v2){ //此处为顶点索引
    //无向图需要同时更新
    martix[v1][v2]=0;
    martix[v2][v1]=0;
 }

/*打印*/
 void print(){
    cout << "顶点列表 = ";
        printVector(vertices);
        cout << "邻接矩阵 =" << endl;
        printVectorMatrix(martix);
 }

};

int main() {
    /* 初始化无向图 */
    // 请注意，edges 元素代表顶点索引，即对应 vertices 元素索引
    vector<int> vertices = {1, 3, 2, 5, 4};
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}};
    GraphAdjMat graph(vertices, edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 添加边 */
    // 顶点 1, 2 的索引分别为 0, 2
    graph.addEdge(0, 2);
    cout << "\n添加边 1-2 后，图为" << endl;
    graph.print();

    /* 删除边 */
    // 顶点 1, 3 的索引分别为 0, 1
    graph.removeEdge(0, 1);
    cout << "\n删除边 1-3 后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    graph.addVertex(6);
    cout << "\n添加顶点 6 后，图为" << endl;
    graph.print();

    /* 删除顶点 */
    // 顶点 3 的索引为 1
    graph.removeVertex(1);
    cout << "\n删除顶点 3 后，图为" << endl;
    graph.print();

    return 0;
}