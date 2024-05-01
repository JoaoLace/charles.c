#include "../lib/charles.h"

int main (){
    srand(time(0));
    Charles::set_config(1000,1000,30,50,200);
    Charles::run();
    return 0;
}
