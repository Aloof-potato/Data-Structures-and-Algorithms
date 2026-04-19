//2026-04-19
#include"../common/common.h"

/* 基于邻接表实现的无向图类 */
class GraphAdjList
{
    private:
    //邻接表，key为顶点，val为顶点指向的链表(即该顶点的所有邻接点)
    //用vector代替链表，便于添加和删除顶点
   unordered_map<Vertex*,vector<Vertex*>> adjList;
   
   /*在邻接点列表中删除指定顶点*/
   void Remove(vector<Vertex*>& vec,  Vertex* v){
    vec.erase(remove(vec.begin(),vec.end(),v),vec.end());
   }

    public:
    /*构造函数*/
    //初始化
    GraphAdjList(const vector<vector<Vertex*>> &edges){ //edges为边的集合
        //添加所有顶点和边
        for(const vector<Vertex*> &vec:edges){
           addVertex(vec[0]);
           addVertex(vec[1]);
           addEdge(vec[0],vec[1]);
        }

    }

    /*添加边*/
    //添加边即在v1(v2)顶点指向链表中添加v2(v1)顶点
    void addEdge(Vertex* v1,Vertex* v2){
        //错误判断
        if (!adjList.count(v1) || !adjList.count(v2) || v1 == v2)
            throw invalid_argument("不存在顶点");
        //无向图，同时添加两个方向的边
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    /*删除边*/
    //删除边即在v1(v2)顶点指向链表中删除v2(v1)顶点
    void removeEdge(Vertex* v1,Vertex* v2){
        //错误判断
     if (!adjList.count(v1) || !adjList.count(v2) || v1 == v2)
        throw invalid_argument("不存在顶点");
       //在v1顶点指向链表中找到v2顶点并删除
       Remove(adjList[v1],v2);
       //在v2顶点指向链表中找到v1顶点并删除
       Remove(adjList[v2],v1);
    }

    /*添加顶点*/
    void addVertex(Vertex* v){
        adjList[v]; //在adjList中声明新的顶点
    }

    /*删除顶点*/
    void removeVertex(Vertex* v){
        //错误判断
        if (!adjList.count(v))
         throw invalid_argument("不存在顶点");
        for(auto &kv:adjList){
            auto &vec=kv.second; //邻接点列表
            Remove(vec,v); //删除邻接点链表中的目标顶点
        }
        adjList.erase(v);//从顶点列表中删除目标顶点
    }

    /*获取顶点数量*/
    int size(){
        return adjList.size();
    }

    /*打印邻接表*/
    void print(){
         cout << "邻接表 =" << endl;
        for (auto &adj : adjList) {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }

};

