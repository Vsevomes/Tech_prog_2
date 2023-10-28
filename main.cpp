#include "header.h"

int task_flag, swap_flag;

int choose_task();

int main(void){

    std::string f_name, str, first, second;
    std::istringstream str_(str);
    std::ifstream file("task2.txt");

    choose_task();
    while(task_flag != 0){
        switch (task_flag){
        case 1:
            system("cls");
            /* code */
            system("pause");
            system("cls");
            choose_task();
            break;
        case 2:  
            system("cls");
            /*while(getline(file, str)){
                //std::cout << str;
                swap_flag = 0;
                while(std::cin >> str){
                    if (swap_flag == 0){
                        std::cin >> first;
                        swap_flag ++; 
                    }
                    else if(swap_flag == 1){
                        std::cin >> second;
                        std::cout << second << " " << first << " ";
                        swap_flag --;
                    }
                }
                if (swap_flag == 1){
                    std::cout << first;
                }
                std::cout << "\n";
            }*/
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