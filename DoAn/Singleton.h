#pragma once
#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton* instance;
public:
	int role;
	static Singleton* getInstance();
	void print();
	Singleton();
	~Singleton();
};