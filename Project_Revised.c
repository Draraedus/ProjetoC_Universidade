#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct 
{
    int enrollment_number;
    float first_grade;
    float second_grade;
    float third_grade;
    float fourth_grade;
    char name[40];
    int class_code; 
    int attendance;
} discipline;

discipline class[30];

void ProjectMenu()
{

    printf("Digite o numero da operacao a ser executada:\n
    1 para cadastrar aluno\n
    2 para remover aluno\n
    3 para update dados de um aluno\n
    4 para listar alunos cadastrados\n
    5 para listar alunos aprovados\n
    6 para listar alunos reprovados por media\n
    7 para listar alunos reprovados por faltas\n
    8 para sair\n
    9 para reiniciar o menu\n");


    scanf("%i", &i);

    switch(i) 
    {
        case 1:
        system("cls"); 
        Registration();
        break;

        case 2:
        system("cls");
        auxmenu_remove();
        break;

        case 3:
        system("cls");
        auxmenu_update();
        break;

        case 4:
        system("cls");
        List_all_students();
        break;

        case 5:
        system("cls");
        List_approved_students();
        break;

        case 6:
        system("cls");
        List_disapproved_fromaverage_students();
        break;

        case 7:
        system("cls");
        List_disapproved_fromabsence_students();
        break;

        case 8:
        return;

        case 9:
        system("cls");
        printf("Reiniciado com sucesso!");
        ProjectMenu();
        break;

        default:
        printf("ERR: Valor inválido, por favor digite novamente.");
        system("cls");
        ProjectMenu();
        break;
    }
}

int Registration()
{   
    int temp_enrollment_number, counter=0; 
    printf("digite a matrícula do aluno\n");

    scanf("%i", &temp_enrollment_number);
    if(temp_enrollment_number > 2021099 || temp_enrollment_number < 2021000)
    {
        printf("Número Inválido de Matrícula, Por favor digite novamente:\n");
        system("cls");
        Registration();
        return 0;
    }
        
    for(int i = 0; i<30; i++)
    {
        if( temp_enrollment_number == class[i].enrollment_number) 
        {
            printf("ERRO: já existe um aluno com essa matricula\n\n");
            submenu_Registration();
            return 0;
        }
        if(class[i].enrollment_number!=0) 
        {
            counter+;
        }
    }
    if(counter=30) 
    {
        printf("ERRO: Turma cheia.\n\n");
        submenu_Registration();
        return 0;
    }

    for(int i=0; i<30; i++)
    {
        if(class[i].enrollment_number==0)
        {
            class[i].enrollment_number= temp_enrollment_number;

            first_grade: 
            printf("Digite a primeira nota:\n");
            scanf("%f", &class[i].first_grade);
            if(class[i].first_grade>10 || class[i].first_grade < 0)
            {
                printf("ERRO: Primeira nota com valor inválido, digite novamente:\n");
                goto first_grade;    
            }

            second_grade:
            printf("Digite a segunda nota:\n");
            scanf("%f", &class[i].second_grade);
            if(class[i].second_grade>10 || class[i].second_grade < 0)
            {
                printf("ERRO: Segunda nota com valor inválido, digite novamente:\n");
                goto second_grade;   
            }

            third_grade:
            printf("Digite a terceira nota:\n");
            scanf("%f", &class[i].third_grade);
            if(class[i].third_grade>10 || class[i].third_grade < 0)
            {
                printf("ERRO: Terceira nota com valor inválido, digite novamente:\n");
                goto third_grade;    
            }

            fourth_grade:
            printf("Digite a quarta nota:\n");
            scanf("%f", &class[i].fourth_grade);
            if(class[i].fourth_grade>10 || class[i].fourth_grade < 0)
            {
                printf("ERRO: Quarta nota com valor inválido, digite novamente:\n");
                goto fourth_grade;   
            }
            
            printf("Digite o name do aluno:\n");
            getchar();
            gets(class[i].name);

            printf("Digite o código da turma:\n");
            scanf("%i", &class[i].class_code);
            
            faltas:
            printf("Número de faltas do aluno:\n");
            scanf("%i", &class[i].attendance);
            if(class[i].attendance>36 || class[i].attendance < 0)
            {
                printf("ERRO: Número de faltas com valor inválido, digite novamente:\n");
                goto faltas;   
            }

             temp_enrollment_number=0;
            submenu_Registration();
            return 0;
        }
    }
}

int submenu_Registration() 
{
    int i;
    printf("Registration finalizado !\nDigite 1 para continuar cadastrando.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");
    scanf("%i", &i);

    retorno:
    switch (i)
    {
        case 1 :
        system("cls");
        Registration();
        break;
        case 2 :
        system("cls");
        menu(9);
        case 3 :
        break;
        default:
        printf("ERRO: Número inválido, digite novamente.\n");
        goto retorno;
        break;
    }
    return 0;
}

int auxmenu_remove()
{
    int counter0;
    printf("No momento existem esses cadastrados que podem ser removidos:\n\n");

    for(int i=0; i<30; i++)
    {
        if(class[i].enrollment_number!=0)
        {
            printf("name: %s\nMatrícula: %i\n\n", class[i].name, class[i].enrollment_number);
            counter+;
        }
    }
    if(counter=0)
    {
        printf("Ops, parece que ainda não há alunos cadastrados.\n");
        submenu_remove();
    }
    else
    {
        remover();
    }
    return 0;
}

int remover()
{
    int enrollment_number;
    printf("Digite a matricula do aluno a ter o Registration removido:\n(Obs: para cancelar a ação digite 0)\n");
    scanf("%i", &enrollment_number);

    for(int i=0; i<30; i++)
    {
        if(class[i].enrollment_number==enrollment_number)
        {
            class[i].enrollment_number=0;
            class[i].first_grade=0;
            class[i].second_grade=0;
            class[i].third_grade=0;
            class[i].fourth_grade=0;
            class[i].name[40]='\0'; 
            class[i].class_code=0;
            class[i].attendance=0;
            break;
        }
    }
    submenu_remove();
    return 0;
}

int submenu_remove()
{
    int i;
    printf("A remoção foi finalizada!\nDigite 1 Para retornar a tela de remoção.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");

    retorna:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    auxmenu_update();
    break;
    case 2:
    system("cls");
    menu(9);
    break;
    case 3:
    break;   
    default:
    printf("Número inválido, digite novamente.\n");
    goto retorna;
    break;
    }
    return 0;
}

