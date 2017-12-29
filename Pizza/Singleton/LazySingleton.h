#pragma once

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new Singleton;
		return m_instance;
	}
private:
	Singleton() {}
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;


/* Usage:
 * Singleton* p = Singleton::GetInstance()
 * 线程不安全
 *
 *
 */