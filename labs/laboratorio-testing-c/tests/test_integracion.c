#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

test_compra_con_descuento()
{
    Carrito c;
    carrito_init(&c);
    Producto p = {"pan", 200, 3};
    carrito_agregar(&c, p);
    Producto l = {"Leche", 350, 2};
    carrito_agregar(&c, l);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

test_agregar_hasta_llenar()
{

    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        int agregado = carrito_agregar(&c, p);
        ASSERT_IGUAL(1, agregado);
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    int extra = carrito_agregar(&c, p);
    ASSERT_IGUAL(0, extra);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void)
{
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
