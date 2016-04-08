#include <cstdlib>
#include <iostream>

#include "myStack.h"

using namespace std;

template <class T>
class Link {
public:
    T data;							// ���ڱ�����Ԫ�ص�����
    Link *next;							// ָ���̽���ָ��
    Link(const T info, Link* nextValue)  {	// ��������������Link���캯��
        data = info;
        next = nextValue;
    }
    Link(Link* nextValue = NULL)  {			// ��������������Link���캯��
        next = nextValue;
    }
};

template <class T>
class lnkStack : public Stack <T>  {
private: 	                    			// ջ����ʽ�洢
    Link<T> *top;						// ָ��ջ����ָ��
    int size;						// ���Ԫ�صĸ���
public:                      				// ջ�������ʽʵ��
    lnkStack();
    lnkStack(int defSize);					// ���캯��
    ~lnkStack();							// ��������
    void clear();							// ���ջ����
    void push(const T item);	    		// ��ջ��������ʽʵ��
    T pop();						// ��ջ����ʽʵ��
    T getTop();					// ����ջ�����ݣ���������
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