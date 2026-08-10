#  S.O.P.H.I.E.A

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%2F20-blue.svg)](https://isocpp.org/)
[![Physics](https://img.shields.io/badge/Physics-RK4%20Numerical%20Integration-red.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

**S.O.P.H.I.E.A.** (*Integrated Mission Control - Europa Deep-Core Exploration*) is a C++17 numerical simulation engine designed to compute the physical descent trajectory of an automated scientific probe dropping into Jupiter's icy moon, Europa.

The simulation seamlessly transitions through four physical environments: the **vacuum of space**, Europa's **ionosphere**, a **25 km ice shell**, and a **subsurface ocean**.

---

## Physics & Numerical Methods

Rather than relying on basic Euler integration, S.O.P.H.I.E.A. uses a custom **4th-Order Runge-Kutta (RK4)** integration algorithm to maintain mathematical stability across extreme boundary transitions (such as hitting high hydrodynamic drag from a vacuum state).

##Important Message from me

All explanations and extras are in the report; feel free to explore it! If you have any doubts or want to discuss a bit, please feel free to dm me on Insta
**I used a lot of AI for syntax errors**, as I had a lot of problems with the coding, but tried my best to always learn with each part and to try to get off this training well. This was my first big project, and I wanted to express it with all I learned during my graduation from high school with physics... 


---

## 📁 Repository Structure

```text

├── include/              # Modular C++ header files (Physics, State, I/O)
│   ├── assets.hpp        # ASCII graphics and visual banners
│   ├── electrico.hpp     # Lorentz force and electromagnetic vectors
│   ├── fisica.hpp        # RK4 integration engine and state derivatives
│   ├── fluidos.hpp       # Hydrodynamic drag, pressure, and buoyancy
│   ├── gravidade.hpp     # Universal gravitation vector field
│   ├── interface.hpp     # Interactive CLI setup sequence
│   ├── logger.hpp        # Telemetry CSV logging system
│   └── sonda.hpp         # Probe data structures and environment constants
├── src/
│   └── main.cpp          # Main simulation loop and real-time telemetry stream
├── docs/
│   └── Report.pdf        # Full Computational Physics Analytical Project Report
├── CMakeLists.txt        # Build system configuration
└── README.md


