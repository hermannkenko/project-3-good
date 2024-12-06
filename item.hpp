#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
public:
    Item(const std::string& name, const std::string& description, int trait, int rarity, int durability);
    ~Item(); 

    std::string getName() const;
    int getTrait() const;
    std::string getDescription() const;
    void useItem(); 
    bool isBroken() const;

private:
    std::string name;
    std::string description;
    int trait;    
    int rarity;   
    int durability; 
};

#endif
