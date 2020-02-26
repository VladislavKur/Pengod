#include <SFML/Graphics.hpp>

class Animacion{

    public:
        Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float cambioImagen, int accion);
        ~Animacion();
        void Update(int fila, float deltaTime, int accion);
        


        sf::IntRect textureRect;

    private:
        sf::Vector2u cantidadImagenes;
        sf::Vector2u spriteActual;
        int accion;

        float tiempoTotal;
        float cambioImagen;
};