#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
    private:
        stack<int> s1;// enqueue 
        stack<int> s2;// dequeue
        // two stacks if we put our current stack up to 
        // down what will happen
        void transfer(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
    public:
        void push(int x){
            s1.push(x);
        }
        int pop(){
            if(empty()) return -1;
            transfer();
            int val = s2.top();
            s2.pop();
            return val;
        }
        int peek(){
            if( empty()) return -1;
            transfer();
            return s2.top();
        }
        bool empty(){
            return s1.empty() && s2.empty();
        }

};
int main(){
    MyQueue mq;
    mq.push(10);
    mq.push(20);
    mq.push(30);
    cout<< mq.pop() << endl;
    cout<< mq.pop() << endl;
    cout<< mq.pop() << endl;

    return 0;
}