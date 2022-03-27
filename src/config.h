#pragma once
#include <thread>
#include <string>

namespace config {
    constexpr auto dev = true;
    constexpr auto production = 1; // 1 - For using single server, 2 - For using multiple servers with libuv. (The stdout and stderr will be redirected to the log file)
    constexpr auto debug = true;

    namespace server {
        constexpr std::string_view host = "127.0.0.1";
        constexpr auto start_port = 17000;
        constexpr auto max_peer = 64;
    }

    namespace database {
        constexpr std::string_view host = "127.0.0.1";
        constexpr auto port = 3306;
        constexpr std::string_view user = "root";
        constexpr std::string_view password = "";
        constexpr std::string_view database = "gtps";
        constexpr auto auto_reconnect = true;
        constexpr auto debug = false;
    }

    namespace cdn {
        constexpr std::string_view host = "ubistatic-a.akamaihd.net";
        constexpr std::string_view cache = "0098/81283/cache/";
    }

    namespace on_super_main {
        constexpr auto param2 = cdn::host;
        constexpr auto param3 = cdn::cache;
        constexpr std::string_view param4 = "cc.cz.madkite.freedom org.aqua.gg idv.aqua.bulldog com.cih.gamecih2 com.cih.gamecih com.cih.game_cih cn.maocai.gamekiller com.gmd.speedtime org.dax.attack com.x0.strai.frep com.x0.strai.free org.cheatengine.cegui org.sbtools.gamehack com.skgames.traffikrider org.sbtoods.gamehaca com.skype.ralder org.cheatengine.cegui.xx.multi1458919170111 com.prohiro.macro me.autotouch.autotouch com.cygery.repetitouch.free com.cygery.repetitouch.pro com.proziro.zacro com.slash.gamebuster";
        constexpr std::string_view param5 = "proto=159|choosemusic=audio/mp3/about_theme.mp3|active_holiday=2|wing_week_day=0|ubi_week_day=0|server_tick=83430103|clash_active=1|drop_lavacheck_faster=1|isPayingUser=0|usingStoreNavigation=1|enableInventoryTab=1|bigBackpack=1|";
    }

    namespace data {
        constexpr std::string_view root = "./data/";
        constexpr std::string_view log = "./data/log/";
    }
}