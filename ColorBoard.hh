#pragma once
#include "RGB.hh"
#include "HSV.hh"
#include<iostream>
#include <cstdlib>
#include <string>
#include <vector>

/* Créez un colorBoard qui produit cinq couleurs similaires */

class ColorBoard:public RGB{
public:
	ColorBoard(ColorSpace &);
	vector<vector<size_t> > tocolorBoard();  //Les valeurs RGB des cinq couleurs sont stockées dans le conteneur
	friend std::ostream& operator<<(std::ostream& , const ColorBoard&);

private:
	HSV adcolor[4];   //Quatre couleurs similaires à la couleur d'entrée
};


ColorBoard::ColorBoard(ColorSpace &c):RGB(){
    vector<size_t> v1 = c.toRGB();
    x = v1[0];
    y = v1[1];
    z = v1[2];
    vector<size_t> v2 = c.toHSV();
    size_t s,v;
    
    for(int i=0;i<4;i++){                    
      adcolor[i].setX(v2[0]);                    //Augmenter ou diminuer la saturation et la value
    	if(i<2){
      	    s=v2[1]-(2-i)*(v2[1]/3);
    		v=v2[2]+(2-i)*((100-v2[2])/3);
    	}
    	else{
    		s=v2[1]+(2-i)*((100-v2[2])/3);
    		v=v2[2]-(2-i)*(v2[2]/3);	
    	}

    	adcolor[i].setY(s);
        adcolor[i].setZ(v);
    }


}
vector<vector<size_t> > ColorBoard::tocolorBoard(){
   vector <vector<size_t> > v;
   v.clear();
     v.push_back(adcolor[0].toRGB());
     v.push_back(adcolor[1].toRGB());
     v.push_back(toRGB());
     v.push_back(adcolor[2].toRGB());
     v.push_back(adcolor[3].toRGB());
     return v;

}

std::ostream& operator<<(std::ostream& os , const ColorBoard& c)
{  
        os << c.adcolor[0].hexadecimal() <<endl;
        os << c.adcolor[1].hexadecimal() <<endl;
        os << c.hexadecimal() <<endl;
        os << c.adcolor[2].hexadecimal() <<endl;
        os << c.adcolor[3].hexadecimal() <<endl;
    
   return os;
}
