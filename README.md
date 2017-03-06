# SQLiteTest
Testing out some SQLite database functionality.

## Guidelines
You should be able to build this in Visual Studio 2015 and see the console output. In order to see/look at the project files you will need:

1. Visual Studio 2015 Community Edition to build the project - available [here.](https://www.visualstudio.com/downloads/)
2. SQLite Studio to edit and see database entries for the `project-database` file - available [here.](https://sqlitestudio.pl/index.rvt?act=download)

To edit database entries:

1. Open up SQLite Studio.
2. Add the database (either Ctrl + O or click the third button from the left in the tool bar at the top).
3. Add the database file (found under `sqlite-database-test/sqlite-database-test/database/project-database.db`).
4. Double click on `Units` under `Tables` under the `Databases` window to the left.
5. Click on the `Data` tab to see actual database entries.
6. Edit to your hearts content!

**NOTE** 
Some of these database entries have constraints on them, so unexpected values cannot be placed in them. For example:
	* Most if not all entries check to make sure the data entered is above 0.