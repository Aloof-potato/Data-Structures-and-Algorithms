//2026-04-12
#include"../common/common.h"

class MaxHeap
{
    public:
    /*构造函数:用输入列表建堆*/
    MaxHeap(vector<int>&heap){
       //将列表不变的添加到堆中
        Maxheap=heap;
       //从最后一个非叶子节点开始，倒序遍历，对每个非叶子节点进行自顶向底堆化操作
       for(int i=parent(size()-1);i>=0;i--){
        siftDown(i);
       }
    }

    /*获取堆顶元素*/
    int peek(){
        return Maxheap[0];
    }

    /*元素入堆*/
    void push(int val){
        //将该元素添加到堆底
        Maxheap.push_back(val);
        //从底至顶对该节点进行堆化
        siftUp(size()-1);
    }

    /*堆顶元素出堆*/
    void pop(){
        //将堆顶元素和堆底元素交换
        swap(Maxheap[0],Maxheap.back());
        //弹出当前的堆底元素(即原来的堆顶元素)
        Maxheap.pop_back();
        siftDown(0);
    }

    /*判断堆是否为空*/
    bool isEmpty(){
        if(size()==0)
        return true;
        else return false;
    }

    /*获取堆大小*/
    int size(){
        return Maxheap.size();
    }

    /*打印堆*(二叉树)*/
    void print(){
         cout << "堆的数组表示：";
        printVector(Maxheap);
        cout << "堆的树状表示：" << endl;
        TreeNode *root = vectorToTree(Maxheap);
        printTree(root);
        freeMemoryTree(root);
    }

    private:
    vector<int> Maxheap; //堆底层为数组表示
    
    /*获取节点索引*/
    //获取左子节点索引
    int left(int i){
        return 2*i+1;
    }
    
    //获取右子节点索引
    int right(int i){
        return 2*i+2;
    }

    //获取父节点索引
    int parent(int i){
        return (i-1)/2;
    }
    
    /*从节点i开始,从底至顶堆化*/ 
    void siftUp(int i){
        while(true){
            //获取节点i的父节点索引
            int p=parent(i); 
            //若越过根节点或无需交换时结束
            if(p<0||Maxheap[i]<=Maxheap[p]) 
             break;
            //交换两节点
            swap(Maxheap[i],Maxheap[p]);
            //循环向上堆化
             i=p; 
        }
    }

    /*从节点i开始,从顶至底堆化*/ 
    void siftDown(int i){
        while(true){
        int l=left(i),r=right(i),max1=i; //先假设i节点最大
        if(l<size()&&Maxheap[l]>Maxheap[max1])
         max1=l;
        if(r<size()&&Maxheap[r]>Maxheap[max1]) //此时的max1为left和i中较大的那一个
         max1=r;
        //此时的max1即为left,right,i中较大的那一个
        if(max1==i) 
         break; //如果i已经最大,则停止堆化
        swap(Maxheap[i],Maxheap[max1]); //否则交换i节点和较大的子节点
        //循环向下堆化
        i=max1;
     }
    }
};

int main() {
    /* 初始化大顶堆 */
    vector<int> vec{9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2};
    MaxHeap maxHeap(vec);
    cout << "\n输入列表并建堆后" << endl;
    maxHeap.print();

    /* 获取堆顶元素 */
    int peek = maxHeap.peek();
    cout << "\n堆顶元素为 " << peek << endl;

    /* 元素入堆 */
    int val = 7;
    maxHeap.push(val);
    cout << "\n元素 " << val << " 入堆后" << endl;
    maxHeap.print();

    /* 堆顶元素出堆 */
    peek = maxHeap.peek();
    maxHeap.pop();
    cout << "\n堆顶元素 " << peek << " 出堆后" << endl;
    maxHeap.print();

    /* 获取堆大小 */
    int size = maxHeap.size();
    cout << "\n堆元素数量为 " << size << endl;

    /* 判断堆是否为空 */
    bool isEmpty = maxHeap.isEmpty();
    cout << "\n堆是否为空 " << isEmpty << endl;

    return 0;
}