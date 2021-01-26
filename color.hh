#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Espace colorimétrique */

class ColorSpace
{
protected: //Trois valeurs de coordonnées
  size_t x; 
  size_t y;
  size_t z;

public:
  ColorSpace(size_t a, size_t b, size_t c);
  ColorSpace(const ColorSpace& color);
  virtual string hexadecimal()const =0;  //Représentation hexadécimale de la couleur
  virtual vector<size_t> toRGB()const=0;  //La valeur RGB de la couleur est stockée dans un conteneur
  virtual vector<size_t> toHSV()const=0;  //La valeur HSV de la couleur est stockée dans un conteneur
  size_t getX(){return x;}           //Obtenir les valeurs des coordonnées 
  size_t getY(){return y;} 
  size_t getZ(){return z;}
  void setX(size_t a){x=a;}         //Changer la valeur des coordonnées
  void setY(size_t a){y=a;}
  void setZ(size_t a){z=a;}
};

ColorSpace::ColorSpace(size_t a, size_t b, size_t c):x(a),y(b),z(c){

}

ColorSpace::ColorSpace(const ColorSpace& color):x(color.x),y(color.y),z(color.z){

}
