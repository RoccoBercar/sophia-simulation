#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "sonda.hpp"
#include "assets.hpp"

inline void configure_mission(Sonda &s) {
    std::system("cls"); 
    AERO::draw_gloss();
    AERO::show_header();
    AERO::draw_gloss();
    
    std::cout << "\n[KERNEL] Initializing scientific telemetry interface...\n";
    std::cout << "[INFO] Please input required orbital state vectors.\n\n";

    double h, ux, uy, uz, vel;
    
    std::cout << "╔═➤ INITIAL STATE VECTOR ═══════════.o.OO°\n";
    std::cout << "║ Injection Altitude (m): "; std::cin >> h;
    std::cout << "║ Direction Vector (X Y Z): "; std::cin >> ux >> uy >> uz;
    
    double mag = std::sqrt(ux*ux + uy*uy + uz*uz);
    if(mag == 0) { ux=0; uy=0; uz=1; mag=1; }
    
    s.x = (R_EUROPA + h) * (ux/mag);
    s.y = (R_EUROPA + h) * (uy/mag);
    s.z = (R_EUROPA + h) * (uz/mag);

    std::cout << "║ Scalar Velocity (m/s): "; std::cin >> vel;
    s.vx = -vel * (ux/mag); s.vy = -vel * (uy/mag); s.vz = -vel * (uz/mag);
    std::cout << "╚═══════════════════════════════════.°.oO\n\n";

    std::cout << "╔═➤ PROBE STRUCTURAL SPECS ═════════.o.OO°\n";
    std::cout << "║ Total Mass (kg): "; std::cin >> s.massa;
    std::cout << "║ Electric Charge (C): "; std::cin >> s.carga;
    std::cout << "║ Frontal Area (m2): "; std::cin >> s.area_frontal;
    s.volume = std::pow(s.area_frontal, 1.5);
    std::cout << "╚═══════════════════════════════════.°.oO\n";

    std::cout << "\n[SYSTEM] Configuration validated.\n";
    std::cout << "Press ENTER to initiate descent sequence...";
    std::cin.ignore(1000, '\n'); std::cin.get();
}

#endif