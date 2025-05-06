#include<iostream>
#include<string.h>
using namespace std;
class hashfunction
{
	typedef struct hash
	{
		long key;
		char name[10];
	}hash;
	hash h[10];
	public:
		hashfunction();
		void insert();
		void display();
		int find(long);
		void Delete(long);
};
hashfunction::hashfunction()
{
	int i;
	for(i=0;i<10;i++)
	{
		h[i].key=-1l;
		strcpy(h[i].name,"NULL");
	}
}
void hashfunction::Delete(long k)
{
	int index =find(k);
	if(index==-1)
	{
		cout<<"\n\tKey not found";
	}
	else
	{
		h[index].key=-1;
		strcpy(h[index].name,"NULL");
		cout<<"\n\tKey is deleted";
	}
}
int hashfunction::find(long k)
{
	int i;
	for(i=0;i<10;i++)
	{
		if (h[i].key==k)
		{
			cout<<"\n\t"<<h[i].key<<"is found at "<<i<<"locztion with name"<<h[i].name;
		}
	}
	if (i==10)
	{
		return -1;
	}
}
void hashfunction::display()
{
	int i;
	cout<<"\n\t\tkey\t\tName";
	for(i=0;i<10;i++)
	{
		cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name;
	}
}
void hashfunction::insert()
{
	char ans ,n[10],ntemp[10];
	long k,temp;
	int v,hi,cnt=0,flag=0,i;
	do
	{
		if(cnt>=10)
		{
			cout<<"\n\t Hash Table Is Full";
			break;
		}
		cout<<"\n\t Enter a Telephone No: ";
		cin>>k;
		cout<<"\n\t Enter a Client Name: ";
		cin>>n;
		hi=k%10;
		if(h[hi].key==-1)
		{
			h[hi].key=k;
			strcpy(h[hi].name,n);
		}
		else
		{
			if(h[hi].key!=hi)
			{
				temp=h[hi].key;
				strcpy(ntemp,h[hi].name);
				h[hi].key=k;
				strcpy(h[hi].name,n);
				for(i=hi+1;i<10;i++)
				{
					if(h[i].key==-1)
					{
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						flag=1;
						break;
					}
				}
				for(i=hi+1;i<10&&flag==0;i++)
				{
					if(h[i].key=-1)
					{
						h[i].key=temp;
						strcpy(h[i].name,ntemp);
						break;
					}
				}
			}
			else
			{
				for(i=hi+1;i<10;i++)
				{
					if(h[i].key==-1)
					{
						h[i].key=k;
						strcpy(h[i].name,n);
						break;
						flag-1;
					}
				}
				for(i=0;i<hi&flag==0;i++)
				{
					if(h[i].key==-1)
					{
						h[i].key=k;
						strcpy(h[i].name,n);
						break;
					}
				}
			}
		}
		flag=0;
		cnt++;
		cout<<"\n\t...Do you want to insert more key(y/n): ";
		cin>>ans;
	 } while(ans=='y'||ans=='Y');
}
int main()
{
	long k;
	int ch, index;
	char ans;
	hashfunction obj;
	do
	{
		cout<"\n\t...Telephone adt...";
		cout<<"\n\t 1]insert\n\t 2]Display\n\t3] find\n\t 4]Delete\n\t 5]Exit";
		cout<<"\n\t....Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		
		case 1:
			obj.insert();
			break;
		case 2:
			obj.display();
			break;
		case 3:
			cout<<"\n\t Enter a key which you want to search: ";
			cin>>k;
			index=obj.find(k);
			if(index==-1)
			{
				cout<<"\n\t key not found";
			}
			break;
		case 4:
			cout<<"\n Enter a key which you want to delete: ";
			cin>>k;
			obj.Delete(k);
			break;
		case 5:
			break;
	}
	cout<<"\n\t..Do you want to continue in menu(y/n): ";
	cin>>ans;
}while(ans=='y'||ans=='Y');
return 0;
}
