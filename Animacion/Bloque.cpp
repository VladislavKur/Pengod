
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
    dir = -1;
    

   //por defecto es un bloque de hielo, no diamante ese raro

    
   



    
}
 
Bloque::~Bloque(){}
          
void Bloque::Update(float deltaTime, bool mov, Player* player){
    sf::Vector2u sprite;
    sf::Vector2f movim;
    
    Juego* juego = Juego::instance();
    sf::Vector2f coord(-1,-1);
    
    std::vector<std::vector<Bloque *>>lista = juego->getListaBloque();
    tiempoT += deltaTime;
    if(tiempoT >= 1){if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        
        tiempoT = 0;
    coord = juego->BloqueBloqueColision(player, this);
        coord.x = (int)coord.x;
        coord.y = (int)coord.y;
       if(coord.x > -1 && coord.y >-1 && coord.x < 14 && coord.y < 16) 
       if(lista[coord.x][coord.y] != nullptr){
       
       cuerpo = lista[coord.x][coord.y]->getBody();
       
       cuerpo.setPosition(coord.x*32, coord.y*32);
       std::cout << cuerpo.getPosition().x << ", " << cuerpo.getPosition().y << std::endl;
       }
        }
    }
        if(coord.x != -1 && coord.y != -1 &&this ==lista[coord.x][coord.y])
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
