#ifndef _BOTCLIENT_H_INCLUDED_
#define _BOTCLIENT_H_INCLUDED_

#include "bots.h"

/**
 * class for ia
 */
class bot_client
{
public:

    /**
     * @param bots a reference to an instance of bots
     */
    bot_client (bots & bots) : _bots(bots) // in this way I can have a reference as a class attribute
    {
        // this wouldn't work
        // _bots = bots;
        _team = -1; // this unreliably avoids problems when _team hasn't been initialized
    };

    virtual ~bot_client () {};

    /**
     * computes next moves for bots
     *
     * @param depth the max level for classic backtracking
     */
    void perform(int depth);

    inline void set_team(bot::team_id team) {
        _team = team;
    }

private:
    bots & _bots;
    bot::team_id _team;
};

#endif