int auxmenu_update()
{
    int counter0;
    printf("No momento existem esses cadastrados que podem ser atualizados:\n\n");

    for(int i=0; i<30; i++)
    {
        if(class[i].enrollment_number!=0)
        {
            printf("name: %s\nMatrícula: %i\n", class[i].name, class[i].enrollment_number);
            counter+;
        }
    }
    if(counter=0)
    {
        printf("Ops, parece que ainda não há alunos cadastrados.\n");
        submenu_update();
    }
    else
    {
        update();
    }
    return 0;
}

int update()
{
    int enrollment_number; 
    printf("Digite a matrícula do Registration que vai ser atualizado:\n(OBS.: digite 0 para cancelar a atualização)\n");
    scanf("%i", &enrollment_number);

    if(enrollment_number==0)
    {
        goto final;
    }

    for(int i=0; i<30; i++) 
    {
        if(class[i].enrollment_number==enrollment_number)
        {
            printf("Digite a primeira nota:\n");
            scanf("%f", &class[i].first_grade);

            printf("Digite a segunda nota:\n");
            scanf("%f", &class[i].second_grade);

            printf("Digite a terceira nota:\n");
            scanf("%f", &class[i].third_grade);

            printf("Digite a quarta nota:\n");
            scanf("%f", &class[i].fourth_grade);

            printf("Digite o número de faltas:\n");
            scanf("%i", &class[i].attendance);

            break;
        }
    }

    final:
    submenu_update();
    return 0;
}

