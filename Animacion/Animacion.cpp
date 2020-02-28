#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Animacion::~Animacion(){}
Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite){

    this->cantidadImagenes = cantidadImagenes;
    this->SwitchTimeSprite = SwitchTimeSprite;

   
    swit = true;
    spriteActual.x =0;
    tiempoTotalDelta = 0.0f;
    

textureRect.height = textura->getSize().y/ float(cantidadImagenes.y);
textureRect.width = textura->getSize().x/ float(cantidadImagenes.x);


}

void Animacion::Update(sf::Vector2u Sprites, float deltaTime){
    
    
    spriteActual.y = Sprites.y;
   
    tiempoTotalDelta += deltaTime;
    spriteActual.x = Sprites.x;
    
    if(tiempoTotalDelta >= SwitchTimeSprite){
        tiempoTotalDelta -= SwitchTimeSprite;
        
        if(swit){
       
            swit= false;
            spriteActual.x=5;
            std::cout << "entra\n";
        }
        else{
         
            spriteActual.x--;
            swit = true;
        } 

        
    }else{  std::cout << "NOentra\n";;}

    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;
    std::cout << spriteActual.x << std:: endl;
     
      std::cout << spriteActual.y<< std:: endl;
      std::cout << "------------------" << std:: endl;
       

}



