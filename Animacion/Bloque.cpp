
#include <SFML/Graphics.hpp>
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos, int t) 


{
         sf::Texture *text = new sf::Texture;
         tipo = t; 
         if (t == 0){
             text->loadFromFile("resources/CuboDeHielo.png");
             if(!text->loadFromFile("resources/CuboDeHielo.png")) std::cout << "sadasds";
            cuerpo.setTextureRect(sf::IntRect (0,0,16,16));
         }else {
                text->loadFromFile("resources/CuboDeDiamante.png");
             if(!text->loadFromFile("resources/CuboDeDiamante.png")) {
                 std::cout << "sadasds";
                    cuerpo.setTextureRect(sf::IntRect (0,0,32,32));
             }
         }
   
   
    //matriz de 13*15 empezando en 1,1
    
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(2*16*pos.x,2*16*pos.y);

     
    cuerpo.setTexture(text);
    dir = -1;
    textu = text;
    CI.x = cantidadImagenes.x; CI.y = cantidadImagenes.y;
    ST = SwitchTimeSprite;
    

   //por defecto es un bloque de hielo, no diamante ese raro

    
   



    
}
 
Bloque::~Bloque(){}
          
void Bloque::Update(float deltaTime, bool mov, Player* player){
    sf::Vector2u sprite;
    sf::Vector2f movim;
    
    Juego* juego = Juego::instance();
    
        switch (dir)
        {
        case -1: movim.x = 0; movim.y = 0;
            break;
        case 0: movim.x = 0; movim.y = speed;
            break;
        case 1: movim.x = -speed; movim.y = 0;
            break;
        case 2: movim.x = 0; movim.y = -speed;
            break;
        case 3: movim.x = speed; movim.y = 0;
            break;
        
        default: movim.x = 0; movim.y = 0;
            break;
        }
        
    cuerpo.move(movim.x*deltaTime,movim.y*deltaTime);

    
    
    
}




void Bloque::setMov(bool semueve){
    mov = semueve;
}



void Bloque::Draw(sf::RenderWindow &window){
    
    window.draw(cuerpo);
}
