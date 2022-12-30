#ifndef COLOR_H_INCLUDED
#define COLOR_h_INCLUDED





#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLACK "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[1;0m"
#define BLUE  "\033[1;34m"
#define CYAN  "\033[1;36m"
#define PURPLE "\033[1;35m"
//color
void reset(){

    system("");
    printf(RESET);

}
void blue(){

    system("");
    printf(BLUE);

}

void cyan(){

    system("");
    printf(CYAN);
}

void purple(){

    system("");
    printf(PURPLE);

}
void yellow(){

    system("");
    printf(YELLOW);

}
void red(){

    system("");
    printf(RED);
}
void green(){

    system("");
    printf(GREEN);
}
void black(){

    system("");
    printf(BLACK);
}
#endif // COLOR_H_INCLUDED
