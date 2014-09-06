#include "botclient.h"
#include "bot.h"
#include <iostream>
#include <limits>

struct node {

    const bot::position & _position;
    const bots & _bots;
    bot::direction _best;
    int _depth;

    /**
     * creates a new search node
     *
     * @param my_pos must belong to current_bots
     * @param current_bots
     * @param depth
     * @param best
     */
    node(const bot::position& my_pos, const bots & current_bots, int depth = 0, bot::direction best = bot::NOTHING) 
        : _position(my_pos), _bots(current_bots), _best(best), _depth(depth) {
        }

    float simple_backtrack(unsigned int max_depth) {
        if(_depth < max_depth) {
            // ugliest hack ever. for-looping over an enum
            int new_depth = _depth + 1;

            float best_heuristic = std::numeric_limits<float>::lowest();

            for(int i = 0; i < 9; i++) {
                bot::direction new_dir = static_cast<bot::direction>(i);

                const bot & temp_bot = _bots[_position];
                if(_bots.can_move(temp_bot, new_dir) || _bots.attacks(temp_bot, new_dir)) {
                    bots new_bots = bots(_bots);
                    new_bots[_position].try_to_do(new_dir);
                    new_bots.step();
                    node new_node(_position, new_bots, new_depth, _best);
                    
                    float new_heuristic = new_node.simple_backtrack(new_depth);

                    if(new_heuristic > best_heuristic) {
                        best_heuristic = new_heuristic;
                        _best = new_dir;
                    }
                }
            }
            return best_heuristic;
        }
        else {
            auto m = _bots.bot_count();
            bot::team_id team = _bots[_position].get_team();
            int res = 0;
            for(auto kv : m) {
                if(team != kv.first) {
                    res += kv.second;
                }

            }
            return (m[team] * 0.5) - (res * 0.3);
        }
    }
};


void bot_client::perform(int depth) {
    // TODO replace with 'for_each_of_my_bots' or sthg like that
    _bots.for_each_bot([this, &depth] (bot & my_bot) {
        if(my_bot.get_team() == _team) {
            node my_node(my_bot.get_position(), _bots);
            my_node.simple_backtrack(depth);
            my_bot.try_to_do(my_node._best);
        }
    });
}

