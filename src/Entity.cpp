#include "Entity.h"
#include "Player.h"

int Boss::bossCount = 0;

//Entitate
Entity::Entity(const string& name) :name(name){}
Entity::~Entity(){}
const string& Entity::getName() const {return name;}

//Personaj
Character::Character(const string& name, int maxHp) :Entity(name),hp(maxHp),maxHp(maxHp){}
void Character::takeDamage(int dmg) {
    hp -= dmg;
    if (hp <= 0)
        hp = 0;
}
bool Character::isAlive() const {return hp > 0;}
int Character::getHp() const {return hp;}
Character&  Character::operator+=(int amount) {
    this->hp+=amount;
    if (this->hp>this->maxHp)
        this->hp=this->maxHp;
    return *this;

}

void Character::fullHeal() {
    hp = maxHp;
}

//inamic
Enemy::Enemy(const string& name, int maxHp, int dmg): Character(name,maxHp),baseDamage(dmg){}
void Enemy::attack(Character *target) {
    cout<<" "<<name<<" ataca dusmanos!\n";
    target->takeDamage(baseDamage);
}


void Enemy::respawn() {
    fullHeal();
}

//Boss
Boss::Boss(const string& name, int maxHp, int dmg, const string& ability) :Enemy(name,maxHp,dmg),specialAbility(ability){bossCount ++;}
int Boss::getCount() {return bossCount;}
void Boss::decreaseCount() { bossCount--; }

void Boss::attack(Character *target) {
    if (hp <= maxHp/2) {
        cout<<" [BOSS] "<<name<< " foloseste " <<specialAbility<<"!\n";
        target->takeDamage(baseDamage *1.5);
    }else {
        cout<<" [BOSS] "<<name<< " ataca normal !\n";
        target->takeDamage(baseDamage);
    }
}

//NPC
NPC::NPC(const string& name, const string& desc, const string& dialogue ,Item *gift)
    : Entity(name), description(desc), dialogue(dialogue), giftItem(gift), itemGiven(false) {}

NPC::~NPC(){if (giftItem) delete giftItem;}
void NPC::describe(){cout<<" [NPC] "<<description<<"\n";}
void NPC::interact(Player *p) {
    cout << "   [" << name << "]: \"..." << dialogue << "\"\n";
    if (giftItem && !itemGiven) {
        std::cout << "   [" << name << "] iti ofera un cadou: " << giftItem->getName() << ".\n";
        p->addItem(giftItem);
        itemGiven = true;
        giftItem = nullptr;
    }
}