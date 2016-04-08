#include <cstdlib>    
#include <iostream>    
using namespace std;   
 
#include "lnkStack.h"     
   
using namespace std;   
   
long fac(long n);   
   
int main(int argc, char *argv[])   
{
    int i;
    cin>>i;
    cout<<fac(i)<<endl;
}     
   
//ÀûÓÃÁ´Õ»Çó½×³Ë    
long fac(long n) {
    lnkStack<long> as(n);
    while (n!=0) {
        as.push(n);
        n--;
    }
    long s = 1;
    while (!as.isEmpty()) {
        s *= as.pop();
    }
    return s;
}      

  


