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
   continuar = 3 ? Diálogo com o pescador
   continuar = 4 ? Lago / cais
   continuar = 5 ? Caixinha
   continuar = 6 ? Decisão sobre a caixinha
   continuar = 7 ? Interior da casa do Morrow
*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa gerador de números aleatórios

    int opcao1, opcao2, opcao3, opcao4;
    int continuar = 1;
    int temCaixinha = 0; // Marca se o jogador pegou a caixinha
    int temChave = 0;    // Marca se o jogador achou a chave do cofre

    // Introdução
    printf("Introdução:\n");
    printf("É o ano de 1927. Você chega à isolada vila costeira de Arkham Hollow, "
           "um lugar que raramente aparece em qualquer mapa. "
           "Um amigo antigo, o professor Elias Morrow, enviou uma carta pedindo ajuda — "
           "dizia ter descoberto 'algo impossível' nas ruínas junto ao penhasco.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    printf("A névoa cobre o porto. O vento traz o som distante de algo... cantando?\n"
           "Um pescador idoso observa você desembarcar, os olhos arregalados.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    printf("Pescador: Você devia ter ficado longe, forasteiro. "
           "O mar aqui devolve o que devia engolir.\n");
    printf("\n[Pressione ENTER para continuar]");
    getchar();
    system("cls");

    // LOOP PRINCIPAL
    while (1) {

        // --- CENA 1: PORTO / ESCOLHA INICIAL ---
        if (continuar == 1) {
            printf("Ao longe, uma trilha leva até a casa de Morrow, meio escondida entre pinheiros.\n");
            printf("\nEscolha:\n");
            printf("1 - Ignorar o pescador e seguir direto à casa de Morrow.\n");
            printf("2 - Perguntar ao pescador o que ele quis dizer.\n");
            printf("3 - Caminhar até o cais para investigar o som que vem do mar.\n");
            printf("> ");
            scanf("%d", &opcao1);
            system("cls");

            switch (opcao1) {
                case 1:
                    printf("Você sobe pela trilha enevoada, sentindo o chão úmido e irregular. "
                           "O silêncio parece denso, quase consciente. ");
                    continuar = 2;
                    break;

                case 2:
                    continuar = 3;
                    break;

                case 3:
                    printf("Você caminha até o cais. A névoa se abre brevemente, revelando o oceano escuro — "
                           "e algo movendo-se sob a superfície. O canto, agora mais claro, soa como "
                           "uma mistura de lamento e oração.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Você observa a lua — a noite fria e a sensação de estar sendo observado "
                           "se torna quase insuportável.\n");
                    break;
            }
        }

        // --- CENA 2: CASA DE MORROW ---
        else if (continuar == 2) {
            printf("A casa de Morrow surge entre os pinheiros — velha, coberta de musgo, "
                   "com janelas pregadas e um cheiro forte de maresia. "
                   "A porta da frente está entreaberta, balançando levemente com o vento.\n\n");
            printf("1 - Empurrar a porta e entrar chamando por Morrow.\n");
            printf("2 - Contornar a casa e espiar pelas janelas antes de entrar.\n");
            printf("3 - Ficar onde está e observar por um tempo.\n");
            printf("4 - Voltar para a praia.\n");
            printf("> ");
            scanf("%d", &opcao2);
            system("cls");

            switch (opcao2) {
                case 1:
                    printf("Você empurra a porta devagar. Ela range alto, revelando um interior escuro, "
                           "onde o ar é denso e cheira a madeira úmida e vela queimada.\n");
                    continuar = 7;
                    break;

                case 2:
                    printf("Você contorna a casa com cuidado. As janelas estão cobertas por tábuas, "
                           "mas por uma fresta você acha ver algo se mover lá dentro — "
                           "ou talvez tenha sido só o reflexo da sua própria lanterna.\n");
                    break;

                case 3:
                    printf("Você fica parado diante da porta, observando. "
                           "O vento faz as tábuas rangerem, e por um instante, "
                           "você acha ouvir passos lá dentro — leves, mas ritmados.\n");
                    break;

                case 4:
                    printf("Você decide voltar para a praia. A neblina parece mais espessa agora.\n");
                    continuar = 1;
                    break;

                default:
                    printf("Você hesita, o som distante das ondas misturando-se ao farfalhar dos pinheiros.\n");
                    break;
            }
        }

        // --- CENA 3: PESCADOR (RESPOSTAS ALEATÓRIAS) ---
        else if (continuar == 3) {
            system("cls");
            printf("Você se aproxima do velho pescador. O vento traz o cheiro de sal e ferrugem, "
                   "e o som distante do mar parece acompanhá-los.\n");

            int resposta = rand() % 3;

            switch (resposta) {
                case 0:
                    printf("\nPescador: “O mar daqui devolve o que devia engolir.”\n");
                    printf("1 - 'O que exatamente ele devolveu?'\n");
                    printf("2 - 'Parece superstição de velho.'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele ri sem humor. “Se não sabe, melhor não descobrir.”\n");
                    else if (opcao2 == 2)
                        printf("O olhar dele endurece. “Diz isso agora. O mar costuma responder aos descrentes.”\n");
                    else
                        printf("O pescador apenas o encara em silêncio.\n");
                    break;

                case 1:
                    printf("\nPescador: “Você também ouviu, né? A cantoria.”\n");
                    printf("1 - 'Quem está cantando?'\n");
                    printf("2 - 'Eu não ouvi nada.'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele aperta os lábios. “Ninguém que ainda viva.”\n");
                    else if (opcao2 == 2)
                        printf("Ele dá um meio sorriso. “Então já começou.”\n");
                    else
                        printf("Ele desvia o olhar para o mar.\n");
                    break;

                case 2:
                    printf("\nPescador: “Nem todo som vem do mar, forasteiro.”\n");
                    printf("1 - 'E de onde vem, então?'\n");
                    printf("2 - 'Você está bêbado?'\n> ");
                    scanf("%d", &opcao2);
                    system("cls");

                    if (opcao2 == 1)
                        printf("Ele suspira. “Algumas vozes sobem da terra. Outras... não sobem de lugar nenhum.”\n");
                    else if (opcao2 == 2)
                        printf("Ele ri, mas o som é seco. “Melhor bêbado do que lúcido nesse lugar.”\n");
                    else
                        printf("O pescador apenas balança a cabeça, voltando o olhar ao mar.\n");
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
            printf("\n1 - Ajoelhar-se e olhar para o fundo da água.\n");
            printf("2 - Tentar identificar de onde vem o som, talvez algo sob o cais.\n");
            printf("3 - Recuar para a praia.\n> ");
            scanf("%d", &opcao2);
            system("cls");

            switch (opcao2) {
                case 1:
                    printf("Você se ajoelha; seu rosto fica perigosamente próximo da água. "
                           "Por um instante, jura ter visto algo mover-se sob a superfície.\n");
                    break;

                case 2:
                    printf("Você perde um tempo ali, procurando. "
                           "Sob o cais, encontra um porta-joias musical. "
                           "A bailarina gira lentamente ao som de uma melodia triste.\n");
                    continuar = 5;
                    break;

                case 3:
                    printf("O medo toma conta de você. O som, o vento e o olhar distante do pescador "
                           "fazem você desejar nunca ter vindo.\n");
                    continuar = 1;
                    break;

                default:
                    printf("O vento gelado parece sussurrar algo em seu ouvido, e você acha que entende.\n");
                    break;
            }
        }

        // --- CENA 5: CAIXINHA ---
        else if (continuar == 5) {
            printf("Você pega a caixinha nas mãos. Ela é fria, úmida, e definitivamente não deveria estar ali.\n");
            printf("\n1 - Analisar a caixinha.\n2 - Devolver ao chão.\n> ");
            scanf("%d", &opcao3);
            system("cls");

            switch (opcao3) {
                case 1:
                    printf("A melodia se interrompe de repente. O ar parece prender a respiração com você.\n");
                    printf("Você observa o porta-joias parado — e por um momento jura que a bailarina ainda se move.\n");
                    printf("Dentro, uma fotografia: os rostos dos pais foram recortados, restando apenas a criança entre eles.\n");
                    printf("Um vazio estranho o invade; algo nessa imagem fala de perda e de um lar esquecido no vilarejo.\n");
                    continuar = 6;
                    break;

                case 2:
                    printf("Você a devolve ao chão, tentando ignorar o incômodo que sente.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Ela fica ali, girando e tocando a mesma melodia.\n");
                    break;
            }
        }

        // --- CENA 6: DECISÃO SOBRE A CAIXINHA ---
        else if (continuar == 6) {
            printf("\n1 - Guardar a caixinha — talvez descubra a quem pertence.\n");
            printf("2 - Deixar onde encontrou — há algo inquietante nesse objeto.\n> ");
            scanf("%d", &opcao4);
            system("cls");

            switch (opcao4) {
                case 1:
                    printf("Você guarda a caixinha com cuidado. "
                           "Por um instante, o som do mar parece cessar — e logo retorna.\n");
                    temCaixinha = 1;
                    continuar = 4;
                    break;

                case 2:
                    printf("Você a deixa onde a encontrou. "
                           "Ainda assim, a melodia ecoa em sua mente.\n");
                    continuar = 4;
                    break;

                default:
                    printf("Você permanece imóvel, encarando o pequeno objeto.\n");
                    break;
            }
        }

        // --- CENA 7: INTERIOR DA CASA ---
        else if (continuar == 7) {
            printf("\nO interior está quase escuro. As lâmpadas não funcionam, e uma vela queimada até o fim ainda solta um fio de fumaça. "
                   "As janelas estão pregadas com tábuas, e o ar tem um cheiro pesado de maresia e mofo. "
                   "Há um som constante de pingos caindo em algum ponto da casa — embora o teto pareça completamente seco.\n");
            printf("1 - Examinar o escritório à esquerda.\n");
            printf("2 - Seguir o som dos pingos.\n");
            printf("3 - Abrir a porta dos fundos.\n");
            printf("4 - Observar os quadros nas paredes.\n");
            printf("5 - Sair da casa.\n> ");
            scanf("%d", &opcao4);
            system("cls");

            switch (opcao4) {
                case 1:
                    printf("Uma escrivaninha coberta de papéis úmidos e instrumentos de medição enferrujados. "
                           "Entre as anotações, um trecho legível:\n"
                           "“As vozes voltam quando a maré sobe. Não são ecos — elas respondem.”\n"
                           "(Você sente que Morrow estava estudando algo que não devia.)\n");
                    break;

                case 2:
                    printf("O som leva até um balde no chão, meio cheio d’água. "
                           "Nenhum sinal de goteira no teto. "
                           "Quando você se aproxima, percebe ondas pequenas se formando dentro do balde, como se algo se movesse sob a superfície.\n");
                    break;

                case 3:
                    printf("A fechadura está inchada pela umidade. Você força e ela cede com um estalo.\n"
                           "Do lado de fora, o vento carrega o cheiro pesado do mar — "
                           "e por um instante, você tem a sensação de que a maré está mais próxima do que antes.\n"
                           "(Talvez a água esteja subindo.)\n");
                    break;

                case 4:
                    printf("Os retratos antigos estão cobertos por uma fina camada de mofo.\n"
                           "Um mostra Morrow, mais jovem, ao lado de uma mulher e de uma criança de expressão séria.\n"
                           "O rosto dos adultos foi riscado, mas o da menina ainda permanece — um olhar fixo e triste, voltado diretamente para você.\n");
                    if (temCaixinha == 1) {
                        printf("\nVocê percebe algo brilhando na moldura — um fragmento dourado, "
                               "idêntico ao material da caixinha que encontrou no lago.\n"
                               "De dentro da sua bolsa, a caixinha começa a tocar sozinha.\n"
                               "A melodia se mistura ao som dos pingos, preenchendo o silêncio da casa.\n"
                               "Você sente que precisa examinar melhor esse objeto.\n"
                               "Ao pegá-la na mão, percebe que há um compartimento aberto que antes não estava.\n");
                        printf("\n1 - Abrir o compartimento secreto\n2 - Guardar a caixinha e voltar\n> ");
                        scanf("%d", &opcao4);
                        system("cls");

                        if (opcao4 == 1) {
                            printf("Você abre um compartimento secreto na caixinha e encontra uma pequena chave e uma sequência de números escritos em um papel:\n");
                            printf("\"4 8 15 16 23 42\"\n");
                            printf("Essa chave deve ser importante para algo no vilarejo...\n"
                                   "Você volta sua atenção para a casa.\n");
                            temChave = 1;
                        }
                    } else {
                        printf("\nAlgo na foto prende seu olhar — o rosto da criança parece familiar, "
                               "mas você não sabe dizer por quê.\n");
                    }
                    break;

                case 5:
                    printf("Você volta para a parte de frente da casa.\n");
                    continuar = 2;
                    break;

                default:
                    printf("Você permanece imóvel, encarando o pequeno objeto.\n");
                    break;
            }
        }
    }

    return 0;
}
				
					
				
				
			
			
		

