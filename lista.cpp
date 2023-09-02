#include <iostream>
using namespace std;
/**
 * Se define la estrucutura para la lista.
 * @param data Dato del nodo.
 * @param next Puntero al siguiente nodo.
 */
struct Node
{
    int data;
    Node *next;
};

/**
 * Función para agregar un elemento al final de la lista
 * @param [out] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista. (Primera vez es nullptr)
 * @param [in] value Valor que sea va designar segun al nuevo Nodo que se va a crear.
 * @param newNode Variable puntero que hace referencia al objeto, y que guarda la posicion de memoria.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void createOne(Node *&head, int value)
{

    Node *newNode = new Node; // Se crea un nuevo Nodo, y '*newNode' guarda la posicion en memoria del objeto. (Puntero)
    newNode->data = value;    // Se actualiza el valor de 'newNode.data' segun 'value'
    newNode->next = nullptr;  // Se actualiza el valor de 'newNode.next' a 'nullptr'

    // Validacion para saber si 'head' tiene alguna direccion en memoria. (No hay otro Nodo. Es el Primer nodo)
    if (head == nullptr)
    {
        head = newNode; // 'head' se actualiza de manera global y guarda ahora la direccion en memoria del primer nodo de la lista.
    }
    // Parte para cuando ya existe un nodo (Lista con un valor), y se va agregar uno nuevo.
    else
    {
        // Se crea el puntero, 'current', de tipo Node para así guardar la direccion en memoria de 'head'.
        Node *current = head;
        // Ciclo para recorrer el parametro 'next' de la estructura Nodo mientras que 'current.next' no sea nullptr. (Busca el ultimo nodo)
        while (current->next != nullptr)
        {
            // Se actualiza la variable 'current' para que así guarde la direccion de memoria del siguiente nodo, según el 'current.next' actual (Guarda el puntero del siguiente elemento de la lista si existe)
            current = current->next;
        }
        // Esto es para que current.next guarde el puntero newNode del nuevo Nodo
        // Se actualiza el valor del parametro 'next' del nodo actual ('current.next') para que guarde la direccion de memoria del nuevo Nodo (Guarda el actual nodo creado en el ultimo Nodo de la lista)

        current->next = newNode;
    }
}
/**
 * Funcion para insetar un valor en una posicion X.
 * @param [out] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista. (Primera vez es nullptr. Y se actualiza si se inserta al incio.
 * @param [in] position Posicion de la lista en la que se va a insertar el dato.
 * @param [in] value Valor del dato que se va a ingresar del Nodo.
 * @param newNode Variable puntero que hace referencia al objeto, y que guarda la posicion de memoria.
 */
