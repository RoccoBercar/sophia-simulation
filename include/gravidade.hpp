#ifndef GRAVIDADE_HPP
#define GRAVIDADE_HPP

#include "sonda.hpp"

inline void aplicarGravidadePura(const Estado& e, double r, double& ax, double& ay, double& az) {
    double g = (G * M_EUROPA) / (r * r);
    ax -= g * (e.x / r);
    ay -= g * (e.y / r);
    az -= g * (e.z / r);
}

#endif