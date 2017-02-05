// Jordan Stein
#include <iostream>
#include <iomanip>

float function(float);
float trapezoid(float, float, float);
float simpsons(float, float, float);

int main()
{
	float a, b, n;
	a = b = n = 0;
	std::cout << "What is the lower bound?\n";
	std::cin >> a;
	std::cout << "What is the upper bound?\n";
	std::cin >> b;
	std::cout << "What is the number of sub-intervals?\n";
	std::cin >> n;

	std::cout << "\nThe value of integration (trapezoid rule) is: " << trapezoid(a, b, n) << std::endl;
	std::cout << "The value of integration (simpsons rule) is: " << simpsons(a, b, n) << std::endl;

	std::cout << "\nEnter any key to exit the program.\n";
	char xx;
	std::cin >> xx;
	return EXIT_SUCCESS;
}

float function(float x)
{
	return ((x*x) / (x*x + 1)); // function to integrate
}

float trapezoid(float a, float b, float n)
{
	float dx = (b - a) / n; //delta x
	float add = 0;

	for (float i = a; i < b + dx; i += dx)
	{
		if (i == a || i == b)
		{
			add += .5*function(i);
		}
		else add += function(i);
	}
	return add*dx;
}

float simpsons(float a, float b, float n) //second formula for simpsons rule
{
	return (4*trapezoid(a, b, 2 * n) - trapezoid(a, b, n))/3;
}