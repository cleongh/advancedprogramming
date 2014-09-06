#include "bot.h"

const int bot::X_OFFSET[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
const int bot::Y_OFFSET[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };

bot::bot(team_id team, const position & pos):_position(pos), _team(team),
_attack(BASE_ATTACK), _defense(BASE_DEFENSE), _experience(1), _energy(MAX_ENERGY), _kills(0), _next_direction(NOTHING)
{
}

bot::~bot()
{
}

void bot::kills_bot(const bot & victim) {
    _experience += victim.get_experience();
    _kills++;
    if(_kills % KILLS_FOR_ENERGY == 0) {
        _energy = MAX_ENERGY;
    }
    _attack = ATTACK_MULTIPLIER * _experience;
    _defense = DEFENSE_MULTIPLIER * _experience;
}

