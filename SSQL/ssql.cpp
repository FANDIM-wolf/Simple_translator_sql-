/*
SSQL high-level translator performed for 
simplifed writting querys for Data base.
It itepretates code query in SQL .

email of author : fandim16k@gmail.com

*/
#include <iostream>
#include <string>


using  namespace std;


int main(){
	//first of translator receive query.
	string query = "CREATE TABLE !table $name.int , $name1.string ;";

	//Determine command in the query and ending of the query , symbol ";". 
	string command_in_query ;
	int  endpoint_in_query_POSITION;
	int  name_of_table_POSITION;
	// position of the end of query
	endpoint_in_query_POSITION = query.find(";");
	// position of the start of query
	name_of_table_POSITION = query.find("!");  
	//take command from the line;
	command_in_query = query.substr(1,name_of_table_POSITION);

	/*developing in the process*/
	cout<<command_in_query<<endl;
	cout<<query<<endl;


	return 0;
}