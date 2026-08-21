#include<iostream>
using namespace std;
// write a function to calculat volume of a cuboid
//scope - it defines the region of your code where a 
// variable or fun is visible , accessible
int cuboid(int l , int b, int h){
    return l * b* h;
}

class myclass{
    private:
        int private_variable;
        int* dataBuffer;
        void greet(){
            cout << " welcome to my class " << endl;
        }
    public:
        myclass(){
            dataBuffer = new int[100];
            private_variable = 10;
        }
    // destructor is a special member function that is automatically called 
    // when an object goes out of scope or is explicitly deleted,
    //  serving as the primary mechanism to free resources
    //  and prevent memory leaks.
        ~myclass(){
            delete[] dataBuffer;
            cout<< "resource cleaned" << endl;
        }
        friend class cse;
        // friend void friendfn(myclass & obj);
        int fact(int n){
            if(n == 0 || n== 1)
                return 1;
            return n*fact(n-1);
        }
};
// void friendfn(myclass &obj){
//     cout << " my class private variable" << obj.private_variable;
//     obj.greet();
// }


class cse{
    public:
        void greetings(myclass &c){
            cout << "hello" << c.private_variable << endl;
        }
};

int main(){
    cse c1;
    myclass my;
    // c1.greetings(my);
    // friendfn(my);
}