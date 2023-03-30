//------------------------------------------------------------------------------
// File:   store.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Problema 4 de TecPro
//------------------------------------------------------------------------------
#pragma once

#include <algorithm>
#include <string>
#include <complex>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class Store
{
protected:
	T	val;
public:
	virtual string name() const = 0;

	virtual void push(const T& v) = 0;
	virtual T    value() const { return val; }
};

template<typename T>
class StoreLast : public Store<T>
{
private:
	using Store<T>::val;
public:

	string name() const override { return "last"; }

	void push(const T& v) override
	{
		val = v;
	}
};

template<typename T>
class StoreMax : public Store<T>
{
private:
	using Store<T>::val;
	bool	first;

public:
	StoreMax() : first(true) {}

	string name() const override { return "max"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = max(val,v);
		}
	}
};

template<typename T>
class StoreMin : public Store<T>
{
private:
	using Store<T>::val;
	bool	first;

public:
	StoreMin() : first(true) {}

	string name() const override { return "min"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = min(val,v);
		}
	}
};

template<typename T>
class StoreAvg : public Store<T>
{
private:
	using Store<T>::val;
	int	count;

public:
	StoreAvg(const T& ini) : count(0) { val = ini; }

	string name() const override { return "average"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		count++;
		val = val+v;
	}

	T value() const override
	{
		return (count>0 ? val/count : val);
	}
};
