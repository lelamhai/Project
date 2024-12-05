#pragma once
#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton* instance;
public:
	string role;
	int moveMenu = 0;
	bool isExecute = false;
	static Singleton* getInstance();
	void print();
	Singleton();
	~Singleton();
};