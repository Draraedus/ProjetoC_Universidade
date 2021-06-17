#include <stdio.h> //blibiotecas
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct //struct
{
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    char Nome[40];
    int Cod_Turma; 
    int frequencia;
}disciplina;

disciplina func[30]; //vetor de struct

//MENU DE OPÇÕES
void menu(int i)
{
    iniciar: // rótulo para o goto iniciar do case 9, serve pra quando uma função chamar o menu novamente, ele irá rodar o menu desde o começo das informações.

    //printf para o menu, ele explica o que deve ser digitado, escolhi números em vez da própria string pois diminui os erros que podem ocorrer.
    printf("Digite o numero da operacao a ser executada:\n1 para cadastrar aluno\n2 para remover aluno\n3 para atualizar dados de um aluno\n4 para listar alunos cadastrados\n5 para listar alunos aprovados\n6 para listar alunos reprovados por media\n7 para listar alunos reprovados por faltas\n8 para sair\n9 para reiniciar o menu\n");

    retornar: // rótulo de goto para se houver um número inválido.

    scanf("%i", &i);

    switch(i) //menu para os itens de 2 a 8, há um novo item que é o 9, mas ele foi incrementado apenas para a chamada de função, não sabia se deveria deixar vísivel ao usuário.
    {
        case 1:
        system("cls"); //system cls para a tela ficar mais limpa, foi colocado em cada opção.
        cadastro();
        break;
        case 2:
        system("cls");
        auxmenu_remocao();
        break;
        case 3:
        system("cls");
        auxmenu_atualizar();
        break;
        case 4:
        system("cls");
        alunos();
        break;
        case 5:
        system("cls");
        aprovados();
        break;
        case 6:
        system("cls");
        reprovados_media();
        break;
        case 7:
        system("cls");
        reprovados_falta();
        break;
        case 8:
        return;
        break;
        case 9:
        system("cls");
        printf("Reiniciado com sucesso!");
        goto iniciar;//goto com rótulo no ínicio do menu.
        default:
        printf("ERRO: Valor inválido, por favor digite novamente.\n"); //default pede para repetir o valor, foi usado um goto com o rótulo antes do scan.
        goto retornar; // aqui o goto sendo usado.
        break;
    }
}

//FUNÇÃO DE CADASTRO DE ALUNO, APENAS 1 POR VEZ.
int cadastro()
{   
    int matric, contador =0; //matric para entrada de matricula e contador para mensagem de erro de turma cheia.
    printf("digite a matrícula do aluno\n");
    matricula_err:
    scanf("%i", &matric);
    if(matric>2021099 || matric<2021000)
    {
        printf("Número Inválido de Matrícula, Por favor digite novamente:\n");
        goto matricula_err;
    }
        
    for(int i = 0; i<30; i++) //aqui nós temos um for com dois if, um serve para transmitir a mensagem de erro de matrículas iguas se necessário, o outro conta quantos espaços do vetor estão cheios para depois transmitir a mensagem de erro de turma cheia se estiver.
    {
        if(matric==func[i].matricula) 
        {
            printf("ERRO: já existe um aluno com essa matricula\n\n");
            submenu_cadastro();
            return 0;
        }
        if(func[i].matricula!=0) 
        {
            contador++;
        }
    }
    if(contador==30) //if para se a turma estiver cheia ele dar o erro e ir para o submenu de cadastro.
    {
        printf("ERRO: Turma cheia.\n\n");
        submenu_cadastro();
        return 0;
    }

    for(int i=0; i<30; i++) //Por fim se não tiver tido nenhum dos erros acima ele vai normalmente para o cadrasto, irá igualar a variável matric a parte de matricula na struct, e também irá fazer os scanf das outras informações.
    {
        if(func[i].matricula==0)
        {
            func[i].matricula=matric;

            nota1: // rótulo usado para goto da nota1.
            printf("Digite a primeira nota:\n");
            scanf("%f", &func[i].nota1);
            if(func[i].nota1>10 || func[i].nota1 < 0)
            {
                printf("ERRO: Primeira nota com valor inválido, digite novamente:\n");
                goto nota1;     // Aqui foi usado goto com um if para se qualquer valor de nota passado não for 0<nota<10 o código pedir para repetir.
            }

            nota2:
            printf("Digite a segunda nota:\n");
            scanf("%f", &func[i].nota2);
            if(func[i].nota2>10 || func[i].nota2 < 0)
            {
                printf("ERRO: Segunda nota com valor inválido, digite novamente:\n");
                goto nota2;     // mesma lógica da nota1, apenas muda a variável.
            }

            nota3:
            printf("Digite a terceira nota:\n");
            scanf("%f", &func[i].nota3);
            if(func[i].nota3>10 || func[i].nota3 < 0)
            {
                printf("ERRO: Terceira nota com valor inválido, digite novamente:\n");
                goto nota3;     // mesma lógica da nota1, apenas muda a variável.
            }

            nota4:
            printf("Digite a quarta nota:\n");
            scanf("%f", &func[i].nota4);
            if(func[i].nota4>10 || func[i].nota4 < 0)
            {
                printf("ERRO: Quarta nota com valor inválido, digite novamente:\n");
                goto nota4;     // mesma lógica da nota1, apenas muda a variável.
            }
            
            printf("Digite o nome do aluno:\n");
            getchar();
            gets(func[i].Nome);

            printf("Digite o código da turma:\n");
            scanf("%i", &func[i].Cod_Turma);
            
            faltas:
            printf("Número de faltas do aluno:\n");
            scanf("%i", &func[i].frequencia);
            if(func[i].frequencia>36 || func[i].frequencia < 0)
            {
                printf("ERRO: Número de faltas com valor inválido, digite novamente:\n");
                goto faltas;    // mesmo goto usado na nota1, com a diferença de que aqui é até 36 faltas.
            }

            matric=0;
            submenu_cadastro(); //aqui vai para o submenu.
            return 0;
        }
    }
}

