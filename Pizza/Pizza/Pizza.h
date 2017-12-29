#pragma once

class Pizza
{
public:
	virtual void prepare();
	virtual void bake();
	virtual void cut();
	virtual void box();
};

class CheesePizza : public Pizza {};
class GreekPizza : public Pizza {};
class PepperoniPizza : public Pizza	{};

class NYStyleCheesePizza : public CheesePizza {};
class NYStyleGreekPizza : public GreekPizza {};
class NYStylePepperoniPizza : public PepperoniPizza {};

class ChicagoStyleCheesePizza : public CheesePizza {};
class ChicagoStyleGreekPizza : public GreekPizza {};
class ChicagoStylePepperoniPizza : public PepperoniPizza {};