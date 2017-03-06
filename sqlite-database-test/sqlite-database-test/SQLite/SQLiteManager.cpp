#include "SQLiteManager.h"

/*
 * Sets up the SQLite manager.
 */
SQLiteManager::SQLiteManager() :
	_databaseConnection(nullptr)
{}

/*
 * Closes the SQLite database.
 */
SQLiteManager::~SQLiteManager()
{
	sqlite3_close(_databaseConnection);
}

/*
 * Loads in the database, establishes a connection to the database.
 * @param bool if the database has successfully opened or not.
 */
bool SQLiteManager::load()
{
	int databaseConnectionStatus = sqlite3_open("./database/project-database.db", &_databaseConnection);

	if (databaseConnectionStatus)
	{
		cout << "Cannot open database." << endl;
		return false;
	}
	else
	{
		cout << "Database opened successfully." << endl;
		onLoad();
		return true;
	}
}

/*
 * What happens when we save this database.
 */
void SQLiteManager::save()
{
	cout << "Totally saving." << endl;
}

/*
 * What happens when this database has been opened.
 */
void SQLiteManager::onLoad()
{
	cout << "Loaded, now do something with the database." << endl;


}

/*
 * What happens when this database has been saved.
 */
void SQLiteManager::onSave()
{
	cout << "Saved." << endl;
}