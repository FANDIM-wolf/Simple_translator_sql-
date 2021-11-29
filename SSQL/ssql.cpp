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
	endpoint_in_query_POSITION = query.find(";");
	name_of_table_POSITION = query.find("!");  



	return 0;
}