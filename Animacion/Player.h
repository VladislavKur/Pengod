#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player{
    public:
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite, float speed);
    ~Player();
    void Update(int accion, float deltaTime,float speed);
    void Draw(sf::RenderWindow &window);
     void setPlayerSprite(sf::Vector2u Sprites);

    

    private:

    sf::RectangleShape cuerpo;
    Animacion animacion;
    sf::Vector2u fila;
    
    float speed;
   
};