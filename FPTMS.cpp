#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>

using namespace std;
struct Task
{
    string description;
    bool completed;
    int priority;
    string date;
};

const int MAX_TASKS = 100;
Task tasks[MAX_TASKS];
int taskCount = 0;

struct Node
{
    Task task;
    Node *next;
};

Node *head, *tail, *cur, *newNode, *del, *before;

void credit()
{
    std::system("cls");
    std::cout << "-------------------------------------------------" << endl;
    std::cout << "|                     CREDIT                    |" << endl;
    std::cout << "|~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ GROUP 2 ~ ~ ~ ~ ~ ~ ~ ~ ~|" << endl;
    std::cout << "|                    23 BCI 01                  |" << endl;
    std::cout << "-------------------------------------------------" << endl;
    std::cout << "|1. ANWAR FAUZI           |     23.61.0251      |" << endl;
    std::cout << "|2. ULIL ABSOR            |     23.61.0259      |" << endl;
    std::cout << "|3. SATRIA IRFAN PRAYOGA  |     23.61.0266      |" << endl;
    std::cout << "-------------------------------------------------" << endl;
    std::system("pause");
}

int countSLL()
{
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void createTask()
{
    system("cls");
    Task task;
    cout << "INPUT TASK DESC                     : ";
    cin.ignore(); // clear the input buffer
    getline(cin, task.description);
    task.completed = false;
    cout << "INPUT TASK PRIORITY (1-HIGH, 5-LOW) : ";
    cin >> task.priority;
    
    cin.ignore(100, '\n');
    cout << "INPUT TASK DUE DATE (DD/MM/YYYY)    : ";
    getline(cin, task.date);

    if (!task.date.empty())
    {
        Node *newNode = new Node;
        newNode->task = task;
        newNode->next = head;
        head = newNode;
        system("cls");
        cout << "TASK ALREADY ADDED !\n";
        system("pause");
    }
    else
    {
        Node *newNode = new Node;
        newNode->task = task;
        newNode->next = head;
        head = newNode;
        system("cls");
        cout << "TASK ALREADY ADDED !\n";
        system("pause");
    }
}

void showTasks()
{
    system("cls");
    std::cout << "|=================================================================================================================================|" << std::endl;
    std::cout << "|~                                                         TASK LIST                                                             ~|" << std::endl;
    std::cout << "|=================================================================================================================================|" << std::endl;
    std::cout << "|" << std::setw(25) << "TASK DESCRIPTION" << std::setw(25) << "|"
              << std::setw(15) << "STATUS" << std::setw(15) << "|"
              << std::setw(10) << "PRIORITY" << std::setw(10) << "|"
              << std::setw(15) << "DATE" << std::setw(15) << "|" << std::endl;
    std::cout << "|=================================================================================================================================|" << std::endl;

    Node *curr = head;
    while (curr != NULL)
    {
        cout << "|" << std::setw(25) << curr->task.description << std::setw(25) << "|"
             << std::setw(15) << (curr->task.completed ? "Selesai" : "Belum Selesai") << std::setw(15) << "|"
             << std::setw(10) << curr->task.priority << std::setw(10) << "|"
             << std::setw(15) << curr->task.date << std::setw(15) << "|" << endl;
        ;
        curr = curr->next;
    }
    std::cout << "|=================================================================================================================================|" << std::endl
              << std::endl;
    system("pause");
}

void searchTask()
{
    cin.ignore(); // To clear the input buffer
    string taskNumber;
    cout << "Masukkan deskripsi tugas yang ingin dicari: ";
    getline(cin, taskNumber);

    Node *curr = head;
    while (curr != NULL && curr->task.description != taskNumber)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
    }
    else
    {
        cout << "Tugas ditemukan: " << curr->task.description << " (Prioritas: " << curr->task.priority << ", " << (curr->task.completed ? "Selesai" : "Belum Selesai") << ", " << "Tenggat: " << curr->task.date << ")\n";
    }
    system("pause");
}

void changeTaskName()
{
    cin.ignore(); // clear the input buffer
    string oldName, newName;
    cout << "Masukkan deskripsi tugas yang ingin diubah namanya: ";
    getline(cin, oldName);

    Node *curr = head;
    while (curr != NULL && curr->task.description != oldName)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
    }
    else
    {
        cout << "Masukkan nama baru untuk tugas: ";
        getline(cin, newName);
        curr->task.description = newName;
        cout << "Nama tugas berhasil diubah!\n";
    }
    system("pause");
}

void changeMark()
{
    cin.ignore();
    string taskNumber;
    cout << "Masukkan deskripsi tugas yang ingin ditandai selesai: ";
    getline(cin, taskNumber);

    Node *curr = head;
    while (curr != NULL && curr->task.description != taskNumber)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
        return;
    }

    curr->task.completed = true;
    cout << "Tugas " << taskNumber << " berhasil ditandai selesai!\n";
    system("pause");
}

