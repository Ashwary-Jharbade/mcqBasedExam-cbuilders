#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>

struct question{
    int qid;
    char stack[10];
    char q[100];
    char a[10];
    char b[10];
    char c[10];
    char d[10];
    char cor;
};
struct question *qa;
int qs[10];
int frq=0;
int testsheet[10];

int count=0;
void addquestion()
{
    system("cls");
    if(count==0)
    {
        qa=(struct question *)malloc((count+1)*sizeof(struct question));
    }
    count++;
    qa=(struct question *)realloc(qa,(count)*sizeof(struct question));
    qa[count-1].qid=count;
    printf("Enter Technology\n");
    getchar();
    gets(qa[count-1].stack);
    printf("Enter Question\n");
    gets(qa[count-1].q);
    printf("Enter Option a\n");
    gets(qa[count-1].a);
    printf("Enter Option b\n");
    gets(qa[count-1].b);
    printf("Enter Option c\n");
    gets(qa[count-1].c);
    printf("Enter Option d\n");
    gets(qa[count-1].d);
    printf("Enter Correct Option:\n");
    scanf("%c",&qa[count-1].cor);
}

int viewset()
{
    system("cls");
    int i;
    int x;
    for(i=0;i<count;i++)
    {
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Question id:%d          Stack:%s\n",qa[i].qid,qa[i].stack);
        printf("%s\n",qa[i].q);
    }
    printf("Enter question id to enter it in test stack or 0 to go back:\n");
    scanf("%d",&x);
    return x;
}

void setque(int id)
{
    if(frq<10)
    {
        qs[frq]=id;
        frq++;
    }
    else{
        printf("Question limit exceeded\n");
        printf("Enter 1 to continue\n");
        int x;
        scanf("%d",&x);
    }
}
void nullify()
{
    int i;
    for(i=0;i<10;i++)
    {
        testsheet[i]=0;
    }
}
int starttest()
{
    nullify();
    if(frq==10)
    {
        int x;
        int i;
        int c;
        char ch;
        i=0;
        while(1)
        {
            system("cls");
            if(i==10)
            {
                i=0;
            }
            if(i==-1)
            {
                i=9;
            }
            int id=qs[i];
            printf("___________________________________________\n");
            printf("%d)%s\n",i+1,qa[id-1].q);
            printf("a)  %s\n",qa[id-1].a);
            printf("b)  %s\n",qa[id-1].b);
            printf("c)  %s\n",qa[id-1].c);
            printf("d)  %s\n",qa[id-1].d);
            printf("Enter answer:\n");
            getchar();
            scanf("%c",&ch);
            if(ch==qa[id-1].cor){
                testsheet[i]=2;
            }
            else{
                testsheet[i]=0;
            }
            printf("Enter 1 to continue,2 to go to previous question and 0 to submit the test:\n");
            scanf("%d",&c);
            if(c==0){
                break;
            }
            else if(c==2)
            {
                i--;
            }
            else{
                i++;
            }
        }
    }
    else{
        printf("Insufficent no of question to start a test.\n");
        printf("Enter 0 to go back\n");
        getch();
    }
}
void blueprint(int x)
{
    system("cls");
    int i;
    int id;
    if(x)
    {
       printf("\t\tBLUEPRINT(Each question carry 2 marks)\t\t\n");
    }
    else{
       printf("\t\tTEST(Each question carry 2 marks)\t\t\n");
    }
    printf("**********************************************************\n");
    for(i=0;i<frq;i++)
    {
        id=qs[i];
        printf("___________________________________________\n");
        printf("%d)%s\n",i+1,qa[id-1].q);
        printf("Stack:%s\n",qa[id-1].stack);
        printf("a)  %s\n",qa[id-1].a);
        printf("b)  %s\n",qa[id-1].b);
        printf("c)  %s\n",qa[id-1].c);
        printf("d)  %s\n",qa[id-1].d);

    }
    printf("**********************************************************\n");
    if(x){
        printf("Enter 1 to continue\n");
        getch();
    }
}

void viewsheet()
{
    system("cls");
    printf("\t\tLAST TEST LOGS\n");
    int i=0;
    int sum=0;
    int id;
    if(frq==10)
    {

    }
    else{
        printf("Test Sheet is empty\n");
        printf("Enter 1 to continue\n");
        getch();
        return;
    }
    for(i=0;i<10;i++)
    {
            id=qs[i];
            printf("Que %d) %s\n",i+1,qa[id-1].q);
            printf("Correct answer:%c\n",qa[id-1].cor);
            printf("score:%d\n",testsheet[i]);
            sum=sum+testsheet[i];
    }
    printf("Total test Score:%d\n",sum);
    printf("Note:Take screenshot of the logs it may not be available in future.\n");
    printf("Enter 1 to continue:");
    getch();
}
void clearquestions()
{
    frq=0;
}
int main()
{
    int choice=1;
    int x;

    while(choice)
    {
        int id;
        system("cls");
        printf("1)Add Questions\n2)Clear question set\n3)Check blueprint of test\n4)Take test\n5)View Question Set\n6)View last test sheet\nEnter one of the above choices:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addquestion();
                break;
            case 2:
                clearquestions();
                break;
            case 3:
                blueprint(1);
                break;
            case 4:
                x=starttest();
                break;
            case 5:
                id=viewset();
                setque(id);
                break;
            case 6:
                viewsheet();
                break;
            default:
                if(choice)
                {
                    printf("wrong choice!\n");
                }
                else{
                    printf("Program  terminated\n");
                }
            }
        }
}
