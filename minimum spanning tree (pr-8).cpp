
#include<iostream>
using namespace std;
class tree {
    int a[20][20], s, d, w, v, e, visited[20];  
public:
    void input();
    void display();
    void minimum();
};
void tree::input() {
    cout << "Enter the number of branches: ";
    cin >> v;
    for (int i = 0; i < v; i++) {
        visited[i] = 0;  
        for (int j = 0; j < v; j++) {
            a[i][j] = 999;
        }
    }
    cout << "Enter the number of connections: ";
    cin >> e;
    for (int i = 0; i < e; i++) {
        cout << "Enter the end branches of the connection: ";
        cin >> s >> d;
        cout << "Enter the phone company charges for this connection: ";
        cin >> w;
        a[s - 1][d - 1] = a[d - 1][s - 1] = w;
    }
}
void tree::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < v; i++) {
    	cout<<endl;
        for (int j = 0; j < v; j++) {
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void tree::minimum() {
    int total = 0;
    int min,p,q;

    visited[0] = 1;

    cout << "Minimum cost connections:\n";

    for (int count = 0; count < v - 1; count++)
	  {
        min = 999;

        for (int i = 0; i < v; i++) 
		  {
            if (visited[i]==1) 
				{
                for (int j = 0; j < v; j++)
					  {
                    if (visited[j]!=1)
						  {
                    	if(a[i][j] < min)
							  { 
                        min = a[i][j];
                        p = i;
                        q = j;
                    		}
               		}
           			 }
        		}
    	 }
        visited[p] = 1; 
        visited[q] = 1; 
        total += min;
        cout << "Minimum cost connection is: " << (p + 1) << " -> " << (q + 1) << " with cost: " << min << endl;
     }
    cout << "Total minimum cost: " << total << endl;
}

int main(){
    int ch;
    tree t;
    char ans='y';
    
    do {
        cout << "*************** Prim's Algorithm ****************\n";
        cout << "1. Input\n2. Display\n3. Find Minimum Cost\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "*************** Input Graph *****************\n";
                t.input();
                break;
            case 2:
                cout << "*************** Display Graph *****************\n";
                t.display();
                break;
            case 3:
                cout << "*************** Minimum Cost Spanning Tree *****************\n";
                t.minimum();
                break;
        }
        cout<<"Do you want to continue:";
        cin>>ans;
    } while (ans=='y');

    return 0;
}


