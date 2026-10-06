#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class stackll{
    Node* top;
    //size of stack
    int size;
    public:
    stackll(){
        top = nullptr;
        size = 0;
    }
    void push(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        size++;
    }
    void pop(){
        if(top == nullptr){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int peek(){
        if(top == nullptr){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool empty(){
        return size == 0;
    }
    void display(){
        if(top == nullptr){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
};
// precedence table
//highest precedence ^
// high *,/,% left to right
// low +,- left to right
// infix notation to postfix notation
//step 1 - initialize stack and empty ans string
//step 2 - scan the infix expression from left to right
//step 3 - if the scanned character is an operand,
//  add it to the ans string
//step 4 - if the scanned character is a left parenthesis (
//  push it to the stack
//step 5 - if the scanned character is a right 
// parenthesis ) pop from the stack and add it to the ans string
//  until a left parenthesis is encountered. pop 
// and discard the left parenthesis
// step 6- if the token is an operator( +,-,*,/,%
//  pop from the stack and add it to the ans string
//  until an operator with lower precedence is encountered.
//  push the scanned operator to the stack\
//step 7 empty the stack and add it to the ans string
int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/' || c == '%') return 2;
    if(c == '^') return 3;
    return 0;
}
string infixToPostfix(string s){
    stackll st;
    string ans = "";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') 
                || (c>='0' && c<='9')){
            ans += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(st.getSize() > 0 && st.peek() != '('){
                ans += st.peek();
                st.pop();
            }
            st.pop();
        }
        else{
            while(st.getSize() > 0 && precedence(c) <= precedence(st.peek())){
                ans += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
    while(st.getSize() > 0){
        ans += st.peek();
        st.pop();
    }
    return ans;
}
// to find prefix follow three steps
// step 1 - reverse the infix expression
// step 2 - replace ( with ) and vice versa
// step 3 - get the postfix expression of the modified expression
// step 4 - reverse the postfix expression to get the prefix expression
string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    } 
    string ans = infixToPostfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}
// find the next greater element of each element in an array
//step 1- pop elements from stack that are less than or
//  equal to the current element
//step 2 if stack is not empty top element is the NGE
// pstep 3 push the current element into stack
void nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stackll stk;
    for(int i =n-1;i>=0;i--){
        while(!stk.empty() && stk.peek() <= arr[i])
            stk.pop();
        if(!stk.empty())
            ans[i]=stk.peek();
        stk.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
}
int main(){
string postfix = infixToPostfix("a+b-c*d/(a-b+c)");
string prefix = infixToPrefix("a+b-c*d/(a-b+c)");

cout << "Postfix of a+b-c*d/(a-b+c) is: " << postfix << endl;
cout << "Prefix of a+b-c*d/(a-b+c) is: " << prefix << endl;
// Postfix of a+b-c*d/(a-b+c) is: ab+cd*ab-c+/-
// Prefix of a+b-c*d/(a-b+c) is: +a-b*c/d-a+bc
//step 1 = read the postfix from left to right
//step 2= if the symbol is an operand , then push it onto stack
////step 3- if an operator pop two operands and 
// add the operator before them 
// string = operator + operand 2 + operand 1;
// and push string to the stack again
}











