#include <iostream>
#include "HashID.h"
#include "loadCSV_Id.h"

int main() {
    HashTable_ID closedHashTable(100, linear_probing);

    // Ruta del archivo CSV de prueba
    std::string filename = "universities_followers.csv";

    // Llamar a la función de carga con un máximo de 10 usuarios
    loadCSV_Id(filename, closedHashTable, 10);

    // Ejemplo de cómo encontrar e imprimir un usuario por ID (opcional)
    int userID = 414942137; // Reemplazar con un ID de usuario del archivo CSV
    const twitterUser* user = closedHashTable.search(userID);


    if (user != nullptr) {
        std::cout << "Usuario encontrado: \n";
        std::cout << "Universidad: " << user->university << "\n";
        std::cout << "ID de Usuario: " << user->userId << "\n";
        std::cout << "Nombre de Usuario: " << user->userName << "\n";
        std::cout << "Número de Tweets: " << user->numberTweets << "\n";
        std::cout << "Amigos: " << user->friends << "\n";
        std::cout << "Seguidores: " << user->followers << "\n";
        std::cout << "Desde: " << user->since << "\n";
    } else {
        std::cout << "Usuario con ID " << userID << " no encontrado.\n";
    }

    return 0;
}
