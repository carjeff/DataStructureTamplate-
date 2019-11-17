#include<iostream>
using namespace std;

template<typename type> class list;

template<typename type> class LNode{
    public:
        type data;
        LNode *pnext;
    public:
        LNode():pnext(NULL){}
        LNode(const type item, LNode<type> *next=NULL):data(item),pnext(next){}
        ~LNode(){
            pnext=NULL;
        }
        type GetData();
};
template<typename type> type LNode<type>::GetData(){
    return this->data;
}

template<typename type> class list{
    private:
        LNode<type> *head;
    public:
		list():head(new LNode<type>()) {}
		~list(){
			Clear();
			delete head;
		}
        void Clear();//清空链表
        int Length();//获取链表长度
        void Insert(type item, int n=0);//插入对应位置元素item,默认位置为第一个位置
        type Find(int n); //查找位置n的元素值
        type Delete(int n=0); //删除对应n位置的数据
        type Get(int n);//获取n位置的数据
        void Print();
};

template<typename type> void list<type>::Clear(){
    LNode<type> *pdel;
    while (head->pnext != NULL) 
    {
        pdel = head->pnext;
        head->pnext=pdel->pnext;
        delete pdel;
    }
}

template<typename type> int list<type>::Length(){
    LNode<type> *pmove = head ->pnext;
    int count = 0;//计数器
    while (pmove!=NULL) 
    {
        pmove = pmove->pnext;
        count++;
    }
    return count;
}

template<typename type> void list<type>::Insert(type item,int n){
    if(n<0){
        cout<<"Insert position is illegal"<<endl;
    }
    LNode<type> *pmove = head;
    LNode<type> *pnode = new LNode<type>(item);//申请一个节点空间
    if (pnode == NULL)
    {
        cout<<"Memery allocation is failed!"<<endl;
    }
    for (int i =0; i<n && pmove; i++) //寻找对应n的节点位置
    {
        pmove = pmove ->pnext;
    }
    
    if(pmove==NULL){
        cout<<"Insert error!"<<endl;
    }
    pnode->pnext = pmove->pnext;
    pmove->pnext = pnode;
}

template<typename type> type list<type>::Find(int n){
    if(n<0){
        cout<<"Find position is illeagal"<<endl;
    }
    LNode<type> *pmove = head->pnext;
    for(int i =0; i<n && pmove; i++){
        pmove = pmove->pnext;
    }
    if(pmove==NULL){
        cout<<"Can't find the position"<<endl;
    }
    return pmove->data;
}

template<typename type> type list<type>::Delete(int n){
    if(n<0){
        cout<<"the position is wrong!"<<endl;
    }
    LNode<type> *pmove = head, *pdel;
    for (int i=0; i<n&&pmove->pnext; i++)//一直遍历直到找到第n个元素
    {
        pmove = pmove->pnext; 
    }
    if(pmove->pnext == NULL){
        cout<<"Can't find this element"<<endl;
    }

    //进行删除
    pdel = pmove -> pnext;
    pmove->pnext = pdel -> pnext;
    type temp = pdel -> data;
    delete pdel;
    return temp;
}

template<typename type> type list<type>::Get(int n){
    if(n<0){
        cout<<"the position is wrong!"<<endl;
    }
    LNode<type> *pmove = head;
    for (int i =0 ; i<n ; i++)
    {
        pmove= pmove->pnext;
        if(pmove->pnext == NULL){
            cout<<"can't find this element"<<endl;
        }
    }
    type temp=pmove->pnext->data;
    return temp;
}

template<typename type> void list<type>::Print(){
    LNode<type> *pmove = head->pnext;
    cout<<"head";
    while (pmove)
    {
        cout<<"--->"<<pmove->data;
        pmove = pmove->pnext;
    }
    cout<<"--->over"<<endl;
}