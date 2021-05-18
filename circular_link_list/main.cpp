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

        tmp->setdata( data ) ;

        if ( this->current )
        {
            this->current->getprev()->setnext( tmp ) ;
            tmp->setprev( current->getprev() ) ;
            tmp->setnext( this->current ) ;
            current->setprev( tmp ) ;
        }
        else
        {
            this->current = tmp ;
            this->current->setnext( tmp ) ;
            this->current->setprev( tmp ) ;
        }

        this->current = tmp ;
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
    void pop()
    {
        node * tmp = this->current ;
        node * tp = tmp;
        if(tmp->getnext()!= nullptr && tmp->getprev()!= nullptr)
        {
            tmp->getprev()->setnext(tmp->getnext());
            tmp->getnext()->setprev(tmp->getprev());
            tmp = tmp->getnext();
            current = tmp;
        }
        else
            current = nullptr;
        delete tp;
    }
    void push_after(int new_data,int pa_data)
        {
            node *temp=new node() ;
            node *C=current ;
            int t=size ;
            while (t){
                if(C->getdata()==pa_data){

                    if(this->size==1){
                        C->setprev(temp) ;
                        temp->setnext(C) ;
                        this->current=temp ;
                    }
                    else{
                        C->getnext()->setprev(temp) ;
                        temp->setnext(C->getnext()) ;
                    }
                    temp->setprev(C) ;
                    temp->setdata(new_data) ;
                    C->setnext(temp) ;
                    this->size++ ;
                    break;
                }
                C=C->getnext() ;
                t-- ;
            }
        }
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

    //git link : https://github.com/AminNaghiyan/circular_link_list

    // علیرضا جعفری دلیگانی 993623010
    // 993623041 محمد امین نقیان
    // محمد جواد صالحی دهنوی 993623027

    return 0;
}
