#ifndef LOADCSV_ID_H
#define LOADCSV_ID_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>  // Agregar la librería para la salida estándar
#include <vector>
#include <iomanip>   // Para manejar precisión al convertir notación científica

#include "twitterUsers.h"

// Carga de archivos solo para probar la inserción de datos a la hash table
// tomando key = userId

template <typename HashTable> // Cualquiera de las posibles tablas

void loadCSV_Id(const std::string& filename, HashTable& hashtable, int max_users) {
	
	std::ifstream file(filename);
	std::string line;
	int users_added = 0;
	if (file.is_open()) {
		std::getline(file, line); // Leer la línea de encabezado

		while (std::getline(file, line) && users_added < max_users) {
			std::stringstream ss(line);
			std::string field;
			std::vector<std::string> fields;

			while (std::getline(ss, field, ',')) {
				fields.push_back(field);
			}

			if (fields.size() != 7) {
				std::cerr << "Error: Número de campos inconsistente en la línea: " << line << "\n";
				continue; // Saltar esta línea y continuar con la siguiente
			}

			std::string uni = fields[0];
			std::string userID = fields[1];
			std::string userName = fields[2];
			std::string numberTweets = fields[3];
			std::string friends = fields[4];
			std::string followers = fields[5];
			std::string since = fields[6];

			// Convertir userID correctamente manejando notación científica
			long long userIdLong;
			if (userID.find('E') != std::string::npos || userID.find('e') != std::string::npos) {
				std::stringstream ss(userID);
				double temp;
				ss >> temp;
				userIdLong = static_cast<long long>(temp);
			} else {
				userIdLong = std::stoll(userID);
			}

			twitterUser user = {uni, userName, since, std::stoi(numberTweets), std::stoi(followers), std::stoi(friends), userIdLong};
			hashtable.insert(user.userId, user);

				// // Imprimir los parámetros del usuario después de la inserción (por motivos de debug)
				// std::cout << "Usuario agregado: \n";
				// std::cout << "Universidad: " << uni << "\n";
				// std::cout << "ID de Usuario: " << userIdLong << "\n";
				// std::cout << "Nombre de Usuario: " << userName << "\n";
				// std::cout << "Número de Tweets: " << numberTweets << "\n";
				// std::cout << "Amigos: " << friends << "\n";
				// std::cout << "Seguidores: " << followers << "\n";
				// std::cout << "Desde: " << since << "\n";
				// std::cout << "------------------------\n";

			users_added++;
		}

		file.close();
	} else {
		std::cerr << "Error: No se pudo abrir el archivo " << filename << "\n";
	}
}

#endif