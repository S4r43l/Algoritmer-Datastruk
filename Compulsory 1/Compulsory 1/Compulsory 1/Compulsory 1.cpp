// Compulsory 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int a;
	int n;
	int i = 0;

	long double Factorial(int n);
	int Fibonacci(int n);

	cout << "Write 1 for Factorial and 2 for 2 Fibonacci" << endl;
	cin >> a;

	if (a == 1) 
	{

		cout << "Fatorial: Enter a positive integer under 171" << endl;
		cin >> n;

		if (n < 0) 
		{
			cout << "That was not positve, try again" << endl << endl;
			main();
		}
		if (n >= 171)
		{
			cout << "enter a smaller number" << endl << endl;
			main();
		}

		cout << Factorial(n) << endl;
	}
	else if(a == 2) 
	{
		cout << "Fibonacci: How many numbers?" << endl;
		cin >> n;

		if (n > 47) {
			cout << "cant be bigger than 47" << endl << endl;
			
			main();
		}

		cout << "First " << n << " of the fibonacci sequence is" << endl;
		while (i < n)
		{
			cout << Fibonacci(i) << endl;
		i++;
		}
	}
	else if (cin.fail())
	{
		cout << endl << "Invalid input" << endl << endl;
		// Clear the error state and flush the input buffer
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main(); 
	}
	else {
		cout << endl << "Invalid input" << endl << endl;

		main();
	}
}


long double Factorial(int n)
{
	if (n == 1 || n==0) {
		return 1;
	}
	else 
		return n * Factorial(n - 1);
}

int Fibonacci(int n)
{
	if ((n == 1) || (n == 0))
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
