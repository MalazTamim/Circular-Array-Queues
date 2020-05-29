#include<iostream>
#include<string>
using namespace std ; 

//arrays and pounters-> need to impleement a copy constructor and overload the assignement operator

class CircArrayQueue
{
        private:
            int* ptr; 
            int tail; 
            int head; 
            int capacity; 
            int arraySize; 

    public:

        CircArrayQueue(int c) ;
        // CircArrayQueue() ;
        int size() ;
        CircArrayQueue(CircArrayQueue& instance) ; //copy constr
        ~CircArrayQueue() ; //?
        CircArrayQueue& operator =(CircArrayQueue& instance) ; 
        void enqueue(int nb) ; 
        int dequeue() ; 
        
        void tostring() ; 
        bool isEmpty() ;
        bool isFull() ;
        int getHead() ;
        int getTail() ;


};
// CircArrayQueue :: CircArrayQueue() : capacity(5),head(0),tail(0) , ptr(new int[5]) , arraySize(0) {}

CircArrayQueue :: CircArrayQueue(int c) : capacity(c) , tail(0) , head(0) , arraySize(0) , ptr(new int[capacity]) {}
int CircArrayQueue :: size() { return arraySize ; } 
bool CircArrayQueue :: isEmpty() { return (arraySize==0) ; }
bool CircArrayQueue :: isFull() { return arraySize==capacity ;}
int CircArrayQueue :: getHead() { return ptr[head] ; } 
int CircArrayQueue :: getTail() { return ptr[tail-1] ; } //-1 bcz tail points to the element after the last one


void CircArrayQueue::enqueue(int nb) 
{
    if(arraySize== capacity) 
    {
        cout<<"Queue is full" ; 
    }
    
    else
    {
        ptr[tail] = nb ; 
        tail ++ ; 
        arraySize++ ; 
    }
    
    
} 

int  CircArrayQueue :: dequeue()
{
    if(arraySize==0) 
    {
        cout<<"Queue is empty" ; 
    }
   
    else
    {
        int tmp = head ; 
        head = (head +1) % capacity ; 
        arraySize-- ; 
        return ptr[tmp] ; 
    } 
    
    
}


void CircArrayQueue::tostring() 
{
    string total ; 
    total+="[";
     if(head<=tail)
    {
        for(int i = head ; i<tail ; i++)
        {
            total+=(to_string(ptr[i])) ; 
            total+=",";
        }
    }
    else
    {
        int i = head ; 
        while(i<capacity) //from head to the end
        {
            total+=(to_string(ptr[i]) ); 
            total+=",";
            i++ ; 
        }
        i = 0 ; 
        while (i<=tail) //from beginning to taol
        {
           total+=(to_string(ptr[i])) ; 
            total+=",";
            i++ ; 
        }
        
    }
    total +='\b' ; //to delete the last comma
    total +=']' ; 
    for(int i = 0; i<total.size();  i++)
    {
        cout<<total[i] ; 
    }
}

CircArrayQueue :: ~CircArrayQueue() 
{
    while(!isEmpty()) 
    {
        dequeue() ; 
    }
}

CircArrayQueue :: CircArrayQueue(CircArrayQueue& instance) 
{
    capacity = instance.capacity ; 
    head = instance.head ; 
    tail = instance.tail ; 
    arraySize = instance.arraySize ; 

    ptr = new int[capacity] ; 

    if(head <= tail)
    {
        for(int i = head ; i<=tail ; i++)
        {
            ptr[i] =instance.ptr[i] ; 
        }
    }
    else
    {
         int i = head ; 
        while(i<capacity)
        {
           ptr[i] = instance.ptr[i] ; 
           i++ ; 
        }
        i = 0 ; 
        while (i<=tail)
        {
          ptr[i] = instance.ptr[i] ; 
          i++ ; 
        }
    
    }
}

CircArrayQueue& CircArrayQueue::operator =(CircArrayQueue& instance) 
{
    capacity = instance.capacity ; 
    head = instance.head ; 
    tail = instance.tail ; 
    arraySize = instance.arraySize ; 
    ptr = new int[capacity] ; 
    if(head<=tail)
    {
        for(int i = head ; i<=tail ; i++)
        {
            ptr[i] =instance.ptr[i] ; 
        }
    }
    else
    {
         int i = head ; 
        while(i<capacity)
        {
           ptr[i] = instance.ptr[i] ; 
           i++ ; 
        }
        i = 0 ; 
        while (i<=tail)
        {
          ptr[i] = instance.ptr[i] ; 
          i++ ; 
        }
        
    }
    return(*this) ; 
}









int main()
{

    CircArrayQueue queue(4) ;
    cout << queue.isEmpty() << endl;
queue.enqueue(5);
queue.enqueue(1);
queue.enqueue(6);
queue.enqueue(7);
int x = queue.dequeue();
cout << queue.isFull() << endl;
cout << queue.size() << endl;
cout << queue.getHead() << endl;
cout << queue.getTail() << endl;
queue.enqueue(10);
cout << queue.isFull() << endl;
cout << queue.size() << endl;
cout << queue.getHead() << endl;
cout << queue.getTail() << endl;
queue.tostring() ;
    
}   