void changeTaskPriority()
{
    string taskDescription;
    cout << "Masukkan deskripsi tugas yang ingin diubah prioritasnya: ";
    getline(cin, taskDescription);

    Node *curr = head;
    while (curr != NULL && curr->task.description != taskDescription)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
        return;
    }

    int newPriority;
    cout << "Masukkan prioritas baru (1-tinggi, 5-rendah): ";
    cin >> newPriority;
    cin.ignore();

    if (newPriority < 1 || newPriority > 5)
    {
        cout << "Prioritas tidak valid.\n";
        return;
    }

    curr->task.priority = newPriority;
    cout << "Prioritas tugas " << taskDescription << " berhasil diubah!\n";
}

void changeDate()
{
    string taskDescription;
    cout << "Masukkan deskripsi tugas yang ingin diubah tenggatnya : ";
    getline(cin, taskDescription);

    Node *curr = head;
    while (curr != NULL && curr->task.description != taskDescription)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
        return;
    }

    string newDate;
    cout << "Masukkan tanggal baru (DD/MM/YYYY)" << endl;
    cin >> newDate;
    cin.ignore();

    curr->task.date = newDate;
    cout << "Tenggat tugas " << taskDescription << " berhasil diubah!\n";
}

void sortTasksAscending()
{
    if (head == NULL || head->next == NULL)
    {
        return; // No need to sort if list has 0 or 1 elements
    }

    Node *sorted = NULL;  // Sorted list
    Node *current = head; // Current node to be inserted

    while (current != NULL)
    {
        Node *next = current->next; // Store next node

        // Insert current node into sorted list
        if (sorted == NULL || sorted->task.description >= current->task.description)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *traverse = sorted;
            while (traverse->next != NULL && traverse->next->task.description < current->task.description)
            {
                traverse = traverse->next;
            }
            current->next = traverse->next;
            traverse->next = current;
        }

        current = next; // Move to next node
    }

    head = sorted; // Update head of sorted list
    system("cls");
    cout << "Tugas berhasil di sorting!" << endl;
    system("pause");
}

void sortTasksDescending()
{
    if (head == NULL || head->next == NULL)
    {
        return; // No need to sort if list has 0 or 1 elements
    }

    Node *sorted = NULL;  // Sorted list
    Node *current = head; // Current node to be inserted

    while (current != NULL)
    {
        Node *next = current->next; // Store next node

        // Insert current node into sorted list
        if (sorted == NULL || sorted->task.description <= current->task.description)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *traverse = sorted;
            while (traverse->next != NULL && traverse->next->task.description > current->task.description)
            {
                traverse = traverse->next;
            }
            current->next = traverse->next;
            traverse->next = current;
        }

        current = next; // Move to next node
    }

    head = sorted; // Update head of sorted list
    system("cls");
    cout << "Tugas berhasil di sorting!" << endl;
    system("pause");
}

void deleteTask()
{
    cin.ignore(); // clear the input buffer
    string taskDescription;
    cout << "Masukkan deskripsi tugas yang ingin dihapus: ";
    getline(cin, taskDescription);

    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL && curr->task.description != taskDescription)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Tugas tidak ditemukan.\n";
    }
    else
    {
        if (prev == NULL)
        {
            head = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
        cout << "Tugas " << taskDescription << " berhasil dihapus!\n";
    }
    system("pause");
}

void wrongInput()
{
    std::system("cls");
    std::cout << "WARNING : Invalid input !, try to input the right choices" << endl;
    std::system("pause");
}

void noTask()
{
    system("cls");
    std::cout << "You don't have any Task on here" << endl;
    std::cout << "Please, try to add some task" << endl;
    std::system("pause");
}

