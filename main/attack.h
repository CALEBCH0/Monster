#ifndef ATTACK_H_
#define ATTACK_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "unitInfo.h"

class Attack{
  private:
    bool mHit = true;
    int mHitPercent = 100;

  public:
    void monsterHitPercent(){
      int randomHit = std::rand() % 100 + 1;
      if (randomHit <= mHitPercent) {mHit = true;}
      else if (randomHit >= mHitPercent) {mHit = false;}
    }

    void magicShield(MonsterInfo &mon, Player &pla){
      /*
      int shieldDamage = shield - mon.mStrength;
      if (shieldDamage < 0) {shieldDamage*-1;}
      std::cout << "you were attacked!  ";
      if (shieldDamage > 0) {shieldDamage * -1; std::cout << "-" << mon.mStrength;}
      shieldDamage = 0;
      std::cout << shieldDamage << '\n';
      if (shieldDamage > 0){
      return pla.health -= shieldDamage;}
      return pla.health -= mon.mStrength;
      shield = 0;
      */
      if (pla.shield < 0) {pla.shield = 0;}
      int shieldDamage = pla.shield - mon.mStrength;
      std::cout << "you were attacked!  ";
      if (shieldDamage < 1) {pla.health += shieldDamage; std::cout << shieldDamage << '\n';}
      else {pla.shield = shieldDamage; shieldDamage = 0; std::cout << shieldDamage << '\n';}
    }

    void cntrattack(MonsterInfo &mon, Player &pla){
      std::cout << pla.shield << '\n';
      monsterHitPercent();
      if (mon.mHealth > 0 && mHit == true){
        magicShield(mon, pla);
        //std::cout << "you were attacked!  " << "-" << mon.mStrength << '\n';
      }
      else if (mon.mHealth < 1) {std::cout << '\n';}
      else {std::cout << "nothing happened... \n";}
      mHit = true;
      mHitPercent = 100;
    }  // void cntrattack

/* moving
    void cntrattack(MonsterInfo &mon, Player &pla){
      if (mon.mHealth > 0 || mHit == true){
        pla.health = pla.health + shield - mon.mStrength;
        shield -= mon.mStrength;
        pla.health -= shield;
        if (shield <= 0) {shield = 0;}
        mHit = true;
        std::cout << "you were attacked!  " << "-" << mon.mStrength << '\n';
      }
    }  // void cntrattack
*/
    void attack(MonsterInfo &mon, Player &pla){
      std::string attack;
      bool deal;
      std::cout << "would you attack? yes/no\n";
      std::getline(std::cin, attack);

      if (attack == "yes" || attack == "y"){
        deal = true;
      }

      else {deal = false;}

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

      else {deal = false;}

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
      bool attackTurn = true;
      std::string spell;

      std::cout << "would you attack? yes/no \t |";
      std::getline(std::cin, attack);

      if (attack == "yes" || attack == "y"){
        deal = true;
      }

      else {deal = false;}

      if (deal == true){
        attackTurn = true;
        std::cout << "1: fireball | 2: blind (" << pla.blindLimit << "/3)" << "| 3: sleep (" << pla.sleepLimit << "/2)" << "| 4: protect (" << pla.protectLimit << "/4)";

        while (attackTurn == true){
          std::cout << "\n\t\t |";
          std::getline(std::cin, spell); 
          std::cout << '\n';
        
          if (spell == "1") {
            std::cout << "fireball! -"  << pla.strength * 0.7 << '\n';
            mon.mHealth -= pla.strength * 0.7;
            attackTurn = false;
          }
          else if (spell == "2" && pla.blindLimit >= 1){
            std::cout << "blind! \n" << pla.strength * 0.3 << '\n'; mon.mHealth -= pla.strength * 0.3; 
            mHitPercent = 50; 
            pla.blindLimit -= 1;
            attackTurn = false;
          }
          else if (spell == "3" && pla.sleepLimit >= 1){
            std::cout << "sleep! \n"; 
            mHit = false; 
            pla.sleepLimit--;
            attackTurn = false;
          }
          else if (spell == "4" && pla.protectLimit >= 1){
            std::cout << "magic shield! \n"; 
            pla.shield += pla.strength * 0.8; 
            pla.protectLimit--;
            attackTurn = false;
          }
          else {std::cout << "exceeded limit \n";}
        }

        if (mon.mHealth <= 0){
          std::cout << "you win! \n";
          pla.strength += 4;
          pla.health += 10;
        }
        cntrattack(mon, pla);
      }
      else if (deal == false){
        std::cout << "nothing happened... \n";
        cntrattack(mon, pla);
      }
    }  // function mageAttack
};

#endif  // ATTACK_H_