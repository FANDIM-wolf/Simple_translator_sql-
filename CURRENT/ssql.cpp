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


//first of translator receive query.
string query = "CREATE TABLE !table $name.int , $name1.string ;";

//Determine command in the query and ending of the query , symbol ";". 
string command_in_query ;
string name_of_the_table ;
string space_of_variables;
string space_of_next_variables;

int  endpoint_in_query_POSITION;
int  distance_from_comma_to_end_of_line; 
int  name_of_table_POSITION;
int  first_variable_POSITION;
int  first_comma_POSITION;
int  comma_position ;
int  comma_for_start = 0 ; // since $ till comma , it is expression which we need get according to algorithm .

// it contains kinda "name.int"
string origin_statement;
string name_of_origin_statement;
string typedata_of_origin_statement;

//specialized variables 
int current_distance ;


string find_variables_and_build_query(string space_of_variables ){
 	
 	if(comma_for_start == 0){
 	
	endpoint_in_query_POSITION = space_of_variables.find(";");
	first_variable_POSITION = space_of_variables.find("$");
	first_comma_POSITION = space_of_variables.find(",");
    
    //space of next variables
    distance_from_comma_to_end_of_line = endpoint_in_query_POSITION - first_comma_POSITION;
    space_of_next_variables = space_of_variables.substr(first_comma_POSITION +1 , distance_from_comma_to_end_of_line);
    cout<<space_of_next_variables<<endl;
	// statement is kinda "$name.int"
	int space_between_start_and_end_of_statement = first_comma_POSITION - first_variable_POSITION;
    // get this statement
    
    origin_statement = space_of_variables.substr(first_variable_POSITION + 1, space_between_start_and_end_of_statement );
    cout<<origin_statement<<"1"<<endl;
    int point_in_origin_statement = origin_statement.find(".");
    name_of_origin_statement = origin_statement.substr(0,point_in_origin_statement);    
    
    // find type data and comma 
    comma_for_start = origin_statement.find(",");
    int distance_between_point_and_comma_for_type_data = comma_for_start - point_in_origin_statement ;
    current_distance = distance_between_point_and_comma_for_type_data;
    // write down type data 
    typedata_of_origin_statement = origin_statement.substr(point_in_origin_statement + 1, distance_between_point_and_comma_for_type_data - 1 );
   
    
    result_query += name_of_origin_statement + " " + typedata_of_origin_statement ; 
    
    find_variables_and_build_query(space_of_variables);
    
 	}
 	else{
 	    cout<<"else"<<endl;
 	    cout<<space_of_next_variables<<" This is space of next variables"<<endl;
 	    endpoint_in_query_POSITION = space_of_next_variables.find(";");
	    first_variable_POSITION = space_of_next_variables.find("$");
	    first_comma_POSITION = space_of_next_variables.find(",");
	    // statement is kinda "$name.int"
	    int space_between_start_and_end_of_statement = first_comma_POSITION - first_variable_POSITION;
        // get this statement
    
        origin_statement = space_of_next_variables.substr(first_variable_POSITION + 1, space_between_start_and_end_of_statement );
        cout<<origin_statement<<"2"<<endl;
        int point_in_origin_statement = origin_statement.find(".");
        name_of_origin_statement = origin_statement.substr(0,point_in_origin_statement);
        cout<<name_of_origin_statement<<" Name of variable"<<endl;
        
        // find type data and comma 
        comma_for_start = origin_statement.find(",");
        int distance_between_point_and_comma_for_type_data = comma_for_start - point_in_origin_statement ;
        current_distance = distance_between_point_and_comma_for_type_data;
        // write down type data 
        typedata_of_origin_statement = origin_statement.substr(point_in_origin_statement + 1, distance_between_point_and_comma_for_type_data - 1 );
 	    cout<<typedata_of_origin_statement<<" Type of data"<<endl;
 	    //if we have ; in end of line 
        if(typedata_of_origin_statement.find(";") != NULL){
            int point_comma_in_the_end_Position = typedata_of_origin_statement.find(";");
            typedata_of_origin_statement = typedata_of_origin_statement.substr(0, point_comma_in_the_end_Position - 1);
            cout<<typedata_of_origin_statement<<endl;
    
        }
        result_query += name_of_origin_statement +" "+ typedata_of_origin_statement;
 	}

	return result_query;
}

int main(){
	
    
	// position of the end of query
	endpoint_in_query_POSITION = query.find(";");
	// position of the start of query
	name_of_table_POSITION = query.find("!");  
	//take command from the line;
	command_in_query = query.substr(1,name_of_table_POSITION);
    // take a name of the variable 
	first_variable_POSITION = query.find("$");
	int distation_between_first_variable_and_start_of_the_name_of_table = first_variable_POSITION - name_of_table_POSITION;
	//title of the table in data base , if simple say it .
	name_of_the_table = query.substr(name_of_table_POSITION +1 , distation_between_first_variable_and_start_of_the_name_of_table  - 1);
	int distance_between_first_variable_and_end_of_the_point =  name_of_table_POSITION - first_variable_POSITION;
	/**/
	space_of_variables = query.substr(first_variable_POSITION  , distance_between_first_variable_and_end_of_the_point + 1 );
    
   cout<<find_variables_and_build_query(query)<<endl;

   	
	/*developing in the process*/
	


	return 0;
}