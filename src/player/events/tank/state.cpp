#include "state.h"
#include "../../../server/serverpool.h"

namespace events {
    state::state(player::Player *player) {
        player->load("gup_" + std::to_string(player::PACKET_STATE), [player](player::GameUpdatePacket *game_update_packet) {
            if (player->m_current_world == "EXIT") {
                return;
            }

            auto *server = server::get_server_pool()->get_server(player->get_server_id());
            if (!server) {
                return;
            }

            auto *world_pool = server->get_world_pool();
            if (!world_pool) {
                return;
            }

            auto *world = world_pool->get_world(player->m_current_world);
            if (!world) {
                return;
            }

            player->m_pos.x = static_cast<int>(game_update_packet->pos_x);
            player->m_pos.y = static_cast<int>(game_update_packet->pos_y);

            game_update_packet->net_id = player->m_net_id;
            world->send_to_all([game_update_packet](player::Player *other_player) {
                other_player->send_raw_packet(player::NET_MESSAGE_GAME_PACKET, game_update_packet);
            });
        });
    }
}