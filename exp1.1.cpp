#include <iostream>
#include <cstring>
using namespace std;
    static const int size = 100;
    int top = -1;
    int a[size];
    // char b[size];
class stack{ 
    public:
    void push(int value){
        if(top == size-1){
            cout << "element cannot be added, stack overflow!"<<endl;
        }
        else{
            top++;
            a[top] = value;
        }
    }
    void pop(){
        if (top == -1){
            cout << "stack underflow!"<<endl;
        }
        else {
            top--;
        }
    }
    void isempty(){
        if(top==-1){
            cout << "\nis empty";
        }
        else{
            cout << "\nis not empty";
        }
    }
    void isfull(){
        if(top == size-1){
            cout << "\nis full";
        }
        else{
            cout <<"\nis not full!";
        }
    }
    int peak(){
        if(top ==-1){
            cout << "-1";
        }
        else{
        cout << a[top];
    }
    }
};

int main (){
    stack mystack;
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.push(50);
    mystack.push(60);
    mystack.push(70);
    mystack.peak();
    mystack.isempty();
    mystack.isfull();
    string e = "hello";
}















// OUTPUT------------------

