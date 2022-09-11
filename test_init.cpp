#include "rc_CUBEinit.h"

main(){
    cube newCube;
    newCube.printCube_v1();

    newCube.swap_acef_at_b_side();
    printf("=================================\n");
    newCube.printCube_v1();
    newCube.swap_acef_at_d_side();
    printf("=================================\n");
    newCube.printCube_v1();

    newCube.swap_bcdf_at_a_side();
    printf("\n\n=================================\n");
    newCube.printCube_v1();
    
    newCube.swap_bcdf_at_e_side();
    printf("=================================\n");
    newCube.printCube_v1();
    
    newCube.swap_adeb_at_c_side();
    printf("\n\n=================================\n");
    newCube.printCube_v1();
    
    newCube.swap_adeb_at_f_side();
    printf("=================================\n");
    newCube.printCube_v1();
    

}