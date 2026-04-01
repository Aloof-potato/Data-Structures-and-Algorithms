//2026-04-01
#include"../common/common.h"
int main()
{
    //初始化节点
    TreeNode*n1=new TreeNode(1);
    TreeNode*n2=new TreeNode(2);
    TreeNode*n3=new TreeNode(3);
    TreeNode*n4=new TreeNode(4);
    TreeNode*n5=new TreeNode(5);
    //连接节点，构建二叉树
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5; 
    cout<<"初始化二叉树后:"<<endl;
    printTree(n1);
    /*插入与删除节点*/
    TreeNode*p=new TreeNode(0);
    //在n1与n2间插入节点p
    n1->left=p; 
    p->left=n2; 
    cout<<"插入节点p后:"<<endl;
    printTree(n1);
    //删除节点p
    n1->left=n2;
    //释放内存
    delete p; //直接删除p即可,不用调整p的指针
    cout<<"删除节点p后:"<<endl;
    printTree(n1);
    //释放树内存
    freeMemoryTree(n1);
    return 0;
}
