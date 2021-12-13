// HelgaSQL.cpp : dialect of SQL , to simplify writting of queries.

#include <iostream>
#include <string>

using namespace std;

//for example 
string query_Helga_SQL = "CREATE TABLE !table $name.int , $name1.string , $name2.double;";


//source query for processing.
string source_query, query_space_of_variables, query_space_of_variable
, next_space;


string processing_of_variables(string query) {
    
    string result_of_processing_variables;
    
    int sign_of_dollar, sign_of_end , distance_between_dollar_and_end;

    //select space of variables

    sign_of_dollar = query.find("$");
    sign_of_end = query.find(";");

    distance_between_dollar_and_end = sign_of_dollar - sign_of_end;

    query_space_of_variables = query.substr(sign_of_dollar, distance_between_dollar_and_end);

    result_of_processing_variables = query_space_of_variables;
    
    return result_of_processing_variables;
}


int main()
{
    std::cout << "HelgaSQL 0.5\n" << "\tString for test of translator:" << query_Helga_SQL << endl;

    cout <<"\nResult"<< processing_of_variables(query_Helga_SQL) << endl;
}
