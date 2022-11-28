#include<stdio.h>
#include<stdlib.h>

void createFood();
void createSnake();
void createSnakeHead();
void createSnakeBody();
void createSnakeTail();
void moveSnake(char canvas[5][5]);
void updateSnake(char);
int score=0;
int turn=1;
int simbol = 1;

struct Snake{
    int x;
    int y;
    char symbol;
    struct Snake *next;
}*head=NULL,*tail=NULL;

struct Food{
    int x;
    int y;
    char symbol;
}food;

struct Meteor{
    int x;
    int y;
    char symbol;
}meteor;

void createSnakeHead()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    s->symbol='H';
    s->x=2;
    s->y=4;
    s->next=NULL;
    head=s;
}

void createSnakeBody()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    struct Snake *temp=head;
    s->symbol='O';
    s->x=2;
    s->y=3;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=s;
    s->next=NULL;
}

void createSnakeTail()
{
    struct Snake *s=(struct Snake*) malloc(sizeof(struct Snake));
    struct Snake *temp=head;
    s->symbol='C';
    s->x=2;
    s->y=2;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=s;
    s->next=NULL;
    tail=s;
}

void createSnake()
{
    createSnakeHead();
    createSnakeBody();
    createSnakeTail();
}

void createFood()
{
    food.x=0;
    food.y=2;
    food.symbol='o';
}

void createMeteor()
{
    meteor.x=3;
    meteor.y=4;
    meteor.symbol='m';
}

void displaySnake()
{
    struct Snake *temp=head;

    while(temp!=NULL){
        printf("%c",temp->symbol);
        temp=temp->next;
    }
    printf("%c",food.symbol);
    printf("%c",meteor.symbol);
}

void updateCanvas(char canvas[5][5])
{   
    if (turn>1){
    printf("\n\nBerhasil bergerak!");
    }
    canvas[food.x][food.y]=food.symbol;
    canvas[meteor.x][meteor.y]=meteor.symbol;
    struct Snake *temp=head;

    while(temp!=NULL){
        canvas[temp->x][temp->y]=temp->symbol;
        temp=temp->next;
    }
}

void createCanvas(char canvas[5][5])
{   
    int i,j;
    for(i=0;i<5;i++){

        for(j=0;j<5;j++){
            canvas[i][j]='.';
            //printf("%c ",canvas[i][j]);
        }
       // printf("\n");
    }
}

void printcanvas(char canvas[5][5])
{   
    printf("Berikut merupakan peta permainan:\n");
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            //canvas[i][j]='.';
            printf("%c ",canvas[i][j]);
        }
        printf("\n");
    }
    printf("Turn %d\n",turn);
}

int getXOfSnakeHead()
{
    struct Snake *temp=head;
    return temp->x;
}

int getYofSnakeHead()
{
    struct Snake *temp=head;
    return temp->y;
}

void updateSnake(char dir)
{
    int x,y;
    x=getXOfSnakeHead();
    y=getYofSnakeHead();

    if(dir=='w'){

        x=x-1;  //up

        if(x<0){
            x=4;
        }
    }
    else if(dir=='a'){
        y=y-1;  //left

        if(y<0){
            y=4;
        }
    }
    else if(dir=='s'){
        x=x+1;  //down

        if(x>4){
            x=0;
        }
    }
    else if(dir=='d'){
        y=y+1;  //right

        if(y>4){
            y=0;
        }
    }
    else{
        return;
    }
    //shifting values of snake clockwise once
    //using stacks.
    int r[225],top=-1,c[255];
    struct Snake *temp=head;

    while(temp!=NULL){
        top++;
        r[top]=temp->x;
        c[top]=temp->y;
        temp=temp->next;
    }
    int i=0;
    struct Snake *temp1=head;
    temp1->x=x;
    temp1->y=y;
    temp1=temp1->next;

    while(temp1!=NULL){
        temp1->x=r[i];
        temp1->y=c[i];
        i++;
        temp1=temp1->next;
    }

}

int checkFoodEaten()
{
    struct Snake *s=head;

    if((s->x==food.x) && (s->y==food.y)){
        return 1;
    }
    else{
        return 0;
    }
}

int checkMeteorHead()
{
    struct Snake *s=head;

    if((s->x==meteor.x) && (s->y==meteor.y)){
        return 1;
    }
    else{
        return 0;
    }
}

void increaseSnakeLength(char dir)
{
    struct Snake *s=tail;
    struct Snake *n=(struct Snake*) malloc(sizeof(struct Snake));
    n->x=s->x;
    n->y=s->y;
    n->symbol='C';
    n->next=NULL;
    s->next=n;
    s->symbol=simbol;
    tail=n;
}

char directionCheck(char dir,char user)
{
    if(dir=='a' && user=='d'){
        return dir;
    }
    if(dir=='d' && user=='a'){
        return dir;
    }
    if(dir=='s' && user=='w'){
        return dir;
    }
    if(dir=='w' && user=='s'){
        return dir;
    }
    return user;
}

void changeFoodLocation()
{
    struct Snake *temp=head;
    int r[5]={0}, c[5]={0},i=0;

    while(temp!=NULL){
        r[temp->x]=1;
        c[temp->y]=1;
        temp=temp->next;
    }
    while((r[food.x]!=0) && (c[food.y]!=0)){
        food.x=rand()%4;
        food.y=rand()%4;
    }

}

void changeMeteorLocation()
{
    struct Snake *temp=head;
    int r[5]={0}, c[5]={0},i=0;

    while(temp!=NULL){
        r[temp->x]=1;
        c[temp->y]=1;
        temp=temp->next;
    }
    while((r[meteor.x]!=0) && (c[meteor.y]!=0)){
        meteor.x=rand()%4;
        meteor.y=rand()%4;
    }

}

int checkBodyTouch()
{
    struct Snake *temp=head;
    int xOfHead=temp->x;
    int yofHead=temp->y;
    temp=temp->next;
    while(temp!=NULL){

        if((temp->x==xOfHead) && (temp->y==yofHead)){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void moveSnake(char canvas[5][5])
{
    int n=100;
    char dir='a';  
    char dirCheck;
    while(1){
        turn+=1;
        printf("Silahkan masukkan command anda: ");
        scanf("%c",&dirCheck);
        while(getchar() != '\n');
        dir=directionCheck(dir,dirCheck);
        updateSnake(dir);
        int hasFoodBeenEaten=checkFoodEaten();
        int hasMeteorHead = checkMeteorHead();

        if(hasFoodBeenEaten){
            increaseSnakeLength(dir);
            changeFoodLocation();
            score+=2;
            simbol+=1;
        }

        int hasBodyTouched=checkBodyTouch();
        if(hasBodyTouched || hasMeteorHead)
        {   
            printf("\nScore akhir: %d\n", score);
            printf("\n------------\nGame Over!!!\n------------\n");
            break;
        }
        createCanvas(canvas);
        updateCanvas(canvas);
        printf("\n");
        printcanvas(canvas);
        changeMeteorLocation();
    }
}

int main()
{   
    char canvas[5][5];
    createCanvas(canvas);
    createSnake();
    createFood();
    createMeteor();
    //printcanvas(canvas);
    updateCanvas(canvas);
    printcanvas(canvas);
    moveSnake(canvas);
    return 0;
}
