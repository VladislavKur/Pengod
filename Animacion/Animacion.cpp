#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Animacion::~Animacion(){}
Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, int accion){

    this->cantidadImagenes = cantidadImagenes;
    this->cambioImagen = cambioImagen;

    accion = 0;

    spriteActual.x =0;
    tiempoTotal = 0.0f;
    

textureRect.height = textura->getSize().y/ float(cantidadImagenes.y);
textureRect.width = textura->getSize().x/ float(cantidadImagenes.x);


}

void Animacion::Update(int fila, float deltaTime, int accion){
    bool swit = true;
    int cambiador = 0;
    if(accion == -1) cambiador = 0;else cambiador = accion;
    
    spriteActual.y = fila;
   


    spriteActual.x = cambiador*2;
    tiempoTotal += deltaTime;

    
    

    if(tiempoTotal >= cambioImagen){
        tiempoTotal -= cambioImagen;
        std:: cout << swit << std:: endl;
        if(swit){
       
        swit= false;
        spriteActual.x++;
        }
        else{
         
            spriteActual.x--;
            swit = true;
        } 

        
    }

    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;
}



