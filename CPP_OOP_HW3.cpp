#include <iostream>


//Task 1 =================================================================================================================
class Figure
{
public:
	Figure() {};
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
	double a, h;

public:
	Parallelogram(double inputA, double inputH)
		: a(inputA), h(inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Square : public Parallelogram
{
public:
	Square(double inputA)
		: Parallelogram(inputA, inputA) {};

	double area() override
	{
		return (a * a);
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

//Task 2 ======================================================================================================================

class Car
{
protected:
	std::string company, model;
public:
	 Car() {}
	 Car(std::string inputCompany, std::string inputModel)
		: company(inputCompany), model(inputModel)
	{
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(){}
	PassengerCar(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\n" << company << " " << model;
	}

	std::string getModel()
	{
		return model;
	}
};

class Bus : virtual public Car
{
public:
	Bus(){}
	Bus(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\n" << company << " " << model;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\n" << company << " " << model;
	}
};

//Task 3 ======================================================================================================================

int main()
{
	//Task 1 ==================================================================================================================
	double squareBase(5);
	Square square(squareBase);
	std::cout << square.area() << "\n";

	double rectangleBase(3), rectangleHeight(3);
	Rectangle rectangle(rectangleBase, rectangleHeight);
	std::cout << rectangle.area() << "\n";

	double rhombusBase(2), rhombusHeight(5);
	Rhombus rhombus(rhombusBase, rhombusHeight);
	std::cout << rhombus.area() << "\n";

	//Task 2 ==================================================================================================================

	Car car("Daewoo", "Matiz");
	PassengerCar passengerCar("Mersedes", "X5");
	Bus bus("PAZ", "3201");
	Minivan("Volkswagen", "Caravelle");

	//Task 3 ==================================================================================================================

	}