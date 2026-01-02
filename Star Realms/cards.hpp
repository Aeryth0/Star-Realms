#ifndef CARDS_HPP
#define CARDS_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>

enum Flags {
    FLAG_BASE = 1 << 0,
    FLAG_PATROL = 1 << 1,
    FLAG_GLOBAL = 1 << 2,
};

enum Factions {
    FACT_BLOB,
    FACT_STAR,
    FACT_MECH,
    FACT_FED,
};

enum Conditions {
    COND_CHOICE,
    COND_DRAW1,
    COND_DRAW2,
    COND_DRAW1_AND_DESTROYBASE,
    COND_DISCARD1,
    COND_JUNKOWN1,
    COND_JUNKMARKET,
    COND_JUNKMARKETASK,
    COND_DESTROYBASE,
    COND_DESTROYBASEORJUNKMARKET,
    COND_DISCARD02,
    COND_TOPDECK,
    COND_JUNK02,
    COND_DRAW2CARDSIF2BASES,
    COND_FREECARD,
    COND_FREECARD_AND_TOPDECK,
    COND_ADDHEALTH,
    COND_ADDMONEY,
    COND_ADDDAMAGE,
    COND_DAMAGEPERSHIP,
    COND_DRAWANDJUNK,
    COND_DRAWPERBLOB
};

struct card2 {
    int cost;
    int damage;
    int coin;
    int heal;
    int flags;

    int conditions, condParams;
    int factConditions, factParams;
    int junkConditions, junkParams;

    int faction;

    std::string name;
    std::string getname() const { return name; }

    card2(std::string name, int cost, int damage, int coin, int heal, int flags, int conditions
        , int condParams, int factConditions, int factParams, int JunkConditions, int junkParams, int faction) 
        : name(name), cost(cost), damage(damage), coin(coin)
        , heal(heal), flags(flags), conditions(conditions), condParams(condParams), factConditions(factConditions) 
        , factParams(factParams), junkConditions(junkConditions), junkParams(junkParams), faction(faction) {};
};

