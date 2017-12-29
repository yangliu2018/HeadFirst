#pragma once

#include <string>
#include "Pizza.h"
using namespace std;

Pizza* OrderPizza(string type)
{
	Pizza* pizza = NULL;
	if (type.compare("cheese") == 0)
		pizza = new CheesePizza;
	else if (type.compare("greek") == 0)
		pizza = new GreekPizza;
	else if (type.compare("pepperoni"))
		pizza = new PepperoniPizza;

	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();
	return pizza;
}

/* Usage:
 * Pizza* pizza = OrderPizza("cheese");
 */