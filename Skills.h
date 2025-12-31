#ifndef Skills_H
#define Skills_H

#include <string>
using namespace std;

class Skills
{
public:
	Skills(string name, int manacost);


private:
	string skillName;
	int manaCost;

};

#endif