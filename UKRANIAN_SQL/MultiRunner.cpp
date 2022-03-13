/*
UKRANIAN SQL TRANSLATOR - UST+
main file 
updated at 13.03.22

*/

#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <locale>

using namespace std;


string sql_ukranian_string = "СТВОРИТИ ТАБЛИЦЮ  !Table ($name int , $ship string , $logic double); ";

//get origin path and return command in SQL
string determine_command(string sql_origin) {
	
	string command ,check;
	char* str_fill_array = new char[45];
	char* str_check_array = new char[45];
	int begin_of_start_name = sql_origin.find("!");
	string array_command_check = " ";

	command = sql_origin.substr(0, begin_of_start_name);
	//array for checking , command , size of array for checking
	strcpy_s(str_fill_array, command.size() + 1, command.c_str());

	for (int i = 0; i <= 44; i++) {
		if (str_fill_array[i] != ' ') {
			str_check_array[i] = str_fill_array[i];
			//it must to have "СТВОРИТИТАБЛИЦЮ" as result or something like that .
		}
	}
	cout << str_check_array << endl;
	return command;
}

int main() {
	setlocale(LC_ALL, "Ukrainian");

	cout <<"Origin Text"<< sql_ukranian_string << endl;
	//check and translate command in sql
	string command_line = determine_command(sql_ukranian_string);
	cout << command_line << endl;
	return 0;
}