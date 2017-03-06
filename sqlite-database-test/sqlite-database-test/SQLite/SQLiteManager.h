#pragma once

#include <iostream>
#include "DatabaseManager.h"
#include "sqlite3.h"

using namespace std;

/*
 * Handles calls to the SQLite database.
 */
class SQLiteManager : public DatabaseManager
{
	public:
		explicit SQLiteManager();
		~SQLiteManager();

		bool load() override;
		void save() override;

	protected:
		void onLoad() override;
		void onSave() override;

	private:
		sqlite3* _databaseConnection = nullptr;
};