//class card {
//private:
//
//public:
//    virtual ~card() = default;
//    virtual void play() const {};
//    virtual std::string getname() const { return name; }
//
//    int cost;
//    std::string name;
//    int coin;
//    int damage;
//
//    card(std::string n, int c) : name(n), cost(c) {}
//
//};
//class StartingMoneyCard :public card {
//public:
//    int cardmoney;
//    StartingMoneyCard(std::string n,int c,int cm)
//        :card(n,c), cardmoney(cm){ }
//    
//
//};
//class StartingDamageCard :public card {
//public:
//    int damage;
//    StartingDamageCard(std::string n,int c, int d)
//        :card(n, c), damage(d){}
//};
//class BaseCard : public card {
//public:
//    int damage;
//    int cardmoney;
//    int heal;
//    BaseCard(std::string n, int c, int d, int cm, int h)
//        :card(n,c), damage(d), cardmoney(cm), heal(h){ }
//     
//};
//class DamageCard : public card {
//public:
//    int damage;
//    DamageCard(std::string n, int c, int d)
//        :card(n, c), damage(d) {
//    }
//};
//class MoneyCard :public card {
//public:
//    int cardmoney;
//    MoneyCard(std::string n, int c, int cm)
//        :card(n, c), cardmoney(cm) {}
//};
//class HealingCard :public card {
//public:
//    int heal;
//    HealingCard(std::string n, int c, int h)
//        :card(n,c), heal(h) {}
//};
//class HybridCard :public card {
//public:
//    int damage;
//    int cardmoney;
//    int heal;
//    HybridCard(std::string n, int c, int cm, int d, int h)
//        :card(n, c), damage(d), cardmoney(cm), heal(h) {
//    }
//};
////blob cards
//class BlobBaseCard :public BaseCard {
//public:
//    int blob;
//    BlobBaseCard(std::string n, int c, int cd, int cm, int h, int b)
//        :BaseCard(n,c,cd,cm,h), blob(b) { }
//    void play() const override {
//    }
//};
//class BlobDamageCard :public DamageCard {
//public:
//    int blob;
//    BlobDamageCard(std::string n, int c, int d, int b)
//        :DamageCard(n, c, d), blob(b) { }
//};
//class BlobMoneyCard :public MoneyCard {
//public:
//    int blob;
//    BlobMoneyCard(std::string n, int c, int m, int b)
//        :MoneyCard(n, c, m), blob(b) { }
//};
//class BlobHealingCard :public HealingCard {
//public:
//    int blob;
//    BlobHealingCard(std::string n, int c, int h,int b)
//        :HealingCard(n,c,h), blob(b) { }
//};
//class BlobHybridCard :public HybridCard {
//public:
//    int blob;
//    BlobHybridCard(std::string n, int c, int cm, int d,int h, int b)
//        :HybridCard(n, c, cm, d, h), blob(b) {}
//
//};
////star cards
//class StarBaseCard :public BaseCard {
//public:
//    int star;
//    StarBaseCard(std::string n, int c, int cd, int cm, int h, int s)
//        :BaseCard(n, c, cd, cm, h), star(s) {
//    }
//};
//class StarDamageCard :public DamageCard {
//public:
//    int star;
//    StarDamageCard(std::string n, int c, int d, int s)
//        :DamageCard(n, c, d), star(s) {
//    }
//};
//class StarMoneyCard :public MoneyCard {
//public:
//    int star;
//    StarMoneyCard(std::string n, int c, int m, int s)
//        :MoneyCard(n, c, m), star(s) {
//    }
//};
//class StarHealingCard :public HealingCard {
//public:
//    int star;
//    StarHealingCard(std::string n, int c, int h, int s)
//        :HealingCard(n, c, h), star(s) {
//    }
//};
//class StarHybridCard :public HybridCard {
//public:
//    int star;
//    StarHybridCard(std::string n, int c, int cm, int d, int h, int s)
//        :HybridCard(n, c, cm, d, h), star(s) {
//    }
//
//};
////fed cards
//class FedBaseCard:public BaseCard{
//public:
//    int fed;
//    FedBaseCard(std::string n, int c, int cd, int cm, int h, int f)
//        :BaseCard(n, c, cd, cm, h), fed(f) {
//    }
//};
//class FedDamageCard :public DamageCard {
//public:
//    int fed;
//    FedDamageCard(std::string n, int c, int d, int f)
//        :DamageCard(n, c, d), fed(f) {
//    }
//};
//class FedMoneyCard :public MoneyCard {
//public:
//    int fed;
//    FedMoneyCard(std::string n, int c, int m, int f)
//        :MoneyCard(n, c, m), fed(f) {
//    }
//};
//class FedHealingCard :public HealingCard {
//public:
//    int fed;
//    FedHealingCard(std::string n, int c, int h, int f)
//        :HealingCard(n, c, h), fed(f) {
//    }
//};
//class FedHybridCard :public HybridCard {
//public:
//    int fed;
//    FedHybridCard(std::string n, int c, int cm, int d, int h, int f)
//        :HybridCard(n, c, cm, d, h), fed(f) {
//    }
//
//};
////cult cards
//class MechCultBaseCard :public BaseCard {
//public:
//    int mechcult;
//    MechCultBaseCard(std::string n, int c, int cd, int cm, int h, int mc)
//        :BaseCard(n, c, cd, cm, h), mechcult(mc) {
//    }
//};
//class MechCultDamageCard :public DamageCard {
//public:
//    int mechcult;
//    MechCultDamageCard(std::string n, int c, int d, int mc)
//        :DamageCard(n, c, d), mechcult(mc) {
//    }
//};
//class MechCultMoneyCard :public MoneyCard {
//public:
//    int mechcult;
//    MechCultMoneyCard(std::string n, int c, int m, int mc)
//        :MoneyCard(n, c, m), mechcult(mc) {
//    }
//};
//class MechCultHealingCard :public HealingCard {
//public:
//    int mechcult;
//    MechCultHealingCard(std::string n, int c, int h, int mc)
//        :HealingCard(n, c, h), mechcult(mc) {
//    }
//};
//class MechCultHybridCard :public HybridCard {
//public:
//    int mechcult;
//    MechCultHybridCard(std::string n, int c, int cm, int d, int h, int mc)
//        :HybridCard(n, c, cm, d, h), mechcult(mc) {
//    }
//};
#endif // !CARDS_HPP
