#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	int value;
	node *next;
}*hashtable[10];
class hashing
{
	public:
		hashing()
		{
			for(int i=0;i<10;i++)
			{
				hashtable[i]==NULL;
			}
			
		}
		int hashfunction(int a)
			{
				int a1=a%10;
				return a1;
			}
		node*create_node(int x)
		{
			node*temp=new node;
			temp->value=x;
			temp->next=NULL;
			return temp;
			
		}
		void display()
		{
			for( int i=0;i<10;i++)
			{
				node*temp=new node;
				temp=hashtable[i];
				cout<<"a["<<i<<"]"<<endl;
				while(temp!=NULL)
				{
					cout<<"->"<<temp->value;
					temp=temp->next;
				}
				cout<<"\n";
				
			}
		}
			int searchelement(int value)
			{
				bool flag=false;
				int hash_val=hashfunction(value);
				node*entry=hashtable[hash_val];
				cout<<"\n element found at index : ";
				while(entry!=NULL){
					if(entry->value==value)
					{
						cout<<hash_val<<":"<<entry->value<<endl;
						flag=true;
					}
					entry=entry->next;
				}
				if(!flag){
					return -1;
				}
			}
			void   deleteElement(int value)
			{
				
				int hash_val=hashfunction(value);
				node*entry=hashtable[hash_val];
			
				if(entry==NULL){
					cout<<"No element found at key ";
					return;
					
			    }
			    
				else if(entry->value==value)
				{
					hashtable[hash_val]=entry->next;
					return;
					
				}
				else
				{
				
				while((entry->next)->value!=value)
				{
					entry=entry->next;
					return;
				}
			}
				entry->next=(entry->next)->next;
				
			}
			 void insertElement(int value)
			 
			 {
			 	int hash_val=hashfunction(value);
			 	node*temp=new node;
			 	node*head=new node;
			 	head=create_node(value);
			 	temp=hashtable[hash_val];
			 	if(temp==NULL)
			 	{
			 		hashtable[hash_val]=head;
				 }
				 else
				 {
				 	while(temp->next!=NULL)
				 	{
				 		temp=temp->next;
					 }
					 temp->next=head;
				 }
			 }
			
		
       };
	int main()
	{
		int ch;
		int data,search,del;
		hashing h;
		do
		{
			cout<<"\n Telephone : \n 1.Insert \n 2.display \n 3.search \n 4.Delete \n 5.Exit\n";
			cout<<"\n Enter your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\n Enter phone no to be inserted: ";
					cin>>data;
					h.insertElement(data);
					break;
			    case 2:
			    	h.display();
			    	break;
			    case 3:
			    	cout<<"\n Enter the no to be searched: ";
			    	cin>>search;
			    	if(h.searchelement(search)==-1)
			    	{
			    		cout<<"\n No element found at key:  ";
			    		continue;
					}
					break;
				case 4:
					
				cout<<"\n Enter the phone no you want to delete: ";
				cin>>del;
				h.deleteElement(del);
				break;
				 
			}
		}while(ch!=5);
		return 0;
	}

