#include "keeper.h"
#include "group.h"

int task_flag, swap_flag, action_flag, ind, group_ind, stud_ind;

int choose_task();
void menu_task1();
int menu();

int main(void){

    std::string f_name, str, first, second;   
    std::ifstream file;

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
    std::cout << "8 - Display best students\n";
    std::cout << "0 - Exit\n";
    std::cin >> action_flag;
    return action_flag;
}

void menu_task1(){

    Keeper<group>* groups = new Keeper<group>;
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
            try{
                if (groups->getCount() != 0){
                    std::cout << "Choose group:\n";
                    for (int i = 1; i < groups->getCount() + 1; i++){
                        std::cout << i << " - Group " << (*groups)[i].get_numb() << "\n";
                    }
                    std::cout << "Insert number: ";
                    std::cin >> group_ind;
                    (*groups)[group_ind].addStudent();
                    (*groups)[group_ind].count_GPA();
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 3:
            system("cls");
            try{
                if (groups->getCount() != 0){
                    std::cout << "Choose group you want to delete:\n";
                    for (int i = 1; i < groups->getCount() + 1; i++){
                        std::cout << i << " - Group " << (*groups)[i].get_numb() << "\n";
                    }
                    std::cout << "Insert number: ";
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
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 4:
            system("cls");
            try{
                if (groups->getCount() != 0){
                    std::cout << "Choose group:\n";
                    for (int i = 1; i < groups->getCount() + 1; i++){
                        std::cout << i << " - Group " << (*groups)[i].get_numb() << "\n";
                    }     
                            std::cout << "Insert number: ";
                            std::cin >> group_ind;
                    try{
                        if((*groups)[group_ind].empStudent() != 0){
                            system("cls");
                            (*groups)[group_ind].getData();
                            std::cout << "Insert number of student: ";
                            std::cin >> stud_ind;
                            try{
                                if (stud_ind <= (*groups)[group_ind].empStudent()){
                                    (*groups)[group_ind].delStudent(stud_ind);
                                    (*groups)[group_ind].count_GPA();
                                }
                                else
                                    throw std::string{"Number is outside the list\n"};
                                }
                            catch(std::string mes){
                                std::cout << mes;
                            }
                        }
                        else
                            throw std::string{"Students list is empty\n"};
                    }
                    catch(std::string mes){
                        std::cout << mes;
                    } 
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            } 
            system("pause");
            system("cls");
            menu();
            break;
        case 5:
            system("cls");
            try{
                if (groups->getCount() != 0){
                    std::cout << "Choose group:\n";
                    for (int i = 1; i < groups->getCount() + 1; i++){
                        std::cout << i << " - Group " << (*groups)[i].get_numb() << "\n";
                    }
                    std::cout << "Insert number: ";
                    std::cin >> group_ind;
                    group_ = new group();
                    system("cls");
                    groups->editElement(group_ind, group_);
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 6:
            system("cls");
            try{
                if (groups->getCount() != 0){
                    std::cout << "Choose group:\n";
                    for (int i = 1; i < groups->getCount() + 1; i++){
                        std::cout << i << " - Group " << (*groups)[i].get_numb() << "\n";
                    }     
                            std::cout << "Insert number: ";
                            std::cin >> group_ind;
                    try{
                        if((*groups)[group_ind].empStudent() != 0){
                            system("cls");
                            (*groups)[group_ind].getData();
                            std::cout << "Insert number of student: ";
                            std::cin >> stud_ind;
                            try{
                                if (stud_ind <= (*groups)[group_ind].empStudent()){
                                    system("cls");
                                    (*groups)[group_ind].editStudent(stud_ind);
                                    (*groups)[group_ind].count_GPA();
                                }
                                else
                                    throw std::string{"Number is outside the list\n"};
                                }
                            catch(std::string mes){
                                std::cout << mes;
                            }
                        }
                        else
                            throw std::string{"Students list is empty\n"};
                    }
                    catch(std::string mes){
                        std::cout << mes;
            } 
                }
                else
                    throw std::string{"Group list is empty\n"};
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
            try{
                if (groups->getCount() != 0){
                    groups->display();
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 8:
            system("cls");
            try{
                if (groups->getCount() != 0){
                    groups->showBest();
                }
                else
                    throw std::string{"Group list is empty\n"};
            }
            catch(std::string mes){
                std::cout << mes;
            }
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
