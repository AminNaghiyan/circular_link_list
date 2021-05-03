#include <bits/stdc++.h>
using namespace std;

class node{
private:
    int data;
    node* next;
    node* prev;
public:
    void setdata (int Data)
    {
        this->data=Data ;
    }

    int getdata ()
    {
        return this->data ;
    }

    void setnext (node *next)
    {
        this->next=next ;
    }

    node *getnext ()
    {
        return this->next;
    }

    void setprev (node *prev)
    {
        this->prev=prev ;
    }

    node *getprev ()
    {
        return this->prev ;
    }
};
class Circular_linked_list{
private:
    int size;
    node* current;
public:
    Circular_linked_list();
    ~Circular_linked_list();

    int getsize ()
    {
        return size ;
    }

    void push();
    void pop();
    void pop(int data);
    void push_after(int new_data,int pa_data);
    void push_befor(int new_data,int pb_data);
    void print();


};



int main(){



}
