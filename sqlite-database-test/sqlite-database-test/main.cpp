#include "SQLite/SQLiteManager.h"

int main()
{
	Trooper trooper;
	cout << "Trooper Health = " << trooper.currentHealth() << endl;

	trooper.setCurrentHealth(50.0f);
	cout << "Trooper Health = " << trooper.currentHealth() << endl;

	SQLiteManager sqliteManager;
	sqliteManager.load();

	return 0;
}