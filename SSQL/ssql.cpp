/*
SSQL high-level translator performed for 
simplifed writting querys for Data base.
It itepretates code query in SQL .

email of author : fandim16k@gmail.com

*/
#include <iostream>
#include <string>


using  namespace std;

/*we will hold result of interpretation of query*/
string result_query;



string find_variables_and_build_query(string space_of_variables){
 	
	endpoint_in_query_POSITION = query.find(";");
	first_variable_POSITION = query.find("$");
	first_point_POSITION = query.find(",");

	// statement is kinda "$name.int"
	int space_between_start_and_end_of_statement = first_point_POSITION - first_variable_POSITION;
    // get this statement
    result_query = space_of_variables.substr(space_between_start_and_end_of_statement + 1 , first_point_POSITION);


	return result_query;
}

int main(){
	//first of translator receive query.
	string query = "CREATE TABLE !table $name.int , $name1.string ;";

	//Determine command in the query and ending of the query , symbol ";". 
	string command_in_query ;
	string name_of_the_table ;
	string space_of_variables;
	;
	int  endpoint_in_query_POSITION;
	int  name_of_table_POSITION;
	int  first_variable_POSITION;
	// position of the end of query
	endpoint_in_query_POSITION = query.find(";");
	// position of the start of query
	name_of_table_POSITION = query.find("!");  
	//take command from the line;
	command_in_query = query.substr(1,name_of_table_POSITION);
	// take a name of the table 
	first_variable_POSITION = query.find("$");
	int distation_between_first_variable_and_start_of_the_name_of_table = first_variable_POSITION - name_of_table_POSITION;
	//title of the table in data base , if simple say it .
	name_of_the_table = query.substr(name_of_table_POSITION +1 , distation_between_first_variable_and_start_of_the_name_of_table  - 1);
	int distance_between_first_variable_and_end_of_the_point =  name_of_table_POSITION - first_variable_POSITION;
	/**/
	space_of_variables = query.substr(first_variable_POSITION  , distance_between_first_variable_and_end_of_the_point + 1 );
    

   	
	/*developing in the process*/
	


	return 0;
}