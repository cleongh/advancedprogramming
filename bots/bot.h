#ifndef _BOT_H_INCLUDED_
#define _BOT_H_INCLUDED_

#include <vector>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/utility.hpp>

class bots;

/**
 * bot
 * ===
 *
 * this file includes the class and relative data for a single bot. it is meant
 * to be used with the <code>bots</code> class.
 *
 * Non-const methods are private and container class is declared as a friend.
 * This enforces a very strict encapsulation pattern.
 */
class bot
{
    public:

        static const int X_OFFSET[];
        static const int Y_OFFSET[];

        // this should be read from a config file... any volunteers?
        // what about a quake-like console? there are some libraries for that!
        static const int MAX_ENERGY = 10;
        static const int BASE_ATTACK = 2;
        static const int BASE_DEFENSE = 1;
        static const int KILLS_FOR_ENERGY = 3;
        static const int ATTACK_MULTIPLIER = 3;
        static const int DEFENSE_MULTIPLIER = 2;

        typedef unsigned short status;

        typedef unsigned int team_id ;

        typedef unsigned int field_size ;

        enum direction { NOTHING, N, NE, E, SE, S, SW, W, NW };

        typedef std::pair<field_size, field_size> position ;

        bot (team_id id, const position & pos);

        bot() = default;

        bot(const bot &b) = default;

        /**
         * use this static method to compute the next hypothetical position
         */
        static position new_position(const position &pos, const direction& dir) {
            return {pos.first + X_OFFSET[dir], pos.second + Y_OFFSET[dir]};
        }

        virtual ~bot ();

        status get_energy() const {
            return _energy;
        }

        inline status get_attack() const {
            return _attack;
        };

        inline status get_defense() const {
            return _defense;
        };

        inline team_id get_team() const {
            return _team;
        }

        inline status get_experience() const {
            return _experience;
        }

        inline const position & get_position() const {
            return _position;
        }

        inline field_size get_x() const {
            return get_position().first;
        }

        inline field_size get_y() const {
            return get_position().second;
        }

        inline const direction & get_next_direction() const {
            return _next_direction;
        }

        inline status get_kills() const {
            return _kills;
        }

        inline bool operator==(const bot & other) const {
            return get_position() == other.get_position();
        }

        inline bool operator!=(const bot & other) const {
            return !(*this == other);
        }

        /**
         * use this method to "move" the bots.
         *
         * moves aren't guaranteed. the bot will try to move towards the
         * desired direction and it either can move, attack or do noting depending on
         * the field.
         *
         * @param dir the direction you want the bot to move to or attack
         */
        inline void try_to_do(const direction & dir) {
            _next_direction = dir;
        }

    private:

        friend class bots;

        status _attack;
        status _defense;
        status _kills;
        status _experience;
        status _energy;
        team_id _team;
        position _position;
        direction _next_direction;

        /**
         * called by <code>bot</code> when a bot kills
         *
         * @param victim the bot that has just died
         */
        void kills_bot(const bot & victim);

    private:

        friend class boost::serialization::access; 

        template <typename Archive> 
            void serialize(Archive &ar, const unsigned int version) 
            { 

                ar & _attack;
                ar & _defense;
                ar & _kills;
                ar & _experience;
                ar & _energy;
                ar & _team;
                ar & _position;
                ar & _next_direction;
            } 

};


#endif