//SUBMENU PARA FINALIZAÇÃO DE CADASTRO DE ALUNO.
int submenu_cadastro() //submenu para a finalização do cadastro, é isso, quando acaba o cadastro ele vem para cá, serve para limpar o código mas antes poder ler informações.
{
    int i;
    printf("Cadastro finalizado !\nDigite 1 para continuar cadastrando.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");
    scanf("%i", &i);

    retorno:
    switch (i)
    {
        case 1 :
        system("cls");
        cadastro();
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

//MENU AUXILIAR DA REMOÇÃO DE CADASTRO.
int auxmenu_remocao() //Mostra alunos cadastrados para remoção, e se não houver alunos cadastrados finaliza a remoção.
{
    int contador=0;
    printf("No momento existem esses cadastrados que podem ser removidos:\n\n");

    for(int i=0; i<30; i++)
    {
        if(func[i].matricula!=0)
        {
            printf("Nome: %s\nMatrícula: %i\n\n", func[i].Nome, func[i].matricula);
            contador++;
        }
    }
    if(contador==0)
    {
        printf("Ops, parece que ainda não há alunos cadastrados.\n");
        submenu_remocao();
    }
    else
    {
        remover();
    }
    return 0;
}

//FUNÇÃO DE REMOÇÃO DE CADASTRO DE ALUNO.
int remover()
{
    int matricula; //variável para procurar a matrícula na struct.
    printf("Digite a matricula do aluno a ter o cadastro removido:\n(Obs: para cancelar a ação digite 0)\n");
    scanf("%i", &matricula);

    for(int i=0; i<30; i++)
    {
        if(func[i].matricula==matricula) //como ele reconhece 0 como nada na matrícula, eu apenas igualei tudo a 0 e esse conjunto já pode ser usado de novo para cadastro.
        {
            func[i].matricula=0;
            func[i].nota1=0;
            func[i].nota2=0;
            func[i].nota3=0;
            func[i].nota4=0;
            func[i].Nome[40]='\0'; //igualei a string a nulo.
            func[i].Cod_Turma=0;
            func[i].frequencia=0;
            break;
        }
    }
    submenu_remocao();
    return 0;
}

//SUBMENU PARA FINALIZAÇÃO DE REMOÇÃO DE CADASTRO.
int submenu_remocao()// menu de finalização da remoção, bem parecido com o submenu do cadastro.
{
    int i;
    printf("A remoção foi finalizada!\nDigite 1 Para retornar a tela de remoção.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");

    retorna:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    auxmenu_atualizar();
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

// MENU AUXILIAR DE ATUALIZAÇÃO DE CADASTRO.
int auxmenu_atualizar() //Cópia do menu auxiliar de remoção, apenas com chamadas diferentes.
{
    int contador=0;
    printf("No momento existem esses cadastrados que podem ser atualizados:\n\n");

    for(int i=0; i<30; i++)
    {
        if(func[i].matricula!=0)
        {
            printf("Nome: %s\nMatrícula: %i\n", func[i].Nome, func[i].matricula);
            contador++;
        }
    }
    if(contador==0)
    {
        printf("Ops, parece que ainda não há alunos cadastrados.\n");
        submenu_atualizar();
    }
    else
    {
        atualizar();
    }
    return 0;
}

//FUNÇÃO DE ATUALIZAÇÃO DE DADOS DE UM CADASTRO.
int atualizar()
{
    int matricula; //variável para matrícula novamente
    printf("Digite a matrícula do cadastro que vai ser atualizado:\n(OBS.: digite 0 para cancelar a atualização)\n");
    scanf("%i", &matricula);

    if(matricula==0)
    {
        goto final;
    }

    for(int i=0; i<30; i++) //aqui procura a matrícula dentro da struct igual a informada para atualizar os dados dos alunos.
    {
        if(func[i].matricula==matricula)
        {
            printf("Digite a primeira nota:\n");
            scanf("%f", &func[i].nota1);

            printf("Digite a segunda nota:\n");
            scanf("%f", &func[i].nota2);

            printf("Digite a terceira nota:\n");
            scanf("%f", &func[i].nota3);

            printf("Digite a quarta nota:\n");
            scanf("%f", &func[i].nota4);

            printf("Digite o número de faltas:\n");
            scanf("%i", &func[i].frequencia);

            break;
        }
    }

    final:
    submenu_atualizar();
    return 0;
}

//MENU DE FINALIZAÇÃO DA ATUALIZAÇÃO DE CADASTRO.
int submenu_atualizar() //é para cá que o user vai ser redirecionado na finalização do cadastro.
{
    int i;
    printf("A Atualização de cadastro foi finalizada!\nDigite 1 Para retornar a tela de atualização.\nDigite 2 para voltar ao menu.\nDigite 3 para finalizar o código.\n");

    retorna:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    auxmenu_atualizar();
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

//LISTAR ALUNOS CADASTRADOS.
int alunos()
{
    int turma, contador=0;
    printf("Digite o codigo da turma\n");
    scanf("%i", &turma);

    printf("Todos os alunos com esse codigo de turma:\n");

    for(int i=0; i<30; i++)//For com um if para listar apenas alunos daquela turma.
    {
        if(func[i].Cod_Turma==turma)
        {
            printf("Matrícula: %i\nPrimeira nota: %.2f\nSegunda nota: %.2f\nTerceira nota:%.2f\nQuarta nota:%.2f\nFaltas:%i\n\n", func[i].matricula, func[i].nota1, func[i].nota2, func[i].nota3, func[i].nota4, func[i].frequencia);
            contador++;
        }
    }
    if(contador==0)
    {
        printf("Ops, Não há alunos nessa turma.\n");
    }
    menuslistas();
    return 0;
}

//LISTAR ALUNOS APROVADOS.
int aprovados()
{
    int turma, frequencia, contador=0; //variável para procurar a turma e para calcular a frequência.
    float media;
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++) //usado para percorrer a struct.
    {
        if(func[i].Cod_Turma==turma)
        {
            media = (func[i].nota1+func[i].nota2+func[i].nota3+func[i].nota4)/4.0; //calculo da média
            frequencia = ((36-func[i].frequencia)*100)/36; //calculo da frequência com base nas faltas.

            if( media>=7 && frequencia>=60)
            {
                printf("Matrícula: %i\n", func[i].matricula);
                printf("Média: %.2f\n", media);
                printf("Frequência: %i%\n\n", frequencia);
                contador++;
            }
        }
    }
    if(contador==0)
    {
        printf("Ops, Não há alunos aprovados.\n");
    }
    menuslistas();
    return 0;
}

//LISTAR ALUNOS REPROVADOS POR MÉDIA.
int reprovados_media() //aqui não tem muito o que falar, é quase o inverso de aprovados, só muda que não tem frequência.
{
    int turma, contador=0;
    float media; 
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++)
    {
        media = (func[i].nota1+func[i].nota2+func[i].nota3+func[i].nota4)/4.0;

        if(func[i].Cod_Turma==turma)
        { 
            if( media<=7)
            {
                printf("Matrícula: %i\n", func[i].matricula);
                printf("Média: %.2f\n\n", media);
                contador++;
            }
        }
    }
    if(contador==0)
    {
        printf("Ops, Não há alunos reprovados por média.\n");
    }
    menuslistas();
    return 0;
}    

//LISTAR ALUNOS REPROVADOS POR FALTA.
int reprovados_falta()
{
    int turma, frequencia, contador=0; //o mesmo do código de média, a diferença é que esse é por frequência.
    printf("Digite o Código da turma:\n");
    scanf("%i", &turma);

    for(int i=0; i<30; i++)
    {
        if(func[i].Cod_Turma==turma)
        {
            frequencia = ((36-func[i].frequencia)*100)/36;

            if(frequencia<=60)
            {
                printf("Matrícula: %i\n", func[i].matricula);
                printf("Frequência: %i%\n\n", frequencia);
                contador++;
            }
        }
    }
    if(contador==0)
    {
        printf("Ops, Não há alunos reprovados por falta.\n");
    }
    menuslistas();
    return 0;
}

//MENU DE FINALIZAÇÃO DAS LISTAS DE ALUNO.
int menuslistas()
{
    int i;
    printf("Operação realizada com Sucesso!!\nDigite 1 para listar cadastros\nDigite 2 para listar aprovados\nDigite 3 para listar reprovados por média\nDigite 4 para listar reprovados por falta.\nDigite 5 para voltar ao menu.\n");

    retorno:
    scanf("%i", &i);

    switch (i)
    {
    case 1:
    system("cls");
    alunos();
    break;
    case 2:
    system("cls");
    aprovados();
    break;
    case 3:
    system("cls");
    reprovados_media();
    break;
    case 4:
    system("cls");
    reprovados_falta();
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


//FUNÇÃO MAIN PARA DAR CLEAN EM WARNS E LER TODO O CÓDIGO ANTES DE RODA-LO.
int main() 
{
  system("cls");
    for(int i=0; i<30; i++) //For para definir todas as matrículas para 0, assim quando não houver uma matrícula ela será igual a 0, facilitando mensagens do tipo erro turma cheia.
    {
        func[i].matricula=0;
    }
  menu(9);
  return 0;
}
