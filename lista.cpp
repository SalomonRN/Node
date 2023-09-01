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
    // / Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
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
    // Ciclo para recorrer la lista siempre y cuando 'current' no sea nullptr (Para recorrer de inicio a fin la lista).
    while (current != nullptr)
    {
        // Se imprime el valor de 'current.data'
        cout << current->data << " ";
        // Se actualiza la varaible 'current' a la direccion en memoria del siguiente nodo guardado en 'current.next'.
        current = current->next;
    }
}
/**
 * Funcion para actualizar un valor en la posicion 
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] value  Posicion de la lista donde se actualizará el dato.
 * @param [in] position Posicion de la lista en la que se va a insertar el dato.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 * 
*/
void updateOne(Node *&head, int value, int position)
{
    Node *current = head;
    int i = 0;
    if (current != NULL) //
    {

        while (true)
        {
            if (i == position)
            {

                current->data = value;
                break;
            }
            current = current->next;
            i++;
        }
    }
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 *
 */
void updateFirts(Node *&head, int new_value, int value)
{
    Node *current = head;
    // 6 actualizar
    // 1 2 3
    //       *
    if (head != NULL)
    {
        while (current->next != nullptr && current->data != value)
        {
            current = current->next;
        }
        if (current->next == nullptr)
        {
            cout << "VALOR NO ENCONTRADO" << endl;
        }
        else
        {
            current->data = new_value;
        }
    }
    else
    {
        cout << "Nada que actualizar" << endl;
    }
}
/**
 *
 */
void updateAll(Node *&head, int new_value, int value)
{
    Node *current = head;
    if (current != NULL) //
    {

        while (current != NULL)
        {
            if (value == current->data)
            {

                current->data = new_value;
            }
            current = current->next;
        }
    }
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 * QUE PASA SI ELIMINO LA CABEZA?
 */
void deleteOne(Node *&head, int value, int position)
{

    Node *current = head;
    Node *past = NULL;
    int i = 1;
    bool band = true;
    // 5 DELETE
    //     *
    // 5 8 5 2 1
    // 1 2 3 4 5
    while (true) // EN VEZ DE TRUE PONER --current->next == nullptr
    {            //         5               5        1       3
        if (current->data == value && position == i && current != NULL)
        {
            // 5
            past->next = current->next;
            delete current;
            band = false;
            cout << "Valor eliminado " << endl;
            break;
        }

        // 8
        past = current;
        // 5
        current = current->next;
        i++;
        if (current->next == nullptr)
        {
            break;
        }
    }
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
void deleteFirts(Node *&head, int value)
{
    Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
    Node *past = NULL;    // // Se crea un nuevo Node 'past' para guardar el Nodo anterior.

    // Validacion para saber si la lista está vacia.
    if (head != NULL)
    {
        // Ciclo while para recorrer la lista siempre y cuando no se llegue al final (current != NULL) o cuando el valor actual de 'current.data' no coincida con 'value' (current->data != value)
        while (current != NULL && current->data != value)
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
        }
        // Para cuando el valor se encuentra, pero no está en la primera posicon
        else
        {
            past->next = current->next; // El nodo pasado apuntará ahora a donde apunta 'current'
            delete current;             // Se libera la memoria de 'current'
        }
    }
    // Impresion cuando la lista está vacia
    else
    {
        cout << "Nada que borrar" << endl;
    }
}
/**
 * QUE PASA SI ELIMINO LA CABEZA?
 */
void deleteAll(Node *&head, int value)
{
    Node *current = head;
    Node *past = NULL;

    if (head != NULL)
    {
        while (current != nullptr)
        {

            // LA CABEZA TIENE UN DATO A BORRAR
            if (current->data == value && head == current)
            {
                head = head->next;
                delete current;
                current = head;
            }
            else
            {
                if (current->data == value)
                {
                    past->next = current->next;
                    delete current;
                    current = past;
                }

                past = current;
                current = current->next;
            }
        }
    }
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
    Node *head = nullptr;
    int data, choise, position, value, new_value;
    do
    {
        cout << "Opciones: "
             << "\n 0: CreateOne --- 1: Creare n Posicion ---  2:ReadOne --- 3:ReadAll --- 4:UpdateOne --- 5:UpdateFirts --- 6:UpdateAll  ---7: deleteOne "
             << "8: Delete Firts 9: DeleteAll" << endl;
        cin >> choise;

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
            cout << "Posicion del dato: ";
            cin >> position;
            updateOne(head, data, position);
            break;
        case 5:
            cout << "Que dato va actualizar: ";
            cin >> value;
            cout << "A que dato a actualizar: ";
            cin >> new_value;
            updateFirts(head, new_value, value);
            break;
        case 6:
            cout << "Que dato va actualizar: ";
            cin >> value;
            cout << "A que dato a actualizar: ";
            cin >> new_value;
            updateAll(head, new_value, value);
            break;
        case 7:
            cout << "Dato a eliminar: ";
            cin >> data;
            cout << "Posicion: ";
            cin >> position;
            deleteOne(head, data, position);
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

        cout << "\n Opciones: \n"
             << "0:Finalizar 1:Seguir" << endl;
        cin >> choise;

    } while (choise == 1);

    // Se crea un puntero de tipo Nodo vacio.

    // Se llama a la funcion 'createOne()' y se pasan de parametros el puntero 'head' y el valor que sea desea guardar en la lista. (El tipo de valor se define en la estrcutura Node).

    // Incio de impresion.
    cout << "Lista de punteros: ";
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
