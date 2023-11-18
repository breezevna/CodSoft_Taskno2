#include <iostream>
#include <cmath>

//Calculates the factorial
int factorial(int n)
{
	return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}
double add(double num1, double num2)
{
	return num1 + num2;
}

// Function for subtraction
double subtract(double num1, double num2)
{
	return num1 - num2;
}

// Function for multiplication
double multiply(double num1, double num2)
{
	return num1 * num2;
}

// Function for division
double divide(double num1, double num2)
{
	if (num2 != 0)
		return num1 / num2;
	else
	{
		std::cout << "Error: Division by zero is not allowed.\n";
		return 0.0;
    }
}

// Function for exponentiation
double exponentiate(double num1, double num2)
{
	return std::pow(num1, num2);
}

// Function for square root
double squareRoot(double num)
{
	if (num >= 0)
		return std::sqrt(num);
	else
	{
		std::cout << "Error: Square root of a negative number is not defined.\n";
		return 0.0;
	}
}

//Checks if operand is valid
bool operandCheck(double& num)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid input. Please enter a valid numeric value for the operand:";
		std::cin >> num;
	}

	return true;
}

// Function for factorial
int calculateFactorial(double num)
{
	if (num >= 0 && std::floor(num) == num)
		return factorial(static_cast<int>(num));
	else
	{
		std::cout << "Error: Factorial is only defined for non-negative integers.\n";
		return 0;
	}
}

//function for 2 operations with factorial or square root
double chooseOperation(double a, double b)
{
	double c;
	char operation;

	std::cout << "Choose operation:\n";
	std::cout << "A. Addition\n";
	std::cout << "S. Subtraction\n";
	std::cout << "M. Multiplication\n";
	std::cout << "D. Division\n";
	std::cout << "E. Exponentiation\n";

	std::cout << "Enter the corresponding letter for the operation: ";
	std::cin >> operation;

	switch(operation)
	{
		case 'A':
		case 'a':
			c = add(a, b);
			std::cout << "Result of Addition: " << c << std::endl;
			break;
		case 'S':
		case 's':
			c = subtract(a, b);
			std::cout << "Result of Subtraction: " << c << std::endl;
			break;
		case 'M':
		case 'm':
			c = multiply(a, b);
			std::cout << "Result of Multiplication: " << c << std::endl;
			break;
		case 'D':
		case 'd':
			if (b != 0)
			{
				c  = divide(a, b);
				std::cout << "Result of Division: " << c << std::endl;
			}
			else
				std::cout << "Error: Division by zero is not allowed.\n";
			break;
		case 'E':
		case 'e':
			c = exponentiate(a, b);
			std::cout << "Result of Exponentiation: " << c << std::endl;
			break;
		default:
			std::cout << "Error: Invalid operation. Please choose a valid operation.\n";
	}
	return (c);
}
int main()
{
	char operation;
	double a, b, c;

	std::cout << "Enter the 1st operand: ";
	std::cin >> a;

	operandCheck(a);

	std::cout << "Choose operation:\n";
	std::cout << "A. Addition\n";
	std::cout << "S. Subtraction\n";
	std::cout << "M. Multiplication\n";
	std::cout << "D. Division\n";
	std::cout << "E. Exponentiation\n";
	std::cout << "R. Square Root\n";
	std::cout << "r. Operation with 2 Square Roots\n";
	std::cout << "F. Factorial\n";
	std::cout << "f. Operations with 2 factorial\n";
	std::cout << "Enter the corresponding letter for the operation: ";
	std::cin >> operation;

	if (operation != 'R' && operation != 'F' )
	{
		std::cout << "Enter the 2nd operand: ";
		std::cin >> b;
		operandCheck(b);
	}

	switch(operation)
	{
		case 'A':
		case 'a':
			c = add(a, b);
			std::cout << "Result of Addition: " << c << std::endl;
			break;
		case 'S':
		case 's':
			c = subtract(a, b);
			std::cout << "Result of Subtraction: " << c << std::endl;
			break;
		case 'M':
		case 'm':
			c = multiply(a, b);
			std::cout << "Result of Multiplication: " << c << std::endl;
			break;
		case 'D':
		case 'd':
			if (b != 0)
			{
				c  = divide(a, b);
				std::cout << "Result of Division: " << c << std::endl;
			}
			else
				std::cout << "Error: Division by zero is not allowed.\n";
			break;
		case 'E':
		case 'e':
			c = exponentiate(a, b);
			std::cout << "Result of Exponentiation: " << c << std::endl;
			break;
		case 'R':
			c = squareRoot(a);
			std::cout << "Sqrt(" << a << ") = " << c << std::endl;
			break;
		case 'F':
			c = calculateFactorial(a);
			std::cout << "Factorial of " << a << ": " << c << std::endl;
			break;
		case 'f':
			c = chooseOperation(factorial(a), factorial(b));
			break;
		case 'r':
			c = chooseOperation(squareRoot(a), squareRoot(b));
			break;
		default:
			std::cout << "Error: Invalid operation. Please choose a valid operation.\n";
	}
	return (0);
}
