#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Car class
class Car {
public:
    string make;
    string model;
    int year;
    double ratePerDay;
    bool available;

    // Default constructor
    Car() : make(""), model(""), year(0), ratePerDay(0.0), available(false) {}

    // Parameterized constructor
    Car(string make, string model, int year, double ratePerDay, bool available) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->ratePerDay = ratePerDay;
        this->available = available;
    }
};

// Customer class
class Customer {
public:
    string name;
    string email;
    string phoneNumber;

    // Default constructor
    Customer() : name(""), email(""), phoneNumber("") {}

    // Parameterized constructor
    Customer(string name, string email, string phoneNumber) {
        this->name = name;
        this->email = email;
        this->phoneNumber = phoneNumber;
    }
};

// RentalRecord class
class RentalRecord {
public:
    Car car;
    Customer customer;
    string rentalStartDate;
    string rentalEndDate;
    double totalCost;

    RentalRecord(Car car, Customer customer, string rentalStartDate, string rentalEndDate, double totalCost) {
        this->car = car;
        this->customer = customer;
        this->rentalStartDate = rentalStartDate;
        this->rentalEndDate = rentalEndDate;
        this->totalCost = totalCost;
    }
};

// Global vectors to store cars, customers, and rental records
vector<Car> cars;
vector<Customer> customers;
vector<RentalRecord> rentalRecords;

// Function prototypes
void addCar();
void updateCar();
void deleteCar();
void addCustomer();
void updateCustomer();
void deleteCustomer();
void rentCar();
void returnCar();
void displayCars();
void displayCustomers();
void displayRentalRecords();

