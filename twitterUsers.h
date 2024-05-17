#ifndef TWITTERUSERS_H // Protectores de cabecera  para evitar errores de
#define TWITTERUSERS_H// compilación


#include <iostream>
#include <string>

// Estructura de twitterUser para almacenar la info. de los usuarios

struct twitterUser{

	std::string university; // Universidad a la que siguen
	std::string userName; // Nombre de usuario
	std::string since; // Fecha de creación de la cuenta

	int numberTweets; // Numero de tweets
	int followers; // Numero de seguidores
	int friends; // Numero de amigos

	long long userId;

};

#endif