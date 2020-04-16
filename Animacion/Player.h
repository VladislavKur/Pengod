#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
    ~Player();
    void Update(int accion, float deltaTime,float speed);
    void Draw(sf::RenderWindow &window);
     void setPlayerSprite(sf::Vector2u Sprites);
     void setPosDespues(float, float);
    sf::RectangleShape getBody(){return cuerpo;}
     

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    
    float speed;
    int accion;
    float tiempoMov;
    sf::Vector2f PosDestino;

    bool notifaller = false;
   
};