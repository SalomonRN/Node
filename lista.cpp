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
void create(Node *&head, int value)
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

void read(int value, Node *head)
{
    Node *current = head;
    int i = 0;
    bool band = true;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "Valor encontrado posicion: "
                 << i << endl;
            band = false;
        }
        current = current->next;
        i++;
    }
    if (band)
    {
        cout << "Valor no encontrado " << endl;
    }
}

void createInPosition(int value, Node *&head, int position) // 0
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
        Node *current = head;
        int i = 0;
        if (position != -1) // 
        {

            while (true)
            {
                // 1  3
                if (i == position)
                {
                    newNode->next = current->next;
                    current->next = newNode;
                    break;
                }
                current = current->next;
                i++;
            }
        }
        else
        {
            cout << "\n 0" << endl;
            newNode->next = head;
            head = newNode;
        }
    }
}

void deleteData(Node *&head, int value, int position)
{
    Node *current = head;
    Node *past = NULL;
    int i = 1;
    bool band = true;
    // 5 DELETE
    //     *
    // 5 8 5 2 1
    // 1 2 3 4 5
    while (true)
    { //         5               5         3       3
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

void deleteFirts(Node *&head, int value)
{
    Node *current = head;
    Node *past = NULL;

    if (head != NULL)
    {
        while ((current != NULL) && (current->data != value))
        {
            past = current;
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "No" << endl;
        }
        else if (past == NULL)
        {
            head = head->next;
            delete current;
        }
        else
        {
            past->next = current->next;
            delete current;
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
    int data, choise, position; // crud
    do
    {
        cout << "Opciones: "
             << "\n 0: Create --- 1: Creare n Posicion ---  2:Read --- 3:Update --- 4:Delete --- 5: Delete Position" << endl;
        cin >> choise;

        switch (choise)
        {
        case 0:
            cout << "Valor a ingresar: ";
            cin >> data;
            create(head, data);
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
            read(data, head);
            break;

        case 3:
            cout << "Dato a actualizar: ";
            cin >> data;
            cout << "Posicion del dato: ";
            cin >> position;
            break;
        case 4:
            cout << "Dato a eliminar: ";
            cin >> data;
            deleteFirts(head, data);
            break;
        case 5:
            cout << "Dato a eliminar: ";
            cin >> data;
            cout << "Posicion: ";
            cin >> position;
            deleteData(head, data, position);
            break;
        case 6:
            printList(head);
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

    // Se llama a la funcion 'create()' y se pasan de parametros el puntero 'head' y el valor que sea desea guardar en la lista. (El tipo de valor se define en la estrcutura Node).

    // Incio de impresion.
    cout << "Lista de punteros: ";
    // Se llama a la lista printList, y se pasa el parametro head.
    printList(head);

    // Liberar la memoria.
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
