/*
Author: Roopam Mishra
Resources: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

COMMONLY USED FUNCTIONS DEFINED IN PRIORITY QUEUES:

1. priority_queue::empty()– empty() function returns whether the queue is empty.
2. priority_queue::size()– size() function returns the size of the queue.
3. priority_queue::top()– Returns a reference to the top most element of the queue
4. priority_queue::push()– push(g) function adds the element ‘g’ at the end of the queue.
5. priority_queue::pop()– pop() function deletes the first element of the queue.
6. priority_queue::swap()– This function is used to swap the contents of one priority queue with another priority queue of same type and size.

*/
**********************************************************************************************************************************************


/* CREATES A MAX HEAP */
************************

#include <iostream> 
#include <queue> 
typedef long long int ll;
using namespace std; 
void PRINTpq(priority_queue<ll> pq) 
{ 
	priority_queue<ll> p=pq; 
	while(!p.empty()) 
	{ 
		cout<<p.top()<<" "; 
		p.pop(); 
	} 
	cout<<endl; 
} 

int main () 
{ 
	priority_queue <ll> pq;
	pq.push(10); 
	pq.push(30); 
	pq.push(20); 
	pq.push(5); 
	pq.push(1); 
	cout<<"The priority queue is: "; 
	PRINTpq(pq); 
	cout<<"Size: "<<pq.size()<<endl; 
	cout<<"Top: "<<pq.top()<<endl; 
	cout<<"Pop: "; 
	pq.pop(); 
	PRINTpq(pq); 
	return 0; 
}


/* CREATES A MIN HEAP */
************************

#include <iostream> 
#include <queue> 
typedef long long int ll;
using namespace std; 
void PRINTpq(priority_queue<ll,vector<ll>,greater<ll>> pq) 
{ 
	priority_queue<ll,vector<ll>,greater<ll>> p=pq; 
	while(!p.empty()) 
	{ 
		cout<<p.top()<<" "; 
		p.pop(); 
	} 
	cout<<endl; 
} 

int main () 
{ 
	priority_queue <ll,vector<ll>,greater<ll>> pq;
	pq.push(10); 
	pq.push(30); 
	pq.push(20); 
	pq.push(5); 
	pq.push(1); 
	cout<<"The priority queue is: "; 
	PRINTpq(pq); 
	cout<<"Size: "<<pq.size()<<endl; 
	cout<<"Top: "<<pq.top()<<endl; 
	cout<<"Pop: "; 
	pq.pop(); 
	PRINTpq(pq); 
	return 0; 
}
