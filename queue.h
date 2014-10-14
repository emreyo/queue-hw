#include <iostream>
#include <assert>

template <class T>					// Queue class definition
class Queue
{
	private:
		int maxsize;            	//maximum size of the queue
		int count;              	//number of elements
		int frontValue, rearValue;        	//front and rear values of the queue
		T * list;               	//pointer list
	public:
		Queue(int=100);         	//if no input is given when creating the queue, default size is 100
		~Queue (){delete [] list;} //destructor
		bool isEmpty (){return count==0;} //if queue is empty, returns 1, 0 otherwise
		bool isFull () {return count==maxsize;} //if queue is full returns 1, 0 otherwise
		void destroyQueue();       //destroys the queue
		T front();                 //returns the front element
		T back();                  //returns the rear element
		void insert (T& item);     //insert an element
		T deleteElement();         //deletes element
		int countQueue(){return count;}       //returns the number of elements, the count
};

template <class T>
Queue<T>::Queue(int size)        //constructor
{
	maxsize = size;               //assign size to queue's size
	list = new T[maxsize];        //create queue dynamically with the given size
	frontValue = 0;                   //front is 0
	rearValue = maxsize - 1;             //rear is one less of maxsize
	count = 0;                      //no elements
}

template <class T>
void Queue<T>::destroyQueue()   //destroyQueue() func
{
	frontValue = count = 0;      //front value and queue element number is 0
	rearValue = maxsize - 1;
}

template <class T>
T Queue<T>::front()            //front() func
{
	assert(!isEmpty());         //if empty queue(no front value), terminate the program
   return list[frontValue];    //return the front value
}

template <class T>
T Queue<T>::back()            //back() func
{
	assert(!isEmpty());        //if empty queue(no rear value), terminate the program
	return list[rearValue];    //return the rear value
}

template <class T>
void Queue<T>::insert(T& item) //insert() func
{
	if(!isFull())               //if the queue is not full, add element, update counter(increment by 1)
	{
		rearValue = (rearValue + 1) % maxsize;
		list[rearValue] = item;
		count++;
	}

	else                       //if the queue is full
		cout << "List is full"; //tell the user that the list is full
}

template <class T>
T Queue<T>::deleteElement()   //deleteElement() func
{
	T var;		//a var variable of the type T

	assert(!isEmpty());	//if list is empty, terminate the program

	var = list[frontValue];
	frontValue = (frontValue + 1) % maxsize;
	count--;

	return var;
}
