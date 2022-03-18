#pragma once
#include <vector>
#include <enet/enet.h>

#include "player.h"

namespace player {
    class PlayerPool {
    public:
        PlayerPool() = default;
        ~PlayerPool();

        Player *new_player(int server_id, ENetPeer* peer);
        void add_player(Player *player);
        void remove_player(Player *player);
        void remove_player(enet_uint32 connect_id);

        Player *get_player(enet_uint32 connect_id);
        std::vector<Player *> get_players();
        size_t get_player_count();

    private:
        std::vector<Player *> m_players;
    };
}
