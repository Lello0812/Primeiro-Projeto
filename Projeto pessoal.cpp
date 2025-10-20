#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
   Projeto: Estudo para desenvolvimento pessoal em C.
   Tema: Narrativa interativa ambientada em um universo Lovecraftiano.
   Estrutura:
   continuar = 1 ? Porto inicial
   continuar = 2 ? Casa de Morrow
   continuar = 3 ? Di�logo com o pescador
   continuar = 4 ? Lago / cais
   continuar = 5 ? Caixinha
   continuar = 6 ? Decis�o sobre a caixinha
   continuar = 7 ? Interior da casa do Morrow
*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa gerador de n�meros aleat�rios

    int opcao1, opcao2, opcao3, opcao4;
    int continuar = 1;
    int temCaixinha = 0; // Marca se o jogador pegou a caixinha
    int temChave = 0;    // Marca se o jogador achou a chave do cofre

    // Introdu��o
    printf("Introdu��o:\n");
    printf("� o ano de 1927. Voc� chega � isolada vila costeira de Arkham Hollow, "
           "um lugar que raramente aparece em qualquer mapa. "
           "Um amigo antigo, o professor Elias Morrow, enviou uma carta pedindo ajuda � "
           "dizia ter descoberto 'algo imposs�vel' nas ru�nas junto ao penhasco.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    printf("A n�voa cobre o porto. O vento traz o som distante de algo... cantando?\n"
           "Um pescador idoso observa voc� desembarcar, os olhos arregalados.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    printf("Pescador: Voc� devia ter ficado longe, forasteiro. "
           "O mar aqui devolve o que devia engolir.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    // LOOP PRINCIPAL
    while (1) {

        // --- CENA 1: PORTO / ESCOLHA INICIAL ---
        if (continuar == 1) {
            printf("Ao longe, uma trilha leva at� a casa de Morrow, meio escondida entre pinheiros.\n");
            printf("\nEscolha:\n");
            printf("1 - Ignorar o pescador e seguir direto � casa de Morrow.\n");
            printf("2 - Perguntar ao pescador o que ele quis dizer.\n");
            printf("3 - Caminhar at� o cais para investigar o som que vem do mar.\n");
            printf("> ");
            scanf("%d", &opcao1);
            system("cls");

            switch (opcao1) {
                case 1:
                    printf("Voc� sobe pela trilha enevoada, sentindo o ch�o �mido e irregular. "
                           "O sil�ncio parece denso, quase consciente. ");
                    continuar = 2;
                    break;

                case 2:
                    continuar = 3;
                    break;

                case 3:
                    printf("Voc� caminha at� o cais. A n�voa se abre brevemente, revelando o oceano escuro � "
                           "e algo movendo-se sob a superf�cie. O canto, agora mais claro, soa como "
                           "uma mistura de lamento e ora��o.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Voc� observa a lua � a noite fria e a sensa��o de estar sendo observado "
                           "se torna quase insuport�vel.\n");
                    break;
            }
        }

        // --- CENA 2: CASA DE MORROW ---
        else if (continuar == 2) {
            printf("A casa de Morrow surge entre os pinheiros � velha, coberta de musgo, "
                   "com janelas pregadas e um cheiro forte de maresia. "
                   "A porta da frente est� entreaberta, balan�ando levemente com o vento.\n\n");
            printf("1 - Empurrar a porta e entrar chamando por Morrow.\n");
            printf("2 - Contornar a casa e espiar pelas janelas antes de entrar.\n");
            printf("3 - Ficar onde est� e observar por um tempo.\n");
            printf("4 - Voltar para a praia.\n");
            printf("> ");
            scanf("%d", &opcao2);
            system("cls");

            switch (opcao2) {
                case 1:
                    printf("Voc� empurra a porta devagar. Ela range alto, revelando um interior escuro, "
                           "onde o ar � denso e cheira a madeira �mida e vela queimada.\n");
                    continuar = 7;
                    break;

                case 2:
                    printf("Voc� contorna a casa com cuidado. As janelas est�o cobertas por t�buas, "
                           "mas por uma fresta voc� acha ver algo se mover l� dentro � "
                           "ou talvez tenha sido s� o reflexo da sua pr�pria lanterna.\n");
                    break;

                case 3:
                    printf("Voc� fica parado diante da porta, observando. "
                           "O vento faz as t�buas rangerem, e por um instante, "
                           "voc� acha ouvir passos l� dentro � leves, mas ritmados.\n");
                    break;

                case 4:
                    printf("Voc� decide voltar para a praia. A neblina parece mais espessa agora.\n");
                    continuar = 1;
                    break;

                default:
                    printf("Voc� hesita, o som distante das ondas misturando-se ao farfalhar dos pinheiros.\n");
                    break;
            }
        }

        // --- CENA 3: PESCADOR (RESPOSTAS ALEAT�RIAS) ---
        else if (continuar == 3) {
            system("cls");
            printf("Voc� se aproxima do velho pescador. O vento traz o cheiro de sal e ferrugem, "
                   "e o som distante do mar parece acompanh�-los.\n");

            int resposta = rand() % 3;

            switch (resposta) {
                case 0:
                    printf("\nPescador: �O mar daqui devolve o que devia engolir.�\n");
                    printf("1 - 'O que exatamente ele devolveu?'\n");
                    printf("2 - 'Parece supersti��o de velho.'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele ri sem humor. �Se n�o sabe, melhor n�o descobrir.�\n");
                    else if (opcao2 == 2)
                        printf("O olhar dele endurece. �Diz isso agora. O mar costuma responder aos descrentes.�\n");
                    else
                        printf("O pescador apenas o encara em sil�ncio.\n");
                    break;

                case 1:
                    printf("\nPescador: �Voc� tamb�m ouviu, n�? A cantoria.�\n");
                    printf("1 - 'Quem est� cantando?'\n");
                    printf("2 - 'Eu n�o ouvi nada.'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele aperta os l�bios. �Ningu�m que ainda viva.�\n");
                    else if (opcao2 == 2)
                        printf("Ele d� um meio sorriso. �Ent�o j� come�ou.�\n");
                    else
                        printf("Ele desvia o olhar para o mar.\n");
                    break;

                case 2:
                    printf("\nPescador: �Nem todo som vem do mar, forasteiro.�\n");
                    printf("1 - 'E de onde vem, ent�o?'\n");
                    printf("2 - 'Voc� est� b�bado?'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele suspira. �Algumas vozes sobem da terra. Outras... n�o sobem de lugar nenhum.�\n");
                    else if (opcao2 == 2)
                        printf("Ele ri, mas o som � seco. �Melhor b�bado do que l�cido nesse lugar.�\n");
                    else
                        printf("O pescador apenas balan�a a cabe�a, voltando o olhar ao mar.\n");
                    break;
            }

            printf("\n[Pressione ENTER para continuar]");
            getchar();
            getchar();
            system("cls");
            continuar = 1;
        }

        // --- CENA 4: LAGO / CAIS ---
        else if (continuar == 4) {
            printf("\n1 - Ajoelhar-se e olhar para o fundo da �gua.\n");
            printf("2 - Tentar identificar de onde vem o som, talvez algo sob o cais.\n");
            printf("3 - Recuar para a praia.\n> ");
            scanf("%d", &opcao2);
            system("cls");

            switch (opcao2) {
                case 1:
                    printf("Voc� se ajoelha; seu rosto fica perigosamente pr�ximo da �gua. "
                           "Por um instante, jura ter visto algo mover-se sob a superf�cie.\n");
                    break;

                case 2:
                    printf("Voc� perde um tempo ali, procurando. "
                           "Sob o cais, encontra um porta-joias musical. "
                           "A bailarina gira lentamente ao som de uma melodia triste.\n");
                    continuar = 5;
                    break;

                case 3:
                    printf("O medo toma conta de voc�. O som, o vento e o olhar distante do pescador "
                           "fazem voc� desejar nunca ter vindo.\n");
                    continuar = 1;
                    break;

                default:
                    printf("O vento gelado parece sussurrar algo em seu ouvido, e voc� acha que entende.\n");
                    break;
            }
        }

        // --- CENA 5: CAIXINHA ---
        else if (continuar == 5) {
            printf("Voc� pega a caixinha nas m�os. Ela � fria, �mida, e definitivamente n�o deveria estar ali.\n");
            printf("\n1 - Analisar a caixinha.\n2 - Devolver ao ch�o.\n> ");
            scanf("%d", &opcao3);
            system("cls");

            switch (opcao3) {
                case 1:
                    printf("A melodia se interrompe de repente. O ar parece prender a respira��o com voc�.\n");
                    printf("Voc� observa o porta-joias parado � e por um momento jura que a bailarina ainda se move.\n");
                    printf("Dentro, uma fotografia: os rostos dos pais foram recortados, restando apenas a crian�a entre eles.\n");
                    printf("Um vazio estranho o invade; algo nessa imagem fala de perda e de um lar esquecido no vilarejo.\n");
                    continuar = 6;
                    break;

                case 2:
                    printf("Voc� a devolve ao ch�o, tentando ignorar o inc�modo que sente.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Ela fica ali, girando e tocando a mesma melodia.\n");
                    break;
            }
        }

        // --- CENA 6: DECIS�O SOBRE A CAIXINHA ---
        else if (continuar == 6) {
            printf("\n1 - Guardar a caixinha � talvez descubra a quem pertence.\n");
            printf("2 - Deixar onde encontrou � h� algo inquietante nesse objeto.\n> ");
            scanf("%d", &opcao4);
            system("cls");

            switch (opcao4) {
                case 1:
                    printf("Voc� guarda a caixinha com cuidado. "
                           "Por um instante, o som do mar parece cessar � e logo retorna.\n");
                    temCaixinha = 1;
                    continuar = 4;
                    break;

                case 2:
                    printf("Voc� a deixa onde a encontrou. "
                           "Ainda assim, a melodia ecoa em sua mente.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Voc� permanece im�vel, encarando o pequeno objeto.\n");
                    break;
            }
        }

        // --- CENA 7: INTERIOR DA CASA ---
        else if (continuar == 7) {
            printf("\nO interior est� quase escuro. As l�mpadas n�o funcionam, e uma vela queimada at� o fim ainda solta um fio de fuma�a. "
                   "As janelas est�o pregadas com t�buas, e o ar tem um cheiro pesado de maresia e mofo. "
                   "H� um som constante de pingos caindo em algum ponto da casa � embora o teto pare�a completamente seco.\n");
            printf("1 - Examinar o escrit�rio � esquerda.\n");
            printf("2 - Seguir o som dos pingos.\n");
            printf("3 - Abrir a porta dos fundos.\n");
            printf("4 - Observar os quadros nas paredes.\n");
            printf("5 - Sair da casa.\n> ");
            scanf("%d", &opcao4);
            system("cls");

            switch (opcao4) {
                case 1:
                    printf("Uma escrivaninha coberta de pap�is �midos e instrumentos de medi��o enferrujados. "
                           "Entre as anota��es, um trecho leg�vel:\n"
                           "�As vozes voltam quando a mar� sobe. N�o s�o ecos � elas respondem.�\n"
                           "(Voc� sente que Morrow estava estudando algo que n�o devia.)\n");
                    break;

                case 2:
                    printf("O som leva at� um balde no ch�o, meio cheio d��gua. "
                           "Nenhum sinal de goteira no teto. "
                           "Quando voc� se aproxima, percebe ondas pequenas se formando dentro do balde, como se algo se movesse sob a superf�cie.\n");
                    break;

                case 3:
                    printf("A fechadura est� inchada pela umidade. Voc� for�a e ela cede com um estalo.\n"
                           "Do lado de fora, o vento carrega o cheiro pesado do mar � "
                           "e por um instante, voc� tem a sensa��o de que a mar� est� mais pr�xima do que antes.\n"
                           "(Talvez a �gua esteja subindo.)\n");
                    break;

                case 4:
                    printf("Os retratos antigos est�o cobertos por uma fina camada de mofo.\n"
                           "Um mostra Morrow, mais jovem, ao lado de uma mulher e de uma crian�a de express�o s�ria.\n"
                           "O rosto dos adultos foi riscado, mas o da menina ainda permanece � um olhar fixo e triste, voltado diretamente para voc�.\n");
                    if (temCaixinha == 1) {
                        printf("\nVoc� percebe algo brilhando na moldura � um fragmento dourado, "
                               "id�ntico ao material da caixinha que encontrou no lago.\n"
                               "De dentro da sua bolsa, a caixinha come�a a tocar sozinha.\n"
                               "A melodia se mistura ao som dos pingos, preenchendo o sil�ncio da casa.\n"
                               "Voc� sente que precisa examinar melhor esse objeto.\n"
                               "Ao peg�-la na m�o, percebe que h� um compartimento aberto que antes n�o estava.\n");
                        printf("\n1 - Abrir o compartimento secreto\n2 - Guardar a caixinha e voltar\n> ");
                        scanf("%d", &opcao4);
                        system("cls");

                        if (opcao4 == 1) {
                            printf("Voc� abre um compartimento secreto na caixinha e encontra uma pequena chave e uma sequ�ncia de n�meros escritos em um papel:\n");
                            printf("\"4 8 15 16 23 42\"\n");
                            printf("Essa chave deve ser importante para algo no vilarejo...\n"
                                   "Voc� volta sua aten��o para a casa.\n");
                            temChave = 1;
                        }
                    } else {
                        printf("\nAlgo na foto prende seu olhar � o rosto da crian�a parece familiar, "
                               "mas voc� n�o sabe dizer por qu�.\n");
                    }
                    break;

                case 5:
                    printf("Voc� volta para a parte de frente da casa.\n");
                    continuar = 2;
                    break;

                default:
                    printf("Voc� permanece im�vel, encarando o pequeno objeto.\n");
                    break;
            }
        }
    }

    return 0;
}
				
					
				
				
			
			
		

