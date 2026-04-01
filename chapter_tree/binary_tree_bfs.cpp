//2026-04-01
#include"../common/common.h"
 
/*层序遍历*/
 vector<int> levelorder(TreeNode*root)
{
        vector<int> vec; //保存输出序列
        queue<TreeNode*>que; //初始化队列，存放节点
        que.push(root);
        while(!que.empty()){
            TreeNode* newNode=que.front(); //父节点
            que.pop();
            vec.push_back(newNode->val); //保存节点值
            if(newNode->left)
            que.push(newNode->left); //左节点入队
            if(newNode->right)
            que.push(newNode->right); //右节点入队
        }
        return vec;
}

int main()
{
   TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout<< "初始化二叉树:" << endl;
    printTree(root);
    
    vector<int>result=levelorder(root);
    cout<<"层序遍历节点序列:"<<endl;
    printVector(result);
}
