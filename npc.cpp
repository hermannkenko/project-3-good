#include "npc.hpp"

NPC::NPC(const std::string& name, const std::string& dialogue, const std::string& quest)
    : name(name), dialogue(dialogue), quest(quest) {}

std::string NPC::interact() const {
    return dialogue;
}

std::string NPC::getQuest() const {
    return quest;
}
