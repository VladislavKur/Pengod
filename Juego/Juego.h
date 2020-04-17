#pragma once
#include <SFML/Graphics.hpp>
#include "../mapaxml/mapa.h"
#include <iostream>

#ifndef JUEGO_H
#define JUEGO_H

    class Juego{

        private:
            
            static Juego* pinstance;
            int numEmenigos; 
            int numObjetos;
            bool no = false;
        protected:
            Juego();

        public:
            static Juego *instance();
            void update(float deltaTime);
            
            void Draw(sf::RenderWindow &window);
            bool ComprobarMov(float);      
            int MovAleatorio();     
            

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