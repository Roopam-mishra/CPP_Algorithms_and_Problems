/*
RESOURCES: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
*/
****************************************************************************************

#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
// function to calculate med of stream 
void printMedians(int arr[], int n) 
{ 
	// max heap to store the smaller half elements 
	priority_queue<double> s; 
	// min heap to store the greater half elements 
	priority_queue<double,vector<double>,greater<double> > g; 
	double med = 1.0*arr[0]; 
	s.push(arr[0]); 
	cout << med << endl; 
	// reading elements of stream one by one 
	/* At any time we try to make heaps balanced and 
		their sizes differ by at-most 1. If heaps are 
		balanced,then we declare median as average of 
		min_heap_right.top() and max_heap_left.top() 
		If heaps are unbalanced,then median is defined 
		as the top element of heap of larger size */
	for (int i=1; i < n; i++) 
	{ 
		double x = 1.0*arr[i]; 
		// case1(left side heap has more elements) 
		if (s.size() > g.size()) 
		{ 
			if (x < med) 
			{ 
				g.push(s.top()); 
				s.pop(); 
				s.push(x); 
			} 
			else
				g.push(x); 

			med = (s.top() + g.top())/2.0; 
		} 
		// case2(both heaps are balanced) 
		else if (s.size()==g.size()) 
		{ 
			if (x < med) 
			{ 
				s.push(x); 
				med = (double)s.top(); 
			} 
			else
			{ 
				g.push(x); 
				med = (double)g.top(); 
			} 
		} 
		// case3(right side heap has more elements) 
		else
		{ 
			if (x > med) 
			{ 
				s.push(g.top()); 
				g.pop(); 
				g.push(x); 
			} 
			else
				s.push(x); 

			med = (s.top() + g.top())/2.0; 
		} 
		cout << med << endl; 
	} 
} 
int main() 
{ 
    int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	printMedians(a,n);
	return 0; 
} 
