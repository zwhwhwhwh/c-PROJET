// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "color.hh"
#include "RGB.hh"
#include "HSV.hh"
#include "Calculer.hh"
#include "Complementaire.hh"
#include "TriColor.hh"
#include "RandomColor.hh"
#include "ColorBoard.hh"
#include <iostream>
#include <string>


TEST_CASE("1: ColorSpace RGB ")
{
  RGB rgb1(255,230,230);
  RGB rgb2(rgb1);
  REQUIRE(rgb2.getX()== 255);
  REQUIRE(rgb2.hexadecimal()== "#ffe6e6");
  std::cout<<"--------- Couleur RGBtoHSV ---------"<<endl;
  std::cout<<(rgb2.toHSV())[0]<<" "<<(rgb2.toHSV())[1]<<" "<<(rgb2.toHSV())[2]<<endl;
  std::cout<<"--------- Valeur hexadécimale ---------"<<endl;
  std::cout<<rgb2;
  std::cout<<"--------- Valeur Grey ----------"<<endl;
  std::cout<<(rgb2.toGrey())[0]<<endl;
  std::cout<<"--------- Valeur unitaire --------"<<endl;
  std::cout<<(rgb2.toUnity())[0]<<" "<<(rgb2.toUnity())[1]<<" "<<(rgb2.toUnity())[2]<<endl;
}

TEST_CASE("2: ColorSpace HSV")
{
  HSV hsv1(270,30,40);
  HSV hsv2(hsv1);
  REQUIRE(hsv1.getY()== 30);
  std::cout<<"-------- Couleur HSVtoRGB ---------"<<endl;
  std::cout<<(hsv2.toRGB())[0]<<" "<<(hsv2.toRGB())[1]<<" "<<(hsv2.toRGB())[2]<<endl;
  std::cout<<"--------- Valeur hexadécimale ---------"<<endl;
  std::cout<<hsv2;

}

TEST_CASE("3: Deux couleurs mélangées")
{
   RGB rgb1(110,60,250);
   RGB rgb2(40,28,80);
   HSV hsv(120,80,25);
   Calculer cal1(rgb1,rgb2);
   REQUIRE(cal1.getX()==75);
   Calculer cal2(rgb1,hsv);
   REQUIRE(cal2.getZ()==131);
   Calculer cal3(rgb1,cal1);
   REQUIRE(cal3.getY()==52);
   std::cout<<"------- Melange 2 RGB ------ "<<endl;
   std::cout<<cal1;
   std::cout<<"------- Melange RGB et HSV ------"<<endl;
   std::cout<<cal2;
   std::cout<<"------- Melange Cal et RGB -------"<<endl;
   std::cout<<cal3;
}


TEST_CASE("4: Couleur complémentaire")
{
  RandomColor ran;
  Complementaire com1(ran);
  HSV hsv(102,102,71);
  Complementaire com2(hsv);
  REQUIRE(com2.getX()==74);
  std::cout<<"------- Couleur complémentaire de RGB random ------ "<<endl;
  std::cout<<com1;
  std::cout<<"------- Couleur complémentaire de HSV ------"<<endl;
  std::cout<<com2;

}

TEST_CASE("5: Méthode de couleur triangulaire")
{
   HSV hsv(60,30,40);
   TriColor tri(hsv);
   REQUIRE((tri.getleftcolorRGB())[0]==102);
   std::cout<<"------- 3 Couleurs triangulaire  ---------"<<endl;
   std::cout<<tri;



}


TEST_CASE("6: Un ensemble de couleurs similaires")
{
   RGB rgb(100,140,50);
   ColorBoard cb(rgb);
   std::cout<<"------- 5 Couleurs similaires  ---------"<<endl;
   std::cout<<cb;



}
