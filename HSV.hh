#pragma once
#include<iostream>
#include <cstdlib>
#include <string>
#include "color.hh"
#include <vector>
#include <sstream>

class HSV :public ColorSpace {
public:
HSV(size_t r, size_t g, size_t b);
HSV(const ColorSpace& color);
HSV();
  vector<size_t> toRGB()const;
  vector<size_t> toHSV()const;
  string hexadecimal()const;
void setX(size_t a){x=a;}
  void setY(size_t a){y=a;}
  void setZ(size_t a){z=a;}
void operator=(const HSV&);
friend std::ostream& operator<<(std::ostream& , const HSV &);
};

HSV::HSV(size_t h, size_t s, size_t v):ColorSpace(h,s,v){

}

HSV::HSV(const ColorSpace& hsv):ColorSpace(hsv){}

HSV::HSV():ColorSpace(0,0,0){}

vector<size_t> HSV::toHSV()const{
	vector<size_t> v;
	v.clear();
	v.push_back(x);
	v.push_back(y);
    v.push_back(z);
    return v;
}

vector<size_t> HSV::toRGB()const{
	 vector<size_t> vec;       
	vec.clear();
	float s=(float)y/100;              //Calcul de la conversion de la valeur HSV en valeur RVB
        float v=(float)z/100;        
	size_t hi=(x/60)%60;
	size_t f=(float)x/60-hi;
    float p=v*(1-s);
    float q=v*(1-f*s);
    float t=v*(1-(1-f)*s);
    size_t p1=(size_t)(p*255);
    size_t q1=(size_t)(q*255);
    size_t t1=(size_t)(t*255);
    size_t v1=(size_t)(v*255);

    if(hi==0){
        vec.push_back(v1);
        vec.push_back(t1);
        vec.push_back(p1);
    }
    else if(hi==1){
        vec.push_back(q1);
        vec.push_back(v1);
        vec.push_back(p1);	
    }
    else if(hi==2){
    	vec.push_back(p1);
        vec.push_back(v1);
        vec.push_back(t1);
    }
    else if(hi==3){
    	vec.push_back(p1);
        vec.push_back(q1);
        vec.push_back(v1);
    }
    else if(hi==4){
    	vec.push_back(t1);
        vec.push_back(p1);
        vec.push_back(v1);
    }
    else{
    	vec.push_back(v1);
        vec.push_back(p1);
        vec.push_back(q1);
    }
    //cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;
  return vec;

}

string HSV::hexadecimal() const{
    vector<size_t> v=toRGB();
    stringstream ss;
        ss << "#";
	ss << std::hex << (v[0] << 16 | v[1] << 8 | v[2]);   //Le format hexadécimal de sortie est: #rrggbb
    
	return ss.str();

}

void HSV::operator=(const HSV& c){
	this->x = c.x;
	this->y = c.y;
	this->z = c.z;
	
}

std::ostream& operator<<(std::ostream& os , const HSV& c)   //Surcharger l'opérateur << pour print sous le fomat hexadécimal
{
   		os << c.hexadecimal() <<endl;
   return os;
}
