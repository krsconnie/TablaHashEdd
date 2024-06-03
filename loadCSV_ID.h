#ifndef LOADCSV_ID_H
#define LOADCSV_ID_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>  // Agregar la librería para la salida estándar
#include <vector>
#include <iomanip>   // Para manejar precisión al convertir notación científica

#include "twitterUsers.h"

/* 
 * Método de Carga de CSV por ID
 * Carga los datos de usuarios desde un archivo CSV y los inserta en una tabla hash
 * filename: Nombre del archivo CSV a leer
 * hashtable: Referencia a la tabla hash donde se insertarán los usuarios
 * max_users: Número máximo de usuarios a insertar
 */

template <typename HashTable> // Permite el uso de cualquier tipo de tabla hash

void loadCSV_Id(const std::string& filename, HashTable& hashtable, int max_users) {
    
    std::ifstream file(filename);
    std::string line;
    int users_added = 0;
    
    // Verifica si el archivo se abrió correctamente
    if (file.is_open()) {
        std::getline(file, line); // Leer la línea de encabezado

        // Leer cada línea del archivo hasta que se alcancen max_users
        while (std::getline(file, line) && users_added < max_users) {
            std::stringstream ss(line);
            std::string field;
            std::vector<std::string> fields;

            // Separar la línea en campos usando la coma como delimitador
            while (std::getline(ss, field, ',')) {
                fields.push_back(field);
            }

            // Verificar si la línea tiene el número correcto de campos
            if (fields.size() != 7) {
                std::cerr << "Error: Número de campos inconsistente en la línea: " << line << "\n";
                continue; // Saltar esta línea y continuar con la siguiente
            }

            // Asignar cada campo a una variable correspondiente
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

            // Crear un objeto usuario con los campos leídos y convertir las cadenas numéricas a enteros
            twitterUser user = {uni, userName, since, std::stoi(numberTweets), std::stoi(followers), std::stoi(friends), userIdLong};
            
            // Insertar el usuario en la tabla hash usando userIdLong como clave
            hashtable.insert(user.userId, user);

            // Incrementar el contador de usuarios añadidos
            users_added++;
        }

        // Cerrar el archivo después de leer todos los datos
        file.close();
    } else {
        // Imprimir un mensaje de error si el archivo no se pudo abrir
        std::cerr << "Error: No se pudo abrir el archivo " << filename << "\n";
    }
}

#endif
