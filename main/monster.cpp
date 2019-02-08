#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "monsterPrint.h"
#include "elementInfo.h"

void statusMonster(MonsterInfo &mon){
  std::cout << "-------------------------------------------------------" << '\n';
  std::cout << mon.mName << " <" << mon.mType << ">" << '\t';
  std::cout << "health: " << mon.mHealth << '\n';
}

void encounterMonster(MonsterInfo &mon){
  std::cout << "-------------------------------------------------------" << '\n';
  std::cout << "you encountered "<< mon.mName << " <" << mon.mType << "> !" << '\n';
  std::cout << "health: " << mon.mHealth << '\n';
}
/*
void action(){
    std::string action;
    std::cout << "attack / heal" << '\n';
    std::getline(std::cin, action);
    if (action == "heal" || action == "y")
}
*/

void cntrattack(MonsterInfo &mon, Player &pla){
  if (mon.mHealth > 0){
    pla.health -= mon.mStrength;
    std::cout << "you were attacked!  " << "-" << mon.mStrength << '\n';
  }
}  // void cntrattack

void attack(MonsterInfo &mon, Player &pla){
  std::string attack;
  bool deal;
  std::cout << "would you attack? yes/no\n";
  std::getline(std::cin, attack);

  if (attack == "yes" || attack == "y"){
    deal = true;
  }

  else if (attack == "no" || attack == "n"){
    deal = false;
  }

  if (deal == true){
    std::cout << "you attacked!   " << "-" << pla.strength << '\n';
    mon.mHealth -= pla.strength;
    cntrattack(mon, pla);

    if (mon.mHealth <= 0){
      std::cout << "you win! \n";
      pla.strength += 4;
      pla.health += 5;
      if (pla.role == "shieldsman"){pla.health += 20;}
      else if (pla.role == "warrior"){pla.strength += 5;}
    }
  }
  else if (deal == false){
    std::cout << "nothing happened... \n";
    cntrattack(mon, pla);
  }
}  // void attack()

void ninjaAttack(MonsterInfo &mon, Player &pla){
  std::string attack;
  bool deal;
  std::cout << "would you attack? yes/no \t |";
  std::getline(std::cin, attack);

  if (attack == "yes" || attack == "y"){
    deal = true;
  }

  else if (attack == "no" || attack == "n"){
    deal = false;
  }

  if (deal == true){
    std::cout << "you attacked!   " << "-" << pla.strength << '\n';
    mon.mHealth -= pla.strength;

    if (mon.mHealth <= 0){
      std::cout << "you win! \n";
      pla.strength += 4;
      pla.health += 15;
    }
    cntrattack(mon, pla);
  }
  else if (deal == false){
    std::cout << "concentrating... \n";
    int dodge = std::rand() % 10 + 1;
    if (dodge == 1 || dodge == 2 || dodge == 3 || dodge == 4 || dodge == 5) {
        std::cout << "you dodged attack! you counterattacked! \n";
        mon.mHealth -= pla.strength*2;
        std::cout << "-" << pla.strength*2 << std::endl;
    }
    else {std::cout << "failed to dodge..." << std::endl; cntrattack(mon, pla);}
  } 
}  // function ninjaAttack

void mageAttack(MonsterInfo &mon, Player &pla){
  std::string attack;
  bool deal;
  std::string spell;
  std::cout << "would you attack? yes/no \t |";
  std::getline(std::cin, attack);

  if (attack == "yes" || attack == "y"){
    deal = true;
  }

  else if (attack == "no" || attack == "n"){
    deal = false;
  }

  if (deal == true){
    std::cout << "fireball/blind/sleep/protect" << '\n';
    std::getline(std::cin, spell); 
    if (spell == "fire")

    if (mon.mHealth <= 0){
      std::cout << "you win! \n";
      pla.strength += 4;
      pla.health += 15;
    }
    cntrattack(mon, pla);
  }
  else if (deal == false){
    std::cout << "concentrating... \n";
    int dodge = std::rand() % 10 + 1;
    if (dodge == 1 || dodge == 2 || dodge == 3 || dodge == 4 || dodge == 5) {
        std::cout << "you dodged attack! you counterattacked! \n";
        mon.mHealth -= pla.strength*2;
        std::cout << "-" << pla.strength*2 << std::endl;
    }
    else {std::cout << "failed to dodge..." << std::endl; cntrattack(mon, pla);}
  } 
}  // function mageAttack

