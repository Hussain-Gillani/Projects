#include <iostream>
using namespace std;


struct Passenger{
	string name;
	Passenger* next;
};

class flight{
	public:
		Passenger* head;
		flight(): head(0) {}
		
	void	reserveTicket(string name){
			Passenger* newPassenger=new Passenger;
			if(head==NULL || head->name  > name){
				newPassenger->next=head;
		head=newPassenger;
			}
			else{
			Passenger* current=head;
			while (current->next && current->name < name){
				current=current->next;
			}
			newPassenger->next=current->next;
			current->next=newPassenger;		
	current=current->next;
}
cout<<"Ticket reserved for"<<name<<endl;
}
void cancelReservation(string name){
		Passenger*temp=head;
	if (head->name==name){
		head=head->next;
		delete temp; 
	}else{
	
	Passenger* current=head;
	while (current->next && current->next->name!=name){
	current=current->next;
}
 if (current->next!=NULL){
		Passenger* temp = current->next;
		current->next=current->next->next;
		delete temp;
	}
}
	cout<<"Reservation cancelled for "<<name<<endl;
}

void checkReservation(string name){
Passenger* current=head;
while ( current!=NULL){
	if (current->name==name){
		cout<<"Ticket is reserved for "<<name << endl;
		}
				current=current->next;		
		 {
			cout<<"Ticket is not reserved for "<<name << endl;

		    
		}
}
	}

void displayPassengers(){
	Passenger* current=head;
	if (current!=NULL){
		cout<<current->name<<" " ;
			current=current->next;

	}
}
};
int main(){
	string name ;
	int op;
	flight fl;
	do{
	cout<<"Menu: "<<endl;
	cout<<"Reserse a ticket:"<<endl;
	cout<<"Cancel a reservation:"<<endl;
	cout<<"Check for reservation"<<endl;
	cout<<"Enter the option:";
	cin>>op;


switch (op) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                fl.reserveTicket(name);
                break;
            case 2:
                cout << "Enter passenger name to cancel: ";
                cin >> name;
                fl.cancelReservation(name);
                break;
            case 3:
                cout << "Enter passenger name to check: ";
                cin >> name;
                (fl.checkReservation(name)) ;
                break;
            case 4:
                fl.displayPassengers();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (op != 5);
}
	
	
	

