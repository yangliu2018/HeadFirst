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
	PizzaStore(SimplePizzaFactory* factory) : m_factory(factory) {}
	Pizza* OrderPizza(string type)
	{
		Pizza* pizza = m_factory->CreatePizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
private:
	SimplePizzaFactory* m_factory;
};

/* Usage:
 * SimplePizzaFactory factory;
 * PizzaStore store(&factory);
 * Pizza* pizza = store.OrderPizza("cheese");
 */