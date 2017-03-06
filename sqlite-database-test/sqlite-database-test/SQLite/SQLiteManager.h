#pragma once

#include <iostream>
#include "../Trooper.h"
#include "DatabaseManager.h"
#include "sqlite3.h"

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
		Trooper _scout, _trickster, _hoplite;
};