/*
  Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the 
  stream formed by each insertion of X to the new stream.
    Example:
  Input:
  4
  5
  15
  1 
  3
  Output:
  5
  10
  5
  4

  Explanation:
  Testcase 1:
  Flow in stream : 5, 15, 1, 3
  5 goes to stream --> median 5 (5)
  15 goes to stream --> median 10 (5, 15)
  1 goes to stream --> median 5 (5, 15, 1)
  3 goes to stream --> median 4 (5, 15, 1, 3)
*/
#include <iostream>
using namespace std;
void max_heapify(int arr[],int i,int n)
{
    int l=2*i;
    int r=2*i+1;
    int max = i;
    if(l<=n && arr[l]>arr[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if(r<=n && arr[r]>arr[max])
    {
        max = r;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        max_heapify(arr,max,n);   
    }
}

void max_create_heap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        max_heapify(arr,i,n);
    }
}

void max_maitainheap(int arr[],int i)
{
    if(i/2==0)
    return;

    if(arr[i/2]<arr[i])
    {
        swap(arr[i/2],arr[i]);
        max_maitainheap(arr,i/2);
    }
}

void max_insertheapify(int arr[],int &n,int v)
{
    arr[++n]=v;
    max_maitainheap(arr,n);
}

void max_deleteheapify(int arr[],int &n)
{
    arr[1]=arr[n--];
    max_heapify(arr,1,n);
}

void min_heapify(int arr[],int i,int n)
{
    int l=2*i;
    int r=2*i+1;
    int max = i;
    if(l<=n && arr[l]<arr[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if(r<=n && arr[r]<arr[max])
    {
        max = r;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        min_heapify(arr,max,n);   
    }
}

void min_create_heap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        min_heapify(arr,i,n);
    }
}

void min_maitainheap(int arr[],int i)
{
    if(i/2==0)
    return;

    if(arr[i/2]>arr[i])
    {
        swap(arr[i/2],arr[i]);
        min_maitainheap(arr,i/2);
    }
}

void min_insertheapify(int arr[],int &n,int v)
{
    arr[++n]=v;
    min_maitainheap(arr,n);
}

void min_deleteheapify(int arr[],int &n)
{
    arr[1]=arr[n--];
    min_heapify(arr,1,n);
}

int main() {
	//code
	int n;
	cin>>n;
	int min_heap[n/2+1];
	int max_heap[n/2+1];
	int min_heap_size=0;
	int max_heap_size=0;
	int v;
	while(n--)                           // 1 based indexing is used in building heaps
	{
	   cin>>v;
	   if(max_heap_size==0)
	   {
	       max_insertheapify(max_heap,max_heap_size,v);
	       cout<<v<<endl;
	       continue;
	   }
	   if(v>max_heap[1])
	   {
	       min_insertheapify(min_heap,min_heap_size,v);
	   }
	   else
	   {
	       max_insertheapify(max_heap,max_heap_size,v);
	   }
	   if(min_heap_size-max_heap_size>1)
	   {
	       max_insertheapify(max_heap,max_heap_size,min_heap[1]);
	       min_deleteheapify(min_heap,min_heap_size);
	   }
	   else if(max_heap_size-min_heap_size>1)
	   {
	       min_insertheapify(min_heap,min_heap_size,max_heap[1]);
	       max_deleteheapify(max_heap,max_heap_size);
	   }
	   if(max_heap_size==min_heap_size)
	   {
	       cout<<(min_heap[1]+max_heap[1])/2<<endl;
	   }
	   else if(max_heap_size>min_heap_size)
	   {
	       cout<<max_heap[1]<<endl;
	   }
	   else
	   {
	       cout<<min_heap[1]<<endl;
	   }
	}
	return 0;
}
