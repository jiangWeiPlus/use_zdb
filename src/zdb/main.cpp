#include <iostream>
#include "zdb.h"

using namespace std;


void zdb_query()
{
    ConnectionPool pool("mysql://192.168.204.137:3306/test?user=root&password=root");
    pool.start();
    Connection con = pool.getConnection();
    // Use C++ variadic template feature to bind parameter 
    ResultSet result = con.executeQuery(
        "select name,id,name from user;", 100
    );
    // Optionally set row prefetch, default is 100
    result.setFetchSize(1000);
    while (result.next()) {
        int id = result.getInt("id");
        const char *name = result.getString("name");
        cout << id << "  " << name << endl;
    }
}


int main()
{
    cout << "main" << endl;
    zdb_query();
    return 0;
}

