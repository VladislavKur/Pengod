#include <SFML/Graphics.hpp>
#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos) : 
animacion(textura, cantidadImagenes, SwitchTimeSprite)
{
    
    //matriz de 13*15 empezando en 1,1
    
    cuerpo.setSize(sf::Vector2f(16.0f*2,16.0f*2));
    cuerpo.setPosition(2*16*pos.x,2*16*pos.y);
    cuerpo.setTexture(textura);
    cuerpo.setTextureRect(sf::IntRect(1*16,9*16,16,16));

    
   


    vida = 5;
    
}
 
Enemigo::~Enemigo(){}
          
void Enemigo::Update( float deltaTime){
    Juego *juego = Juego::instance();
    sf::Vector2f movement;
    sf::Vector2u sprite;
    float timer = 0;
    bool choca = false;
    choca =juego->EnemigoBloqueColision();
    timer += deltaTime;
    for(int i = 0; i <= 4; i++){
    int acciones;
    
    acciones = rand()%4;
    
    // aqui luego ira un bool donde diga que a colisionado con algo
      switch (acciones){
            
            case 0: sprite.x = 1;sprite.y = 9; ;break;
            case 1: sprite.x = 3;sprite.y = 9; ;break;
            case 2: sprite.x = 5;sprite.y = 9; ;break;
            case 3: sprite.x = 7;sprite.y = 9;  ;;break;
            

        default :  break;
        }
       
    }
        //std::cout << cuerpo.getPosition().x << ", " << cuerpo.getPosition().y <<" ====" << PosDestino.x <<", " << PosDestino.y << std::endl;
        
   cuerpo.move(0*deltaTime,0*deltaTime);

    animacion.Update(sprite, deltaTime);
    cuerpo.setTextureRect(animacion.textureRect);
    
}


void Enemigo::setEnemigoSprite(sf::Vector2u Sprites){
    animacion.setSprite(Sprites);
}




void Enemigo::setvidas(){
    vida--;
   // if(vida<= 0) morir();
}


void Enemigo::Draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}
