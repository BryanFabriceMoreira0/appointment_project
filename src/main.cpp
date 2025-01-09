#include <iostream>
#include "Database.h"

int main(){
    std::cout << "Hello, from appointment_project!\n";

    Database &db = Database::GetInstance();
}
