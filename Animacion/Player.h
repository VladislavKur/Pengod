#pragma once

#include <SFML/Graphics.hpp>
#include "Animacion.h"


class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
    ~Player();
    void Update(int accion, float deltaTime);
    void Draw(sf::RenderWindow &window);
     void setPlayerSprite(sf::Vector2u Sprites);
     void setPosDespues(float, float);
    sf::RectangleShape getBody(){return cuerpo;}
    sf::Vector2f posDestino(){return PosDestino;}
    
    
    bool getvelocidadx(){return velx;}
    void setVelx(bool v){velx = v;}
    bool getvelocidady(){return vely;}
    void setVely(bool v){vely = v;}

    void setvidas();
    
     

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    bool nopulsarCheck=false;
    float speed= 75;
    
    int accion;
    
    sf::Vector2f PosDestino;

    int vida;

    bool velx= false;
    bool vely= false;
   
};