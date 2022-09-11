#include <cstdio>
#include <cstdlib>
//eswn

class one_face{
    char NW, N, NE, 
         W, CEN, E,
         SW, S, SE;    
    public:
        //  normal cube
        one_face(char color){
            NW = N = NE = 
            W = CEN = E =
            SW = S = SE = color;
        }
        void set_one_face(char color){
            NW = N = NE = 
            W = CEN = E =
            SW = S = SE = color;
        }
        //  enigma
        void setEnigma(char new_NW, char new_N, char new_NE,
                    char new_W, char new_CEN, char new_E,
                    char new_SW, char new_S, char new_SE){
            NW = new_NW; N = new_N; NE = new_NE;
            W = new_W; CEN = new_CEN; E = new_E;
            SW = new_SW; S = new_S; SE = new_SE;
        }
    /*      NW <- N <- NE
            |           ^
            v           |
            W     o     E
            |           ^
            v           |
            SW -> S -> SE
            ...........
    */
        void swap_anti_clkwise(){
            char temp = NW;

            NW = NE;
            NE = SE;
            SE = SW;
            SW = temp;

                temp = N;
            N = E;
            E = S;
            S = W;
            W = temp;

        }
        void swap_clkwise(){
            char temp = NW;

            NW = SW;
            SW = SE;
            SE = NE;
            NE = temp;
                temp = N;
            N = W;
            W = S;
            S = E;
            E = temp;
        }

        void print_face_WHOLE(char ltf_spacing_1, char rgh_spacing_1){
            printf("%c%c %c %c%c", ltf_spacing_1, NW, N, NE, rgh_spacing_1);
            printf("%c%c %c %c%c", ltf_spacing_1, W, CEN, E, rgh_spacing_1);
            printf("%c%c %c %c%c", ltf_spacing_1, SW, S, SE, rgh_spacing_1);
        }
        void print_face_N(char ltf_spacing_1, char rgh_spacing_1){
            printf("%c%c %c %c%c", ltf_spacing_1, NW, N, NE, rgh_spacing_1);
        }
        void print_face_WE(char ltf_spacing_1, char rgh_spacing_1){
            printf("%c%c %c %c%c", ltf_spacing_1, W, CEN, E, rgh_spacing_1);
        }
        void print_face_S(char ltf_spacing_1, char rgh_spacing_1){

            printf("%c%c %c %c%c", ltf_spacing_1, SW, S, SE, rgh_spacing_1);
        }
            
        void set_N_side(char new_NW, char new_N, char new_NE){
            NW = new_NW; N = new_N; NE = new_NE;
        }
        void set_W_side(char new_NW, char new_W, char new_SW){
            NW = new_NW; W = new_W; SW = new_SW;
        }
        void set_S_side(char new_SW, char new_S, char new_SE){
            SW = new_SW; S = new_S; SE = new_SE;
        }
        void set_E_side(char new_NE, char new_E, char new_SE){
            NE = new_NE; E = new_E; SE = new_SE;
        }

        void get_N_side(char* new_NW, char* new_N, char* new_NE){
            *new_NW = NW; *new_N = N; *new_NE = NE;
        }
        void get_W_side(char* new_NW, char* new_W, char* new_SW){
            *new_NW = NW; *new_W = W; *new_SW = SW;
        }
        void get_S_side(char* new_SW, char* new_S, char* new_SE){
            *new_SW = SW; *new_S = S; *new_SE = SE;
        }
        void get_E_side(char* new_NE, char* new_E, char* new_SE){
            *new_NE = NE; *new_E = E; *new_SE = SE;
        }

};

