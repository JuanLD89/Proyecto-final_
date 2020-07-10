#ifndef ACTUALIZACIONES_H
#define ACTUALIZACIONES_H


class actualizaciones
{
public:
    actualizaciones(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_);
    ~actualizaciones();
    float get_posX();   //obtener la posicion en X
    float get_posY();   //obtener la posicion en Y
    float get_Radio(); //obtener el radio
    float get_e();      //obtener el coeficiente de restitución
    float get_velX();   //obtener la velocidad en X
    float get_velY();   //obtener la velocidad en Y
    float get_masa();   //obtener la masa del objeto
    void set_vel(float velx, float vely, float px, float py);       //funcion que se usara para las coliciones teniendo en cunta la posición del jugador
    void actualizar();  //aplica la cualidad fisica del salto parabolico, salto normal y gravedad en el jugador

private:
    float PX;//posicion en x
    float PY;//posicion en y
    float mass;//masa del cuerpo
    float R;//radio del cuerpo
    float VX;//velocidad en x
    float VY;//velocidad en y
    float angulo;//angulo en el que va el cuerpo.
    float AX;//aceleracion en x
    float AY;//aceleracion en y
    float G;//gravedad
    float K;//resistencia del aire
    float e;//coeficiente de restitucion.
    float V;//vector velocidad.
    float dt;//delta de tiempo.
};

#endif // ACTUALIZACIONES_H
