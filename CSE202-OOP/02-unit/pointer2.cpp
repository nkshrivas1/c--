#include<iostream>
using namespace std;
class Car{
    public:
        string model;
        double* price;
        Car(string model,double p){
            // this model is belongs to the current object
            this->model = model;
            price = new double(p);
        }
        void start(){
            cout<< "Car model no: "+model+ " started"<<endl;
            cout<< "price of car is : "<< *price <<endl;
        }
        ~Car(){
            delete price;
        }
};
class Counter{
    private:
        int value;
    public:
        Counter(){value=0;}
        Counter& increment(){
            value++;
            return *this;
        }
        void display(){
            cout<< value << endl;
        }
};
int main(){
    Counter c;
    c.increment().increment();
    c.display();
    // create an array of cars where we will store our cars;
    Car cars[4]={
        Car("B-100",200000.89),
        Car("B-200",300000.89),
        Car("B-300",400000.89),
        Car("B-400",500000.89),
    };
    // cars[0].start();
    // traverse our car array and call start function
    for(Car c_s:cars){
        c_s.start();
    }

    // int x = 10;
    // int *p=&x;
    //Dynamic object
    // Car* c = new Car("B-100");
    // c->start();
    //to prevent  memory leak
    // delete c;
    // c=nullptr;
    // Car* cp=&c;



    //how do we call this start usin cp?
    // c.start();
    // (*cp).start();
    // cp->start();
    //Pointer to object
    //create a class product with name and price display
    //and access it using a pointer 
    return 0;
}