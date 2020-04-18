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

        protected:
            Juego();

        public:
            static Juego *instance();
            void update(float deltaTime);
            
            void Draw(sf::RenderWindow &window);
            void DrawBloques(sf::RenderWindow &window);
            void DrawEnemigos(sf::RenderWindow &window);


            bool ComprobarMov(float);      
            int MovAleatorio(); 

            void crearBloques(); 
            void crearEnemigos();

            std::vector<std::vector<Enemigo *>> getListaEnemigos(){return listaEnemigos;}
            

            /*void colisionBulletJugador(float deltatime);
            void colisionBulletEnemigo(float deltaTime);
            void colisionPlayerMundo(float deltaTime);
            void colisionBulletMundo(float deltaTime);

            void crearObjetos();
            void destruirObjetos(Objeto*);
            void crearEnemigos();
            Player *getJugador(){return jugador;};
            void matarEnemigo(Enemigo* enem);
            void matarJugador();
            void disparar(float deltaTime);
            void dispararEnemigo(float deltaTime, float x, float y, bool direccion);
            void colisionEnemigoPlayer(Enemigo* enem, float deltaTime);*/
            


            
            //sf::View view;
    };

#endif