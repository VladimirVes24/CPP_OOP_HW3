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

class Fraction
{
private:
	double numerator, denominator;
public:
	Fraction(double inputNumerator, double inputDenominator)
		: numerator(inputNumerator), denominator(inputDenominator)
	{
		if (denominator == 0) denominator = 0.00000001;
	}

	friend Fraction operator+(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1, const Fraction& d2);
	friend Fraction operator*(const Fraction& d1, const Fraction& d2);
	friend Fraction operator/(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

	void setDenominator(double inputDenominator)
	{
		if (inputDenominator == 0) inputDenominator = 0.00000001;
		denominator = inputDenominator;
	}

	void setNumerator(double inputNumerator)
	{
		numerator = inputNumerator;
	}

	double getNumerator()
	{
		return numerator;
	}

	double getDenominator()
	{
		return denominator;
	}

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator*d2.denominator + d2.numerator*d1.denominator, d1.denominator*d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
	return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
	else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
	if (d1 == d2) return false;
	else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
	if (!(d1 > d2)) return true;
	else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
	if (!(d1 < d2)) return true;
	else return false;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;

	return out;
}

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
	Fraction d1(3, 2);
	Fraction d2(8, 3);
	std::cout << "\n\n" << (d1+d2);
	std::cout << "\n\n" << (d1 - d2);
	std::cout << "\n\n" << (d1 * d2);
	std::cout << "\n\n" << (d1 / d2);
	std::cout << "\n\n" << (-d1) << "\n";

	if (d1 == d2) std::cout << "\nFraction 1 == Fraction 2";
	if (d1 != d2) std::cout << "\nFraction 1 != Fraction 2";
	if (d1 > d2) std::cout << "\nFraction 1 > Fraction 2";
	if (d1 <= d2) std::cout << "\nFraction 1 <= Fraction 2";
	if (d1 < d2) std::cout << "\nFraction 1 < Fraction 2";
	if (d1 >= d2) std::cout << "\nFraction 1 >= Fraction 2";
	}