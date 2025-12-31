#include "Skills.h"
#include <iostream>
#include <cstdlib> // for rand(), srand()
using namespace std;


// Player Properties & Methods
Skills::Skills(string name, int cost)
{
	skillName = name;
	manaCost = cost;
}