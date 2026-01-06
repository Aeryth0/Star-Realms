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
    FACT_NONE,
    FACT_BLOB,
    FACT_STAR,
    FACT_MECH,
    FACT_FED,
};

extern const char* factNames[];

enum Conditions {
    COND_CHOICE = 1,
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
    int baseHealth;

    int conditions, condParams; std::string condDescription;
    int factConditions, factParams; std::string factDescription;
    int junkConditions, junkParams; std::string junkDescription;

    int faction;

    std::string name;
    std::string getname() const { return name; }
    std::string getdetails() const {
        // Name
        std::string ret = name + " (";
        // Faction
        ret += factNames[faction];
        // Type (base or ship)
        if (flags & FLAG_PATROL) ret += "patrol base with " + std::to_string(baseHealth) + " health)";
        else if (flags & FLAG_BASE) ret += "base with " + std::to_string(baseHealth) + " health)";
        else ret += "ship)";
        // Cost
        ret += "\n\t- Cost: " + std::to_string(cost) + " coins";
        // Coins
        if(coin)
            ret += "\n\t- +" + std::to_string(coin) + " coins";
        // Damage
        if(damage)
            ret += "\n\t- " + std::to_string(damage) + " damage";
        // Heal
        if (heal)
            ret += "\n\t- " + std::to_string(heal) + " heal";
        // Conditions
        if (conditions) ret += "\n\t- Condition: " + condDescription;
        if (factConditions) ret += "\n\t- Faction Condition: " + factDescription;
        if (junkConditions) ret += "\n\t- Junk Condition: " + junkDescription;
        return ret;
    }

    card2(std::string name, int cost, int damage, int coin, int heal, int flags, int conditions
        , int condParams, int factConditions, int factParams, int JunkConditions, int junkParams, int faction, int baseHealth = 0
        , std::string condDescription = "", std::string factDescription = "", std::string junkDescription = "")
        : name(name), cost(cost), damage(damage), coin(coin)
        , heal(heal), flags(flags), conditions(conditions), condParams(condParams), factConditions(factConditions)
        , factParams(factParams), junkConditions(junkConditions), junkParams(junkParams), faction(faction), baseHealth(baseHealth)
        , condDescription(condDescription), factDescription(factDescription), junkDescription(junkDescription) {};
};

#endif // !CARDS_HPP
