#include "xparameters.h"
#include "xil_io.h"
#include "cordic_ip.h"
#include <stdio.h>

int main (void) {
    xil_printf("-- Inicio del programa para validar el uso de IP cores propios --\r\n");

    u32 base_address = 0x40000000;  // Dirección base del dispositivo CORDIC en el mapa de memoria

    // Leer valores de salida
    u32 Xout, Yout;

    for (int i = 0; i <= 45; i++) {
        // Escribir valores de entrada: Xin = 1, Yin = 0, angle = i grados
        CORDIC_IP_mWriteReg(base_address, CORDIC_IP_S_AXI_SLV_REG0_OFFSET, 1);  // Xin
        CORDIC_IP_mWriteReg(base_address, CORDIC_IP_S_AXI_SLV_REG1_OFFSET, 0);  // Yin
        CORDIC_IP_mWriteReg(base_address, CORDIC_IP_S_AXI_SLV_REG2_OFFSET, i << 30);  // angle (i grados en formato Q1.30)

        // Esperar un breve tiempo para que la IP Cordic procese los datos
        usleep(1000);  // Esperar 1 ms

        // Leer valores de salida
        Xout = CORDIC_IP_mReadReg(base_address, CORDIC_IP_S_AXI_SLV_REG3_OFFSET);  // Xout
        Yout = CORDIC_IP_mReadReg(base_address, CORDIC_IP_S_AXI_SLV_REG4_OFFSET);  // Yout

        // Imprimir resultados
        printf("Ángulo: %d grados - Xout: %08lx, Yout: %08lx\n", i, Xout, Yout);
    }

    // Ejecutar auto-prueba
    if (CORDIC_IP_Reg_SelfTest((void *)base_address) != XST_SUCCESS) {
        printf("CORDIC IP self-test failed.\n");
        return -1;
    }

    printf("CORDIC IP self-test passed.\n");
    return 0;
}