void createInPosition(int value, Node *&head, int position)
{
    Node *newNode = new Node; // Se crea un nuevo Nodo, y '*newNode' guarda la posicion en memoria del objeto. (Puntero)
    newNode->data = value;    // Se actualiza el valor de 'newNode.data' segun 'value'
    newNode->next = nullptr;  // Se actualiza el valor de 'newNode.next' a 'nullptr'

    // Validacion para saber si 'head' tiene alguna direccion en memoria. (No hay otro Nodo. Es el Primer nodo)
    if (head == nullptr)
    {
        head = newNode; // 'head' se actualiza de manera global y guarda ahora la direccion en memoria del primer nodo de la lista.
    }
    // Parte para cuando ya existe un nodo (Lista con un valor), y se va agregar uno nuevo.
    else
    {
        Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
        int i = 0;            // Variable para llevar el indice actual.
        if (position != -1)   // Validacion para saber si la variable 'position' es diferente de -1, para así saber que no se quiere poner en primera posicion.
        {

            while (true) // Ciclo While para recorrer toda la lista.
            {
                //  Validacion para saber si 'i' es igual a 'position' y así aagregar el Nodo.
                if (i == position)
                {
                    newNode->next = current->next; // 'newNode.next' se actualiza y apunta al nodo actual. (El nuevo nodo apunta al nodo que apuntaba'current')
                    current->next = newNode;       // 'current.next' de actualiza y apunta al nuevo nodo (El nodo alcutal apunta )
                    break;
                }
                if (current == NULL)
                {
                    cout << "Posicion fuera de la lista, ingrese mas valores" << endl;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        else // Cuando el valor que se ingresa va a ser en la primera posicion.
        {

            newNode->next = head; // 'newNode' ahora apunta a la cabeza actual de la lista.
            head = newNode;       // El nuevo nodo se vuelve la cabeza ('newNode' se vuelve el primer Nodo de la lista) y
        }
    }
}
/**
 * Funcion para buscar un valor e imprir la posicion en la que está.
 * @param [in] value Valor que se buscará en la lista.
 * @param [in] head  Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param current Variable tipo nodo que se usa para moverse entre la lista.
 * @param i Variable referente a la poscion actual de la lista. (Indice)
 * @param band Boolean para valdiar si se encuentra un elemento.
 */
void readOne(int value, Node *head)
{
    // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    Node *current = head;
    // Se crea la variable 'i' para indicar la poscion actual de la lista.
    int i = 0;
    // Se crea la variable 'band' para validacion.
    bool band = true;
    // Ciclo while para recorrer la lista
    while (current != nullptr)
    {
        // Validacion para saber si el valor de 'current.data' es igual a 'value' (Si se encontró el valor)
        if (current->data == value)
        {
            // Se imprime la posicion donde se encontró el valor.
            cout << "Valor encontrado posicion: "
                 << i << endl;
            // Se cambia el valor de 'band'
            band = false;
        }
        // Se cambia el apuntado de 'current' a 'current.next' (Ahora apunta donde apunta 'current')
        current = current->next;
        // Se suma uno a 'i'
        i++;
    }
    // Validacion para saber si se encontró el valor en la lista. (En el caso que si se haya encontrado anteriormente 'band' se pone en false)
    if (band)
    {
        // Impresion cuando no se encontró nada
        cout << "Valor no encontrado " << endl;
    }
}
/**
 * Función para imprimir la lista
 * @param [in] head Puntero que hace referencia al espacio de memoria del primer nodo.
 * @param current Puntero que guarda el espacio de memoria de 'head'.
 *
 */
void readAll(Node *head)
{
    // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    Node *current = head;
    if (current != NULL)
    {
        // Ciclo para recorrer la lista siempre y cuando 'current' no sea nullptr (Para recorrer de inicio a fin la lista).
        while (current != nullptr)
        {
            // Se imprime el valor de 'current.data'
            cout << current->data << " ";
            // Se actualiza la varaible 'current' a la direccion en memoria del siguiente nodo guardado en 'current.next'.
            current = current->next;
        }
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}
/**
 * Funcion para actualizar un valor en la posicion
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] position Posicion de la lista en la que se va a insertar el dato.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateOne(Node *&head, int new_value, int position)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    int i = 0;            // Variable para llevar el indice actual.
    // Validacion para verificar si la lista no está vacia
    if (current != NULL)
    {
        // Ciclo while para recorrer la lista
        while (i != position && current != nullptr) // Si el indice 'i' no coincide con la posicion 'position' y el valor actual al que apunta 'current' no es nullptr entra al while (El valor que se busca no es el actual)
        {
            // Se rota las posiciones de 'current' a 'current.next' para asi que se guarde el nodo al que está apuntado 'current'
            current = current->next;
            // Se suma uno al indice
            i++;
        }
        // Validacion para cuando 'current'apunta a nulo (Fin de la lista) (Validacion para que el programa se crashee)
        if (current == NULL)
        {
            // Impresion de posicion fuera de la longitud actual de la lista
            cout << "Posicion fuera de la lista, ingrese mas valores" << endl;
        }
        // Cuando el valor de 'current' no es null, entonces si se encontró el valor
        else
        {
            // Confirmacion de dato actualizado
            current->data = new_value;
            cout << "DATO ACTUALIZADO" << endl;
        }
    }
    // Parte cuando la lista está vacia
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 * Funcion para actualizar al primir numero que coincide con 'value'.
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] new_value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] filter Variable de filtro para buscar el valor a editar.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateFirts(Node *&head, int new_value, int filter)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    // Validacion para saber si la lista está vacia
    if (head != NULL)
    {
        // Ciclo while que recorre la lista hasta encontrar el nodo que se quiere modificar
        while (current->next != nullptr && current->data != filter)
        {
            // Se rotan los puntero de 'current' a donde apunta 'current.next'
            current = current->next;
        }
        // Validacion para ver si se llegó al final de la lista sin encontrar el valor
        if (current->next == nullptr)
        {
            cout << "VALOR NO ENCONTRADO" << endl;
        }
        // Parte para cuando si existe el dato y se actualiza
        else
        {
            //  Actualiza el dato a lo que esté en la variable 'new_value'
            current->data = new_value;
            // Impresion de confirmacion
            cout << "Se actualizó el dato" << endl;
        }
    }
    // Cuando la lista está vacia
    else
    {
        cout << "Nada que actualizar" << endl;
    }
}
/**
 * Funcion para actualizar todos los datos iguales a 'filter'
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] new_value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] flter Variable de filtro para buscar el valor a editar.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateAll(Node *&head, int new_value, int filter)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    bool band = true;
    // Validacion para comprar si la lista no esté vacia
    if (current != NULL)
    {
        // Ciclo while que recorre la lista siempre y cuando 'current' sea diferente de null (Para saber si se llega al final de la lista)
        while (current != NULL)
        {
            // Validacion para sabe si se el valor actual del nodo 'current.data' es igual al valor de 'filter'
            if (current->data == filter)
            {
                // Se actualiza el valor del nodo actual al valor de 'new_value'
                current->data = new_value;
                cout << "Valor actualizado" << endl;
                band = false;
            }
            // Se rotan los apuntados de memorias, de 'current' a 'current.next'
            current = current->next;
        }
        if (band)
        {
            cout << "No se encontró ningur valor" << endl;
        }
    }
    // Parte cuando la lista está vacia
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 * Funcion para eliminar un nodo en la posicion X
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] filter Variable que sea usa como filtro, debe ser igual al valor de la lista en la posicion X.
 * @param [in] position Posicion de la lista en la que se va a eliminar el dato.
 * @param past Variable node para guardar el nodo anterior para despues actualizar su apuntador
 */
void deleteOne(Node *&head, int filter, int position)
{

    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    Node *past = NULL;    // Se crea un puntero para de tipo Nodo iniciado en null.
    int i = 0;            // Variable para llevar el indice actual.
    bool band = true;     // Boleano para indicar si un valor de encontró o no

    // Ciclo while para recorre la lista
    while (current != nullptr)
    {
        // Validacion saber si 'current.data' es igual a 'filter', y si la posicion 'positiomn' que se desar ir es igual al indice 'i', y tambien si 'current' y 'head' son iguales; esto es para eliminar el primer dato de la lista, y actualizar la cabeza
        if (current->data == filter && position == i && current == head)
        {
            head = current->next; // Se actualiza la cabeza a donde esté apuntado 'current'
            delete current;       // Se libera la memoria de current
            band = false;         // Se coloca la bandera el false para indicar que si se borró un dato
            cout << "Valor de la cabeza eliminados" << endl;
            break;
        }
        // Validacion saber si 'current.data' es igual a 'filter', y si la posicion 'positiomn' que se desar ir es igual al indice 'i', y si 'current' es diferente de null (Para saber si se llegó al final de la lista), esto para saber si se encontro el valor; esto es para cuando el valor si se encuentra, pero no es la cabeza
        if (current->data == filter && position == i && current != NULL)
        {

            past->next = current->next; // Se actualiza el puntero del nodo anterior a donde esté apuntado 'current'
            delete current;             // Se libera la memoria de current
            band = false;               // Se coloca la bandera el false para indicar que si se borró un dato
            cout << "Valor eliminado " << endl;
            break;
        }

        // 'past' pasa a ser 'current' para así guardarlo y no perder el nodo anterior
        past = current;
        // Se rota a donde esté apuntando 'current'
        current = current->next;
        // Se le agrega uno al indice
        i++;
    }
    // Validacon para saber si el un dato fue eliminado
    if (band)
    {
        cout << "Valor no eliminado " << endl;
    }
}
/**
 * Funcion para borrar al primir numero que coincide con 'value'.
 * @param [in] head  Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] value Valor que se va a borrar de la lista.
 * @param current Variable tipo Node para moverse en la lista.
 * @param past Variable tipo Node para guardar el nodo anterior de manera temporal.
 *
 */
void deleteFirts(Node *&head, int filter)
{
    Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
    Node *past = NULL;    // // Se crea un nuevo Node 'past' para guardar el Nodo anterior.

    // Validacion para saber si la lista está vacia.
    if (head != NULL)
    {
        // Ciclo while para recorrer la lista siempre y cuando no se llegue al final (current != NULL) o cuando el valor actual de 'current.data' no coincida con 'filter' (current->data != filter)
        while (current != NULL && current->data != filter)
        {
            // 'past' se actualiza a 'current' para guardar el nodo que está en 'current' para usarlo despues.
            past = current;
            // 'current' se actualiza al nodo que está 'current.next'
            current = current->next;
        }
        // Validacion para cuando 'current'apunta a nulo (Fin de la lista)
        if (current == NULL)
        {
            cout << "No se encontró el valor en la lista" << endl;
        }
        // Validacion para cuando past nunca se actualiza (El dato a buscar está en la primiera posicion de la lista)
        else if (past == NULL)
        {
            head = head->next; // La cabeza se actualiza al siguiente valor de la lista, 'head.next'
            delete current;    // Se libera la memoria de 'current'
            cout << "Valor eliminado en la cabeza" << endl;
        }
        // Para cuando el valor se encuentra, pero no está en la primera posicon
        else
        {
            past->next = current->next; // El nodo pasado apuntará ahora a donde apunta 'current'
            delete current;             // Se libera la memoria de 'current'
            cout << "Valor eliminado" << endl;
        }
    }
    // Impresion cuando la lista está vacia
    else
    {
        cout << "Nada que borrar" << endl;
    }
}
/**
 * Funcion para eliminar todos los datos que coincidan.
 * @param [in] head untero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] filter Variable de filtro para buscar el valor a borrar.
 * @param current Variable tipo Node para moverse en la lista.
 * @param past  Variable node para guardar el nodo anterior para despues actualizar su apuntador
 */
void deleteAll(Node *&head, int filter)
{
    Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
    Node *past = NULL;    // // Se crea un nuevo Node 'past' para guardar el Nodo anterior.
    bool band = true;     // Boleano para indicar si un valor de encontró o no

    // Validacion para saber si la lista está vacia
    if (head != NULL)
    {
        // Ciclo while para recorrer la lista siempre y cuando no se llegue al final
        while (current != nullptr)
        {

            // Validacion para saber si la cabeza tiene el valor que sea desea borrar.
            if (current->data == filter && head == current)
            {
                head = head->next; // Se actualiza la cabeza a donde esté apuntando la cabeza
                delete current;    // Se libera la memoria de 'current'
                cout << "Se ha eliminado el valor de la cabeza" << endl;
                current = head; // 'current' pasa a ser la nueva cabeza para seguir buscando
                band = false;   // Se coloca la bandera el false para indicar que si se borró un dato
            }
            // Para cuando la cabeaza no tiene el valor que sea desea borrar
            else
            {
                // Validacion para saber si el dato del nodo actual coincide con el filtro
                if (current->data == filter)
                {
                    past->next = current->next; // El nodo anterior ahora apunta a donde está apuntando 'current'
                    delete current;             // Se libera la memoria de 'current'
                    cout << "Se ha eliminado un valor de lista" << endl;
                    current = past; //  'current' pasa a ser el ultimo nodo para seguir buscando
                    band = false;   // Se coloca la bandera el false para indicar que si se borró un dato
                }

                past = current;          // Se rotan, 'past' pasa a ser 'current' para no perder la referencia
                current = current->next; // Se rotan, ahora 'current' pasa a ser donde está apuntando 'current.next'
            }
        }
        // Validacon para saber si el un dato fue eliminado
        if (band)
        {
            cout << "No se encontró ningur valor" << endl;
        }
    }
    // Para cuando la lista está vacia
    else
    {
        cout << "Nada que borrar" << endl;
    }
}
/**
 * @param head Variable puntero nulo.
 * @param temp Variable puntero que hace referencia a la direccion de memoria que está guardada en 'head'.
 */
int main()
{
    Node *head = nullptr; // Se crea un puntero de tipo Nodo vacio.
    int data, choise, position, filter, new_value;
    do
    {
        cout << "OPCIONES: " << endl;
        cout << "0. CreateOne: Para crear una dato al final de la fila" << endl;
        cout << "1. createInPosition: Para insetar un dato en una posicion" << endl;
        cout << "2. ReadOne: Para leer y mostar el indice de los datos segun el dato" << endl;
        cout << "3. ReadAll: Para leer todos los datos de la lista" << endl;
        cout << "4. UpdateOne: Para actualizar el valor segun la poscion" << endl;
        cout << "5. UpdateFirts: Para actualizar el valor del primer dato encontrado segun el filtro" << endl;
        cout << "6. UpdateAll: Para actualizar todos los valores seguna el filtro a un nuevo valor" << endl;
        cout << "7. DeleteOne: Para eliminar un valor segun la posicion" << endl;
        cout << "8. DeleteFirts: Para eliminar el valor del primer dato encontrado segun el filtro " << endl;
        cout << "9. DeleteAll: Para eliminar todos los valores seguna el filtro" << endl;
        cin >> choise;
        // Switch que maneja las posibles opciones
        switch (choise)
        {
        case 0:
            cout << "Valor a ingresar: ";
            cin >> data;
            createOne(head, data);
            break;

        case 1:
            cout << "Valor a ingresar: ";
            cin >> data;
            cout << "Posicion: ";
            cin >> position;
            createInPosition(data, head, position);
            break;
        case 2:
            cout << "Dato a buscar: ";
            cin >> data;
            readOne(data, head);
            break;
        case 3:
            readAll(head);
            break;
        case 4:
            cout << "Dato a actualizar: ";
            cin >> data;
            cout << "Posicion de la lista para actualizar: ";
            cin >> position;
            updateOne(head, data, position);
            break;
        case 5:
            cout << "Datos que va a reemplezar: ";
            cin >> filter;
            cout << "Dato por el cual va a reemplazar: ";
            cin >> new_value;
            updateFirts(head, new_value, filter);
            break;
        case 6:
            cout << "Datos que va a reemplezar: ";
            cin >> filter;
            cout << "Datos por el cual va a reemplazar: ";
            cin >> new_value;
            updateAll(head, new_value, filter);
            break;
        case 7:
            cout << "Dato a eliminar: ";
            cin >> filter;
            cout << "Posicion: ";
            cin >> position;
            deleteOne(head, filter, position);
            break;
        case 8:
            cout << "Dato a eliminar: ";
            cin >> data;
            deleteFirts(head, data);
            break;
        case 9:
            cout << "Datos a eliminar: ";
            cin >> data;
            deleteAll(head, data);
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }

        cout << "\nOpciones: \n"
             << "0:Finalizar 1:Seguir" << endl;
        cin >> choise;
        // system("cls");
    } while (choise == 1);

    // Incio de impresion.
    cout << "Lista final: " << endl;
    // Se llama a la lista readAll, y se pasa el parametro head.
    readAll(head);
    // Ciclo While que se ejecuta siempre y cuando 'head' sea diferente a nullptr.
    /*while (head != nullptr)
         {
             // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
             Node *temp = head;
             // Se actualiza el valor de 'head' al siguiente espacio en memoria del siguiente Nodo..
             head = head->next;
             // Se libera la memoria, segun 'temp'.
             delete temp;
         }*/
    system("PAUSE");
    return 0;
}
