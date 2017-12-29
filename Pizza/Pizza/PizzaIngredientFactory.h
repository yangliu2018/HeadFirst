#pragma once

#include <string>

class Dough {};
class Sauce {};
class Cheese {};
//class Clam {};

class ThinCrustDough : public Dough {};
class MarinaraSauce : public Sauce {};
class ReggianoCheese : public Cheese {};

class ThickCrustDough : public Dough {};
class PlumTomatoSauce : public Sauce {};
class MozzarellaCheese : public Cheese {};

class PizzaIngredientFactory
{
public:
	virtual Dough* CreateDough();
	virtual Sauce* CreateSause();
	virtual Cheese* CreateCheese();
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
	Dough* CreateDough()
	{
		return new ThinCrustDough;
	}
	Sauce* CreateSauce()
	{
		return new MarinaraSauce;
	}
	Cheese* CreateCheese()
	{
		return new ReggianoCheese;
	}
};

class ChicagoPizzaIngredientFactory : PizzaIngredientFactory
{
public:
	virtual Dough* CreateDough()
	{
		return new ThickCrustDough;
	}
	virtual Sauce* CreateSause()
	{
		return new PlumTomatoSauce;
	}
	virtual Cheese* CreateCheese()
	{
		return new MozzarellaCheese;
	}
};

class Pizza
{
public:
	virtual void prepare() = 0;
	void bake() {}
	void cut() {}
	void box() {}
protected:
	Dough* m_dough;
	Sauce* m_sauce;
	Cheese* m_cheese;
};

class CheesePizza : public Pizza
{
public:
	CheesePizza(PizzaIngredientFactory* factory) : m_factory(factory) {}
	virtual void prepare()
	{
		m_dough = m_factory->CreateDough();
		m_sauce = m_factory->CreateSause();
		m_cheese = m_factory->CreateCheese();
	}
private:
	PizzaIngredientFactory* m_factory;
};

class ClamPizza : public Pizza
{
public:
	ClamPizza(PizzaIngredientFactory* factory) : m_factory(factory) {}
	virtual void prepare()
	{
		m_dough = m_factory->CreateDough();
		m_sauce = m_factory->CreateSause();
//		m_cheese = m_factory->CreateCheese();
	}
private:
	PizzaIngredientFactory* m_factory;
};

class PizzaStore
{
public:
	virtual Pizza* CreatePizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore
{
public:
	virtual Pizza* CreatePizza(std::string type)
	{
		Pizza* pizza = NULL;
		PizzaIngredientFactory* factory = new NYPizzaIngredientFactory;
		if (type.compare("cheese") == 0)
		{
			pizza = new CheesePizza(factory);
		}
		else if (type.compare("veggie") == 0)
		{
			pizza = new ClamPizza(factory);
		}
		return pizza;
	}
};


/* Usage:
 * NYPizzaStore store;
 * Pizza* pizza = store.CreatePizza("cheese");
 *
 *
 *
 */