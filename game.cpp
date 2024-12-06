#include "game.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Game::Game(const std::string& playerName, const std::string& playerType)
    : player(playerName, playerType) {
    // Initialize some NPCs with quest hooks
    npcs.push_back(NPC("Guard", "Stay safe out there, traveler!", "Defeat 3 monsters."));
    npcs.push_back(NPC("Wizard", "Magic is a powerful tool, use it wisely.", "Collect a rare magical artifact."));
    
    // Initialize achievements
    achievements["Monster Slayer"] = false;
    achievements["Treasure Hunter"] = false;
    achievements["Level 5 Achieved"] = false;

    srand(static_cast<unsigned int>(time(0)));
}

void Game::start() {
    std::string command;
    while (player.isAlive()) {
        std::cout << "\nWhat would you like to do? (stats, combat, npc, quests, achievements, random, quit): ";
        std::cin >> command;

        if (command == "stats") {
            player.displayStats();
        } else if (command == "combat") {
            engageCombat();
        } else if (command == "npc") {
            int npcIndex;
            std::cout << "Enter NPC index to interact with (0-" << npcs.size() - 1 << "): ";
            std::cin >> npcIndex;

            try {
                if (npcIndex < 0 || npcIndex >= npcs.size()) {
                    throw std::out_of_range("Invalid NPC index!");
                }
                interactWithNPC(npcIndex);
            } catch (const std::out_of_range& e) {
                std::cout << e.what() << "\n";
            }
        } else if (command == "quests") {
            displayQuests();
        } else if (command == "achievements") {
            displayAchievements();
        } else if (command == "random") {
            randomEvent();
        } else if (command == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}

void Game::interactWithNPC(int npcIndex) {
    std::cout << "NPC says: " << npcs[npcIndex].interact() << "\n";
    std::string quest = npcs[npcIndex].getQuest();
    if (!quest.empty() && questLog.find(quest) == questLog.end()) {
        questLog[quest] = "Incomplete";
        std::cout << "New quest added: " << quest << "\n";
    }
}

void Game::engageCombat() {
    int monsterDamage = rand() % 20 + 5;
    std::cout << "You encounter a monster! It deals " << monsterDamage << " damage.\n";
    player.takeDamage(monsterDamage);

    if (player.isAlive()) {
        player.gainExperience(5);
        if (rand() % 100 < 50) { // 50% chance to drop an item
            Item* newItem = new Item("Potion", "Restores 10 health.", 10, 1, 1);
            player.equipItem(newItem);
            std::cout << "You found a " << newItem->getName() << "!\n";
        }

        // Update achievement
        achievements["Monster Slayer"] = true;
    }
}

void Game::displayAchievements() {
    std::cout << "Achievements:\n";
    for (const auto& [key, completed] : achievements) {
        std::cout << "- " << key << ": " << (completed ? "Completed" : "Incomplete") << "\n";
    }
}

void Game::displayQuests() {
    std::cout << "Quest Log:\n";
    for (const auto& [quest, status] : questLog) {
        std::cout << "- " << quest << ": " << status << "\n";
    }
}

void Game::completeQuest(const std::string& questName) {
    if (questLog.find(questName) != questLog.end()) {
        questLog[questName] = "Complete";
        std::cout << "Quest \"" << questName << "\" is now complete!\n";
    }
}

void Game::randomEvent() {
    int event = rand() % 3;
    switch (event) {
        case 0:
            std::cout << "A mysterious merchant offers you a rare item!\n";
            break;
        case 1:
            std::cout << "You stumble upon a treasure chest. Gain 10 gold!\n";
            break;
        case 2:
            std::cout << "You fall into a trap! Lose 10 health.\n";
            player.takeDamage(10);
            break;
        default:
            break;
    }
}
