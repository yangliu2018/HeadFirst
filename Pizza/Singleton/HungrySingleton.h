#pragma once

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return m_instance;
	}
private:
	Singleton() {}
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = new Singleton;


/* Usage:
* Singleton* p = Singleton::GetInstance()
* 线程安全
*
*
*/