#include<iostream>
using namespace std;
class Heap
{

	int n;
	int *minheap,*maxheap;
	public:
		void get();
		void displayMin()
		{
			cout<<"Minimum mark are: "<<minheap[0]<<endl;
			cout<<" FULL ARRAY: "<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<minheap[i]<<endl;
			}
		}
		void displayMax()
		{
			cout<<"Maximum marks are: "<<maxheap[0,n-1]<<endl;
			cout<<" FULL ARRAY: "<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<maxheap[i]<<endl;
			}
		                                                             
		}
		void upAdjust(bool,int);
	};
		void Heap::get()
		{
			cout<<"Enter number of student: "<<endl;
			cin>>n;
			int k,l;
			minheap=new int[n];
			maxheap=new int[n];
			cout<<"Enter marks of student: "<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>k;
				minheap[i]=k;
				upAdjust(0,i);
				maxheap[i]=k;
				upAdjust(1,i);
			}
		}
		void Heap::upAdjust(bool m,int l)
		{
			int s;
			if(!m)
			{
				while(minheap[(l-1)/2]>minheap[l])
				 {
				 	s=minheap[l];
				 	minheap[l]=minheap[(l-1)/2];
				 	minheap[(l-1)/2]=s;
				 	l=(l-1)/2;
				 	if(l==-1)
				 	 break;
				 }
			}
			else
			{
				while(maxheap[(l-1)/2]<maxheap[l])
				 {
				 	s=maxheap[l];
				 	maxheap[l]=maxheap[(l-1)/2];
				 	maxheap[(l-1)/2]=s;
				 	l=(l-1)/2;
				 	if(l==-1)
				 	 break;
				 }
			}
		}
		
 int main()
		{
			Heap H;
			H.get();
			H.displayMin();
			H.displayMax();
			return 0;
		}

