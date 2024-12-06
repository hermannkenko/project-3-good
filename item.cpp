#include "item.hpp"

Item::Item(const std::string& name, const std::string& description, int trait, int rarity, int durability)
    : name(name), description(description), trait(trait), rarity(rarity), durability(durability) {}

Item::~Item() {
    if (durability == 0) {
        std::cout << "The item \"" << name << "\" has been broken and discarded.\n";
    }
}

std::string Item::getName() const { return name; }
int Item::getTrait() const { return trait; }
std::string Item::getDescription() const { return description; }

void Item::useItem() {
    if (durability > 0) {
        durability--;
    }
    if (durability == 0) {
        std::cout << "The item \"" << name << "\" is now broken.\n";
    }
}

bool Item::isBroken() const { return durability == 0; }
