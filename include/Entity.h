#ifndef PROIECT_OOP_ENTITY_H
#define PROIECT_OOP_ENTITY_H
#include<string>
#include<vector>
#include<iostream>
#include "Item.h"
using namespace std;
class Player;

class Entity {
protected:
    string name;
public:
    explicit Entity(const string& name);
    virtual ~Entity();
    const string& getName() const;
};

class Character:public Entity {
protected:
    int hp,maxHp;
public:
    Character(const string& name, int maxHp);
    
    
    ~Character() override = default;

    virtual void takeDamage(int dmg);
    bool isAlive() const;
    int getHp() const;
   // void heal(int amount);
    Character& operator+=(int amount);
    void fullHeal();
    virtual void attack(Character* target)=0;
};

class Enemy:public Character {
protected:
    int baseDamage;
public:
    Enemy(const string& name, int maxHp, int dmg);
    void attack(Character* target) override;
    void respawn();
};

class Boss:public Enemy {
private:
    static int bossCount;
    string specialAbility;
public:
    Boss(const string& name, int maxHp, int dmg, const string& ability);
    void attack(Character* target) override;
    static int getCount();
    static void decreaseCount();
};

class NPC:public Entity {
private:
    string description;
    string dialogue;
    Item* giftItem;
    bool itemGiven;
public:
    NPC(const string& name, const string& desc, const string& dialogue, Item* gift=nullptr);
    
   
    ~NPC() override;
    
    void describe();
    void interact(Player* p);
};

#endif //PROIECT_OOP_ENTITY_H