/* Aquí agrego las librerias para el funcionamiento de este programa */

#include <stdio.h> // Biblioteca que contiene las funciones de entrada y salida estandar
#include <iostream> // Biblioteca que contiene las funciones de entrada y salida estandar
#include <conio.h> // Uso de comandos MS-DOS dentro del programa
#include <string.h> // Biblioteca para la manipulacion de memoria
#include <stdlib.h> // Biblioteca para la gestion de memoria dinamica

/* Creamos una estructura para los clientes */
struct cliente{
	int id_cli; // ID del cliente
	char cedula[12]; // Cedula del cliente con un tamaño de 12
	char nombre[30]; // Nombre del cliente con un tamaño de 30
	char direccion[30]; // Direccion del cliente con un tamaño de 30
	char telefono[15]; // Telefono del cliente con un tamaño de 15
}clientes[100],*p_clientes=clientes; // Creamos un apuntador para clientes

/* Creamos una estructura para los productos */
struct producto{
	int id_pro; // ID del producto
	char nombre[30]; // Nombre del producto con un tamaño de 30
	int valor; // Valor o precio del producto
}productos[100],*p_productos=productos; // Creamos un apuntador para productos

/* Creamos una estructura para la factura */
struct factura{
	int id_fac; // ID de la factura
	struct cliente idcli; // Vinculamos la estructura del cliente pero solo el ID del cliente para usarlo en la factura
	struct producto idpro[100]; // Vinculamos la estructura del producto pero solo el ID del producto para usarlo en la factura
	int cantidad[100]; // Cantidad de productos comprados dentro de la factura
	int total; // Total de la compra dentro de la factura
	bool estado; // Estado, al ser booleano dará como resultado 0 o 1
}facturas[100],*p_facturas=facturas; // Creamos un apuntador para facturas

char n,op; // Aquí creamos dos variables globales de tipo CHAR.
int i, m, b, h, j, acum, acumt, cant_cli = 0, cant_pro = 0, cant_fac = 0; // Aquí creamos diez variables globales de tipo CHAR
/*
    Estas variables son usadas en el funcionamiento del programa, unas para el menu principal,
    otras para la creacion de clientes, productos, facturas (cant_cli, cant_pro, cant_fac)
    Algunas de estas variables como, i, m, b, h, j se utilizan para los ciclos dentro del programa
*/

/* Aqui creamos las funciones que usara el programa */
void crear_clientes(); // Para crear los clientes
void listar_clientes(cliente *); // Para mostrar los clientes
void modificar_clientes(); // Para modificar los clientes

void crear_productos(); // Para crear los productos
void listar_productos(producto *); // Para mostrar los productos
void modificar_productos(); // Para modificar los productos

void crear_facturas(); // Para crear facturas
void listar_facturas(factura *); // Para mostrar facturas
void modificar_facturas(); // Para modificar facturas

