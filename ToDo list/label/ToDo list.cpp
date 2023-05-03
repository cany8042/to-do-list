#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>
#include <locale.h>


using namespace std;

int ID;
//пользовательский тип todo, который содержит два поля id и task  
struct todo 
{
    setlocale(LC_ALL, "Russian");
    int id;
    string task;
};

//этот метод используется для добавления новой задачи в список задач 
void addtodo()
{

    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                    WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task); //получить пользовательский ввод
    ID++; //увеличить идентификатор для текущей задачи


    //теперь запишите эту задачу в todo.txt файл
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task;
    write.close();

    //запишите идентификатор в новый файл, чтобы мы могли использовать этот
    //идентификатор позже для добавления новой задачи 
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "Do you want to add more task? y/n" << endl;
    cin >> ch;

    //если пользователь хочет снова добавить новую задачу,
    //то вызовите ту же функцию, иначе верните 
    if (ch == 'y') {
        addtodo();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// этот метод используется для вывода задачи на экран
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//Этот метод используется для чтения данных из todo.txt 
//создайте файл и распечатайте его на экране
void readData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t------------------Your current Tasks in the list--------------------";
    //  пока мы не дойдем до конца файла, продолжайте выводить данные на экран
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

//этот метод используется для поиска конкретной задачи из todo.txt файл 
int searchData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    //пока мы не доходим до конца сохранения файла или поиска идентификатора,
    //соответствующего идентификатору пользовательского ввода 
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

// этот метод используется для удаления задачи из todo.txt файл
void deleteData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        //пока мы не дошли до конца файла, продолжайте
        //искать идентификатор для удаления задачи 
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

//этот метод используется для обновления задачи 
//здесь мы создаем новый temp.txt файл и добавьте все обновленные данные в этот файл
// после обновления мы удаляем оригинал todo.txt а затем переименуйте этот файл в todo.txt
void updateData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchData();
    cout << "\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        // пока мы не дойдем до конца файла, продолжайте поиск идентификатора и,
        //как только найдете, обновите новыми данными 
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}
int main()
{
    system("cls");
    system("Color E0"); //"Цвет XY", X - цвет фона, Y - цвет текстаr
    system("title todoapp @copyassignment");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1.Add student data";
        cout << "\n\t2.See student data";
        cout << "\n\t3.Search student data";
        cout << "\n\t4.Delete student data";
        cout << "\n\t5.Update student data";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}

