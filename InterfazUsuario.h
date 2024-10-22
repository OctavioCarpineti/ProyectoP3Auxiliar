#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include <string>

class GestorConsultas;
class BaseDeDatos;

class InterfazUsuario {
private:
    GestorConsultas* gestorConsultas;
    BaseDeDatos* baseDeDatos;

public:
    InterfazUsuario(GestorConsultas* gestorConsultas, BaseDeDatos* baseDeDatos);
    void mostrarMenuPrincipal();
    void mostrarMenuInicial();
    void mostrarMenuBusqueda();
    void mostrarMenuResultadosPrincipales();
    void mostrarMenuConsultasDinamicas();
    void mostrarMenuModificacion();

    void mostrarPartidosConMasGoles();
    void mostrarGolesTotalesPorEquipo();
    void mostrarPromedioGolesPorEquipo();
    void mostrarDerrotasYTriunfosPorEquipo();
    void mostrarFechasConMasYMenosGoles();
    void mostrarCompeticionConMasGoles();
    void mostrarEquipoConMasYMenosGoles();

    void consultarResultadosEquipoCompeticion();
    void consultarResultadosEquipoFechas();
    void compararRendimientoGeneral();
    void compararRendimientoParticular();
    void filtrarEquiposPorUmbral();

    void buscarPorCompeticion();
    void buscarPorEquipo();
    void buscarPorTemporada();
    void buscarPorFecha();
    void mostrarEstadisticasGenerales();
    void mostrarPartidosDestacados();
    void mostrarClasificaciones();

    void agregarPartido();
    void eliminarPartido();
    void modificarPartido();

    void mostrarCompeticiones();
    void mostrarEquipos();
    void mostrarTemporadas();
    std::string solicitarFecha();
    std::string obtenerNombreCompeticion(int opcion);
};

#endif // INTERFAZUSUARIO_H