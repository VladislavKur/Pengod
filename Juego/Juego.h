#pragma once
#include <SFML/Graphics.hpp>
#include "../mapaxml/mapa.h"
#include <iostream>
#include "../Animacion/Bloque.h"
#include "../Animacion/Enemigo.h"
#include "../Animacion/Player.h"

#ifndef JUEGO_H
#define JUEGO_H
    class Bloque;
    class Enemigo;
    class Player;

    class Juego{

        private:
            
            static Juego* pinstance;
            int numEmenigos; 
            int numObjetos;
            bool no = false;
            std::vector<std::vector<Bloque *>>  listaBloque;
            std::vector<std::vector<Enemigo *>>  listaEnemigos;
            std::vector<std::vector<Bloque *>>  rlistaBloque;
            std::vector<std::vector<Enemigo *>>  rlistaEnemigos;

            sf::Vector2f bcoord;
            sf::Vector2f bcoordF;
            float timer = 0;
            float timer2 = 0;
            

        protected:
            Juego();

        public:
            static Juego *instance();
            void update(float deltaTime, Player *,sf::RenderWindow &window );
            
            void Draw(sf::RenderWindow &window);
            void DrawBloques(sf::RenderWindow &window);
            void DrawEnemigos(sf::RenderWindow &window);
            void DrawrBloques(sf::RenderWindow &window);
            void DrawrEnemigos(sf::RenderWindow &window);


        
            bool Reinicio(Player *, sf::RenderWindow &window);
            void Next(sf::RenderWindow &window);
            void Borrar();
            void crearBloques(); 
            void crearEnemigos();

            void morir(Player *, float,sf::RenderWindow &window);

            


            
            

            bool PlayerBloqueColision(Player * jugador,int ); 
            bool EnemigoBloqueColision();
            sf::Vector2f BloqueBloqueColision(Player *);
            sf::Vector2f BloqueBloqueColisionF(Player *);
            std::vector<std::vector<Enemigo *>> getListaEnemigos(){return listaEnemigos;}
            std::vector<std::vector<Bloque *>> getListaBloque(){return listaBloque;}
            

       
    };

#endif