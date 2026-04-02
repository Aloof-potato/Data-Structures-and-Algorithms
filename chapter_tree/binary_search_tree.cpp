//2026-04-02
#include"../common/common.h"

class BinarySearchTree 
{
    public:
    BinarySearchTree(){ //构造函数
        root=nullptr;
    }

    ~BinarySearchTree(){ //析构函数
       freeMemoryTree(root);
    }

    /*获取头结点*/
    TreeNode* getRoot(){
        return root;
    }

    /*查找某个节点值*/
    TreeNode* search(int num){
        TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->val<num) //num值大,在右子树中
            cur=cur->right;
            else if(cur->val>num) //num值小,在左子树中
            cur=cur->left;
            else break; //找到num值
        }
        return cur;
    }

    /*插入节点*/ //插入节点只会在最末端，不改变树的链状结构
    void Insert(int num){
        //树为空
        if(root==nullptr){
            root=new TreeNode(num);
            return;
        }

        TreeNode* cur=root; //cur记录当前节点
        TreeNode* pre=root; //pre记录父节点，便于插入
        while(cur!=nullptr){ //寻找空节点
            if(cur->val<num){
                pre=cur;
                cur=cur->right;
            }
            else if(cur->val>num){
                pre=cur;
                cur=cur->left;
            }
            else return;
        }
        TreeNode*newNode=new TreeNode(num); //创建新节点，值为num
        if(pre->val<num) //若num值大
        pre->right=newNode; //则形成右子树
        else 
        pre->left=newNode; //否则形成左子树
    }

    /*删除节点*/
    void Remove(int num){
        //树为空
        if(root==nullptr) 
        return; 
        TreeNode*cur=root;
        TreeNode*pre=root;
        //查找待删除节点
        while(cur!=nullptr){
            if(cur->val<num){
                pre=cur;
                cur=cur->right;
            }
            else if(cur->val>num){
                pre=cur;
                cur=cur->left;
            }
            else break; //找到待删除节点,此时cur为待删除节点,pre为cur的父节点
        }
        if(cur==nullptr) return; //不存在待删除节点
        //待删除节点没有或有1个子节点
        if(cur->left==nullptr||cur->right==nullptr){
            TreeNode* child;
            if(cur->left!=nullptr)
            child=cur->left; 
            else child=cur->right; //child涵盖了左子节点或右子节点或空子节点
            //使pre直接指向child的子节点
            if(pre->left==cur) //cur为pre的左节点
            pre->left=child;
            else //cur为pre的右节点
            pre->right=child;
            delete cur; //删除cur
        }
        //待删除节点有两个子节点
        else{
            TreeNode*temp=cur->right;  //用待删除节点的右子树中最左的节点(即右子树中值最小的点,但是对于左子树来说，值依然最大)替换待删除节点,保证大小顺序
            TreeNode*pretemp;
            while(temp->left!=nullptr){
                pretemp=temp; //pretemp为temp的父节点,便于断开与temp的连接
                temp=temp->left;
            }
            cur->val=temp->val;
            pretemp->left=nullptr; //释放temp前要先断开pretemp与temp的连接
            delete temp; //删除用来替换的节点
        }
    }
    private:
    TreeNode*root;
};

int main() {
    /* 初始化二叉搜索树 */
    BinarySearchTree *bst= new BinarySearchTree();
    // 请注意，不同的插入顺序会生成不同的二叉树，该序列可以生成一个完美二叉树
    vector<int> nums = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int num : nums) {
        bst->Insert(num);
    }
    cout << endl << "初始化的二叉树为\n" << endl;
    printTree(bst->getRoot());

     /* 查找节点 */
    TreeNode *node = bst->search(7);
    cout << endl << "查找到的节点对象为 " << node << "，节点值 = " << node->val << endl;

    /* 插入节点 */
    bst->Insert(16);
    cout << endl << "插入节点 16 后，二叉树为\n" << endl;
    printTree(bst->getRoot());

    /* 删除节点 */
    bst->Remove(1);
    cout << endl << "删除节点 1 后，二叉树为\n" << endl;
    printTree(bst->getRoot());
    bst->Remove(2);
    cout << endl << "删除节点 2 后，二叉树为\n" << endl;
    printTree(bst->getRoot());
    bst->Remove(4);
    cout << endl << "删除节点 4 后，二叉树为\n" << endl;
    printTree(bst->getRoot());

    // 释放内存
    delete bst;

    return 0;
}
