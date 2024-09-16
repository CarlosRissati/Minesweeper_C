#include <stdio.h>
#include <stdlib.h>
#define X 10
#define Y 10

typedef struct Node{
    int data_x;
    int data_y;
    struct Node* next;
}Node;

void add(Node** tail, Node** head, int data_x, int data_y){
    Node* novo = (Node*)malloc(sizeof(Node));

    novo->data_x = data_x;
    novo->data_y = data_y;
    novo->next = NULL;

    if((*tail) == NULL){
        (*tail) = novo;
        (*head) = (*tail);
    }else{
        (*tail)->next = novo;
        (*tail) = novo;
    }
}

void del(Node** head){
    if((*head) == NULL){
        printf("sem elementos na lista.\n");
    }else{
        if((*head)->next != NULL){
            Node* aux = (*head);
            (*head) = aux->next;
            free(aux);
        }else{
            Node* aux = (*head);
            (*head) = NULL;
            free(aux);
        }
    }
}

void show(Node** head){
    Node* aux = (*head);
    while(aux != NULL){
        printf("%d:%d ", aux->data_x, aux->data_y);
        aux = aux->next;
    }
    printf("\n");
}

void delAll(Node** head, Node** tail){
    if((*head == NULL) || (*tail == NULL)){
        printf("sem elementos na lista.\n");
    }else{
        Node* aux = (*head);
        while((*head)->next != NULL){
            (*head) = aux->next;
            free(aux);
            aux = (*head);
        }
        (*tail) = NULL;
        aux = (*head);
        (*head) = NULL;
        free(aux);
    }
}

void abrir_campo(char mine[X][Y], int x, int y, char numeros_char[X][Y]){
    // int terminou = 0;
    Node* head = NULL;
    Node* tail = NULL;

    add(&tail, &head, x, y);
    while(head != NULL){
        printf("Entrei no while\n");
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int checkX = i + head->data_x;
                int checkY = j + head->data_y;
                if(checkX >= 0 && checkX < X && checkY >= 0 && checkY < Y){
                    if(mine[checkX][checkY] == 'X'){
                        mine[checkX][checkY] = ' ';
                        if(numeros_char[checkX][checkY] == ' '){
                            add(&tail, &head, checkX, checkY);
                        }
                    }
                }
            }
        }
        del(&head);
    }
}

int contar_minas(int minas[X][Y]){
    int cont = 0;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            if(minas[i][j] == 1){
                cont++;
            }
        }
    }
    return cont;
}

void printar_numeros(int numeros[X][Y], char numeros_char[X][Y]){
    printf("\n");
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            switch (numeros[i][j])
            {
            case -1:
                // printf("X ");
                numeros_char[i][j] = 'x';
                break;
            case 0:
                // printf("  ");
                numeros_char[i][j] = ' ';
                break;
            case 1:
                // printf("\033[1;36m1\033[0m ");
                numeros_char[i][j] = '1';
                break;
            case 2:
                // printf("\033[1;32m2\033[0m ");
                numeros_char[i][j] = '2';
                break;
            case 3:
                // printf("\033[1;31m3\033[0m ");
                numeros_char[i][j] = '3';
                break;
            case 4:
                // printf("\033[1;34m4\033[0m ");
                numeros_char[i][j] = '4';
                break;
            case 5:
                // printf("\033[1;35m5\033[0m ");
                numeros_char[i][j] = '5';
                break;
            case 6:
                // printf("\033[1;33m6\033[0m ");
                numeros_char[i][j] = '6';
                break;
            case 7:
                // printf("\033[1;37m7\033[0m ");
                numeros_char[i][j] = '7';
                break;
            case 8:
                // printf("\033[1;30m8\033[0m ");
                numeros_char[i][j] = '8';
                break;
            }
        }
        // printf("\n");
    }
}

