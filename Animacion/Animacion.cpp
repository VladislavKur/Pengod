#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Animacion::~Animacion(){}
Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen){

    this->cantidadImagenes = cantidadImagenes;
    this->cambioImagen = cambioImagen;

    spriteActual.x =0;
    tiempoTotal = 0.0f;


textureRect.height = textura->getSize().y/ float(cantidadImagenes.y);
textureRect.width = textura->getSize().x/ float(cantidadImagenes.x);


}

void Animacion::Update(int fila, float deltaTime){

    spriteActual.x = fila;
    tiempoTotal += deltaTime;
    

    if(tiempoTotal >= cambioImagen){
        tiempoTotal -= cambioImagen;
        std::cout << spriteActual.x << std::endl;
        spriteActual.x++;

        if (spriteActual.x >= 7)
        {
            spriteActual.x = 0;
        }
        
    }

    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;
}



