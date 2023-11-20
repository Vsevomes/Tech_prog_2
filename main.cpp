#include "keeper.h"
#include "group.h"

int task_flag, swap_flag, action_flag, ind;

int choose_task();
void menu_task1();

int main(void){

    std::string f_name, str, first, second;   
    std::ifstream file;
    //int size;

    choose_task();
    while(task_flag != 0){
        switch (task_flag){
        case 1:
            system("cls");
            menu_task1();
            system("pause");
            system("cls");
            choose_task();
            break;
        case 2:  
            system("cls");
            std::cout << "Input file name: ";
            std::cin >> f_name;
            file.open(f_name);
            try{
                if (!file.is_open()){
                    throw std::string{"Error opening file\n"};
                }
            }
            catch(std::string mes){
                std::cout << mes;
            }

            while (getline(file, str)) {
                std::istringstream ss(str);
                size_t count = 0;
                swap_flag = 0;
                for (; ss >> str; count++){
                    if (swap_flag == 0){
                        first = str;
                        swap_flag = 1;
                    }
                    else{
                        second = str;
                        std::cout << second << " " << first << " ";
                        swap_flag = 0;
                    }
                }
                
                if (swap_flag == 1){
                    std::cout << first;
                }
                std::cout << "\n";
            }

            file.close();

            system("pause");
            system("cls");
            choose_task();
            break;
        
        default:
            system("cls");
            std::cout << "Wrong type\n";
            system("pause");
            system("cls");
            choose_task();
            break;
        }
    }

    file.close();

    return 0;
}

int choose_task(){
    std::cout << "Choose task:\n";
    std::cout << "1 - First task\n";
    std::cout << "2 - Second task\n";
    std::cout << "0 - Exit\n";
    std::cin >> task_flag;
    return task_flag;
}

int menu(){
    std::cout << "Select an action:\n";
    std::cout << "1 - Add group\n";
    std::cout << "2 - Add student\n";
    std::cout << "3 - Delete group\n";
    std::cout << "4 - Delete student\n";
    std::cout << "5 - Edit group\n";
    std::cout << "6 - Edit student\n";
    std::cout << "7 - Display all\n";
    std::cout << "0 - Exit\n";
    std::cin >> action_flag;
    return action_flag;
}

void menu_task1(){

    Keeper<group>* groups;
    group* group_;
    Student* student_;

    menu();
    while(action_flag != 0){
        switch (action_flag){
        case 1:
            system("cls");
            group_ = new group();
            system("cls");
            group_->setData();   
            groups->add(group_);
            if (groups->getCount() > 1){
                groups->sort();
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 2:  
            system("cls");
            std::cout << "Choose group number:\n";
            for (int i = 0; i < groups->getCount(); i++){
                std::cout << (*groups)[i].get_numb() << "\n";
            }
            if (std::cin)
            system("pause");
            system("cls");
            menu();
            break;
        case 3:
            system("cls");
            std::cout << "Insert number of element which you wnat to delete: ";
                std::cin >> ind;
                try{
                    if (ind <= groups->getCount())
                        groups->remove(ind);
                    else
                        throw std::string{"Number is outside the list\n"};
                }
                catch(std::string mes){
                    std::cout << mes;
                }
            system("pause");
            system("cls");
            menu();
            break;
        case 7:
            system("cls");
            groups->display();
            system("pause");
            system("cls");
            menu();
            break;
        default:
            system("cls");
            std::cout << "Wrong type\n";
            system("pause");
            system("cls");
            menu();
            break;
        }
    }
}

// Keeper<Group>* keep = new Keeper<Group>;
//     Group* group = new Group;

//     group->setData();
//     keep->addElement(group);

//     group = new Group;
//     group->setData();
//     keep->addElement(group);

//     keep->sortirovka();
//     keep->displayKeep();