#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Animacion::~Animacion(){}
Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite){

    this->cantidadImagenes = cantidadImagenes;
    this->SwitchTimeSprite = SwitchTimeSprite;

   
    swit = true;
    spriteActual.x =1;
    
    tiempoTotalDelta = 0.0f;
    

textureRect.height = textura->getSize().y/ float(cantidadImagenes.y);
textureRect.width = textura->getSize().x/ float(cantidadImagenes.x);


}

void Animacion::Update(sf::Vector2u Sprites, float deltaTime){

    spriteActual.y = Sprites.y;
    //spriteActual.x = Sprites.x; // esto tengo que ponerlo antes

    tiempoTotalDelta += deltaTime;
    if(tiempoTotalDelta >= SwitchTimeSprite){
        tiempoTotalDelta = 0;
        
        if(swit){
            
            swit= false;
            spriteActual.x=Sprites.x;
            
        }
        else{
         
            spriteActual.x --;
            swit = true;
        } 

        
    }

    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;
    
       

}

 void Animacion::setSprite(sf::Vector2u Sprites){
    spriteActual.x=Sprites.x;
    spriteActual.y=Sprites.y;

    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;

 }



