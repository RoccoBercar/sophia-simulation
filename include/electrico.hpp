#ifndef ELECTRICO_HPP
#define ELECTRICO_HPP

#include "sonda.hpp"

namespace SOPHIA {
    inline void aplicarLorentzPura(const Sonda& s, double r, double& ax, double& ay, double& az) {
        if (std::abs(s.carga) < 1e-12) return;

        double ex = E_IONOSFERA * (s.x / r);
        double ey = E_IONOSFERA * (s.y / r);
        double ez = E_IONOSFERA * (s.z / r);

        double bx = 0, by = 0, bz = B_JUPITER;
        
        double v_cross_bx = (s.vy * bz - s.vz * by);
        double v_cross_by = (s.vz * bx - s.vx * bz);
        double v_cross_bz = (s.vx * by - s.vy * bx);

        ax += (s.carga * (ex + v_cross_bx)) / s.massa;
        ay += (s.carga * (ey + v_cross_by)) / s.massa;
        az += (s.carga * (ez + v_cross_bz)) / s.massa;
    }
}
#endif