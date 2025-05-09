#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cars {
private:
    string car;
    string model;
    int year;
    string color;
    double mileage;
    string transmission;
    string fuelType;
    double rentalPrice;
    bool available;
bool passedInspection;
     string availableCars[15] = {"Lamborghini", "Ferrari", "Bugatti", "Nissan GTR", "Supra", "Tesla", "Civic", "Porsche", "BMW", "Lexus", "Land Rover", "Mercedes-Benz", "Lexus", "Ford", "Dodge"};
    
     string hourly = "hourly";
    string weekly = "weekly";
    string monthly = "monthly";

public:
     Cars() {
         available = true;

        cout << "Welcome to Car Rental System" << endl;
        cout<<endl;
        cout << "Available Cars are : " << endl;
        for (int i = 0; i < 15; ++i) {
            cout << i + 1 << ". " << availableCars[i] << endl;
         }
        cout << "Please select option of car you want to rent : ";
        cin >> car;
        cout<<endl;

         model = "Model";  
        year = 2022;  
        color = "Color"; 
        mileage = 0;  
        transmission = "Transmission";  
        fuelType = "Fuel Type";  
         passedInspection = true;
        
         bool validCar = false;
        for (int i = 0; i < 15; ++i) {
            if (car == availableCars[i]) {
                validCar = true;
                break;
            }
        }
        if (!validCar) {
            cout << "Invalid car selection! Program will now exit." << endl;
        }
    }

     void Pricing_Plan() {
        string plan;
        cout << "Please select Plan for " << car << endl;
        cout << "1. Hourly" << endl;
        cout << "2. Weekly" << endl;
        cout << "3. Monthly" << endl;
        cout << "Enter your choice: ";
        cin >> plan;
cout<<endl;
        if (plan == hourly) {
            cout << "You can rent " << car << " for $100 per hour" << endl;
            rentalPrice = 100;  
        } else if (plan == weekly) {
            cout << "You can rent " << car << " for 1 week for $5000" << endl;
            rentalPrice = 5000;  
        } else if (plan == monthly) {
            cout << "You can rent " << car << " for 1 month for $20000" << endl;
            rentalPrice = 20000;  
        } else {
            cout << "Invalid choice!" << endl;
        }

         if (plan == hourly || plan == weekly || plan == monthly) {
            available = false;
        }
        
         Confirmation confirmation(car, plan);
    }
    
     class Confirmation {
    private:
        int num , phone , cnic ;
        string name , address;
    public:
         Confirmation(string selectedCar, string selectedPlan) {
            cout << "Please press 1 to confirm selection" << endl;
            cin >> num;
            
            cout<<endl;
            
			cout<<"Enter your details for record:- "<<endl;
            cout<<endl;
            
			cout<<"Enter your name:"<<endl;
            cin>>name;
            cout<<endl;
            
             cout<<"Enter your Phone Number:"<<endl;
            cin>>phone;
            cout<<endl;
            
             cout<<"Enter your Adress:"<<endl;
            cin>>address;
            cout<<endl;
            
             cout<<"Enter your CNIC:"<<endl;
            cin>>cnic;
            cout<<endl;
            
            if (num == 1) {
                cout << "Mr. "<<name <<" rented" << selectedCar << " on 11th May for " << selectedPlan << endl;
            } else {
                cout << "Please review the list and select your desired car" << endl;
            }
        }
    };
void performInspection() {
         if (!passedInspection) {
            cout << "Car is damaged. Customer has to pay fine." << endl;
     }
 }
    void displayDetails() {
        cout << "Car Details :" << endl;
        cout << "Car: " << car << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
        cout << "Mileage: " << mileage << " miles" << endl;
        cout << "Transmission: " << transmission << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Rental Price: $" << fixed << setprecision(2) << rentalPrice << " per hour" << endl;
        cout << "Availability: " << "Available"  << endl;
    }

    bool isAvailable() {
        return available;
    }

    void modifyDetails(string newModel, int newYear, string newColor, double newMileage, string newTransmission, string newFuelType, double newRentalPrice, bool newAvailability) {
        model = newModel;
        year = newYear;
        color = newColor;
        mileage = newMileage;
        transmission = newTransmission;
        fuelType = newFuelType;
        rentalPrice = newRentalPrice;
        available = newAvailability;
    }
};

int main() {
    Cars car;
    car.Pricing_Plan();
cout << "Car Details: ";
    car.displayDetails();

    if (car.isAvailable()) {
        cout << "The car  available for rental.";
        }
cout<<endl;

    car.modifyDetails("Model S", 2023, "Red", 20000, "Automatic", "Diesel", 120, false);

cout<<endl;

    cout << "Modified Car Details: ";
    cout<<endl;
    car.displayDetails();
    cout<<endl;

cout<<"Thankyou for choosing our services!";
    }
