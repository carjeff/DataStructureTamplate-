#include<iostream>
using namespace std;
template<typename type>
class Vector{
    private:
        type *items; //分配后的数组
        type *preitems;//分配前的数组
        int capacity;//定义初始化的数组大小
        int length;//当前数组大小
        int itemsFlag;//当itemFlag= 0 用preitems进行存储，当itemFlag=1 用items进行存储
    public:
        Vector(int n):length(0),capacity(n){
            itemsFlag = 0;
            preitems = new type[capacity];
            if(preitems == NULL){
                cout<<"Memory allocation failed!"<<endl;
                exit(-1);
            }
            items = nullptr;
        }
        ~Vector(){
            if(preitems!= nullptr){
                delete[] preitems;
            }
            if(items!= nullptr)
            {
                delete[] items;
            }
        }
        bool CheckIndex(int index);//检查要操作的下标是否在数组容量范围内
        bool IsEmpty()//判断线性表是否空
        {
            return length == 0;
        }
        bool IsFull()//判断线性表是否满
        {
            return length == capacity;
        }
        int GetLength(){ //获取当前数组容量
            return length;
        }
        void Clear();
        void Insert(int index, type e);//添加对应下标的元素e
        type Delete(int index);
        type Get(int index); //获取对应下标元素
        void Set(int index, type e);//修改对应下标的元素
        bool Contains(type e);//查看线性表中是否存在某值
        int Find(type e);//查找线性表中是否存在某值
        void Expand();//扩大容量
        void Print();

};


template<typename type> bool Vector<type>::CheckIndex(int index){
    if(index<0 || index >= capacity){
        int cap = capacity - 1;
        cout<<"Out of range! Please ensure the index be in 0 ~ "<< cap << endl;
        return false;
    }
    return true;
}

template<typename type> type Vector<type>::Get(int index){
    if(CheckIndex(index))
    {
        if(!itemsFlag){
            return preitems[index];
        }
        else
        {
            return items[index];
        }   
    }
}

template<typename type> void Vector<type>::Set(int index, type e){
    if(CheckIndex(index)){
        if(!itemsFlag){
            preitems[index] = e;
        }
        else
        {
            items[index] = e;
        }
        
    }
}

template<typename type> bool Vector<type>::Contains(type e){
    for (int i = 0; i <= length - 1; i++)
    {
        if(!itemsFlag){
            if (e == preitems[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(e == items[i])
            {
                return true;
            }
            else
            {
                return false;
            }   
        }
    }
}

template<typename type> int Vector<type>::Find(type e){
 for (int i = 0; i <= length - 1; i++)
    {
        if(!itemsFlag){
            if (e == preitems[i])
            {
                cout<<"we find the "<<e<<" , the index is "<<i<<endl;
                return i;
            }
        }
        else
        {
            if(e == items[i])
            {
                cout<<"we find the "<<e<<" , the index is "<<i<<endl;
                return i;
            } 
        }
    }
    cout<<"The Vector don't have the element of "<<e<<endl;    
}

template<typename type> void Vector<type>::Expand(){
    cout<<"the Vector's capacity is too small, we should expand the capacity"<<endl;
    capacity = capacity + 1;
    if(!itemsFlag){
        itemsFlag = 1;
        items = new type[capacity];
        if(items == NULL){
            cout<<"Memory allocation is failed!";
            exit(-1);
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                *(items+i) = *(preitems + i);
            }
            delete[] preitems;
            preitems = nullptr;
        }
    }

    else
    {
        itemsFlag = 0;
        preitems = new type[capacity];
        if(preitems == NULL){
            cout<<"Memory allocation is failed!";
            exit(-1);
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                *(preitems+i) = *(items + i);
            }
            delete[] items;
            items = nullptr;
        }
    }
}


template<typename type> void Vector<type>::Insert(int index, type e){
    if(IsFull()){
        cout<<"The Vector is full! We will expand it."<<endl;
        Expand();
    }
    if(CheckIndex(index)){
        if(!itemsFlag){
            for (int i = length; i > index; i--)
            {
                preitems[i] = preitems[i-1];
            }
            preitems[index] = e;
        }
        else
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i-1];
            }
            items[index] = e;
        }
        length++;
    }
}


template<typename type> type Vector<type>::Delete(int index){
    if(!IsEmpty()){
        if(CheckIndex(index)){
            if(!itemsFlag){
                type temp = preitems[index];
                for(int i = index+1; i < length; i++){
                    preitems[i -1] = preitems[i];
                }
                length --;
                return temp;
            }
            else
            {
                type temp = items[index];
                for(int i = index+1; i < length; i++){
                    items[i -1] = items[i];
                }
                length --;
                return temp;
            }
        }
    }
    else
    {
        cout<<"Vector is empty!"<<endl;
        return -1;
    }
}

template<typename type> void Vector<type>::Print(){
    for(int i = 0; i< length; i++){
        if(!itemsFlag){
            cout<<preitems[i]<<' ';
        }
        else
        {
            cout<<items[i]<<' ';
        }
    }
    cout<<endl;
}