int main()
{
menu:
    int pil;
    std::system("cls");
    std::cout << "-------------------------------------------------" << endl;
    std::cout << "|                                               |" << endl;
    std::cout << "|~    WELCOME TO THE TASK MANAGEMENT PROGRAM   ~|" << endl;
    std::cout << "|                                               |" << endl;
    std::cout << "-------------------------------------------------" << endl;
    std::cout << "|1. CREATE TASK                                 |" << endl;
    std::cout << "|2. UPDATE TASK                                 |" << endl;
    std::cout << "|3. DISPLAY TASK                                |" << endl;
    std::cout << "|4. REMOVE TASK                                 |" << endl;
    std::cout << "|5. CREDIT                                      |" << endl;
    std::cout << "|6. EXIT                                        |" << endl;
    std::cout << "-------------------------------------------------" << endl;
    std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
    std::cout << "-------------------------------------------------" << endl;
    cin >> pil;
    switch (pil)
    {
    case 1:
    // PILIHAN MENU CREATE
    create:
        int pilC;
        std::system("cls");
        std::cout << "-------------------------------------------------" << endl;
        std::cout << "|~                CREATE MENU                  ~|" << endl;
        std::cout << "-------------------------------------------------" << endl;
        std::cout << "|1. CREATE TASK                                 |" << endl;
        std::cout << "|2. BACK TO MAIN MENU                           |" << endl;
        std::cout << "-------------------------------------------------" << endl;
        std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
        std::cout << "-------------------------------------------------" << endl;
        cin >> pilC;
        switch (pilC)
        {
        case 1:
            createTask();
            goto create;
            break;
        case 2:
            goto menu;
            break;
        default:
            wrongInput();
            goto create;
            break;
        }
        break;
    case 2:
        // PILIHAN MENU UPDATE
        if (head == NULL)
        {
            noTask();
            goto menu;
        }
        else
        {
        update:
            int pilU;
            std::system("cls");
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|~                UPDATE MENU                  ~|" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|1. CHANGE MARK                                 |" << endl;
            std::cout << "|2. CHANGE TASK                                 |" << endl;
            std::cout << "|3. CHANGE DUE DATE                             |" << endl;
            std::cout << "|4. BACK TO MAIN MENU                           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            cin >> pilU;
            switch (pilU)
            {
            case 1:
                changeMark();
                goto update;
                break;
            case 2:
                changeTaskName();
                goto update;
                break;
            case 3:
                changeDate();
                goto update;
                break;
            case 4:
                goto menu;
                break;
            default:
                wrongInput();
                goto update;
                break;
            }
        }
        break;
    case 3:
        // PILIHAN MENU DISPLAY
        if (head == NULL)
        {
            noTask();
            goto menu;
        }
        else
        {
        display:
            int pilD;
            std::system("cls");
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|~                DISPLAY MENU                 ~|" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|1. SHOW TASK                                   |" << endl;
            std::cout << "|2. SEARCHING TASK                              |" << endl;
            std::cout << "|3. SORTING TASK                                |" << endl;
            std::cout << "|4. BACK TO MAIN MENU                           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            cin >> pilD;
            switch (pilD)
            {
            case 1:
                showTasks();
                goto display;
                break;
            case 2:
                searchTask();
                goto display;
                break;
            case 3:
            sort:
                int sorts;
                std::system("cls");
                std::cout << "-------------------------------------------------" << endl;
                std::cout << "|~                SORTING MENU                 ~|" << endl;
                std::cout << "-------------------------------------------------" << endl;
                std::cout << "|1. FORWARD ORDER                               |" << endl;
                std::cout << "|2. REVERSE ORDER                               |" << endl;
                std::cout << "|3. BACK TO DISPLAY MENU                        |" << endl;
                std::cout << "|4. BACK TO MAIN MENU                           |" << endl;
                std::cout << "-------------------------------------------------" << endl;
                std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
                std::cout << "-------------------------------------------------" << endl;
                cin >> sorts;
                switch (sorts)
                {
                case 1:
                    sortTasksAscending();
                    goto display;
                    break;
                case 2:
                    sortTasksDescending();
                    goto display;
                    break;
                case 3:
                    goto display;
                    break;
                case 4:
                    goto menu;
                    break;
                default:
                    wrongInput();
                    goto sort;
                    break;
                }
                break;
            case 4:
                goto menu;
                break;
            default:
                goto display;
                break;
            }
        }
        break;
    case 4:
        // PILIHAN MENU REMOVE
        if (head == NULL)
        {
            noTask();
            goto menu;
        }
        else
        {
        remove:
            int pilR;
            system("cls");
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|~                REMOVE MENU                  ~|" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|1. REMOVE TASK                                 |" << endl;
            std::cout << "|2. BACK TO MAIN MENU                           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            std::cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
            std::cout << "-------------------------------------------------" << endl;
            cin >> pilR;
            switch (pilR)
            {
            case 1:
                deleteTask();
                goto remove;
                break;
            case 2:
                goto menu;
                break;
            default:
                wrongInput();
                goto remove;
                break;
            }
        }
        break;
    case 5:
        // PILIHAN MENU CREDIT
        credit();
        goto menu;
        break;
    case 6:
        // PILIHAN MENU EXIT
        std::system("cls");
        char exited;
        std::cout << "Are You Sure Wanna Exit From This Program ?" << endl;
        std::cout << "Your List of Task will be Lost" << endl;
        std::cout << "(Y/T)" << endl;
        cin >> exited;
        std::system("cls");
        if (exited == 'y' || exited == 'Y')
        {
            std::cout << "THANK YOU FOR USING THIS PROGRAM !" << endl;
            std::cout << "Have a Nice Day ! ( > 3 < ) " << endl;
            std::system("exit");
        }
        else if (exited == 't' || exited == 'T')
        {
            goto menu;
        }
        else
        {
            wrongInput();
        }
        break;
    default:
        // DEFAULT SYSTEM
        wrongInput();
        goto menu;
        break;
    }
    return 0;
}