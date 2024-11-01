//Ftemeh Arab
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
class student_list{
	public:
		student_list();
		//~student_list();
		static void display();
		void add();
		void print();
		void search();
		void edit();
		void delete_stu();
	private:
		struct stu{
		  int stu_number;
		  string fn;
		  string ln;
		  string stu_field;
	    };
	stu *student;
	int n;//maximume number of students
	int k=0;//counter
	
};

student_list::student_list()
{
	cout<<"Enter the max number of students:"<<endl;
	cin>>n;
	//return n;
}

void student_list :: display()
{
	cout<<"University name is : University of Qom"<<endl;
	cout<<"This list is for students of engineering faculty entering 1391-1403."<<endl;
	cout<<"\n*********************************************************"<<endl;
}

void student_list :: add()
{
	student=new stu[n];
	if(k<n)
	{
		cout<<"Enter number of student"<<k+1<<":"<<endl;
		cin>>student[k].stu_number;
		
		if(student[k].stu_number>100&&student[k].stu_number<=1100)
		{
		  cout<<"Enter firstname of student"<<k+1<<":"<<endl;
		  cin>>student[k].fn;
		  cout<<"Enter lastname of student"<<k+1<<":"<<endl;
		  cin>>student[k].ln;
		  cout<<"Enter feild of student"<<k+1<<":"<<endl;
		  cin>>student[k].stu_field;
		  k++;
		  system("cls");
	    }
	    else
		{
		    cout<<"The entered student number is incorrect!!!";
		    //i--;//One is subtracted from the counter,So that the wrong student code is not counted.
		    getchar();
		}
	}
	else
	    cout<<"\nMuximum number of students!!!"<<endl;
	getchar();	
}

void student_list :: print()
{
	for(int i=0;i<k;++i)
	{
		cout<<"Number of student"<<i+1<<"is:"<<student[i].stu_number<<endl;
		cout<<"Firstname of student"<<i+1<<"is:"<<student[i].fn<<endl;
		cout<<"Lastname of student"<<i+1<<"is:"<<student[i].ln<<endl;
		cout<<"Feild of student"<<i+1<<"is:"<<student[i].stu_field<<endl;
		cout<<"\n***************************************************\n";	
	}
}

void student_list:: search()
{
	bool found=false;
	int sn;
	cout<<"Enter your desired student number: "<<endl;
	cin>>sn;
	for(int i=0;i<k;++i)
	{
		if(student[i].stu_number==sn)
		{
			found=true;
			cout<<"Student number:"<<student[i].stu_number<<endl;
			cout<<"Firstname is: "<<student[i].fn<<endl;
			cout<<"Lastname is: "<<student[i].ln<<endl;
			cout<<"Feild: "<<student[i].stu_field<<endl;		
		}
	}
	if(!found)
		{
		   cout<<"\nSTUDENT NOT FOUND!!!"<<endl;
	    }
	getchar();
}

void student_list :: edit()
{
	bool found=false;
	int sn;
	cout<<"Enter your desired student number for edit information: "<<endl;
	cin>>sn;
	for(int i=0;i<k;++i)
	{
		if(student[i].stu_number==sn)
		{
			found=true;
			cout<<"Enter new firstname:"<<endl;
			cin>>student[i].fn;
			cout<<"Enter new lastname:"<<endl;
			cin>>student[i].ln;
			cout<<"Enter new feild:"<<endl;
			cin>>student[i].stu_field;
			cout<<"Information edited."<<endl;
		}		
    }
    if(!found)
		{
		   cout<<"\nSTUDENT NOT FOUND!!!"<<endl;
	    }
	getchar();
}

void student_list ::  delete_stu()
{
	bool found=false;
	bool archive=false;
	int sn;
	cout<<"Enter your desired student number for delete student: "<<endl;
	cin>>sn;
	cout<<"\nDo you want to archive the student?(1 for yes,0 for no): ";
	cin>>archive;
	for(int i=0;i<k;++i)
	{
		if(student[i].stu_number==sn)
		{
			found=true;
			if(!archive)
			{
			  for(int j=i;j<n;++j)
			    student[j]=student[j+1];
			  n--;
			}
			cout<<"\nSTUDENT"<<(archive?" ARHIVED":" DELETED")<<" SUCCESSFULLI!!!"<<endl;
		}
    }
    if(!found)
		{
		   cout<<"\nSTUDENT NOT FOUND!!!"<<endl;
	    }
	getchar();	
}

int show_menu();

int main()
{
	int menu;
	//student_list::display();
	student_list d;
	char ch='y';
	while(ch =='y')
	{
		student_list::display();
		menu=show_menu();
	  switch(menu){
	  	case 1:
	  		system("cls");
	  		int k;
	  		cout<<"How many students do you want to enter?";
            cin>>k;
            for(int j=0;j<k;++j)
	  		  d.add(); 
	  	break;
	  		
		case 2:
			system("cls");
			d.search();
		break;
		
		case 3:
			system("cls");
			d.edit();
		break;
		
		case 4:
			system("cls");
			d.delete_stu();
		break;
		
		case 5:
			system("cls");
			d.print();
		break;
			
	   }
	system("cls");
	cout<<"\ndo you want to continue?(y/n):"<<endl;
	cin>>ch;
	}
	
	return 0;	  
}

	int show_menu()
{
	system("cls");
	int a;
	cout<<"******MENU******"<<endl;
	cout<<"1-ADD\n2-SEARCH\n3-EDIT\n4-DELETE\n5-PRINT INFORMATION\n6-EXIT"<<endl;
	cout<<"Enter number: ";
	cin>>a;
	return a;
}
