#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "/include/sonda.hpp"
#include "/include/interface.hpp"
#include "/include/logger.hpp"
#include "/include/fisica.hpp"
#include "/include/assets.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    Sonda sophia;
    std::ofstream report;
    std::string filename;

    std::cout << ".oO° Data Report Filename: "; std::cin >> filename;
    configure_mission(sophia);
    SOPHIA::inicializarRelatorio(report, filename);

    double t = 0.0, dt = 0.01; 
    bool active_mission = true;

    std::cout << "\n╔═➤ REAL-TIME TELEMETRY STREAM ══════════════════════╗\n";
    std::cout << "║  TIME   |   ALTITUDE   |  VELOCITY   |   MEDIUM    ║\n";
    std::cout << "╠═════════╬══════════════╬═════════════╬═════════════╣\n";

    while (active_mission) {
        double r = std::sqrt(sophia.x*sophia.x + sophia.y*sophia.y + sophia.z*sophia.z);
        double alt = r - R_EUROPA;
        std::string env = (alt > 100000) ? "VACUUM" : (alt > 0) ? "IONOSPHERE" : (alt > -ESPESSURA_GELO) ? "ICE-SHELL" : "OCEAN";

        if ((int)(t * 100) % 2000 == 0) {
            double v_tot = std::sqrt(sophia.vx*sophia.vx + sophia.vy*sophia.vy + sophia.vz*sophia.vz);
            std::cout << "\r║ " << std::setw(6) << (int)t << "s  | " 
                      << std::setw(9) << std::fixed << std::setprecision(2) << alt/1000.0 << " km | "
                      << std::setw(7) << (int)v_tot << " m/s | "
                      << std::setw(11) << env << " ║" << std::flush;
        }

        SOPHIA::integrarRK4(sophia, dt, t);
        SOPHIA::gravarDados(report, t, sophia, env);
        t += dt;

        if (alt <= 0 && !sophia.modoEscavacao) {
             if (std::sqrt(sophia.vx*sophia.vx + sophia.vy*sophia.vy + sophia.vz*sophia.vz) > LIMITE_VEL_IMPACTO) {
                 std::cout << "\n[CRITICAL] STRUCTURAL FAILURE AT T=" << t << "s.\n";
                 active_mission = false;
             } else {
                 sophia.modoEscavacao = true;
             }
        }

        if (alt < fundodooceano) {
            std::cout << "\n[SUCCESS] Sophia reached the benthic seafloor.\n";
            active_mission = false;
        }
    }

    report.close();
    
    AERO::draw_home_artwork();
    
    return 0;
}
