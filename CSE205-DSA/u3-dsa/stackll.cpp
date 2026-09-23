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
        cout << "Top element is: " << top->data << endl;
        return top->data;
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
int main(){
int result = 2 + 3 * 4;
cout << "Result of 2 + 3 * 4 is: " << result << endl;
}











