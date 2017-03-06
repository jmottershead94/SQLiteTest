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

	int databaseConnection;
	char* sqlCommand;
	sqlite3_stmt* scoutResults;
	sqlite3_stmt* tricksterResults;
	sqlite3_stmt* hopliteResults;

	// Select all of the objects in the Units table.
	sqlCommand = "SELECT * from Units";

	// Send the command to the SQLite database and fetch the results to the scout results variable.
	databaseConnection = sqlite3_prepare_v2(_databaseConnection, sqlCommand, -1, &scoutResults, 0);

	// Loading trooper data!
	sqlite3_step(scoutResults);
	_scout.trooperID(sqlite3_column_int(scoutResults, 0));
	_scout.trooperName(reinterpret_cast<const char*>(sqlite3_column_text(scoutResults, 1)));
	_scout.setRawAttack(static_cast<float>(sqlite3_column_double(scoutResults, 2)));
	_scout.setRawAttackRange(static_cast<float>(sqlite3_column_double(scoutResults, 3)));
	_scout.setBonusAttack(static_cast<float>(sqlite3_column_double(scoutResults, 4)));
	_scout.setBonusAttackRange(static_cast<float>(sqlite3_column_double(scoutResults, 5)));
	_scout.setAttackRange(sqlite3_column_int(scoutResults, 6));
	_scout.setRawDefence(static_cast<float>(sqlite3_column_double(scoutResults, 7)));
	_scout.setCriticalChance(static_cast<float>(sqlite3_column_double(scoutResults, 8)));
	_scout.setCriticalMultiplier(static_cast<float>(sqlite3_column_double(scoutResults, 9)));
	_scout.setEvasion(static_cast<float>(sqlite3_column_double(scoutResults, 10)));
	_scout.setCooldown(static_cast<float>(sqlite3_column_double(scoutResults, 11)));
	_scout.setMaxHealth(static_cast<float>(sqlite3_column_double(scoutResults, 12)));
	_scout.setMovement(sqlite3_column_int(scoutResults, 13));
	_scout.setNumberOfActions(sqlite3_column_int(scoutResults, 14));
}

/*
 * What happens when this database has been saved.
 */
void SQLiteManager::onSave()
{
	cout << "Saved." << endl;
}