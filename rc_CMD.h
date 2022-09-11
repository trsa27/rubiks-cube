#include "rc_CUBEinit.h"
typedef void (*FUNC_ARRAY)(void);
int controller(){
        cube newCube;
        
        int choice = 0;
    while(1){
        newCube.printCube_v1();
        printf(
                "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                "\t\trubic's cube\n"
                "\t1.direction a->c->e->f(->a) @ B\n"
                "\t2.direction a->c->e->f(->a) @ D\n"
                "\t3.direction b->c->d->f(->b) @ A\n"
                "\t4.direction b->c->d->f(->b) @ E\n"
                "\t5.direction a->d->e->b(->a) @ C\n"
                "\t6.direction a->d->e->b(->a) @ F\n"
                "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                "\t>>>>>"
                );

        if( scanf("%d", &choice)    ){
            switch(choice){
                case 1:
                    newCube.swap_acef_at_b_side();
                        break ;
                case 2:
                    newCube.swap_acef_at_d_side();
                        break ;
                case 3:
                    newCube.swap_bcdf_at_a_side();
                        break ;
                case 4:
                    newCube.swap_bcdf_at_e_side();
                        break ;
                case 5:
                    newCube.swap_adeb_at_c_side();
                        break ;
                case 6:
                    newCube.swap_adeb_at_f_side();
                        break ;
                default:
                    printf("\nwrong input, please try again\n");
                        break;
                    }
                }else{
                    getchar();getchar();    //catch grapage char
                }
        }

        return 1;
}