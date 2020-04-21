
#include <SFML/Graphics.hpp>
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos, int t) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)

{
         sf::Texture *text = new sf::Texture;
         tipo = t; if (t == 0){
             text->loadFromFile("resources/CuboDeHielo.png");
             if(!text->loadFromFile("resources/CuboDeHielo.png")) std::cout << "sadasds";

         }else {
                text->loadFromFile("resources/CuboDeDiamante.png");
             if(!text->loadFromFile("resources/CuboDeDiamante.png")) std::cout << "sadasds";

         }
   
   
    //matriz de 13*15 empezando en 1,1
    
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(2*16*pos.x,2*16*pos.y);

     
    cuerpo.setTexture(text);
    

   //por defecto es un bloque de hielo, no diamante ese raro

    
   



    
}
 
Bloque::~Bloque(){}
          
void Bloque::Update(float deltaTime, bool mov, Player* player){
    sf::Vector2u sprite;
    sf::Vector2f movim;
    Juego* juego = Juego::instance();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    juego->BloqueBloqueColision(player,deltaTime);
    

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    
}


void Bloque::setBloqueSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}


void Bloque::setMov(bool semueve){
    mov = semueve;
}



void Bloque::Draw(sf::RenderWindow &window){
    cuerpo.setTextureRect(sf::IntRect (0,0,16,16));
    window.draw(cuerpo);
}
