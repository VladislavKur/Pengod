#pragma once
#include "mapa.h"
#include <iostream>
using namespace std;

Mapa::Mapa(){}
Mapa* Mapa::mapainstance=NULL;
Mapa* Mapa::instance(){

    if(mapainstance == 0){

        mapainstance = new Mapa();

    }

    return(mapainstance);
}


void Mapa::cargarmapa(const char * f){

    if(!fichero.LoadFile(f))cout<< "No carga"<<endl;
    

    mapa = fichero.FirstChildElement("map");
    //cosas linea <map width="28" height="32" tilewidth="8" tileheight="8" nextobjectid="1">
    mapa->QueryIntAttribute("width", &width);
    mapa->QueryIntAttribute("height", &height);
    mapa->QueryIntAttribute("tilewidth", &tileWidth);
    mapa->QueryIntAttribute("tileheight", &tileHeight);
    mapa->QueryIntAttribute("nextobjectid", &nextobjectid);




    TiXmlElement * lineaTileSet = mapa->FirstChildElement("tileset");
    //cosas linea <tileset firstgid="1" name="Arcade - Pengo - Playfield &amp; Blocks" tilewidth="8" tileheight="8" tilecount="4725">

    lineaTileSet->QueryIntAttribute("tilewidth", &tileSetwidth);
    lineaTileSet->QueryIntAttribute("tileheight", &tileSetheight);
    lineaTileSet->QueryIntAttribute("tilecount", &tileSetcount);

    nTileSets= 0;
    while(lineaTileSet){// en principio solo uso un tileset
        nTileSets++;
        lineaTileSet = lineaTileSet->NextSiblingElement("tileset");
    }

    imgs = new TiXmlElement *[nTileSets]; 
    imgWidth = new int[nTileSets];
    imgHeight = new int[nTileSets];
    cambio = new int[nTileSets];
    tileSetTexture = new sf::Texture[nTileSets];

    lineaTileSet = mapa->FirstChildElement("tileset");
    int aux = 0;
    while(lineaTileSet){
        //primer while
        lineaTileSet->QueryIntAttribute("tilecount", &cambio[aux]);
        //cambio
        imgs[aux] =  lineaTileSet->FirstChildElement("image");
        lineaTileSet = lineaTileSet->NextSiblingElement("tileset");
        aux++;
    }

    for(int i = 0; i < nTileSets; i++){
         
         const char *filename = imgs[i]->Attribute("source");
        
        if(tileSetTexture[i].loadFromFile(filename)== false) cout<< "NO SE CARGA LA TEXTURA = " << /*i << */endl;
        if(filename == NULL) cout<< "error del imgSource" << i<<endl;
        
        imgs[i]->QueryIntAttribute("width", &imgWidth[i]);
        imgs[i]->QueryIntAttribute("height", &imgHeight[i]);
    }

    TiXmlElement *layer = mapa->FirstChildElement("layer");
    if(layer == NULL) cout<<" error layer"<<endl;
    
    nLayers = 0;
    while(layer){
        nLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    //reservar memoria para cada Sprite y Tile
    reservarMemoria();

      TiXmlElement * TilegidZone;
  for(int k=0; k < nLayers;){
    if( k == 0 )
        TilegidZone = mapa->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    else 
        if(k != 0){
            TilegidZone = mapa->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
        }
    for(int y=0; y< height; y++){
      for(int x=0; x< width; x++){ 
        TilegidZone->QueryIntAttribute("gid", & tilesDemapa[k][y][x]);
        TilegidZone = TilegidZone->NextSiblingElement("tile");
      }
    }
    k++;
  }

  
  }

  void Mapa::hacerSprites(){

  for(int l=0; l < nLayers; l++){
    for(int y=0; y< height; y++){
      for(int x=0; x< width; x++){
      int imagen = 0;
      bool pintada = false;
        for(int k = 0; k< nTileSets && !pintada; k++){
          int gid = tilesDemapa[l][y][x];
          if(imagen != 0){
            gid = gid - cambio[k-1];
          }
          if(gid <=  cambio[k]){
            if(gid > cambio[k]){
              cout << "Error, gid at (l,x,y)= (" << l << "," << x << "," 
              << y << ") :" << gid << " fuera del rango del tileset (" 
              << width*height << ")" << endl;
            }else if(gid > 0){
              tileMapaSprite[l][y][x] = new sf::Sprite(tileSetTexture[k]);
              int Tcolumnas = imgWidth[k] / tileWidth; 
              int fila = (gid / Tcolumnas);
              int columna = (gid % Tcolumnas);
              if(columna == 0){
                fila = fila - 1;
                columna = Tcolumnas -1 ;
              }else{
                columna = columna - 1;
              }
              if(columna < 0){
                columna = 0;
              }
              tileMapaSprite[l][y][x]->setTextureRect(sf::IntRect(columna*16, fila*16, 16, 16));
              tileMapaSprite[l][y][x]->setPosition(x*(tileWidth*3), y*3*tileHeight);
              tileMapaSprite[l][y][x]->setScale(3,3);
              pintada = true;
            }else{
              tileMapaSprite[l][y][x] = NULL;
            }
          }else{
            imagen++;
          }
        }
      }
    }
  }

}
    
        
    

void Mapa::reservarMemoria(){
    //reservar memoria para cada Sprite
 tilesDemapa = new int **[nLayers];
  for(int i = 0; i < nLayers; i++){
    tilesDemapa[i] = new int * [height];
  }
  for(int i = 0; i < nLayers; i++){
    for(int j = 0; j < height; j++){
      tilesDemapa[i][j] = new int [width];
    }
  }

    //reservar memoria
  tileMapaSprite = new sf::Sprite ***[nLayers];
  for(int i = 0; i < nLayers; i++){
    tileMapaSprite[i] = new sf::Sprite ** [height];
  }
  for(int i = 0; i < nLayers; i++){
    for(int j = 0; j < height; j++){
      tileMapaSprite[i][j] = new sf::Sprite * [width];
    }
  }


} 


void Mapa::draw(sf::RenderWindow& window){
 for(int l=0; l< nLayers;l++){
    for(int y=0; y<height;y++){
      for(int x=0; x<width;x++){
          window.draw(*(tileMapaSprite[l][y][x]));
      }
    }
  }
}

