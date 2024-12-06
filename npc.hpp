#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
public:
    NPC(const std::string& name, const std::string& dialogue, const std::string& quest = "");

    std::string interact() const;
    std::string getQuest() const;

private:
    std::string name;
    std::string dialogue;
    std::string quest;
};

#endif
