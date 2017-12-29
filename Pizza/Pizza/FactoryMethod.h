#pragma once

#include "Pizza.h"
#include <string>
using namespace std;

class SimplePizzaFactory
{
public:
	Pizza* CreatePizza(string type)
	{
		Pizza* pizza = NULL;
		if (type.compare("cheese") == 0)
			pizza = new CheesePizza;
		else if (type.compare("greek") == 0)
			pizza = new GreekPizza;
		else if (type.compare("pepperoni"))
			pizza = new PepperoniPizza;
		return pizza;
	}
};

class PizzaStore
{
public:
	Pizza* OrderPizza(string type)
	{
		Pizza* pizza = CreatePizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
private:
	virtual Pizza* CreatePizza(string type) = 0;
};

class NYStylePizzaStore : public PizzaStore
{
	Pizza* CreatePizza(string type)
	{
		Pizza* pizza = NULL;
		if (type.compare("cheese") == 0)
			pizza = new NYStyleCheesePizza;
		else if (type.compare("greek") == 0)
			pizza = new NYStyleGreekPizza;
		else if (type.compare("pepperoni"))
			pizza = new NYStylePepperoniPizza;
		return pizza;
	}
};

class ChicagoStylePizzaStore : public PizzaStore
{
	Pizza* CreatePizza(string type)
	{
		Pizza* pizza = NULL;
		if (type.compare("cheese") == 0)
			pizza = new ChicagoStyleCheesePizza;
		else if (type.compare("greek") == 0)
			pizza = new ChicagoStyleGreekPizza;
		else if (type.compare("pepperoni"))
			pizza = new ChicagoStylePepperoniPizza;
		return pizza;
	}
};


/* Usage:
 * NYStylePizzaStore store;
 * store.OrderPizza("cheese");
 */