#include <iostream>
using namespace std;

class Stack{
public:
    int size = 0;
	int top = -1; 
    char *items;

    Stack(int stackcap){ 
        size = stackcap;
        items = new char[size];
    }

    void push(char item){
        if(top == size-1){
            cout<<"Stack is full"<<endl;
        }else{
            top++;
            items[top] = item;
        }
    }

    char pop(){
        char item;
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }else{
            item = items[top];
            cout << "Element Popped: " << item << endl; //For better visualization 
            top--; 
        }
        return item;
    }
};

int main(){

    Stack z(5);

    z.push('O'); 
    z.push('P'); 
    z.push('Q');
	z.push('X'); 
    z.push('Z');
    

    while(z.top != -1){
        z.pop();
    }

    return 0;
}
