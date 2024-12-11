#include <iostream>
#include <fstream> 
#include <cstdlib>

using namespace std;

const int MAX_SIZE_RANDOM = 2000000;

const string FILE_RANDOM_SAVE = "rdid.dat";

class RandomID
{
private:
	int* nodes;
	int n;
private:
	int getLength();
	void createListRandom();
	void printList();
	void saveToFile();
	void loadFromFile();
public:
	RandomID();
	~RandomID();
	int getRandomId();
};


