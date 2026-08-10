#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <string>
#include "sonda.hpp"

namespace SOPHIA {
    inline void inicializarRelatorio(std::ofstream& f, std::string n) {
        f.open(n + ".csv");
        f << "Tempo(s),X(m),Y(m),Z(m),V(m/s),Ambiente\n";
    }
    inline void gravarDados(std::ofstream& f, double t, const Sonda& s, std::string amb) {
        double v = std::sqrt(s.vx*s.vx + s.vy*s.vy + s.vz*s.vz);
        f << t << "," << s.x << "," << s.y << "," << s.z << "," << v << "," << amb << "\n";
    }
}
#endif