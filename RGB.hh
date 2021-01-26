#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include "color.hh"
#include <vector>
#include <sstream> //Convertir en hexadecimal

class RGB :public ColorSpace {
public:
RGB(size_t r, size_t g, size_t b);
RGB(const RGB& rgb);
  RGB();
  vector<size_t> toGrey()const;
vector<float> toUnity()const;
  vector<size_t> toRGB()const;
  vector<size_t> toHSV()const;
  string hexadecimal()const;
void setX(size_t a){x=a;}
  void setY(size_t a){y=a;}
  void setZ(size_t a){z=a;}
  RGB operator*(const RGB&);
void operator=(const RGB&);
friend std::ostream& operator<<(std::ostream& , const RGB &);
};


RGB::RGB(size_t r, size_t g, size_t b) : ColorSpace(r,g,b){}

RGB::RGB(const RGB& rgb) : ColorSpace(rgb){}

RGB::RGB():ColorSpace(0,0,0){}

vector<size_t> RGB::toGrey()const {
    size_t grey = (x*30+y*59+z*11)/100;  //Convertir RVB en valeur de niveaux de gris
     vector<size_t> v;
    v.clear();
    for(int i=0;i<3;i++){
        v.push_back(grey);
    }
    return v;
}

vector<float> RGB::toUnity()const{    //Normaliser les valeurs RVB
    vector<float> v;
    v.clear();
    v.push_back((float)x/255);
    v.push_back((float)y/255);
    v.push_back((float)z/255);
    return v;
}


vector<size_t> RGB::toRGB()const{
  vector<size_t> v;
  v.clear();
  v.push_back(x);
  v.push_back(y);
  v.push_back(z);
  return v;
}

vector<size_t> RGB::toHSV()const{
  size_t h,s,v;
  float max,min;
  vector<float> v1;
  v1.clear();
  v1=toUnity();
    //obtenir max et min pour calculer les valeur HSV
    if(v1[0]>v1[1]){
        max = v1[0];
        min = v1[1];
    }
    else{
        max = v1[1];
        min = v1[0];
    }
    if(max<v1[2]) max = v1[2];
    if(min>v1[2]) min = v1[2];
    //calculer H
    if(max==min) h=0;
    else{
        if(max==x){
	  if(v1[1]<v1[2]) h = (size_t)(60*(v1[1]-v1[2])/(max-min)+360);
	  else h = (size_t)(60*(v1[1]-v1[2])/(max-min));
        }
        if(max==v1[1]) h = (size_t)(60*(v1[2]-v1[0])/(max-min)+120);
        if(max==v1[2]) h = (size_t)(60*(v1[0]-v1[1])/(max-min)+240);
    }
    //calculer S
    if(max==0) s = 0;
    else s = (size_t)((1-min/max)*100);
    //calculer V
    v =(size_t) (max*100);

     vector<size_t> vec;
    vec.clear();
    vec.push_back(h);
    vec.push_back(s);
    vec.push_back(v);
    //cout<<vec[0]<<". "<<vec[1]<<". "<<vec[2]<<endl;
    return vec;    
}

string RGB::hexadecimal()const{
   vector<size_t> v=toRGB();
    stringstream ss;
        ss << "#";
	ss << std::hex << (v[0] << 16 | v[1] << 8 | v[2]);
    
	return ss.str();
}


RGB RGB::operator*(const RGB& c){     
  vector<float> v1=toUnity();
  vector<float> v2=c.toUnity();
  x=(size_t)(v1[0]*v2[0]*255);
  y=(size_t)(v1[1]*v2[1]*255);
  y=(size_t)(v1[2]*v2[2]*255);
    return *this;
}

void RGB::operator=(const RGB& c){
    this->x = c.x;
    this->y = c.y;
    this->z = c.z;
    
}

std::ostream& operator<<(std::ostream& os , const RGB& c)    ////Surcharger l'opérateur << pour print sous le fomat hexadécimal
{
        os << c.hexadecimal() <<endl;
   return os;
}
