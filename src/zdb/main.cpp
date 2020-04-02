#include <iostream>
#include "zdb.h"
#include "Exception.h" 
#include "Connection.h" 
#include "URL.h" 


using namespace std;


void zdb_query()
{
    URL_T url = URL_new("mysql://192.168.204.137:3306/test?user=root&password=root");
    // 生成连接池对象 
    ConnectionPool_T pool = ConnectionPool_new(url);
    // 开启连接池，默认是5个，通过setinitconnection修改 
    ConnectionPool_start(pool);
    cout << "start poll" << endl;
    // 获取一个连接 释放连接 Connection_close(Connection_T c)或ConnectionPool_retuenConnection(T p, connection_t t)
    Connection_T con = ConnectionPool_getConnection(pool);
    TRY{
        //Connection_executeQuery(con,"create database test2;");
        ResultSet_T result = Connection_executeQuery(con, 
                             "select * from user;");
        cout << "query sql" << endl;
        // 有下一行放回true 
        while (ResultSet_next(result)) 
        {
            // 获取列名 索引是从1开始的 
            const char *column_name = ResultSet_getColumnName(result,1);
            cout << column_name << endl;
            // 根据索引获取值 
            const char *name = ResultSet_getString(result, 1);
            int id = ResultSet_getInt(result, 3);
            int user_age = ResultSet_getIntByName(result, "age");
            cout << id << "  " << name << "  " <<  user_age << endl;
             
        }
    }CATCH(SQLException){
        cout << "exception -- " << Exception_frame.message << endl;
    }FINALLY{
        Connection_close(con);
    }END_TRY;
    ConnectionPool_free(&pool);
    URL_free(&url);
}


int main()
{
    cout << "main" << endl;
    zdb_query();
    return 0;
}

