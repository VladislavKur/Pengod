#pragma once

#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Player.h"
#include "../Juego/Juego.h"

class Player;
class Bloque{
    public:
    Bloque(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite,sf::Vector2f pos, int );
    ~Bloque();
    void Update(float deltaTime, bool, Player *);
    void Draw(sf::RenderWindow &window);
     void setBloqueSprite(sf::Vector2u Sprites);
     void setPosDespues(float, float);
    sf::RectangleShape getBody(){return cuerpo;}
    sf::Vector2f posDestino(){return PosDestino;}

    bool getMov(){return mov;}
    void setMov(bool);

    int getTipo(){return tipo;}
    sf::Texture* getTexture(){return textu;}
    sf::Vector2f getCI(){return CI;}
    float getST(){return ST;}
    void setAccion(int a){dir = a;}

    

    private:

    sf::RectangleShape cuerpo;
    sf::Texture * textu;
    sf::Vector2f CI;
    float ST;
    Animacion animacion;
    sf::Vector2u fila;
    bool mov=false;
    float speed=400;
    int dir;
    int tipo = 0;
    float tiempoT =0;
    
    sf::Vector2f PosDestino;

   
};