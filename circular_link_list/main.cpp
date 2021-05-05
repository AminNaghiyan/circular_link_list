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
    Circular_linked_list()
    {
        this->size=0 ;
        current=nullptr ;
    }
    ~Circular_linked_list()
    {
        node * tmp = this->current ;
        if ( current != nullptr ){
            do{
                node * tp = tmp;
                tmp = tmp->getnext() ;
                delete tp ;
            }
            while (tmp != current);
        }
        this->size = 0 ;
        this->current = nullptr ;
    }

    int getsize ()
    {
        return size ;
    }

    void push( int data )
    {
        node * tmp = new node ;

        tmp->setnext( this->current ) ;
        tmp->setdata( data );

        if ( this->current )
        {
            tmp->setprev( current->getprev() ) ;
            current->setprev( tmp );
            this->current = tmp ;
        }
        else
        {
            tmp->setprev( tmp ) ;
            this->current = tmp ;
        }

        this->size ++ ;
    }

    void pop( int data )
    {
        node * tmp = this->current ;
        while( tmp->getdata() != data )
        {
            tmp = tmp->getnext() ;
            if ( tmp == this->current )
                break ;
        }
        this->current = tmp ;
        this->pop() ;
    }

    void pop(int data);
    void push_after(int new_data,int pa_data);

    void push_befor(int new_data,int pb_data)
    {
        node *temp=new node() ;
        node *C=current ;
        int t=size ;
        while (t){
            if(C->getdata()==pb_data){

                if(this->size==1){
                    C->setnext(temp) ;
                    temp->setprev(C) ;
                    this->current=temp ;
                }
                else{
                    C->getprev()->setnext(temp) ;
                    temp->setprev(C->getprev()) ;
                }
                temp->setnext(C) ;
                temp->setdata(new_data) ;
                C->setprev(temp) ;
                this->size++ ;
                break;
            }
            C=C->getnext() ;
            t-- ;
        }
    }

    void print()
    {
        node * tmp = this->current ;
        if ( current != nullptr ){
            do{
                cout<< tmp->getdata() << endl ;
                tmp=tmp->getnext() ;
            }
            while (tmp != current);
        }
    }

};



int main(){



}
