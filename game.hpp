#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "npc.hpp"
#include <vector>
#include <map>
#include <string>

class Game {
public:
    Game(const std::string& playerName, const std::string& playerType);
    void start();

private:
    Player player;
    std::vector<NPC> npcs;
    std::map<std::string, bool> achievements; 
    std::map<std::string, std::string> questLog; 

    void interactWithNPC(int npcIndex);
    void engageCombat();
    void displayAchievements();
    void displayQuests();
    void completeQuest(const std::string& questName);
    void randomEvent(); 
};

#endif