int main(){ // Este es nuestro main, solo incluye el menu con todas las opciones que permite hacer el programa
	int opcion;
	do{ // Usamos la funcion do while para la creacion del menu
		printf("************MENU************\n");
		printf("1.Crear,listar y crear clientes\n");
		printf("2.Crear,listar y crear productos\n");
		printf("3.Crear,listar y crear facturas\n");
		printf("4.Mostrar todas las facturas\n");
		printf("5.Mostrar todos los clientes\n");
		printf("6.Mostrar todas las facturas generadas por el cliente\n");
		printf("7.Mostrar todos los productos con la cantidad vendida de cada uno\n");
		printf("8.Listar facturas pagadas y sin pagar\n");
		printf("0.Salir\n");
		printf("*****************************\n");
		printf("Ingrese una opcion: "); // Le pedimos al usuario que ponga un numero del 0 al 8, si pone una diferente no lo aceptara
		scanf("%d",&opcion); // Lo guardara en una variable llamada opcion
		system("CLS"); // Limpiara la pantalla
		switch(opcion){ // Aqui validara lo anterior, que si pone 0, 1... Hasta 8
			char op;
            case 1:{ // Aqui entrara al menu de clientes
                do{ // Otro do while, esta vez para la gestion de clientes
                    fflush(stdin); // Sirve para limpiar el buffer de entrada del teclado, esto porque usaremos la variable "op" de nuevo en este menu
                    printf("**********Gestion de Clientes*********************\n");
                    printf("a.Crear clientes\n");
                    printf("b.Listar clientes\n");
                    printf("c.Modificar clientes\n");
                    printf("s.SALIR\n");
                    printf("*************************************\n");
                    printf("Ingrese una opcion: "); // Aqui pediremos ingresar una opcion entre a hasta c, contando la s como salir
                    scanf("%c",&op);
                    system("CLS");
                    switch(op){
                        case 'a':{
                            crear_clientes(); // Aqui crearemos los clientes
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 'b':{
                            listar_clientes(p_clientes); // Aqui mostraremos los clientes
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 'c':{
                            modificar_clientes(); // Aqui modificaremos los clientes
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 's':
                        {
                            break;
                        }
                        default:
                        {
                            printf("Error al digitar\n");
                            system("pause");
                            system("CLS");
                        }
                        break;
                    }
                }while(op!='s');
                break;
            }
            case 2:{ // Aqui entrada al menu de productos
                do{ // Otro do while, esta vez para la gestion de productos
                    fflush(stdin); // Volvemos a limpiar el buffer del teclado para la variable "op"
                    printf("************Gestion de Productos*******************\n");
                    printf("a.Crear productos\n");
                    printf("b.Listar productos\n");
                    printf("c.Modificar productos\n");
                    printf("s.SALIR\n");
                    printf("*************************************\n");
                    printf("Ingrese una opcion: "); // Aqui pediremos ingresar una opcion entre a hasta c, contando la s como salir
                    scanf("%c",&op);
                    system("CLS");
                    switch(op){
                        case 'a':{
                            crear_productos(); // Aqui crearemos los productos
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 'b':{
                            listar_productos(p_productos); // Aqui mostraremos los productos
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 'c':{
                            modificar_productos(); // Aqui modificaremos los productos
                            system("pause");
                            system("CLS");
                            break;
                        }
                        case 's':
                        {
                            break;
                        }
                        default:
                        {
                            printf("Error al digitar\n");
                            system("pause");
                            system("CLS");
                            break;
                        }
                    }
                }while(op!='s');
                break;
            }
            case 3:{ // Aqui entrara al menu de facturas
                do{ // Otro do while, esta vez para la gestion de facturas
                    fflush(stdin); // Volvemos a limpiar el buffer del teclado para la variable "op"
                    printf("************Gestionar Facturas*******************\n");
                    printf("a.Crear facturas\n");
                    printf("b.Listar facturas\n");
                    printf("c.Modificar facturas\n");
                    printf("s.SALIR\n");
                    printf("*************************************\n");
                    printf("Ingrese una opcion: "); // Aqui pediremos ingresar una opcion entre a hasta c, contando la s como salir
                    scanf("%c",&op);
                    system("CLS");
                    switch(op){
                        case 'a':{
                            crear_facturas(); // Aqui crearemos las facturas
                            break;
                        }
                        case 'b':{
                            listar_facturas(p_facturas); // Aqui mostraremos las facturas
                            break;
                        }
                        case 'c':{
                            modificar_facturas(); // Aqui modificaremos las facturas
                            break;
                        }
                        case 's':
                        {
                            break;
                        }
                        default:
                        {
                            printf("Error al digitar\n");
                            break;
                        }
                    }
                }while(op!='s');
                break;
            }
            case 4:{}
            case 5:{ // Aqui mostrara los clientes
                listar_clientes(p_clientes);
                system("pause");
                system("CLS");
                break;
            }
            case 6:{}
            case 7:{}
            case 8:{}
            case 0:{}
        }
	}while(opcion!=0);
}

void crear_clientes(){ // En esta funcion crearemos los clientes
	printf("-----------------Crear Clientes------------------------\n");
    do{
        fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado
        (p_clientes+cant_cli)->id_cli=cant_cli; // Aqui estamos asignando al id del cliente el ultimo valor de cant_cli, lo que funcionara como un autoincremental y el id nunca se repita
        fflush(stdin);
        printf("Por favor digitar su numero de cedula: "); // Pedimos que digite cedula al cliente
        fgets((p_clientes+cant_cli)->cedula,12,stdin); // fgets permitira que el dato aparezca con espacios sin problemas (EJ: Santiago Giraldo)
        printf("Por favor digitar su nombre completo: ");
        fgets((p_clientes+cant_cli)->nombre,30,stdin);
        printf("Por favor digitar la direccion donde reside: ");
        fgets((p_clientes+cant_cli)->direccion,30,stdin);
        printf("Por favor digitar su numero de telefono: ");
        fgets((p_clientes+cant_cli)->telefono,15,stdin);
        printf("\n\n");
        printf("¿Desea agregar otro cliente?\n si=s o no=n: "); // Le damos la opcion a quien usara el programa si desea digitar mas clientes
        scanf("%c",&n);
        printf("\n\n");
        cant_cli++; // cant_cli se sumara por cada creacion de cliente (Si antes era 0, pasara a 1)

    }while(n!='n');
}

void listar_clientes(cliente *p_clientes){ // En esta funcion mostraremos los clientes
	printf("-----------------Lista de Clientes------------------------\n");
	for (i=0;i<cant_cli;i++){ // i llegara hasta la cantidad de clientes que haya creados
		fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

		/* Mostrara los datos de los clientes registrados */
		printf("\nId cliente %d",(p_clientes+i)->id_cli);
		printf("\tCedula: %s",(p_clientes+i)->cedula);
		printf("\tNombre:  %s",(p_clientes+i)->nombre);
		printf("\tDireccion: %s ",(p_clientes+i)->direccion);
		printf("\tTelefono: %s",(p_clientes+i)->telefono);
		printf("\n\n");
	}
}

void modificar_clientes(){ // En esta funcion modificaremos los clientes
	listar_clientes(p_clientes); // Mostrara todos los clientes que estan actualmente registrados
	printf("-----------------Modificar Clientes------------------------\n");
	int var_cli;
	printf("Por favor Digite el ID a Modificar: "); // Pedira que digites el id de uno de esos clientes
	scanf("%d",&var_cli);
	if(var_cli>cant_cli){ // Aqui validara si el id puesto corresponde a uno existente
		printf("Id invalido\n");
		printf("Intente de nuevo\n");
		system("pause");
	}
	for(int j=0;j<=cant_cli;j++){ // Recorrera con un for hasta encontrar el id correspondiente al puesto en la variable "var_cli"
		if((p_clientes+j)->id_cli == var_cli){ // Aqui la hara la validacion nombrada con anterioridad
			fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

			/* Modificara los datos del cliente registrado */
			printf("Por favor digitar el nuevo numero de cedula: ");
			fgets((p_clientes+j)->cedula,12,stdin);
			printf("Por favor digitar el nuevo nombre completo: ");
			fgets((p_clientes+j)->nombre,30,stdin);
			printf("Por favor digitar la nueva direccion donde reside: ");
			fgets((p_clientes+j)->direccion,30,stdin);
			printf("Por favor digitar su nuevo numero de telefono: ");
			fgets((p_clientes+j)->telefono,15,stdin);
			printf("\n\n");
			break;
		}
	}
}

void crear_productos(){ // En esta funcion crearemos los productos
	printf("-----------------Crear productos------------------------\n");
    do{
        fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado
        (p_productos+cant_pro)->id_pro=cant_pro; // Aqui estamos asignando al id del producto el ultimo valor de cant_pro, lo que funcionara como un autoincremental y el id nunca se repita
        fflush(stdin);
        printf("Por favor digitar el nombre del producto: "); // Pedimos que digite nombre del producto
        fgets((p_productos+cant_pro)->nombre,30,stdin); // fgets permitira que el dato aparezca con espacios sin problemas (EJ: Ariel Quita Manchas)
        printf("Por favor digitar el valor del producto: ");
        scanf("%d",&(p_productos+cant_pro)->valor);
        fflush(stdin);
        printf("\n\n");
        printf("¿Desea agregar otro producto?\n si=s o no=n: "); // Le damos la opcion a quien usara el programa si desea digitar mas productos
        scanf("%c",&n);

        printf("\n\n");
        cant_pro++;
    }while(n!='n');
}

void listar_productos(producto *p_productos){ // En esta funcion mostraremos los productos
	printf("-----------------Lista de productos------------------------\n");
	for (i=0;i<cant_pro;i++){ // i llegara hasta la cantidad de productos que haya creados
		fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

		/* Mostrara los datos de los productos registrados */
		printf("\nId producto:%d \n",(p_productos+i)->id_pro);
		printf("Nombre: %s",(p_productos+i)->nombre);
		printf("Valor: %d",(p_productos+i)->valor);
		printf("\n\n");
	}
}

void modificar_productos(){ // En esta funcion modificaremos los productos
	listar_productos(p_productos); // Mostrara todos los productos que estan actualmente registrados
	int var_pro;
	printf("Por favor Digite el Id del producto a modificar: "); // Pedira que digites el id de uno de esos productos
	scanf("%d",&var_pro);
	if(var_pro>cant_pro){ // Aqui validara si el id puesto corresponde a uno existente
		printf("Id invalido\n");
		printf("Intente de nuevo\n");
		system("pause");
	}
	for(int j=0;j<=cant_pro;j++){ // Recorrera con un for hasta encontrar el id correspondiente al puesto en la variable "var_pro"
		if((p_productos+j)->id_pro == var_pro){ // Aqui la hara la validacion nombrada con anterioridad
			fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

			/* Modificara los datos del producto registrado */
			printf("Por favor digitar el nuevo nombre del producto: ");
			fgets((p_productos+j)->nombre,30,stdin);
			printf("Por favor digitar el nuevo valor del producto: ");
			scanf("%d",&(p_productos+j)->valor);
			fflush(stdin);
			printf("\n\n");
			break;
		}
	}
}

void crear_facturas(){ // En esta funcion crearemos las facturas
	printf("-----------------Crear Facturas------------------------\n");
	do{
		fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado
		(p_facturas+cant_fac)->id_fac=cant_fac; // Aqui estamos asignando al id de la factura el ultimo valor de cant_fac, lo que funcionara como un autoincremental y el id nunca se repita
		fflush(stdin);
		printf("Por favor digitar el ID del cliente que desea agregar a la factura: "); // Pedimos que digite el id del cliente al que le agregara la factura
		scanf("%d",&(p_facturas+cant_fac)->idcli.id_cli);
		fflush(stdin);
		for(h=0;h<cant_pro;h++){ // Aqui buscara por todos los productos creados y mas adelante pedira el id del producto que desea poner en facturacion
			printf("Por favor digitar el ID del producto que desea agregar a la factura: "); // Aqui hara lo dicho en la linea anterior
			scanf("%d",&(p_facturas+cant_fac)->idpro[h].id_pro);
			fflush(stdin);
			printf("Por favor digitar la cantidad del producto: ");
			scanf("%d",&(p_facturas+cant_fac)->cantidad[h]);
			fflush(stdin);
		}
		(p_facturas+cant_fac)->total=0; // Aqui le asignamos el valor de 0 al total de la factura
		for(j=0;j<cant_pro;j++){ // Recorrera por todos los productos para sacar el valor de cada producto que este en la factura y asi crear el total
            acum=(p_facturas+cant_fac)->idpro[j].valor*(p_facturas+cant_fac)->cantidad[j];
            (p_facturas+cant_fac)->total=acum+(p_facturas+cant_fac)->total;
		}
		fflush(stdin);
		printf("\n\n");
		printf("¿Desea agregar otra factura?\n si=s o no=n: "); // Le damos la opcion a quien usara el programa si desea digitar mas facturas
		scanf("%c",&n);
		printf("\n\n");
		cant_fac++;
		printf("\n\n");
	}while(n!='n');
}

void listar_facturas(factura *p_facturas){ // En esta funcion mostraremos las facturas
	for (i=0;i<cant_fac;i++){ // i llegara hasta la cantidad de facturas que haya creadas
		fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

		/* Mostrara los datos de las facturas registradas */
		for (i=0;i<cant_pro;i++){
            printf("\nId factura:%d \n",(p_facturas+i)->id_fac);
            printf("Id cliente:%d",(p_facturas+i)->idcli.id_cli);
            printf("Nombre del cliente: %s",(p_facturas+i)->idcli.nombre);
            printf("Id del producto %d",(p_facturas+i)->idpro[i].id_pro);
            printf("cantidad total del producto: %d",(p_facturas+i)->cantidad[i]);
            printf("\n\n");
		}
	}
}

void modificar_facturas(){ // En esta funcion modificaremos las facturas
	int var_fac;
	printf("Por favor Digite el Id de la factura a modificar: "); // Pedira que digites el id de uno de las facturas existentes
	scanf("%d",&var_fac);
	printf("dato: %d",var_fac);
	for(int j=0;j<=cant_fac;j++){ // Recorrera con un for hasta encontrar el id correspondiente al puesto en la variable "var_fac"
		if((p_facturas+j)->id_fac == var_fac){ // Aqui la hara la validacion nombrada con anterioridad
			fflush(stdin); // Limpiamos el buffer de cualquier entrada del teclado

			/* Modificara los datos de la factura registrada */
			printf("Por favor digitar el nuevo ID de la factura: ");
			scanf("%d",&(p_facturas+i)->id_fac);
			printf("Por favor digitar la nueva cantidad de producto: ");
			scanf("%d",(p_facturas+i)->cantidad);
			printf("Por favor digitar el nuevo total de la factura: ");
			scanf("%d",&(p_facturas+i)->total);
			printf("\n\n");
		}else{
			printf("\nError al digitar el ID de la factura\n");
			break;
		}
	}
}
