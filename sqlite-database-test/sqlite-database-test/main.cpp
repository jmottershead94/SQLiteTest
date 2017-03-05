#include <iostream>
#include "SQLite/sqlite3.h"
#include "Trooper.h"

using namespace std;

int main()
{
	Trooper trooper;
	cout << "Trooper Health = " << trooper.currentHealth() << endl;

	trooper.setCurrentHealth(50.0f);
	cout << "Trooper Health = " << trooper.currentHealth() << endl;

	return 0;
}