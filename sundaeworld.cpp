#include <iostream>
#include <vector>
using namespace std;

class Sundae
{
public:
	Sundae();
	void outputDescription();
	double computePrice();
private:
	char flavor;
	char size;
	int toppings;
};

class Order
{
public:
	Order();
	void outputOrder();
	void outputTotalPrice();
	static int getSundaeTotal();
private:
	vector<Sundae> s;
	static int sundaeCount;
};

int Order::sundaeCount = 0;

int main()
{
	cout << "Welcome to Sundae World!" << endl;
	cout << "Now serving customer #1.\n";
	Order one;
	one.outputOrder();
	one.outputTotalPrice();
	cout << "Now serving customer #2!\n";
	Order two;
	two.outputOrder();
	two.outputTotalPrice();
	cout << "\nToday we served " << Order::getSundaeTotal() << " sundaes total.\n";
	cout << "Thank you for choosing Sundae World!\n";
	return 0;
}

Order::Order()
{
	char ans = 'y';
	int i = 0;
	while (ans == 'y' || ans == 'Y')
	{
		Sundae a;
		s.push_back(a);
		i++;
		cout << "Would you like to add another order? (y/n) \n";
		cin >> ans;
	}
	sundaeCount += i;
}

void Order::outputOrder()
{
	for(unsigned int j = 0; j < s.size(); j++)
	{
		s[j].outputDescription();
		cout << "Price: $" << s[j].computePrice() << endl;
	}
}

void Order::outputTotalPrice()
{
	double totalPrice = 0;
	for (unsigned int k = 0; k < s.size(); k++)
	{
		totalPrice += s[k].computePrice();
	}
	cout << "Your total price is: $" << totalPrice << endl;
}

int Order::getSundaeTotal()
{
	return sundaeCount;
}

Sundae::Sundae()
{
	cout << "Choose a flavor of ice cream:\n";
	cout << "Vanilla (v), Chocolate (c) or Oreo (o)\n";
	cin >> flavor;
	if (flavor != 'v' && flavor != 'c' && flavor != 'o')
	{
		cout << "Illegal input. Order canceled.";
		exit(1);
	}
	cout << "Choose a portion size:\n";
	cout << "Small (s), Medium (m) or Large (l): \n";
	cin >> size;
	if (size != 's' && size != 'm' && size != 'l')
	{
		cout << "Illegal input. Order canceled.";
		exit(1);
	}
	cout << "Choose the number of toppings:\n";
	cin >> toppings;
}

double Sundae::computePrice()
{
	double price = 0.00;
	if (size == 's')
		price += 4.00;
	else if (size == 'm')
		price += 5.00;
	else
		price += 6.00;
	price += (toppings * 1.00);
	return price;
}

void Sundae::outputDescription()
{
	cout << "You ordered ";
	if (flavor == 'v')
		cout << "vanilla ice cream ";
	else if (flavor == 'c')
		cout << "chocolate ice cream ";
	else
		cout << "Oreo ice cream ";
	if (size == 's')
			cout << "in a small dish with " << toppings << " toppings.\n";
	else if (size == 'm')
		cout << "in a medium dish with " << toppings << " toppings.\n";
	else
		cout << "in a large dish with " << toppings << " toppings.\n";
}
