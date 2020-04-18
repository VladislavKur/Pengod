#pragma once

#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Enemigo{
    public:
    Enemigo(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite, sf::Vector2f);
    ~Enemigo();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);
     void setEnemigoSprite(sf::Vector2u Sprites);
     
    sf::RectangleShape getBody(){return cuerpo;}

    void setvidas();
     

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    
    float speed= 150;
    int accion;

    int vida;
   
};