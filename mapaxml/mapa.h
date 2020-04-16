
#pragma once
#include "tinyxml.h"


#include <SFML/System.hpp>


#include <string>
#include "SFML/Graphics.hpp"


class Mapa {

public:
  static Mapa *instance();
   void cargarmapa(const char * f ); 
  ~Mapa();
  void hacerSprites();
  

  void reservarMemoria();
  void draw(sf::RenderWindow& window);
  protected:
            Mapa();
  
private:

        static Mapa* mapainstance;
        TiXmlDocument  fichero;
        TiXmlElement * mapa;

        //cosas del <map>
        int height;
        int width;
        int tileHeight;
        int tileWidth;
        int nextobjectid;

        //cosas del tileset
        int nTileSets = 0;
        int tileSetwidth;
        int tileSetheight;
        int tileSetcount;

        sf::Sprite **** tileMapaSprite;
        sf::Texture * tileSetTexture;
        TiXmlElement ** imgs;
        int * cambio;
        int * imgWidth;
        int * imgHeight;

        //cosas de layer
        int nLayers;
        int ***tilesDemapa;
       
 

};