int main() {
    int choice;
    do {
        cout << "\n\n===== Car Rental System =====\n";
        cout << "1. Add Car"<<endl;
        cout << "2. Update Car"<<endl;
        cout << "3. Delete Car"<<endl;
        cout << "4. Add Customer"<<endl;
        cout << "5. Update Customer"<<endl;
        cout << "6. Delete Customer"<<endl;
        cout << "7. Rent Car"<<endl;
        cout << "8. Return Car"<<endl;
        cout << "9. Display Cars"<<endl;
        cout << "10. Display Customers"<<endl;
        cout << "11. Display Rental Records"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        switch (choice) {
            case 1: addCar(); break;
            case 2: updateCar(); break;
            case 3: deleteCar(); break;
            case 4: addCustomer(); break;
            case 5: updateCustomer(); break;
            case 6: deleteCustomer(); break;
            case 7: rentCar(); break;
            case 8: returnCar(); break;
            case 9: displayCars(); break;
            case 10: displayCustomers(); break;
            case 11: displayRentalRecords(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Please try again."<<endl;
        }
    } while (choice != 0);
    return 0;
}

// Function definitions
void addCar() {
    string make, model;
    int year;
    double ratePerDay;
    bool available;
    cout << "\nEnter car make: "<<endl;
    cin >> make;
    cout << "Enter car model: "<<endl;
    cin >> model;
    cout << "Enter car year: "<<endl;
    cin >> year;
    cout << "Enter car rate per day: "<<endl;
    cin >> ratePerDay;
    cout << "Is the car available? (0 for no, 1 for yes): "<<endl;
    cin >> available;
    Car newCar(make, model, year, ratePerDay, available);
    cars.push_back(newCar);
    cout << "Car added successfully!\n";
}

void updateCar() {
    int carIndex;
    cout << "\nEnter the index of the car to update: ";
    cin >> carIndex;
    if (carIndex >= 0 && carIndex < cars.size()) {
        string make, model;
        int year;
        double ratePerDay;
        bool available;
        cout << "Enter new car make: "<<endl;
        cin >> make;
        cout << "Enter new car model: "<<endl;
        cin >> model;
        cout << "Enter new car year: "<<endl;
        cin >> year;
        cout << "Enter new car rate per day: "<<endl;
        cin >> ratePerDay;
        cout << "Is the car available? (0 for no, 1 for yes): "<<endl;
        cin >> available;
        cars[carIndex].make = make;
        cars[carIndex].model = model;
        cars[carIndex].year = year;
        cars[carIndex].ratePerDay = ratePerDay;
        cars[carIndex].available = available;
        cout << "Car updated successfully!\n";
    } else {
        cout << "Invalid car index."<<endl;
    }
}

void deleteCar() {
    int carIndex;
    cout << "\nEnter the index of the car to delete: ";
    cin >> carIndex;
    if (carIndex >= 0 && carIndex < cars.size()) {
        cars.erase(cars.begin() + carIndex);
        cout << "Car deleted successfully!"<<endl;
    } else {
        cout << "Invalid car index."<<endl;
    }
}

void addCustomer() {
    string name, email, phoneNumber;
    cout << "\nEnter customer name: ";
    cin >> name;
    cout << "Enter customer email: "<<endl;
    cin >> email;
    cout << "Enter customer phone number: "<<endl;
    cin >> phoneNumber;
    Customer newCustomer(name, email, phoneNumber);
    customers.push_back(newCustomer);
    cout << "Customer added successfully!"<<endl;
}

void updateCustomer() {
    int customerIndex;
    cout << "\nEnter the index of the customer to update: ";
    cin >> customerIndex;
    if (customerIndex >= 0 && customerIndex < customers.size()) {
        string name, email, phoneNumber;
        cout << "Enter new customer name: "<<endl;;
        cin >> name;
        cout << "Enter new customer email: "<<endl;
        cin >> email;
        cout << "Enter new customer phone number: "<<endl;
        cin >> phoneNumber;
        customers[customerIndex].name = name;
        customers[customerIndex].email = email;
        customers[customerIndex].phoneNumber = phoneNumber;
        cout << "Customer updated successfully!"<<endl;
    } else {
        cout << "Invalid customer index."<<endl;
    }
}

void deleteCustomer() {
    int customerIndex;
    cout << "\nEnter the index of the customer to delete: ";
    cin >> customerIndex;
    if (customerIndex >= 0 && customerIndex < customers.size()) {
        customers.erase(customers.begin() + customerIndex);
        cout << "Customer deleted successfully!"<<endl;
    } else {
        cout << "Invalid customer index."<<endl;
    }
}

void rentCar() {
    int carIndex, customerIndex;
    string rentalStartDate, rentalEndDate;
    double totalCost;
    cout << "\nEnter the index of the car to rent: "<<endl;
    cin >> carIndex;
    cout << "Enter the index of the customer renting the car: "<<endl;
    cin >> customerIndex;
    cout << "Enter the rental start date (dd/mm/yyyy): "<<endl;
    cin >> rentalStartDate;
    cout << "Enter the rental end date (dd/mm/yyyy): "<<endl;
    cin >> rentalEndDate;
    if (carIndex >= 0 && carIndex < cars.size() && customerIndex >= 0 && customerIndex < customers.size()) {
        if (cars[carIndex].available) {
            // Calculate total cost based on rental duration and car rate
            // (Assuming 30 days per month for simplicity)
            int startDay, startMonth, startYear;
            int endDay, endMonth, endYear;
            sscanf(rentalStartDate.c_str(), "%d/%d/%d", &startDay, &startMonth, &startYear);
            sscanf(rentalEndDate.c_str(), "%d/%d/%d", &endDay, &endMonth, &endYear);
            int rentalDays = (endYear - startYear) * 365 + (endMonth - startMonth) * 30 + (endDay - startDay);
            totalCost = rentalDays * cars[carIndex].ratePerDay;
            RentalRecord newRentalRecord(cars[carIndex], customers[customerIndex], rentalStartDate, rentalEndDate, totalCost);
            rentalRecords.push_back(newRentalRecord);
            cars[carIndex].available = false;
            cout << "Car rented successfully!"<<endl;
            cout << "Total cost: " << totalCost << "PKR"<<endl;
        } else {
            cout << "The selected car is not available for rent."<<endl;
        }
    } else {
        cout << "Invalid car or customer index."<<endl;
    }
}

void returnCar() {
    int rentalRecordIndex;
    cout << "\nEnter the index of the rental record to return the car: ";
    cin >> rentalRecordIndex;
    if (rentalRecordIndex >= 0 && rentalRecordIndex < rentalRecords.size()) {
        int carIndex = -1;
        for (int i = 0; i < cars.size(); i++) {
            if (cars[i].make == rentalRecords[rentalRecordIndex].car.make &&
                cars[i].model == rentalRecords[rentalRecordIndex].car.model &&
                cars[i].year == rentalRecords[rentalRecordIndex].car.year) {
                carIndex = i;
                break;
            }
        }
        if (carIndex != -1) {
            cars[carIndex].available = true;
            rentalRecords.erase(rentalRecords.begin() + rentalRecordIndex);
            cout << "Car returned successfully!\n";
        } else {
            cout << "Car not found in the system."<<endl;
        }
    } else {
        cout << "Invalid rental record index."<<endl;
    }
}

void displayCars() {
    cout << "\n===== Available Cars =====\n";
    if (cars.empty()) {
        cout << "No cars available."<<endl;
    } else {
        for (int i = 0; i < cars.size(); i++) {
            cout << "Index: " << i << "\n";
            cout << "Make: " << cars[i].make <<endl;
            cout << "Model: " << cars[i].model <<endl;
            cout << "Year: " << cars[i].year <<endl;
            cout << "Rate per day: " << cars[i].ratePerDay <<"PKR"<<endl;
            cout << "Available: " << (cars[i].available ? "Yes" : "No") <<endl;
        }
    }
}

void displayCustomers() {
    cout << "\n===== Registered Customers =====\n";
    if (customers.empty()) {
        cout << "No customers registered."<<endl;
    } else {
        for (int i = 0; i < customers.size(); i++) {
            cout << "Index: " << i << "\n";
            cout << "Name: " << customers[i].name <<endl;
            cout << "Email: " << customers[i].email <<endl;
            cout << "Phone Number: " << customers[i].phoneNumber <<endl;
        }
    }
}

void displayRentalRecords() {
    cout << "\n===== Rental Records =====\n";
    if (rentalRecords.empty()) {
        cout << "No rental records found."<<endl;
    } else {
        for (int i = 0; i < rentalRecords.size(); i++) {
            cout << "Index: " << i << "\n";
            cout << "Car: " << rentalRecords[i].car.make << " " << rentalRecords[i].car.model << " (" << rentalRecords[i].car.year << ")\n";
            cout << "Customer: " << rentalRecords[i].customer.name <<endl;
            cout << "Rental Start Date: " << rentalRecords[i].rentalStartDate <<endl;
            cout << "Rental End Date: " << rentalRecords[i].rentalEndDate <<endl;
            cout << "Total Cost: " << rentalRecords[i].totalCost << "PKR"<<endl;
        }
    }
}
