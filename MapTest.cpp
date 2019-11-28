#include "Map.h"
#include "Employee.h"
using namespace std;

int main()
{
	typedef unsigned int ID;
	Map<ID, Employee> database;

	database.add(761028073, Employee("Jan Kowalski", "salesman", 28));  // Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(761028073, Employee("Kan Jowalski", "buysman", 82));   // Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54)); // Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32)); // Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << database << endl; // Print database

	Map<ID, Employee> newDatabase = database; // Make a copy of database (copy constructor called)

	Employee *pE;
	pE = newDatabase.find(510212881); // Find employee using its ID
	pE->position = "salesman";		  // Modify the position of employee
	pE = newDatabase.find(761028073); // Find employee using its ID
	pE->age = 29;					  // Modify the age of employee

	database = newDatabase;

	cout << database << endl; // Print original database

	return 0;
};