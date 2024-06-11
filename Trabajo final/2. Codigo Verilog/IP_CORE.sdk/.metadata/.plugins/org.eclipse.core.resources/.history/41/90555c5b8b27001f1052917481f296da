#include "xparameters.h"
#include "xil_io.h"
#include "cordic_ip.h"
#include <stdio.h>
 

//====================================================

int main (void) {

	int angle = 1073741824; // 90 grados
    int Xin = 1;
	int Yin = 0;
    int Xout;
    int Yout;

    xil_printf("-- Inicio del programa para validar el uso de IP cores propios --\r\n");
 
    // Escribir los valores de entrada en los registros del módulo CORDIC
    Xil_Out32(CORDIC_BASE_ADDR + CORDIC_ANGLE_OFFSET, angle);
    Xil_Out32(CORDIC_BASE_ADDR + CORDIC_XIN_OFFSET, Xin);
    Xil_Out32(CORDIC_BASE_ADDR + CORDIC_YIN_OFFSET, Yin);

    // Leer los valores de salida del módulo CORDIC
    int Xout = Xil_In32(CORDIC_BASE_ADDR + CORDIC_XOUT_OFFSET);
    int Yout = Xil_In32(CORDIC_BASE_ADDR + CORDIC_YOUT_OFFSET);

    // Imprimir los resultados
    printf("Xout: %d\n", Xout);
    printf("Yout: %d\n", Yout);

    return 0;
