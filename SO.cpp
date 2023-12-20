#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AsignadorRecursos {
public:
    AsignadorRecursos(vector<Proceso>& procesos, int memoriaDisponible, int velocidadCPU)
        : procesos(procesos), memoriaDisponible(memoriaDisponible), velocidadCPU(velocidadCPU) {}

    void asignacionPreventiva() {
        for (int i = 0; i < procesos.size(); i++) {
            asignarRecursos(i);
        }
    }

    void asignacionPorSolicitudYLiberacion() {
        for (int i = 0; i < procesos.size(); i++) {
            asignarRecursos(i);
        }
        liberarRecursos();
    }

    void asignacionPorDeteccionYRecuperacion() {
        for (int i = 0; i < procesos.size(); i++) {
            asignarRecursos(i);
        }
        if (hayInterbloqueo()) {
            // Manejar el interbloqueo
        }
    }

private:
    vector<Proceso>& procesos;
    int memoriaDisponible;
    int velocidadCPU;

    void asignarRecursos(int indiceProceso) {
        // Logica de asignacion de recursos
    }

    void liberarRecursos() {
        // Logica de liberacion de recursos
    }

    bool hayInterbloqueo() {
        // Logica de deteccion de interbloqueo
        return false;
    }
};

int main() {
    // Definir los procesos
    Proceso p1 = {"P1", 50, 2};
    Proceso p2 = {"P2", 200, 1};
    Proceso p3 = {"P3", 50, 1};
    
    // Agregar los procesos al vector de procesos
    vector<Proceso> procesos;
    procesos.push_back(p1);
    procesos.push_back(p2);
    procesos.push_back(p3);

    // Definir los recursos disponibles
    int memoriaDisponible = 100;
    int velocidadCPU = 4;

    // Crear un objeto AsignadorRecursos y ejecutar los diferentes mecanismos
    AsignadorRecursos asignador(procesos, memoriaDisponible, velocidadCPU);

    cout << "Asignacion preventiva:" << endl;
    asignador.asignacionPreventiva();

    cout << endl << "Asignacion por solicitud y liberacion:" << endl;
    asignador.asignacionPorSolicitudYLiberacion();

    cout << endl << "Asignacion por deteccion y recuperacion:" << endl;
    asignador.asignacionPorDeteccionYRecuperacion();

    return 0;
}

