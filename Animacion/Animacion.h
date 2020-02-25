#include <SFML/Graphics.hpp>

class Animacion{

    public:
        Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen);
        ~Animacion();
        void Update(int fila, float deltaTime);


        sf::IntRect textureRect;

    private:
        sf::Vector2u cantidadImagenes;
        sf::Vector2u spriteActual;
  

        float tiempoTotal;
        float cambioImagen;
};