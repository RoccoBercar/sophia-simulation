#ifndef FLUIDOS_HPP
#define FLUIDOS_HPP

#include "sonda.hpp"

inline double calcularArquimedesMagnitude(const Sonda& s, double alt, double r) {
    if (alt <= -ESPESSURA_GELO) { 
        double g_local = (G * M_EUROPA) / (r * r);
        return RHO_OCEANO * s.volume * g_local; 
    }
    return 0.0;
}

inline double calcularAceleracaoResistencia(const Sonda& s, double alt, double v_comp, double v_tot) {
    if (alt > 0) return 0.0;
    if (alt <= 0 && alt > -ESPESSURA_GELO) {
        return (DRAG_GELO * v_comp) / s.massa;
    }
    return (0.5 * RHO_OCEANO * s.area_frontal * DRAG_AGUA * v_tot * v_comp) / s.massa;
}

inline double calcularPressao(double alt, double r) {
    double prof = std::abs(alt) - ESPESSURA_GELO;
    if (prof > 0) {
        double g_local = (G * M_EUROPA) / (r * r);
        return RHO_OCEANO * g_local * prof;
    }
    return 0.0;
}
#endif