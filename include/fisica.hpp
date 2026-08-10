#ifndef FISICA_HPP
#define FISICA_HPP

#include "sonda.hpp"
#include "gravidade.hpp"
#include "electrico.hpp"
#include "fluidos.hpp"

namespace SOPHIA {

    struct Derivada {
        double dx, dy, dz;
        double dvx, dvy, dvz;
    };

    inline Derivada calcularDerivadas(const Sonda& s, const Estado& est, double t) {
        Derivada d;
        d.dx = est.vx; d.dy = est.vy; d.dz = est.vz;

        double r = std::sqrt(est.x*est.x + est.y*est.y + est.z*est.z);
        if (r < 1000.0) r = 1000.0;
        double altitude = r - R_EUROPA;

        double ax = 0, ay = 0, az = 0;

        aplicarGravidadePura(est, r, ax, ay, az);

        Sonda temp = s; 
        temp.x = est.x; temp.y = est.y; temp.z = est.z;
        temp.vx = est.vx; temp.vy = est.vy; temp.vz = est.vz;
        aplicarLorentzPura(temp, r, ax, ay, az);

        if (altitude <= 0) {
            double v_tot = std::sqrt(est.vx*est.vx + est.vy*est.vy + est.vz*est.vz);
            // Resistência
            ax -= calcularAceleracaoResistencia(s, altitude, est.vx, v_tot);
            ay -= calcularAceleracaoResistencia(s, altitude, est.vy, v_tot);
            az -= calcularAceleracaoResistencia(s, altitude, est.vz, v_tot);
            // Empuxo
            double a_arq = calcularArquimedesMagnitude(s, altitude, r) / s.massa;
            ax += a_arq * (est.x / r);
            ay += a_arq * (est.y / r);
            az += a_arq * (est.z / r);
        }

        d.dvx = ax; d.dvy = ay; d.dvz = az;
        return d;
    }

    inline void integrarRK4(Sonda& s, double dt, double t) {
        Estado inicial = s.obterEstado();

        Derivada k1 = calcularDerivadas(s, inicial, t);

        Estado est_k2 = { inicial.x + k1.dx*dt/2, inicial.y + k1.dy*dt/2, inicial.z + k1.dz*dt/2,
                          inicial.vx + k1.dvx*dt/2, inicial.vy + k1.dvy*dt/2, inicial.vz + k1.dvz*dt/2 };
        Derivada k2 = calcularDerivadas(s, est_k2, t + dt/2);

        Estado est_k3 = { inicial.x + k2.dx*dt/2, inicial.y + k2.dy*dt/2, inicial.z + k2.dz*dt/2,
                          inicial.vx + k2.dvx*dt/2, inicial.vy + k2.dvy*dt/2, inicial.vz + k2.dvz*dt/2 };
        Derivada k3 = calcularDerivadas(s, est_k3, t + dt/2);

        Estado est_k4 = { inicial.x + k3.dx*dt, inicial.y + k3.dy*dt, inicial.z + k3.dz*dt,
                          inicial.vx + k3.dvx*dt, inicial.vy + k3.dvy*dt, inicial.vz + k3.dvz*dt };
        Derivada k4 = calcularDerivadas(s, est_k4, t + dt);

        s.x += (dt/6.0) * (k1.dx + 2*k2.dx + 2*k3.dx + k4.dx);
        s.y += (dt/6.0) * (k1.dy + 2*k2.dy + 2*k3.dy + k4.dy);
        s.z += (dt/6.0) * (k1.dz + 2*k2.dz + 2*k3.dz + k4.dz);
        s.vx += (dt/6.0) * (k1.dvx + 2*k2.dvx + 2*k3.dvx + k4.dvx);
        s.vy += (dt/6.0) * (k1.dvy + 2*k2.dvy + 2*k3.dvy + k4.dvy);
        s.vz += (dt/6.0) * (k1.dvz + 2*k2.dvz + 2*k3.dvz + k4.dvz);
    }
}

#endif