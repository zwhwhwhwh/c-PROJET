#pragma once
#include "RGB.hh"
#include "HSV.hh"
#include<iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

/* Méthode de couleur triangulaire */

class TriColor:public RGB{
public:
	TriColor(ColorSpace &);
    vector<size_t> getleftcolorRGB(){return leftcolor.toRGB();}     
    vector<size_t> getrightcolorRGB(){return leftcolor.toRGB();}   
    friend std::ostream& operator<<(std::ostream& , const TriColor &);
private:
	HSV leftcolor;//Dans le cercle de couleur, la couleur à gauche de la couleur spécifiee 
	HSV rightcolor;//Dans le cercle de couleur, la couleur à droite de la couleur spécifiee 
};

TriColor::TriColor(ColorSpace &c):RGB(){
    vector<size_t> v1 = c.toRGB();          
    
    x = v1[0];
    y = v1[1];
    z = v1[2];                 
    vector<size_t> v2 = c.toHSV();
    v2.clear();
    size_t H1;                     //Dans le cercle de couleur, prenez deux couleurs qui forment un triangle équilatéraux avec la couleur d'entrée
    if(v2[0]>=120){
      H1=v2[0]-120;}
    else{
      H1=v2[0]+360-120;}
    size_t hi = v2[0] + 120;
    //cout<<hi<<endl;
    size_t H2 ;
    if(hi>360){
      H2=hi-360;}
    else{
      H2=hi;}
    HSV L(H1,v2[1],v2[2]);
    HSV R(H2,v2[1],v2[2]);
    leftcolor=L;
    rightcolor=R;
   }

std::ostream& operator<<(std::ostream& os , const TriColor& c)
{
        os << c.leftcolor.hexadecimal() << endl;
        os << c.hexadecimal() << endl;
        os << c.rightcolor.hexadecimal() << endl;
   return os;
}
