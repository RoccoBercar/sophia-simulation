#ifndef SONDA_HPP
#define SONDA_HPP

#include <cmath>

// --- CONSTANTES FÍSICAS ---
const double G = 6.67430e-11; 
const double M_EUROPA = 4.8e22;       
const double R_EUROPA = 1560000.0;    
const double RHO_OCEANO = 1025.0;     
const double ESPESSURA_GELO = 25000.0; 
const double LIMITE_VEL_IMPACTO = 150.0; 
const double Pressaomaxima = 100000000.0; 
const double fundodooceano = -120000.0; 

const double B_JUPITER = 450e-9;
const double E_IONOSFERA = 0.02; 

const double DRAG_GELO = 5000.0; 
const double DRAG_AGUA = 0.5; 

struct Estado {
    double x, y, z;
    double vx, vy, vz;
};

struct Sonda {
    double x, y, z; 
    double vx, vy, vz; 
    double massa; 
    double carga; 
    double volume; 
    double area_frontal;
    bool modoEscavacao = false;

    Estado obterEstado() const {
        return {x, y, z, vx, vy, vz};
    }
};

#endif