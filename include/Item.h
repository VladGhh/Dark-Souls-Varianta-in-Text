#ifndef PROIECT_OOP_ITEM_H
#define PROIECT_OOP_ITEM_H
#include<iostream>
#include<string>
using namespace std;
class Player;
class Entity;

//clasa item
class Item {
protected:
    string name;
public:
    // FIX: const string&
    Item(const string& name);
    virtual ~Item();
    // FIX: return const string&
    const string& getName() const;
    virtual void use() const = 0;
    virtual void display() const = 0;
};

//clasa cheie
class KeyItem:public Item {
private:
   
    string description;
public:
    KeyItem(const string& name, const string& desc); 
    
    void use() const override;
    void display() const override;
};

//clasa arma
class Weapon: public Item {
protected:
    int damage;
public:
    Weapon(const string& name, int d);
    virtual int getDamage() const;
    void use() const override;
    void display() const override;
};

//clasa arma magica
class MagicWeapon: public Weapon {
private:
    int magicBonus;
public:
    MagicWeapon(const string& name, int d, int bonus);
    int getDamage() const override;
    void use() const override;
    void display() const override;
};

//clasa consumabile
class Consumable:public Item {
private:
    int power;
    bool isOffensive;
public:
    Consumable(const string& name, int power, bool offensive);
    int getPower() const;
    bool getIsOffensive() const;
    void use() const override;
    void display() const override;
};

#endif //PROIECT_OOP_ITEM_H