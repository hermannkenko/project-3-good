#include "player.hpp"

Player::Player(const std::string& name, const std::string& type)
    : name(name), type(type), health(100), level(1), experience(0), skillPoints(0), equippedItem(nullptr) {
    if (type == "Wizard") {
        magic = 15;
        strength = 5;
    } else if (type == "Knight") {
        magic = 5;
        strength = 15;
    } else {
        magic = 10;
        strength = 10;
    }

    // Initialize skills
    skills["Fireball"] = 0;
    skills["Sword Mastery"] = 0;
    skills["Healing"] = 0;
}

Player::~Player() {
    if (equippedItem != nullptr) {
        delete equippedItem;
    }
}

void Player::displayStats() const {
    std::cout << "Player Stats:\n";
    std::cout << "Name: " << name << "\nType: " << type << "\nHealth: " << health << "\n";
    std::cout << "Magic: " << magic << "\nStrength: " << strength << "\nLevel: " << level << "\n";
    std::cout << "Experience: " << experience << "\nSkill Points: " << skillPoints << "\n";
}

void Player::equipItem(Item* item) {
    equippedItem = item;
    std::cout << "Equipped: " << equippedItem->getName() << "\n";
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
        std::cout << "Your health dropped to zero. You died. Game over!\n";
        exit(0);
    }
}

void Player::gainExperience(int xp) {
    experience += xp;
    if (experience >= level * 10) {
        experience = 0;
        level++;
        skillPoints++;
        std::cout << "Level up! You are now level " << level << " and earned 1 skill point!\n";
    }
}

void Player::assignSkillPoint(const std::string& skill) {
    if (skills.find(skill) != skills.end() && skillPoints > 0) {
        skills[skill]++;
        skillPoints--;
        std::cout << "Assigned a skill point to " << skill << ". Current level: " << skills[skill] << "\n";
    } else {
        std::cout << "Invalid skill or no skill points available.\n";
    }
}

void Player::useEquippedItem() {
    if (equippedItem != nullptr) {
        equippedItem->useItem();
        if (equippedItem->isBroken()) {
            delete equippedItem;
            equippedItem = nullptr;
        }
    } else {
        std::cout << "No item equipped.\n";
    }
}

bool Player::isAlive() const {
    return health > 0;
}
