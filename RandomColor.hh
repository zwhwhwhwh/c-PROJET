#pragma once
#include "RGB.hh"
#include<iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>

/* Générer une couleur de RGB au hasard */

class RandomColor:public RGB{
public:
        RandomColor();
	friend std::ostream& operator<<(std::ostream& , const RandomColor &);

};

RandomColor::RandomColor():RGB(){
       srand(time(NULL));
	x=rand()%256;
	y=rand()%256;
    z=rand()%256;
}

std::ostream& operator<<(std::ostream& os , const RandomColor& c)
{
        os << c.hexadecimal() << endl;
   return os;
}
