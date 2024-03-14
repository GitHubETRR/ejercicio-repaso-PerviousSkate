#include <stdio.h>
#define CANT_MAX 5
#define LONG_NOMBRE 100

typedef struct {
    char nombre[LONG_NOMBRE];
    unsigned int edad;
    unsigned int salario;
}empleados_t;

empleados_t ingresarDatos(empleados_t);
void procesarDatos(empleados_t[], int);


int main(){
    empleados_t personas[CANT_MAX];
    unsigned int personasIngresadas = 0;
    int seleccion = 0;
    do{
        printf("\n---MENU---\n");
        printf("1. Ingresar datos de un empleado\n");
        printf("2. Procesar datos almacenados y mostrar empleados\n");
        printf("3. Finalizar programa\n");
        printf("\nSeleccione una opcion:");
        scanf("%d",&seleccion);
        if (seleccion == 1){
            personas[personasIngresadas] = ingresarDatos(personas[personasIngresadas]);
            personasIngresadas++;
        }
        else if (seleccion == 2){
            mostrarDatos(personas, personasIngresadas);
            procesarDatos(personas, personasIngresadas);
        }
    }while(seleccion != 3);

}

empleados_t ingresarDatos(empleados_t personas){
    printf("Por favor ingrese el nombre del empleado: ");
    scanf("\n%[^\n]%*c",personas.nombre);
    printf("Por favor ingrese la edad del empleado:");
    scanf("%i", &personas.edad);
    printf("Por favor ingrese el salario del empleado:");
    scanf("%i", &personas.salario);
    
    return personas;
}

void procesarDatos(empleados_t personas[], int personasIngresadas){
    int salarioMayor=0;
    int IndexSalarioMayor=0;
    int promedio=0;
    
    for(int i = 0; i<personasIngresadas; i++){
        
        if(personas[i].salario>salarioMayor){
            salarioMayor = personas[i].salario;
            IndexSalarioMayor = i;
        }

        promedio += personas[i].salario;
        
    }
     
        promedio /= personasIngresadas;
    printf("\nEl promedio del salario fue de %d" ,promedio);
    printf("\nEl empleado con mayor salario es %s que gana $%d \n\n",personas[IndexSalarioMayor].nombre,personas[IndexSalarioMayor].salario);
}

void mostrarDatos(empleados_t personas[], int personasIngresadas){
    for(int i = 0; i<personasIngresadas; i++){
        printf("\nNombre:%s",personas[i].nombre);
        printf("\nEdad:%d",personas[i].edad);
        printf("\nSalario:%d \n",personas[i].salario);
    }
}

