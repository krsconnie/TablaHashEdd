#ifndef TWITTERUSERS_H // Protectores de cabecera  para evitar errores de
#define TWITTERUSERS_H// compilación


#include <iostream>
#include <string>
/* Estructura twitterUser
 * Almacena la información de los usuarios de Twitter.
 */
struct twitterUser {
    std::string university; // Universidad a la que siguen
    std::string userName; // Nombre de usuario
    std::string since; // Fecha de creación de la cuenta

    int numberTweets; // Número de tweets
    int followers; // Número de seguidores
    int friends; // Número de amigos

    long long userId; // ID del usuario
};

#endif
