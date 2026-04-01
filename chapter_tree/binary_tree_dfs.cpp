//2026-04-01
#include"../common/common.h"

vector<int>vec; //存储序列结果

//递归
/*前序遍历*/
void preOrder1(TreeNode*root)
{
    if(root==nullptr) return;
    vec.push_back(root->val); //根节点
    preOrder1(root->left); //左子树
    preOrder1(root->right);//右子树
}

/*中序遍历*/
void inOrder1(TreeNode*root)
{
    if(root==nullptr) return;
    inOrder1(root->left); //左子树
    vec.push_back(root->val); //根节点
    inOrder1(root->right); //右子树
}

/*后序遍历*/
void postOrder1(TreeNode*root)
{
    if(root==nullptr) return;
    postOrder1(root->left); //左子树
    postOrder1(root->right); //右子树
    vec.push_back(root->val); //根节点
}

//迭代
/*前序遍历*/ //栈实现
void preOrder2(TreeNode*root)
{
    stack<TreeNode*> st;
    if(root==nullptr) return;
    st.push(root); //根节点入栈
    while(!st.empty()){
        TreeNode* node=st.top(); 
        st.pop();
        vec.push_back(node->val); //访问中间节点
        if(node->right)
        st.push(node->right); //右节点先入栈
        if(node->left)
        st.push(node->left); //左节点后入栈 确保中左右顺序
    }
}

/*中序遍历*/
void inOrder2(TreeNode*root)
{
    stack<TreeNode*> st;
    if(root==nullptr) return;
    TreeNode* ptr=root; //跟踪指针
    while(ptr!=nullptr||!st.empty()){ //ptr不为空或栈不为空
        while(ptr!=nullptr){
            st.push(ptr); //中间节点入栈
            ptr=ptr->left;  
        }
     //此时ptr指向最左下的节点左边的空节点
        TreeNode* node=st.top(); //栈顶为最左下的节点
        st.pop();
        vec.push_back(node->val); //访问最左下的节点,同时也为中间节点
        ptr=node->right; //转向右子树
    }
}

/*后序遍历*/  //左右中=中右左+反转
void postOrder2(TreeNode*root)
{
    stack<TreeNode*>st;
    if(root==nullptr) return;
    st.push(root); //根节点入栈
    while(!st.empty()){
        TreeNode*node=st.top();
        st.pop();
        vec.push_back(node->val); //访问中间节点
        if(node->left) 
        st.push(node->left); //左节点先入栈
        if(node->right) 
        st.push(node->right); //右节点后入栈
    }
    //此时为中右左序列
    reverse(vec.begin(),vec.end());
    //反转为左右中序列
}

int main()
{
    TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout<< "初始化二叉树:" << endl;
    printTree(root);
    
    /*递归实现*/
    //前序遍历
    vec.clear();
    preOrder1(root);
    cout<<endl<<"递归法前序遍历序列为:"; printVector(vec);
    
    //中序遍历
    vec.clear();
    inOrder1(root);
    cout<<endl<<"递归法中序遍历序列为:"; printVector(vec);
    
    //后序遍历
    vec.clear();
    postOrder1(root);
    cout<<endl<<"递归法后序遍历序列为:"; printVector(vec);
    
    /*迭代实现*/
    //前序遍历
    vec.clear();
    preOrder2(root);
    cout<<endl<<"迭代法前序遍历序列为:"; printVector(vec);
    
    //中序遍历
    vec.clear();
    inOrder2(root);
    cout<<endl<<"迭代法中序遍历序列为:"; printVector(vec);
    
    //后序遍历
    vec.clear();
    postOrder2(root);
    cout<<endl<<"迭代法后序遍历序列为:"; printVector(vec);
}
