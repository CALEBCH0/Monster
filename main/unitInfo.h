#ifndef UNITINFO_H_
#define UNITINFO_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>


class Player {
  public:
    std::string name;
    std::string role;
    int health;
    int strength;
    int shield = 0;
    int blindLimit;
    int sleepLimit; 
    int protectLimit;
    bool life = false;
    
    bool deathCheck(){
      if (health < 1){
        return true;
        }
      return false;
    }
    
    int getPlayer(){
      std::string yn;
      bool getName = false;
      std::cout << "wellcome! what's your name: \t\t\t |";
      std::getline(std::cin, name);
      std::cout << "select your role( warrior/shieldsman/ninja ): \n";
      std::cout << "warrior:      high attack, moderate health \n";
      std::cout << "shieldsman:   high health, low attack, heal every round \n";
      std::cout << "ninja:        moderate attack, moderate attack, counterattack if dodge attack \n";
      std::cout << "mage:         low health, high attack, attack/blind/sleep enemy or make protection \n";
      while (getName == false){
      std::cout << "\t |";
      std::getline(std::cin, role);
      if (role == "warrior") {health = 120; strength = 40; getName = true;}
      else if (role == "shieldsman") {health = 150; strength = 20; getName = true;}
      else if (role == "ninja") {health = 100; strength = 25; getName = true;}
      else if (role == "mage") {health = 80; strength = 50; getName = true;}
      else if (role == "master") {health = 1; strength = 1000; getName = true;}
      else {getName = false;}
      }

      return 0;
    }
    
    void statusPlayer(){
      std::cout << name << " <"  << role << ">" << "\t health: " << health << "\t strength: " << strength;
      if (role == "mage") {std::cout << " shield: " << shield << '\n';}
      else {std::cout << '\n';}
    }
};


class MonsterInfo {
  private:
    std::string slimeN1 = "Wangui";
    std::string slimeN2 = "Nomusa";
    std::string slimeN3 = "Pua";
    std::string spiderN1 = "Vaso";
    std::string spiderN2 = "Toril";
    std::string spiderN3 = "Hulda";
    std::string orcN1 = "Chinweike";
    std::string orcN2 = "Nkechi";
    std::string orcN3 = "Olufunke";
    std::string ogreN1 = "Chioma";
    std::string ogreN2 = "Simisola";
    std::string ogreN3 = "Imamu";
    std::string dragonN1 = "Mahtab";
    std::string dragonN2 = "Mirembe";
    std::string dragonN3 = "Mandlenkosi";
    
  public:
    std::string mName;
    std::string mType;
    int mHealth;
    int mStrength;
    bool mLife = false;
    
    std::string mRandName(std::string type){
      int picker;
          
      if (type == "slime") {
        picker = std::rand() % 3 + 1;
        if (picker == 1) {return slimeN1;}
        else if (picker == 2) {return slimeN2;}
        else if (picker == 3) {return slimeN3;}
      }
      else if(type == "spider") {
        picker = std::rand() % 3 + 4;
        if (picker == 4) {return spiderN1;}
        else if (picker == 5) {return spiderN2;}
        else if (picker == 6) {return spiderN3;}
      }
      else if (type == "orc") {
        picker = std::rand() % 3 + 7;
        if (picker == 7) {return orcN1;}
        else if (picker == 8) {return orcN2;}
        else if (picker == 9) {return orcN3;}
      }
      else if (type == "ogre") { 
        picker = std::rand() % 3 + 10;
        if (picker == 10) {return ogreN1;}
        else if (picker == 11) {return ogreN2;}
        else if (picker == 12) {return ogreN3;}
      }
      else if (type == "dragon") {
        picker = std::rand() % 3 + 13;
        if (picker == 13) {return dragonN1;}
        else if (picker == 14) {return dragonN2;}
        else if (picker == 15) {return dragonN3;}
      }
      return "error";
    }  // function mRandName()
      
    void mStatus(std::string type){
      if (type == "slime") {mName = mRandName(type); mType = type; mHealth = 20; mStrength = 10;}
      else if (type == "spider") {mName = mRandName(type); mType = type; mHealth = 40; mStrength = 20;}
      else if (type == "orc") {mName = mRandName(type); mType = type; mHealth = 60; mStrength = 30;}
      else if (type == "ogre") {mName = mRandName(type); mType = type; mHealth = 100; mStrength = 40;}
      else if (type == "dragon") {mName = mRandName(type); mType = type; mHealth = 200; mStrength = 50;}
    }  // funcion mStatus
      
    void statusMonster(){
      std::cout << "-------------------------------------------------------" << '\n';
      std::cout << mName << " <" << mType << ">" << '\t';
      std::cout << "health: " << mHealth << '\n';
    }

    void encounterMonster(){
      std::cout << "-------------------------------------------------------" << '\n';
      std::cout << "you encountered "<< mName << " <" << mType << "> !" << '\n';
      std::cout << "health: " << mHealth << '\n';
    }      

    bool mDeathCheck(){
      if (mHealth < 1){
        return true;
      }
      return false;
    }

};  // class MonsterInfo


#endif // UNITNFO_H_
