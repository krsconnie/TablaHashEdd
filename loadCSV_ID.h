#ifndef LOADCSV_ID_H
#define LOADCSV_ID_H

#include <fstream>
#include <sstream>
#include <string>

#include "twitterUsers.h"


//Carga de archivos solo para probar la inserción de datos a la hash table
//tomando key = userId

template <typename HashTable> //Cualquiera de las posibles tablas

void loadCSV_Id(const std::string& filename, HashTable& hashtable, int max_users){
	
	std::ifstream file(filename);
	std::string line;
	int users_added = 0;
	if(file.is_open()){

		std::getline(file, line);

		while (std::getline(file, line) && users_added < max_users){
			
			std::stringstream ss(line);
			std::string uni, userID, userName, numberTweets, friends, followers, since;

			std::getline(ss, uni, ',');
			std::getline(ss, userID, ',');
			std::getline(ss, userName, ',');
			std::getline(ss, numberTweets, ',');
			std::getline(ss, friends, ',');
			std::getline(ss, followers, ',');
			std::getline(ss, since, ',');

			twitterUser user = {uni, userName, since, std::stoi(numberTweets), std::stoi(followers), std::stoi(friends),std::stoll(userID)};
			hashtable.insert(std::stoi(userID), user);

			users_added++;
		}

		file.close();
	}
}
#endif 