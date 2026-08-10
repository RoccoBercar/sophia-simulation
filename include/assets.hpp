#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <iostream>
#include <string>
namespace AERO {
    inline void draw_gloss() {
        std::cout << "  . o O ° O . o . O ° O . o . O ° O . o . O ° O . o\n";
    }

    inline void show_header() {
        std::cout << "╔═════════════════════════════════════════════════════╗\n";
        std::cout << "║    S.O.P.H.I.E.A. - INTEGRATED MISSION CONTROL      ║\n";
        std::cout << "║           EUROPA DEEP-CORE EXPLORATION              ║\n";
        std::cout << "╚═════════════════════════════════════════════════════╝\n";
    }

    inline void draw_home_artwork() {
        std::cout << "\n[SYSTEM] Telemetry finalized. S.O.P.H.I.E.A. is now OFFLINE.\n";
        std::cout << "Press enter to leave\n";
        std::cin.ignore(1000, '\n'); std::cin.get();
    }
}

#endif