#include<iostream>
#include<string>
using namespace std;
struct Expense
{
	string goods;
	double price;
	string date;
	int weekNo;
	int month;
	Expense* next;
};
class ExpenseT
{
	Expense* head;
	public:
		ExpenseT(): head(NULL){}
		void addExpense(string goods,double price,string date,int week,int month)
		{
			Expense* newExpense =new Expense{goods,price,date,week,month,NULL};
			if(head==NULL)
			{
				head=newExpense;
			}
			else
			{
				Expense* temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newExpense;
			}
			cout<<"Expense added successfully\n";
			}
		void viewExpenses()
		{
		if(head==NULL)
		{
			cout<<"No Expenses\n";
			return;
			}
			cout<<"\n--All Expenses--\n";
			Expense* temp=head;
				while(temp!=NULL)
				{
					cout<<"Date"<<temp->date<<" | Goods"<<temp->goods<<" | Price"<<temp->price<<" | WeekNo"<<temp->weekNo<<" | Month"<<temp->month<<"\n";
					temp=temp->next;
				}	
				cout<<"--------\n";
			}		
	void totalExpenses()
	{
		double total =0;
		Expense* temp=head;
				while(temp!=NULL)
				{
					total +=temp->price;
					temp=temp->next;
				}
				cout<<"Total Expenses:"<<total<<"\n";
	}
      void weeklyreport(int week)
	  {
	  	double total=0;
		Expense* temp=head;
				while(temp!=NULL)
				{
					if(temp->weekNo==week)
					{
						total +=temp->price;
					}
					temp=temp->next;
				}
				cout<<"Weeklyreport"<<week<<"total:"<<total<<"\n";
		  }	
		  void monthlyreport(int month)
	  {
	  	
	  	double total =0;
		Expense* temp=head;
				while(temp!=NULL)
				{
					if(temp->month==month)
					{
						total +=temp->price;
					}
					temp=temp->next;
				}
				cout<<"Monthlyreport"<<month<<"total:"<<total<<"\n";
		  }	
		  
		  ~ExpenseT()
		  {
		  	Expense* temp;
		  	while(head!=NULL)
		  	{
		  		temp=head;
		  		head=head->next;
		  		delete temp;
			  }
		  }
};
int main()
{
	ExpenseT track;
	int option;
	string goo,date;
	double price;
	int week,month;
	do
	{
		cout<<"\n Menu\n";
		cout<<"1. Add expense\n";
		cout<<"2. View all Expenses\n";
		cout<<"3. Total Expenses\n";
		cout<<"4. Weekly Report\n";
		cout<<"5. Monthly Report\n";
		cout<<"6. Exit\n";
		cout<<"Choose: ";
		cin>>option;
		cin.ignore();
		switch(option)
		{
		    	case 1:
				cout<<"Enter goods you want to buy:";
				getline(cin,goo);
				cout<<"Enter price:";
				cin>>price;
				cin.ignore();
				cout<<"Enter date(YYYY-MM-DD):";
				getline(cin,date);
				cout<<"Enter week number(1-52):";
				cin>>week;
				cout<<"Enter month(1-12):";
				cin>>month;
				cin.ignore();
				track.addExpense(goo,price,date,week,month);
				break;
				case 2:
					track.viewExpenses();
					break;
				case 3:
					track.totalExpenses();
					break;
				case 4:
						cout<<"Enter week number:";
						cin>>week;
						track.weeklyreport(week);
						cin.ignore();
						break;
				case 5:
					    cout<<"Enter month:";
					    cin>>month;
					    track.monthlyreport(month);
					    cin.ignore();
					    break;
				case 6:
					cout<<"TaTa Byebye\n";
					break;
					default:
						cout<<"Invalid option";
						}
						
		}while(option!=6);
	
	return 0;
}
