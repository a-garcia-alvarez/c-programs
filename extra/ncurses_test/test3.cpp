#include <ncurses.h>

int main()
{
    int ch;

    initscr();                      /* Inicia el modo curses            */
    raw();                          /* Desactiva buffer de linea        */
    keypad(stdscr, TRUE);           /* Obtener F1, F2 etc..d            */
    noecho();                       /* Sin echo() al hacer getch        */

    do{
    raw();
    printw( "pulse cualquier caracter para verlo remarcado\n"
            "o pulse F10 para salir");
    ch = getch();                   /* Si no ha llamado a raw() tenemos
                                     * que pulsar enter antes que que
                                     * que llegue al programa           */
    if(ch == KEY_F(1))              /* sin habilitar keypad esto no     */
        printw("F1 Key pressed");     /* llegara a nosotros               */
                                      /* Sin noecho() algunos feos
                                       * caracteres de escape podrian ser
                                       * impresos en pantalla             */
    else
    {
        if(ch == KEY_F(10)){
            printw("Pulse cualquier tecla para salir ");
        }
        else{
            printw("La tecla pulsada es ");
            attron(A_BOLD); // atribute on BOLD
            printw("%c", ch);
            attroff(A_BOLD); // disable A_BOLD atttribute
        }
    }

    wrefresh(stdscr);                      /* Imprime stdscr en la pantalla real      */
    halfdelay(20);
    getch();
    clear();
    }while(ch!=KEY_F(10));
    endwin();
    return 0;

}
