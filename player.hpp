#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>
#include "item.hpp"

class Player {
public:
    Player(const std::string& name, const std::string& type);
    ~Player();

    void displayStats() const;
    void equipItem(Item* item);
    void takeDamage(int damage);
    void gainExperience(int xp);
    void assignSkillPoint(const std::string& skill);
    void useEquippedItem();
    bool isAlive() const;

private:
    std::string name;
    std::string type;
    int health;
    int magic;
    int strength;
    int level;
    int experience;
    int skillPoints;

    Item* equippedItem;
    std::map<std::string, int> skills; // Skill tree
};

#endif
