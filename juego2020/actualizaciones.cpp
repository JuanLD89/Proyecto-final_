#include "actualizaciones.h"
#include <math.h>
#include <cmath>

actualizaciones::actualizaciones(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)

{
    PX = posX_; //posicion en X
    PY = posY_; //posicion en Y
    mass = masa_; //masa
    R = radio_; //radio
    VX = velX_; //velocidad en X
    VY = velY_; //velocidad en Y
    AX = 0; //aceleración en X
    AY = 0; //aceleración en Y
    G = 10; //gravedad
    K = K_; //resistencia al aire
    e = e_; //coeciente de restitución
    V = 0; //vector de velocidad
    dt = 0.1; //delta de tiempo
}

actualizaciones::~actualizaciones()
{

}

float actualizaciones::get_posX() //obtener a posición e X
{
    return PX;
}

float actualizaciones::get_posY() //obtener a posición e Y
{
    return PY;
}

float actualizaciones::get_Radio() //obtener radio
{
    return R;
}

float actualizaciones::get_e() //obtener  coeficiente de restitución
{
    return e;
}

float actualizaciones::get_velX() //obtener velocidad en X
{
    return VX;
}

float actualizaciones::get_velY()   //obtener velocidad en Y
{
    return VY;
}

float actualizaciones::get_masa()  //obtener masa
{
    return mass;
}

void actualizaciones::set_vel(float velx, float vely, float px, float py)   //función para determinar velocidades y posiciones
{
    VX = velx;
    VY = vely;
    PX = px;
    PY = py;
}

void actualizaciones::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2); //potencia
    angulo = atan2(VY, VX);     //Calcula el valor principal del arco tangente de vy/vx, usando los signos de ambos argumentos para determinar el cuadrante del valor de retorno
    if (VX >= 0){
        AX = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-1; //saca la aceleracion en X
    }
    if (VX < 0){
        AX = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))+1;  //saca la aceleracion en X
    }    AY = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-G; //saca la aceleracion en Y
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);       //determina la posición en X
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);       //determina la posición en Y
    VX = VX + AX*dt;    //determina nuevamente la velocidad en X
    VY = VY + AY*dt;    //determina nuevamente la velocidad en Y
}
