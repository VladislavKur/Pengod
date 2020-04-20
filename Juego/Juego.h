#pragma once
#include <SFML/Graphics.hpp>
#include "../mapaxml/mapa.h"
#include <iostream>
#include "../Animacion/Bloque.h"
#include "../Animacion/Enemigo.h"
#include "../Animacion/Player.h"

#ifndef JUEGO_H
#define JUEGO_H

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
            

        protected:
            Juego();

        public:
            static Juego *instance();
            void update(float deltaTime);
            
            void Draw(sf::RenderWindow &window);
            void DrawBloques(sf::RenderWindow &window);
            void DrawEnemigos(sf::RenderWindow &window);


        

            void crearBloques(); 
            void crearEnemigos();
            void crearBloquesR(); 
            void crearEnemigosR();

            bool PlayerBloqueColision(Player * jugador,int ); 

            std::vector<std::vector<Enemigo *>> getListaEnemigos(){return listaEnemigos;}
            

       
    };

#endif