void heal(Player &pla, int &healTime){
  std::string action;
  std::cout << "heal? (" << healTime << "/4) \t |";
  std::getline(std::cin, action);
  if (action == "heal" || action == "yes" || action == "y" && healTime > 0){
    pla.health += 30;   
    std::cout << "\n +30" << '\n';
    healTime --;
  } 
  else {std::cout << "no heal \n";}  
}

int main(){
  Player pla;
  MonsterInfo mon;
  std::string name_ = pla.name;
  int *health_ = &pla.health;
  pla.getPlayer();
  pla.statusPlayer();
  std::srand(std::time(nullptr));
  int healTime = 4;
  
  if (pla.deathCheck() == false) {
        
    for (int mOrder = 0; mOrder <= 5; ++mOrder){
      int choose = rand() % 4 + 1;
      switch(choose){
        case 1:
          {
            if (pla.deathCheck() == true){break;}
             mon.mStatus("slime");
             std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
             std::cout << " you encountered an enemy!! " << std::endl;
             std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
             while (mon.mHealth > 0){
                if (pla.deathCheck() == true){break;}
                if (pla.role == "shieldsman"){health_ += 10;}
                pla.deathCheck();
                printSlime();
                statusMonster(mon);
                pla.statusPlayer();
                heal(pla, healTime);
                if (pla.role == "ninja") {ninjaAttack(mon, pla);}
                else {attack(mon, pla);}
            }
            break;
          }

        case 2:
          {
            if (pla.deathCheck() == true){break;}
            mon.mStatus("spider");
            std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
            std::cout << " you encountered an enemy!! " << std::endl;
            std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
            while (mon.mHealth > 0){
              if (pla.deathCheck() == true){break;}
              if (pla.role == "shieldsman"){health_ += 10;}
              pla.deathCheck();
              printSpider();
              statusMonster(mon);
              pla.statusPlayer();
              heal(pla, healTime);
              if (pla.role == "ninja") {ninjaAttack(mon, pla);}
              else {attack(mon, pla);}
            }
            break;
          }

        case 3:
          {
            if (pla.deathCheck() == true){break;}
            mon.mStatus("orc");
            std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
            std::cout << " you encountered an enemy!! " << std::endl;
            std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
            while (mon.mHealth > 0){
              if (pla.deathCheck() == true){break;}
              if (pla.role == "shieldsman"){health_ += 10;}
              pla.deathCheck();
              printOrc();
              statusMonster(mon);
              pla.statusPlayer();
              heal(pla, healTime);
              if (pla.role == "ninja") {ninjaAttack(mon, pla);}
              else {attack(mon, pla);}
            }
            break;
          }

        case 4:
          {
            if (pla.deathCheck() == true){break;}
            mon.mStatus("ogre");
            std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
            std::cout << " you encountered an enemy!! " << std::endl;
            std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
            while (mon.mHealth > 0){
              if (pla.deathCheck() == true){break;}
              if (pla.role == "shieldsman"){health_ += 10;}
              pla.deathCheck();
              printOgre();
              statusMonster(mon);
              pla.statusPlayer();
              heal(pla, healTime);
              if (pla.role == "ninja") {ninjaAttack(mon, pla);}
              else {attack(mon, pla);}
            }
            break;
          }
      }  // switch
    }  // for loop
      
    if (pla.deathCheck() == false){
      mon.mStatus("dragon");
      std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
      std::cout << " you encountered the boss!! " << std::endl;
      std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
      while (mon.mHealth > 0){
        if (pla.deathCheck() == true){break; }
        if (pla.role == "shieldsman"){health_ += 10;}
        pla.deathCheck();
        printDragon();
        statusMonster(mon);
        pla.statusPlayer();
        if (pla.role == "ninja") {ninjaAttack(mon, pla);}
        else {attack(mon, pla);}
      }
    }
  }  // if die
  if (pla.deathCheck() == true) {
    std::cout << "-------------------------------------------------------" << '\n';
    std::cout << "you're dead!...... \n";
  }
  return 0;
}