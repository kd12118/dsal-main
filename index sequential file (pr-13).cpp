#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Employee
  {
  	private:
  		int code;
  		char name[20];
  		float salary;
  		public:
  			void read();
  			void display();
  			int getEmpCode()
  			{
  				return code;
			  }
			int getSalary()
			{
				return salary;
			}
			void updateSalary(float s)
			{
				salary=s;
			}
  };
  void Employee::read()
  {
  	cout<<"\n Enter Employee Code: ";
  	cin>>code;
  	cout<<"\n Enter name: ";
  	cin.ignore(1);
  	cin.getline(name,20);
  	cout<<"\n Enter salary: ";
  	cin>>salary;
  }
void Employee::display() 
{   
    cout<<"ID: "<<code<<"    "<<"NAME: "<<name<<"    "<<"SALARY: "<<salary<<endl; 
} 
 
fstream file; 
  
void deleteExistingFile(){ 
    remove("kunal.DAT"); 
}  
void appendToFille(){ 
    Employee    x;  
    x.read(); 
      
    file.open("kunal.DAT",ios::binary|ios::app); 
    if(!file){ 
        cout<<"ERROR IN CREATING FILE\n"; 
        return; 
    } 
    file.write((char*)&x,sizeof(x)); 
    file.close(); 
    cout<<"Record added sucessfully.\n"; 
} 
  
void displayAll() {
    Employee x;
    bool found = false;

    file.open("kunal.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        x.display();
        found = true;
    }

    if (!found) {
        cout << "No employee records found.\n";
    }

    file.close();
}

  
void searchForRecord(){ 
    Employee    x; 
    int c; 
    int isFound=0; 
  
    cout<<"Enter employee code: "; 
    cin>>c; 
  
  
    file.open("kunal.DAT",ios::binary|ios::in); 
    if(!file){ 
        cout<<"ERROR IN OPENING FILE \n"; 
        return; 
    } 
    while(file){ 
        if(file.read((char*)&x,sizeof(x))){ 
            if(x.getEmpCode()==c){ 
                cout<<"RECORD FOUND\n"; 
                x.display(); 
                isFound=1; 
                break; 
            } 
        } 
    } 
    if(isFound==0){ 
        cout<<"Record not found!!!\n"; 
    } 
    file.close(); 
}  
void increaseSalary() {
    Employee x;
    int c;
    float sal;
    bool isFound = false;

    cout << "Enter employee code: ";
    cin >> c;

    file.open("kunal.DAT", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "ERROR IN OPENING FILE\n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "Current Salary: " << x.getSalary() << endl;
            cout << "Enter amount to increase: ";
            cin >> sal;

            x.updateSalary(x.getSalary() + sal);

            int pos = file.tellg(); 
            file.seekp(pos - sizeof(x)); 

            file.write((char*)&x, sizeof(x)); 
            isFound = true;
            cout << "Salary updated successfully.\n";
            break;
        }
    }

    if (!isFound) {
        cout << "Record not found!!!\n";
    }

    file.close();
}

void insertRecord() {
    Employee x;
    Employee newEmp;
    newEmp.read();

    bool exists = false;

    file.open("kunal.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == newEmp.getEmpCode()) {
            exists = true;
            break;
        }
    }
    file.close();

    if (exists) {
        cout << "Employee with code " << newEmp.getEmpCode() << " already exists!\n";
        return;
    }

    file.open("kunal.DAT", ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file for writing!\n";
        return;
    }

    file.write((char*)&newEmp, sizeof(newEmp));
    file.close();

    cout << "Record inserted successfully.\n";
}

  
int main() 
{ 
     char ch; 
     deleteExistingFile(); 
  
     do{ 
     int n; 
  
     cout<<"Enter choice\n";
	 cout<<"1.Add an employee\n";
	 cout<<"2.display\n";
	 cout<<"3.search\n";
	 cout<<"4.Increase salary\n";
	 cout<<"5.Insert record\n"; 
     cout<<"Make a choice: "; 
     
     cin>>n; 
  
     switch(n){ 
          case 1: 
            appendToFille(); 
            break; 
          case 2 : 
            displayAll(); 
            break; 
          case 3: 
            searchForRecord(); 
            break; 
        case 4: 
            increaseSalary(); 
            break; 
        case 5: 
            insertRecord(); 
            break; 
  
          default : 
                cout<<"Invalid Choice\n"; 
     } 
  
     cout<<"Do you want to continue(y/n) ? : "; 
     cin>>ch; 
  
     }while(ch=='Y'||ch=='y'); 
      
    return 0; 
}