int submenu_update() 
{
    int i;
    printf("A Atualização de Registration foi finalizada!\nDigite 1 Para retornar a tela de atualização.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");

    retorna:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    auxmenu_update();
    break;
    case 2:
    system("cls");
    menu(9);
    break;
    case 3:
    break;   
    default:
    printf("Número inválido, digite novamente.\n");
    goto retorna;
    break;
    }
    return 0;
}

int List_all_students()
{
    int turma, counter0;
    printf("Digite o codigo da turma\n");
    scanf("%i", &turma);

    printf("Todos os alunos com esse codigo de turma:\n");

    for(int i=0; i<30; i++)
    {
        if(class[i].class_code==turma)
        {
            printf("Matrícula: %i\nPrimeira nota: %.2f\nSegunda nota: %.2f\nTerceira nota:%.2f\nQuarta nota:%.2f\nFaltas:%i\n\n", class[i].enrollment_number, class[i].first_grade, class[i].second_grade, class[i].third_grade, class[i].fourth_grade, class[i].attendance);
            counter+;
        }
    }
    if(counter=0)
    {
        printf("Ops, Não há alunos nessa turma.\n");
    }
    menuslistas();
    return 0;
}

int List_approved_students()
{
    int turma, attendance, counter0; 
    float media;
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++)
    {
        if(class[i].class_code==turma)
        {
            media = (class[i].first_grade+class[i].second_grade+class[i].third_grade+class[i].fourth_grade)/4.0; 
            attendance = ((36-class[i].attendance)*100)/36;

            if( media>=7 && attendance>=60)
            {
                printf("Matrícula: %i\n", class[i].enrollment_number);
                printf("Média: %.2f\n", media);
                printf("Frequência: %i%\n\n", attendance);
                counter+;
            }
        }
    }
    if(counter=0)
    {
        printf("Ops, Não há alunos aprovados.\n");
    }
    menuslistas();
    return 0;
}

int List_disapproved_fromaverage_students() 
{
    int turma, counter0;
    float media; 
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++)
    {
        media = (class[i].first_grade+class[i].second_grade+class[i].third_grade+class[i].fourth_grade)/4.0;

        if(class[i].class_code==turma)
        { 
            if( media<=7)
            {
                printf("Matrícula: %i\n", class[i].enrollment_number);
                printf("Média: %.2f\n\n", media);
                counter+;
            }
        }
    }
    if(counter=0)
    {
        printf("Ops, Não há alunos reprovados por média.\n");
    }
    menuslistas();
    return 0;
}    

int List_disapproved_fromabsence_students()
{
    int turma, attendance, counter0; 
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++)
    {
        if(class[i].class_code==turma)
        {
            attendance = ((36-class[i].attendance)*100)/36;

            if(attendance<=60)
            {
                printf("Matrícula: %i\n", class[i].enrollment_number);
                printf("Frequência: %i%\n\n", attendance);
                counter+;
            }
        }
    }
    if(counter=0)
    {
        printf("Ops, Não há alunos reprovados por falta.\n");
    }
    menuslistas();
    return 0;
}

int menuslistas()
{
    int i;
    printf("Operação realizada com Sucesso!!\nDigite 1 para listar Registrations\nDigite 2 para listar aprovados\nDigite 3 para listar reprovados por média\nDigite 4 para listar reprovados por falta.\nDigite 5 para voltar ao menu.\n");

    retorno:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    List_all_students();
    break;
    case 2:
    system("cls");
    List_approved_students();
    break;
    case 3:
    system("cls");
    List_disapproved_fromaverage_students();
    break;
    case 4:
    system("cls");
    List_disapproved_fromabsence_students();
    break;
    case 5:
    system("cls");
    menu(9);
    break;
    default:
    printf("Número Inválido, Por favor digite novamente:\n");
    goto retorno;
    break;
    }
    return 0;
}

int main() 
{
  system("cls");
    for(int i=0; i<30; i++) 
    {
        class[i].enrollment_number=0;
    }
  menu(9);
  return 0;
}
