#include <iostream>
#include <string>

using namespace std;

// Base class for vehicles
class Vehicle {
protected:
    string brand;
    string model;
    string paintColor;
    int yearOfManufacture;

public:
    Vehicle(string brand = "Generic", string model = "Basic", string color = "White", int year = 2000)
        : brand(brand), model(model), paintColor(color), yearOfManufacture(year) {}

    // Setters and getters for vehicle properties
    void setBrand(const string& b) {
        brand = b;
    }

    string getBrand() const {
        return brand;
    }

    void setModel(const string& m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    void setColor(const string& c) {
        paintColor = c;
    }

    string getColor() const {
        return paintColor;
    }

    void setYear(int y) {
        yearOfManufacture = y;
    }

    int getYear() const {
        return yearOfManufacture;
    }
};

// Utility class for outputting vehicle details
class VehicleReporter {
private:
    const Vehicle* vehicle;

public:
    VehicleReporter(const Vehicle* v) : vehicle(v) {}

    void report() const {
        cout << "Vehicle Information:" << endl;
        cout << "Brand: " << vehicle->getBrand() << endl;
        cout << "Model: " << vehicle->getModel() << endl;
        cout << "Color: " << vehicle->getColor() << endl;
        cout << "Year: " << vehicle->getYear() << endl;
    }
};

// Utility class for user input to configure vehicle details
class VehicleConfigurer {
private:
    Vehicle* vehicle;

public:
    VehicleConfigurer(Vehicle* v) : vehicle(v) {}

    void configure() {
        cout << "Configure your vehicle:" << endl;
        string input;
        int year;

        cout << "Enter brand: ";
        getline(cin, input);
        vehicle->setBrand(input);

        cout << "Enter model: ";
        getline(cin, input);
        vehicle->setModel(input);

        cout << "Enter color: ";
        getline(cin, input);
        vehicle->setColor(input);

        cout << "Enter year: ";
        cin >> year;
        vehicle->setYear(year);
    }
};

int main() {
    Vehicle myCar("Tesla", "Model S", "Red", 2022);  // Default vehicle setup

    VehicleReporter reporter(&myCar);
    reporter.report();  // Initial report

    VehicleConfigurer configurer(&myCar);
    configurer.configure();  // User input to modify vehicle details

    reporter.report();  // Report after modifications

    return 0;
}