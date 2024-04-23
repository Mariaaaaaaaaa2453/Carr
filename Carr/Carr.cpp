#include <iostream>
using namespace std;

class Car {

	string brand;
	string model;
	string color;
	int year;

public:

	Car()
	{
		brand = "";
		model = "";
		color = "";
		year = 2000;
	}

	Car(string b, string m, string c, int y) :brand(b), model(m), color(c), year(y) {};

	void SetBrand(string b)
	{
		brand = b;
	}

	string GetBrand()
	{
		return brand;
	}

	void SetModel(string m)
	{
		model = m;
	}

	string GetModel()
	{
		return model;
	}

	void SetColor(string c)
	{
		color = c;
	}

	string GetColor()
	{
		return color;
	}

	void SetYear(int y)
	{
		year = y;
	}

	int GetYear()
	{
		return year;
	}

};

class CarPrinter
{
	Car* car;
public:
	CarPrinter(Car* car) :car(car) {};

	void PrintInfo()
	{
		cout << "Brand: " << car->GetBrand() << "\n" << "Model:" << car->GetModel() << "\n" << "Color:" << car->GetColor() << "\n" << "Year:" << car->GetYear() << "\n\n";
	}
};

class CarInputter {
	Car* car;

public:
	CarInputter(Car* car) :car(car) {};

	void InputInfo() {
		string brand, model, color;
		int year;

		cout << "Enter brand: ";
		cin >> brand;
		car->SetBrand(brand);

		cout << "Enter model: ";
		cin >> model;
		car->SetModel(model);

		cout << "Enter color: ";
		cin >> color;
		car->SetColor(color);

		cout << "Enter year: ";
		cin >> year;
		car->SetYear(year);
	}
};

int main() {
	Car car("BMW", "X5", "black", 2019);

	CarPrinter carPrinter(&car);
	carPrinter.PrintInfo();

	CarInputter carInputter(&car);
	carInputter.InputInfo();

	carPrinter.PrintInfo();


	return 0;
}