void printar_campo(char mine[X][Y], int x, int y, char numeros_char[X][Y]){
    // mine[x][y] = numeros_char[x][y];
    printf("\n\n");
    printf("  ");
    for(int i = 0; i < Y; i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < X; i++){
        printf("%d ", i);
        for(int j = 0; j < Y; j++){
            if(mine[i][j] == ' '){
                switch (numeros_char[i][j])
                {
                case 'x':
                    printf("\033[1;30mX\033[0m ");
                    // numeros_char[i][j] = 'X';
                    break;
                case ' ':
                    printf("  ");
                    // numeros_char[i][j] = ' ';
                    break;
                case '1':
                    printf("\033[1;36m1\033[0m ");
                    // numeros_char[i][j] = '1';
                    break;
                case '2':
                    printf("\033[1;32m2\033[0m ");
                    // numeros_char[i][j] = '2';
                    break;
                case '3':
                    printf("\033[1;31m3\033[0m ");
                    // numeros_char[i][j] = '3';
                    break;
                case '4':
                    printf("\033[1;34m4\033[0m ");
                    // numeros_char[i][j] = '4';
                    break;
                case '5':
                    printf("\033[1;35m5\033[0m ");
                    // numeros_char[i][j] = '5';
                    break;
                case '6':
                    printf("\033[1;33m6\033[0m ");
                    // numeros_char[i][j] = '6';
                    break;
                case '7':
                    printf("\033[1;37m7\033[0m ");
                    // numeros_char[i][j] = '7';
                    break;
                case '8':
                    printf("\033[1;30m8\033[0m ");
                    // numeros_char[i][j] = '8';
                    break;
                default:
                    printf("%c ", mine[i][j]);
                    break;
                }
            }else{
                printf("%c ", mine[i][j]);
            }
        }
        printf("\n");
    }
}

int tem_minas(int x){
    if(x == 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char mine[X][Y]; // Variavel matriz do campo, é o que será printado
    // Printa
    printf("  ");
    for(int i = 0; i < Y; i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < X; i++){
        printf("%d ", i);
        for(int j = 0; j < Y; j++){
            mine[i][j] = 'X';
            printf("%c ", mine[i][j]);
        }
        printf("\n");
    }
    int input_X;
    int input_Y;
    int minas[X][Y] = { {1,0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,1,0,0,0,0,0}};
    int numeros[X][Y];
    char numeros_char[X][Y];

    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            int cont_minas = 0;
            if(i - 1 >= 0 && j - 1 >= 0){//cima-esquerda
                cont_minas += tem_minas(minas[i-1][j-1]);
            }
            if(i-1 >= 0){//cima
                cont_minas += tem_minas(minas[i-1][j]);
            }
            if(i-1 >= 0 && j+1 < Y){//cima-direita
                cont_minas += tem_minas(minas[i-1][j+1]);
            }
            if(j-1 >= 0){//esquerda
                cont_minas += tem_minas(minas[i][j-1]);
            }
            if(j+1 < Y){//direita
                cont_minas += tem_minas(minas[i][j+1]);
            }
            if(i+1 < X && j-1 >= 0){//baixo-esquerda
                cont_minas += tem_minas(minas[i+1][j-1]);
            }
            if(i+1 < X){//baixo
                cont_minas += tem_minas(minas[i+1][j]);
            }
            if(i+1 < X && j+1 < Y){//baixo-direita
                cont_minas += tem_minas(minas[i+1][j+1]);
            }
            numeros[i][j] = cont_minas;
            if(tem_minas(minas[i][j]) == 1){//verificar se a celula atual é uma bomba.
                numeros[i][j] = -1;
            }
            // printf("%d ", numeros[i][j]);
            cont_minas = 0;
        }
        // printf("\n");
    }
    //mostra na tela os números coloridos, e faz um parse da array int numeros para char numeros_char
    printar_numeros(numeros, numeros_char);

    // printf("Matriz numeros_char\n");
    // for(int i = 0; i < X; i++){
    //     for(int j = 0; j < Y; j++){
    //         printf("%c ", numeros_char[i][j]);
    //     }
    //     printf("\n");
    // }


    int total_minas = contar_minas(minas);
    while(input_X != -1){
        printf("Digite uma coordenada no formato (X:Y)\n");
        fflush(stdin);
        scanf("%d:%d", &input_X, &input_Y);
        printf("\n%d:%d\n", input_X, input_Y);
        mine[input_X][input_Y] = ' ';
        if(numeros_char[input_X][input_Y] == 'x'){
            printf("\nPERDEU");
            break;
        }
        if(numeros_char[input_X][input_Y] == ' '){
            printf("entrei em abrir campo\n\n");
            abrir_campo(mine, input_X, input_Y, numeros_char);
        }
        printar_campo(mine, input_X, input_Y, numeros_char);
    }
    return 0;
}