#include <cstdlib>
#include <iostream>

#include "myStack.h"

using namespace std;

template <class T>
class Link {
public:
    T data;							// 用于保存结点元素的内容
    Link *next;							// 指向后继结点的指针
    Link(const T info, Link* nextValue)  {	// 具有两个参数的Link构造函数
        data = info;
        next = nextValue;
    }
    Link(Link* nextValue = NULL)  {			// 具有两个参数的Link构造函数
        next = nextValue;
    }
};

template <class T>
class lnkStack : public Stack <T>  {
private: 	                    			// 栈的链式存储
    Link<T> *top;						// 指向栈顶的指针
    int size;						// 存放元素的个数
public:                      				// 栈运算的链式实现
    lnkStack();
    lnkStack(int defSize);					// 构造函数
    ~lnkStack();							// 析构函数
    void clear();							// 清空栈内容
    void push(const T item);	    		// 入栈操作的链式实现
    T pop();						// 出栈的链式实现
    T getTop();					// 返回栈顶内容，但不弹出
    bool isEmpty();
};
template <class T>
lnkStack<T>::lnkStack(){
    top = NULL;
}
template <class T>
lnkStack<T>::lnkStack(int defSize){
    size = defSize;
    top = NULL;
}
template <class T>
lnkStack<T>::~lnkStack(){
    clear();
}
template <class T>
void lnkStack<T>::clear(){
    Link<T>* p = top;
    if (p) {
        Link<T>* d = p;
        delete d;
        
    }
}
template <class T>
void lnkStack<T>::push(const T item){
    Link<T>* n = new Link<T>(item, top);
    top = n;
}
template <class T>
T lnkStack<T>::pop(){
    if (top) {
        Link<T>* d = top;
        T x = d->data;
        top = top->next;
        delete d;
        return x;
    }else{
        cout<<"Stack Underflow.\n";
        return NULL;
    }
}
template <class T>
T lnkStack<T>::getTop(){
    if (top) {
        return top->data;
    }else{
        cout<<"Empty Stack.\n";
        return NULL;
    }
}
template <class T>
bool lnkStack<T>::isEmpty(){
    if (top) {
        return false;
    }else{
        return true;
    }
}