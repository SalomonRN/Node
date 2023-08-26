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
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo. ()
 */
void append(Node *&head, int value)
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
 * Función para imprimir la lista
 * @param [in] head Puntero que hace referencia al espacio de memoria del primer nodo.
 * @param current Puntero que guarda el espacio de memoria de 'head'.
 *
 */
void printList(Node *head)
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
 * @param head Variable puntero nulo.
 * @param temp Variable puntero que hace referencia a la direccion de memoria que está guardada en 'head'.
 */
int main()
{
    // Se crea un puntero de tipo Nodo vacio.
    Node *head = nullptr;
    // Se llama a la funcion 'append()' y se pasan de parametros el puntero 'head' y el valor que sea desea guardar en la lista. (El tipo de valor se define en la estrcutura Node).
    append(head, 1);
    append(head, 3);
    append(head, 2);
    append(head, 3);
    append(head, 845614);
    append(head, 5);

    // Incio de impresion.
    cout << "Lista de punteros: ";
    // Se llama a la lista printList, y se pasa el parametro head.
    printList(head);

    // Liberar la memoria.
    // Ciclo While que se ejecuta siempre y cuando 'head' sea diferente a nullptr.
    while (head != nullptr)
    {
        // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
        Node *temp = head;
        // Se actualiza el valor de 'head' al siguiente espacio en memoria del siguiente Nodo..
        head = head->next;
        // Se libera la memoria, segun 'temp'.
        delete temp;
    }
    system("PAUSE");
    return 0;
}
