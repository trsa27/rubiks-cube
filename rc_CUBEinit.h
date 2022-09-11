#include "rc_oneFace.h"

/*  vision 1, acef direction
         a
         |
b    -   c   -   d        
         |
         e
         |
         f
*/
/*  vision 2, bcdf direction
         a
         |
b    -   c   -   d    -    f        
         |
         e
*/
/*  vision 3, adef direction
         a
         |
c    -   d   -   f        
         |
         e
         |
         b
*/

class cube{

    one_face a{'a'};
    one_face b{'b'};
    one_face c{'c'};
    one_face d{'d'};
    one_face e{'e'};
    one_face f{'f'};
    public:
        cube(){
            // a.set_one_face('a'); b.set_one_face('b');
            // c.set_one_face('c'); d.set_one_face('d');
            // e.set_one_face('e'); f.set_one_face('f');
        }

        void printCube_v1(){
            putchar('\n');
                a.print_face_WHOLE('\t', '\n');
            putchar('\n');
                b.print_face_N('\0', '\t');
                c.print_face_N('\0', '\t');
                d.print_face_N('\0', '\n');

                b.print_face_WE('\0', '\t');
                c.print_face_WE('\0', '\t');
                d.print_face_WE('\0', '\n');

                b.print_face_S('\0', '\t');  
                c.print_face_S('\0', '\t');
                d.print_face_S('\0', '\n');
            putchar('\n');
                e.print_face_WHOLE('\t', '\n');
            putchar('\n');
                f.print_face_WHOLE('\t', '\n');
        }
        // void printCube_v2(){
        //  
        // }
        // void printCube_v3(){}
        void swap_acef_at_b_side(){
            b.swap_clkwise();
            char temp_NW, temp_W, temp_SW;

            char next_NW, next_W, next_SW;
            //  temp = a.w
            a.get_W_side(&temp_NW, &temp_W, &temp_SW);
            //  next = f.w
            f.get_W_side(&next_NW, &next_W, &next_SW);
            //  a.w = f.w(next)
            a.set_W_side(next_NW, next_W, next_SW);
                    // printf("\nstep 1:\n");
                    // printCube_v1();
            
            e.get_W_side(&next_NW, &next_W, &next_SW);
            //  f.w = e.w
            f.set_W_side(next_NW, next_W, next_SW);
                    // printf("\nstep 2:\n");
                    // printCube_v1();
            
            c.get_W_side(&next_NW, &next_W, &next_SW);
            //  e.w = c.w
            e.set_W_side(next_NW, next_W, next_SW);
                    // printf("\nstep 3:\n");
                    // printCube_v1();
            //  c.w = a_temp
            c.set_W_side(temp_NW, temp_W, temp_SW);
                    // printf("\nstep 4:\n");
                    // printCube_v1();
        }
        void swap_acef_at_d_side(){
            d.swap_anti_clkwise();
            char temp_NE, temp_E, temp_SE;

            char next_NE, next_E, next_SE;
            //  temp = a.e
            a.get_E_side(&temp_NE, &temp_E, &temp_SE);
            //  next = f.e
            f.get_E_side(&next_NE, &next_E, &next_SE);
            //  a.e = f.e(next)
            a.set_E_side(next_NE, next_E, next_SE);
                    // printf("\nstep 1:\n");
                    // printCube_v1();
            
            e.get_E_side(&next_NE, &next_E, &next_SE);
            //  f.e = e.e
            f.set_E_side(next_NE, next_E, next_SE);
                    // printf("\nstep 2:\n");
                    // printCube_v1();
            
            c.get_E_side(&next_NE, &next_E, &next_SE);
            //  e.e = c.e
            e.set_E_side(next_NE, next_E, next_SE);
                    // printf("\nstep 3:\n");
                    // printCube_v1();
            //  c.e = a_temp
            c.set_E_side(temp_NE, temp_E, temp_SE);
                    // printf("\nstep 4:\n");
                    // printCube_v1();
        }
        //      v2
        void swap_bcdf_at_a_side(){
            a.swap_anti_clkwise();
            char temp_SW, temp_S, temp_SE;

            char next_NW, next_N, next_NE;
            //  temp = f
            f.get_S_side(&temp_SW, &temp_S, &temp_SE);
            //  next = d
            d.get_N_side(&next_NW, &next_N, &next_NE);
            //  f = d
            f.set_S_side(next_NE, next_N, next_NW);

            //  d = c
            c.get_N_side(&next_NW, &next_N, &next_NE);
            d.set_N_side(next_NW, next_N, next_NE);

            //  c = b
            b.get_N_side(&next_NW, &next_N, &next_NE);
            c.set_N_side(next_NW, next_N, next_NE);

            //b = temp
            b.set_N_side(temp_SE, temp_S, temp_SW);
        }
        void swap_bcdf_at_e_side(){
            e.swap_clkwise();
            char temp_NW, temp_N, temp_NE;

            char next_SW, next_S, next_SE;
            //  temp = f
            f.get_N_side(&temp_NW, &temp_N, &temp_NE);
            //  next = d
            d.get_S_side(&next_SW, &next_S, &next_SE);
            //  f = d
            f.set_N_side(next_SE, next_S, next_SW);

            //  d = c
            c.get_S_side(&next_SW, &next_S, &next_SE);
            d.set_S_side(next_SW, next_S, next_SE);

            //  c = b
            b.get_S_side(&next_SW, &next_S, &next_SE);
            c.set_S_side(next_SW, next_S, next_SE);

            //b = temp
            b.set_S_side(temp_NE, temp_N, temp_NW);
        }
        //      v3
        void swap_adeb_at_c_side(){
            c.swap_clkwise();
            char temp_1, temp_2, temp_3;
            char next_1, next_2, next_3;

            //  temp = a
            //  get_N_side(char* new_NW, char* new_N, char* new_NE)
            //  get_W_side(char* new_NW, char* new_W, char* new_SW)
            //  get_S_side(char* new_SW, char* new_S, char* new_SE)
            //  get_E_side(char* new_NE, char* new_E, char* new_SE)
            b.get_E_side(&temp_1, &temp_2, &temp_3 );//   ne, e, se

            e.get_N_side(&next_1, &next_2, &next_3);//   nw, e, ne
            b.set_E_side(next_1, next_2, next_3);// b->E = e->N

            d.get_W_side(&next_3, &next_2, &next_1);//  nw, w, sw
            e.set_N_side(next_1, next_2, next_3);// e = d

            a.get_S_side(&next_1, &next_2, &next_3);//  sw, s, se
            d.set_W_side(next_1, next_2, next_3);// d = a

            a.set_S_side(temp_3, temp_2, temp_1);
        }
        void swap_adeb_at_f_side(){
            f.swap_anti_clkwise();
            char temp_1, temp_2, temp_3;
            char next_1, next_2, next_3;
            b.get_W_side(&temp_1, &temp_2, &temp_3);//nw,w,sw

            e.get_S_side(&next_1, &next_2, &next_3);//sw, s, se
            b.set_W_side(next_1, next_2, next_3);// b = e

            d.get_E_side(&next_1, &next_2,&next_3);// ne, e, se
            e.set_S_side(next_3, next_2, next_1);// e = d

            a.get_N_side(&next_1, &next_2, &next_3);
            d.set_E_side(next_1, next_2, next_3);

            a.set_N_side(temp_3, temp_2, temp_1);

        }
};