#include "header.h"

int task_flag, swap_flag;

int choose_task();

int main(void){

    std::string f_name, str, first, second;   
    std::ifstream file;
    //int size;

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


/* возможный способ  ввода предметов для класса
            std::cout << "Input str\n";
            std::cin.ignore();
            getline(std::cin, str);
            size = std::count(str.begin(), str.end(), ' ') + 1;
            std::cout << str << " " << size;
*/