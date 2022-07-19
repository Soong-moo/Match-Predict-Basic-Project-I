#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>


#define UP 0
#define DOWN 1
#define SELECT 2
#define SIZE 30
#define CLEAN system("cls")
#define PAUSE system("pause");

typedef struct element {
    char team[SIZE]; // ����
    int wPer, dPer, lPer, w, d, l, point, rank, groups; //�¹��� Ȯ��, �¹��� ��, ����, ����, ��(��� �� %c ���)
    int tourWin; // ��ʸ�Ʈ �¸� Ƚ��
    int winPoint[10]; // �¸� �� ���� ����
} element;

typedef struct node {
    struct node* link;
    element data;
} node;

void gotoxy(int x, int y); // ��ǥ ���� �Լ�
int keyControl(); // ����Ű �̵�
int randNum(); // ���� ����
int menu(); // �ʱ� ȭ��
void addTeam(node* target, int groups); // �� �Է�
void list(node* target); // �� ����Ʈ
void bubbleSort(node* target); // ����Ʈ ���� (���� ��)
int selectPrintListMenu(); // ��� ����Ʈ �� ����
void removeTeam(node* target); // �� ����
void reviseTeam(node* target); // �� ����
void match(node* target); // ��� ����
void matchWinner(node* target); // aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
int selectTournamentMenu(); // ��ʸ�Ʈ ����
void round_16(node* target, node* target2); //16��
void round_8(node* target, node* target2); //8��
void round_4(node* target, node* target2); //4��
void round_2(node* target, node* target2); //���
void loser_round(node* target, node* target2); //3, 4�� ������
int selectRankMenu(); // ����ǥ ����
void addtxt(node* target, int groups, char txt[]); // ���� �ҷ�����
void getTxt(); // ���� �ҷ����� �������̽�
void rainbow(short text, short back); // �����Ҷ� �߱½�Ѱ�
void notice(int x, int y); // �������̽� 1 (ǥ����)
void endProgram(); // ���α׷� ����

int main(void) { // groups ���� ��� ã��

    system("mode con cols=110 lines=30 | title 2022 ����������Ʈ I �̿��� ����"); // �ܼ� â ũ�� ���� �� ���� ����

    bool state = true;
    int num;
    char team[SIZE];
    int groups = 65; // ASCII A
    int txt_cnt = 0, match_result = 0, round16_result = 0, round8_result = 0, round4_result = 0, round2_result = 0; // ���� ��� Ƚ��  + ���� �ҷ����� Ƚ�� (1�̸� ���� �� ����)

    // ���� ��� 8 * 4 �� ����
    node* head[8] = { (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)) };
    // 8�� �� ����
    node* round8[8] = { (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)), (node*)malloc(sizeof(node)) };
    // 4�� �� ����
    node* semi_final[4] = { (node*)malloc(sizeof(node)) , (node*)malloc(sizeof(node)) , (node*)malloc(sizeof(node)) , (node*)malloc(sizeof(node)) };
    // ��� �� ����
    node* final[2] = { (node*)malloc(sizeof(node)) , (node*)malloc(sizeof(node)) };
    // 3,4�� �� �� ����
    node* loser_final[2] = { (node*)malloc(sizeof(node)) , (node*)malloc(sizeof(node)) };

    for (int i = 0; i < 8; i++) {
        head[i]->link = NULL;
        round8[i]->link = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        semi_final[i]->link = NULL;
    }
    for (int i = 0; i < 2; i++)
    {
        final[i]->link = NULL;
        loser_final[i]->link = NULL;
    }

    while (state) {

        int menuCode = menu();

        switch (menuCode) {

        case 1: {
            CLEAN;
            printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
            printf("\t\t\t\t��\t     ��, �·� �Է� \t\t\b\b\b��\n\n");
            printf("\t\t\t\t����������������������������������������������������������������������������\n");
            num = selectPrintListMenu();
            switch (num) {
            case 1: {
                addTeam(head[num - 1], groups);
                break;
            }
            case 2: {
                addTeam(head[num - 1], groups + 1);
                break;
            }
            case 3: {
                addTeam(head[num - 1], groups + 2);
                break;
            }
            case 4: {
                addTeam(head[num - 1], groups + 3);
                break;
            }
            case 5: {
                addTeam(head[num - 1], groups + 4);
                break;
            }
            case 6: {
                addTeam(head[num - 1], groups + 5);
                break;
            }
            case 7: {
                addTeam(head[num - 1], groups + 6);
                break;
            }
            case 8: {
                addTeam(head[num - 1], groups + 7);
                break;
            }
            case 9: {
                CLEAN;
                break;
            }
            }
            break;
        }

        case 2: {
            CLEAN;
            printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
            printf("\t\t\t\t��\t     �� ����Ʈ ��� \t\t\b\b\b��\n\n");
            printf("\t\t\t\t����������������������������������������������������������������������������\n");
            num = selectPrintListMenu();
            switch (num) {
            case 1: {
                list(head[num - 1]);
                break;
            }
            case 2: {
                list(head[num - 1]);
                break;
            }
            case 3: {
                list(head[num - 1]);
                break;
            }
            case 4: {
                list(head[num - 1]);
                break;
            }
            case 5: {
                list(head[num - 1]);
                break;
            }
            case 6: {
                list(head[num - 1]);
                break;
            }
            case 7: {
                list(head[num - 1]);
                break;
            }
            case 8: {
                list(head[num - 1]);
                break;
            }
            case 9: {
                CLEAN;
                break;
            }
            }
            break;
        }

        case 3: {
            CLEAN;
            printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
            printf("\t\t\t\t��\t\t�� ���� \t\t\b\b\b��\n\n");
            printf("\t\t\t\t����������������������������������������������������������������������������\n");
            num = selectPrintListMenu();
            switch (num) {
            case 1: {
                removeTeam(head[num - 1]);
                break;
            }
            case 2: {
                removeTeam(head[num - 1]);
                break;
            }
            case 3: {
                removeTeam(head[num - 1]);
                break;
            }
            case 4: {
                removeTeam(head[num - 1]);
                break;
            }
            case 5: {
                removeTeam(head[num - 1]);
                break;
            }
            case 6: {
                removeTeam(head[num - 1]);
                break;
            }
            case 7: {
                removeTeam(head[num - 1]);
                break;
            }
            case 8: {
                removeTeam(head[num - 1]);
                break;
            }
            case 9: {
                CLEAN;
                break;
            }
            }
            break;
        }

        case 4: {
            CLEAN;
            num = selectPrintListMenu();
            switch (num) {
            case 1: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 2: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 3: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 4: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 5: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 6: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 7: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 8: {
                reviseTeam(head[num - 1]);
                break;
            }
            case 9: {
                CLEAN;
                break;
            }
            }
            break;
        }

        case 5: {
            CLEAN;

            int cnt = 1;

            for (int i = 0; i < 8; i++) {
                CLEAN;
                printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t��\t       ���� ��� \t\t\b\b\b��\n\n");
                printf("\t\t\t\t����������������������������������������������������������������������������\n");
                match(head[i]);
                Sleep(500);

            }

            match_result = 1;

            PAUSE;
            CLEAN;
            break;
        }

        case 6: {
            CLEAN;
            if (match_result != 1) {
                notice(32, 8);
                gotoxy(36, 11);
                printf(" ���� ��⸦ ���� ġ����մϴ�!\n");
                printf("\n\n\n\n\n\n\n");

                PAUSE;
                CLEAN;
                break;
            }

            int num = selectTournamentMenu();

            switch (num) {
            case 1: {
                CLEAN;

                if (round16_result == 1) {
                    notice(32, 8);
                    gotoxy(38, 10);
                    printf("�̹� ��Ⱑ ����Ǿ����ϴ�.\n");
                    gotoxy(38, 12);
                    printf("���� ��⸦ �������ּ���.\n");
                    printf("\n\n\n\n\n\n\n");
                    PAUSE;
                    CLEAN;
                    break;
                }

                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t\t\b\b\b\b��\t\t\t\b\b\b\b1 6 ��\t\t\t\b\b\b\b\b\b\b��\n\n");
                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n");
                int x = 45, y = 7;

                gotoxy(x - 35, y - 2);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                for (int i = 6; i < 26; i++) {
                    gotoxy(x - 35, i);
                    printf("��");
                    gotoxy(x + 49, i);
                    printf("��");
                }
                gotoxy(x - 35, y + 18);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

                x = 20, y = 12;

                for (int i = 0; i < 4; i++) { // a�� 1�� h�� 2��, a�� 2�� h�� 1�� ��
                    if (head[i]->link == NULL || head[7 - i]->link == NULL) {
                        int x = 30, y = 8;
                        notice(x, y);
                        gotoxy(x, y + 3);
                        printf("\t\t\b\b\b\b��⸦ ������ �� �����ϴ�.");
                        printf("\n\n\n\n\n\n\n\n\n\n\n");
                        break;
                    }


                    gotoxy(x, y);
                    round_16(head[i], head[7 - i]);

                    if (head[i]->link->data.tourWin == 1) {
                        round8[i]->link = head[i]->link;
                    }
                    else if (head[7 - i]->link->link->data.tourWin == 1) {
                        round8[i]->link = head[7 - i]->link->link;
                    }

                    if (head[i]->link->link->data.tourWin == 1) {
                        round8[7 - i]->link = head[i]->link->link;
                    }
                    else if (head[7 - i]->link->data.tourWin == 1) {
                        round8[7 - i]->link = head[7 - i]->link;
                    }
                    round16_result = 1;
                    y += 2;
                }
                printf("\n\n\n\n\n\n\n\n\n");
                PAUSE;
                CLEAN;
                break;
            }

            case 2:

            {
                CLEAN;

                if (round8_result == 1) {
                    notice(32, 8);
                    gotoxy(38, 10);
                    printf("�̹� ��Ⱑ ����Ǿ����ϴ�.\n");
                    gotoxy(38, 12);
                    printf("���� ��⸦ �������ּ���.\n");
                    printf("\n\n\n\n\n\n\n");
                    PAUSE;
                    CLEAN;
                    break;
                }
                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t\t\b\b\b\b��\t\t\t\b\b8 ��\t\t\t\b\b\b\b\b\b\b��\n\n");
                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n");

                int x = 45, y = 7;

                gotoxy(x - 35, y - 2);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                for (int i = 6; i < 26; i++) {
                    gotoxy(x - 35, i);
                    printf("��");
                    gotoxy(x + 49, i);
                    printf("��");
                }
                gotoxy(x - 35, y + 18);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

                x = 20, y = 12;

                for (int i = 0; i < 4; i++) {
                    if (round8[i]->link == NULL || round8[7 - i]->link == NULL) {
                        int x = 30, y = 8;
                        notice(x, y);
                        gotoxy(x, y + 3);
                        printf("\t\t\b\b\b\b��⸦ ������ �� �����ϴ�.");
                        printf("\n\n\n\n\n\n\n\n\n\n\n");
                        break;
                    }
                    gotoxy(x, y);
                    round_8(round8[i], round8[7 - i]);

                    if (round8[i]->link->data.tourWin == 2) {
                        semi_final[i]->link = round8[i]->link;
                    }
                    else if (round8[7 - i]->link->data.tourWin == 2) {
                        semi_final[i]->link = round8[7 - i]->link;
                    }
                    round8_result = 1;
                    y += 2;
                }
                printf("\n\n\n\n\n\n\n\n\n");
                PAUSE;
                CLEAN;
                break;
            }


            case 3: {
                CLEAN;
                if (round4_result == 1) {
                    notice(32, 8);
                    gotoxy(38, 10);
                    printf("�̹� ��Ⱑ ����Ǿ����ϴ�.\n");
                    gotoxy(38, 12);
                    printf("���� ��⸦ �������ּ���.\n");
                    printf("\n\n\n\n\n\n\n");
                    PAUSE;
                    CLEAN;
                    break;
                }

                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t\t\b\b\b\b��\t\t\t\b\b\b\b\b\b�� �� �� ��\t\t\t\b\b\b\b\b\b\b��\n\n");
                printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n");
                int x = 45, y = 7;

                gotoxy(x - 35, y - 2);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                for (int i = 6; i < 26; i++) {
                    gotoxy(x - 35, i);
                    printf("��");
                    gotoxy(x + 49, i);
                    printf("��");
                }
                gotoxy(x - 35, y + 18);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

                x = 20, y = 15;

                for (int i = 0; i < 2; i++) {
                    if (semi_final[i]->link == NULL || semi_final[3 - i]->link == NULL) {
                        int x = 30, y = 8;
                        notice(x, y);
                        gotoxy(x, y + 3);
                        printf("\t\t\b\b\b\b��⸦ ������ �� �����ϴ�.");
                        printf("\n\n\n\n\n\n\n\n\n\n\n");
                        break;
                    }
                    gotoxy(x, y - 2);
                    round_4(semi_final[i], semi_final[3 - i]);

                    if (semi_final[i]->link->data.tourWin == 4) {
                        final[i]->link = semi_final[i]->link;
                        loser_final[i]->link = semi_final[3 - i]->link;
                    }
                    else if (semi_final[3 - i]->link->data.tourWin == 4) {
                        final[i]->link = semi_final[3 - i]->link;
                        loser_final[i]->link = semi_final[i]->link;
                    }
                    round4_result = 0;
                    y = y + 2;
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                PAUSE;
                CLEAN;
                break;
            }

            case 4: {
                CLEAN;

                if (round2_result == 1) {
                    notice(32, 8);
                    gotoxy(38, 10);
                    printf("�̹� ��Ⱑ ����Ǿ����ϴ�.\n");
                    gotoxy(34, 12);
                    printf("����ǥ�� ���� ��� ���� Ȯ�����ּ���.\n");
                    printf("\n\n\n\n\n\n\n");
                    PAUSE;
                    CLEAN;
                    break;
                }

                printf("\t\t\t\t\t\b\b\b\b\b����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t\t\b\b\b\b\b��\t\t\t\b\b\b\b�� ��\t\t\t\b\b\b\b\b\b\b\b��\n\n");
                printf("\t\t\t\t\t\b\b\b\b\b����������������������������������������������������������������������������\n");

                int x = 45, y = 7;

                gotoxy(x - 35, y - 2);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                for (int i = 6; i < 26; i++) {
                    gotoxy(x - 35, i);
                    printf("��");
                    gotoxy(x + 49, i);
                    printf("��");
                }
                gotoxy(x - 35, y + 18);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                if (final[0]->link == NULL || final[1]->link == NULL || loser_final[0]->link == NULL || loser_final[1]->link == NULL) {
                    int x = 30, y = 8;
                    notice(x, y);
                    gotoxy(x, y + 3);
                    printf("\t\t\b\b\b\b��⸦ ������ �� �����ϴ�.");
                    printf("\n\n\n\n\n\n\n\n\n\n\n");
                    PAUSE;
                    CLEAN;
                    break;
                }
                gotoxy(x, y + 8);
                loser_round(loser_final[0], loser_final[1]);
                round_2(final[0], final[1]);

                round2_result = 1;

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                PAUSE;
                CLEAN;
                break;
            }

            case 5: {
                CLEAN;
                break;
            }
            }
            break;
        }

        case 7: {
            CLEAN;

            int num = selectRankMenu();

            switch (num) {

            case 1: {
                CLEAN;

                if (match_result == 0) {
                    int x = 30, y = 8;
                    notice(x, y);
                    gotoxy(x, y + 3);
                    printf("\t���� ������ �������� �ʾҽ��ϴ�.");
                    printf("\n\n\n\n\n\n\n\n\n\n\n");
                }

                else {

                    printf("\t\t\t\t  ����������������������������������������������������������������������������\b\b\n\n");
                    printf("\t\t\t\t  ��\t\t 16�� ����\t\t\b��\b\b\b\n\n");
                    printf("\t\t\t\t  ����������������������������������������������������������������������������\b\b\n");

                    int x = 45, y = 8;

                    gotoxy(x - 35, y - 3);
                    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                    for (int i = 6; i < 25; i++) {
                        gotoxy(x - 35, i);
                        printf("��");
                        gotoxy(x + 49, i);
                        printf("��");
                    }
                    gotoxy(x - 35, y + 17);
                    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");


                    for (int i = 0; i < 8; i++) {
                        gotoxy(30, y);
                        matchWinner(head[i]);
                        y += 2;
                    }
                    printf("\n\n\n\n");
                }
                PAUSE;
                CLEAN;
                break;
            }

            case 2: {
                CLEAN;

                printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
                printf("\t\t\t\t��\t     ��ʸ�Ʈ  \t\t\t\b\b\b��\n\n");
                printf("\t\t\t\t����������������������������������������������������������������������������\n");

                int x = 45, y = 8;

                gotoxy(x - 35, y - 3);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
                for (int i = 6; i < 25; i++) {
                    gotoxy(x - 35, i);
                    printf("��");
                    gotoxy(x + 49, i);
                    printf("��");
                }
                gotoxy(x - 35, y + 17);
                printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

                for (int i = 0; i < 2; i++) { // �������
                    if (final[i]->link == NULL) continue;

                    gotoxy(x - 15 + (40 * i), y + 6);
                    printf("%s\n", final[i]->link->data.team);

                    if (final[i]->link->data.tourWin == 5) {

                        gotoxy(x + 5, y + 2);
                        printf("%s\n", final[i]->link->data.team);
                    }
                }

                gotoxy(x - 15, y + 4);
                printf("������������������������������������������������������������������������������������");

                gotoxy(x - 25, y + 7);
                printf("��������������������������������������������                  ����������������������������������������");

                for (int i = 0; i < 2; i++) { // �ذ�� ����
                    if (semi_final[i]->link == NULL) continue;
                    gotoxy(x - 25 + (40 * i), y + 9);
                    printf("%s\n", semi_final[i]->link->data.team);

                    gotoxy(x - 5 + (40 * i), y + 9);
                    printf("%s\n", semi_final[3 - i]->link->data.team);
                }

                gotoxy(x - 30, y + 10);
                printf("������������������������         ����������������������        ����������������������         ����������������������");

                int temp = 0;
                int k = 0;

                for (int i = 0; i < 4; i++) { //8�� ������
                    if (round8[i]->link == NULL) continue;

                    if (i == 1) k = 1;

                    gotoxy(x - 30 + (20 * i), y + 12);
                    if (i != 1)
                        printf("%s\n", round8[i - k]->link->data.team);

                    gotoxy(x - 20 + (20 * i), y + 12);
                    if (i != 1)
                        printf("%s\n", round8[7 - i + k]->link->data.team);
                    else temp = i;
                }
                gotoxy(x - 10, y + 12);
                if (round8[temp + 2]->link != NULL)
                    printf("%s\n", round8[temp + 2]->link->data.team);
                gotoxy(x, y + 12);
                if (round8[5 - temp]->link != NULL)
                    printf("%s\n", round8[5 - temp]->link->data.team);

                printf("\n\n\n\n\n\n\n");
                PAUSE;
                CLEAN;
                break;
            }

            case 3: {
                CLEAN;
                break;
            }
            }

            CLEAN;
            break;
        }

        case 8: {
            CLEAN;
            if (txt_cnt == 1) {
                printf("�̹� ���� �ҷ����⸦ �����߽��ϴ�.\n");
                PAUSE;
                CLEAN;
                break;

            }
            addtxt(head[0], groups, "groupA.txt");
            addtxt(head[1], groups + 1, "groupB.txt");
            addtxt(head[2], groups + 2, "groupC.txt");
            addtxt(head[3], groups + 3, "groupD.txt");
            addtxt(head[4], groups + 4, "groupE.txt");
            addtxt(head[5], groups + 5, "groupF.txt");
            addtxt(head[6], groups + 6, "groupG.txt");
            addtxt(head[7], groups + 7, "groupH.txt");
            getTxt();
            txt_cnt = 1;
            break;
        }

        case 9: {
            CLEAN;
            state = false;
            for (int i = 0; i < 8; i++) {
                free(head[i]);
                free(round8[i]);
            }
            for (int i = 0; i < 4; i++) {
                free(semi_final[i]);
            }
            for (int i = 0; i < 2; i++) {
                free(final[i]);
                free(loser_final[i]);
            }
            break;
        }

        default: {
            CLEAN;
            break;
        }
        }
    }

    CLEAN;

    endProgram();
    return 0;
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int keyControl() {
    int temp = getch();

    if (temp == 72) return UP; // ����Ű ��
    else if (temp == 80) return DOWN; // ����Ű �Ʒ�
    else if (temp == 13) return SELECT; // ����
}

int randNum() {
    int random;
    //srand((unsigned int)time(NULL));
    random = (rand() % 20) + 1; // 1 ~ 20

    return random;
}

int menu() {
    int x = 45, y = 8;
    printf("\n\n\t\t\t\t|_    _  _|_  _ _   _   _     _  _    |    _\n");
    printf("\t\t\t\t|_)  (/_  |  | | | (_| | | . (_ (_) . |<  | \n");

    gotoxy(x - 35, y - 3);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for (int i = 6; i < 26; i++) {
        gotoxy(x - 35, i);
        printf("��");
        gotoxy(x + 49, i);
        printf("��");
    }
    gotoxy(x - 35, y + 18);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    gotoxy(x - 2, y);
    printf("> 1. ��, �·� �Է�");
    gotoxy(x, y + 2);
    printf("2. �� ����Ʈ ���");
    gotoxy(x, y + 4);
    printf("3. �� ����");
    gotoxy(x, y + 6);
    printf("4. �� ����");
    gotoxy(x, y + 8);
    printf("5. ���� ���");
    gotoxy(x, y + 10);
    printf("6. ���� ���");
    gotoxy(x, y + 12);
    printf("7. ����ǥ");
    gotoxy(x, y + 14);
    printf("8. ���� �ҷ�����");
    gotoxy(x, y + 16);
    printf("9. ����");

    while (1) {

        int n = keyControl();

        switch (n) {

        case UP: {
            if (y > 8) {
                gotoxy(x - 2, y);
                printf(" ");
                y -= 2;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case DOWN: {
            if (y < 24) {
                gotoxy(x - 2, y);
                printf(" ");
                y += 2;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case SELECT: {
            return (y - 8) / 2 + 1;
        }
        }
    }
}

void addTeam(node* target, int groups) {

    CLEAN;

    char team[SIZE];
    int w, d, l;
    int sequence = 1;

    while (target->link != NULL) { // ����Ʈ ����
        target = target->link;
        sequence++; // 4�� �� ���� ����
    }

    if (sequence == 5) { // 4�� �� ���� ����
        int x = 30, y = 8;
        notice(x, y);
        gotoxy(x, y + 3);
        printf("\t\t\b\b����Ʈ�� ���� á���ϴ�!         \n");
        printf("\n\n\n\n\n");
        PAUSE;
        CLEAN;
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));

    newNode->link = NULL;
    target->link = newNode;

    while (1) {
        int x = 25, y = 9;
        printf("  \t\t\t\t����������������������������������������������������������������������������\n\n");
        printf("  \t\t\t\t��\t   %c Group List Input  \t\t\b\b\b��\n\n", groups);
        printf("  \t\t\t\t����������������������������������������������������������������������������\n\n\n");
        gotoxy(x, y);
        printf("���� �Է� : ");
        scanf_s("%s", team, SIZE);
        gotoxy(x - 10, y + 3);
        printf("�ؽ� �� �� Ȯ���� ���� 10�� �Ǿ�� �ϰ� 0�� ���� �� �����ϴ�. ex) 2 3 5");
        gotoxy(x, y + 5);
        printf("�� �� �� Ȯ�� �Է� : ");
        scanf_s("%d %d %d", &w, &d, &l);
        getchar();
        if (w + d + l > 10 || w + d + l < 10 || w == 10 || d == 10 || l == 10 || w == 0 || d == 0 || l == 0) {
            CLEAN;
            gotoxy(x, y - 3);
            printf("�·� ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���\n");
        }
        else {
            strcpy(newNode->data.team, team);
            newNode->data.wPer = w;
            newNode->data.dPer = d;
            newNode->data.lPer = l;
            newNode->data.w = 0;
            newNode->data.d = 0;
            newNode->data.l = 0;
            newNode->data.point = 0;
            newNode->data.groups = groups;
            CLEAN;
            break;
        }
        gotoxy(0, 0);
    }
}

void list(node* target) {

    CLEAN;

    bubbleSort(target);

    node* curr = (node*)malloc(sizeof(node));
    curr = target->link;

    int i = 1;

    if (curr != NULL) {
        printf("  \t\t\t\t����������������������������������������������������������������������������\n\n");
        printf("  \t\t\t\t��\t     %c Group List  \t\t\b\b\b��\n\n", curr->data.groups);
        printf("  \t\t\t\t����������������������������������������������������������������������������\n\n\n");
    }
    if (target->link == NULL) {
        int x = 30, y = 8;

        notice(x, y);
        gotoxy(x, y + 3);
        printf("\t\t\b\b����� ���� �����ϴ�!         \n");

    }
    else {
        int x = 45, y = 7;

        gotoxy(x - 42, y - 2);
        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
        for (int i = 6; i < 21; i++) {
            gotoxy(x - 42, i);
            printf("��");
            gotoxy(x + 55, i);
            printf("��");
        }
        gotoxy(x - 42, y + 14);
        printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

        while (curr != NULL) {
            gotoxy(x - 40, y + 2);
            curr->data.rank = i;
            printf("%d�� �� : %s ", curr->data.rank, curr->data.team);
            printf("Ȯ�� > �� : %d%% �� : %d%% �� : %d%%", curr->data.wPer * 10, curr->data.dPer * 10, curr->data.lPer * 10);
            printf("\t�� : %d �� : %d �� : %d", curr->data.w, curr->data.d, curr->data.l);
            printf("\t���� :% d\n\n", curr->data.point);
            i++;
            curr = curr->link;
            y += 2;
        }
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    PAUSE;
    CLEAN;
}

void bubbleSort(node* target) {

    node* p, * q;
    element temp;

    for (p = target->link; p != NULL; p = p->link) {
        for (q = p; q != NULL; q = q->link) {
            if (q->data.point > p->data.point) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

int selectPrintListMenu() {
    int x = 45, y = 7;

    gotoxy(x - 35, y - 2);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for (int i = 6; i < 26; i++) {
        gotoxy(x - 35, i);
        printf("��");
        gotoxy(x + 49, i);
        printf("��");
    }
    gotoxy(x - 35, y + 18);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    gotoxy(x - 2, y);
    printf("> 1. Group A");
    gotoxy(x, y + 2);
    printf("2. Group B");
    gotoxy(x, y + 4);
    printf("3. Group C");
    gotoxy(x, y + 6);
    printf("4. Group D");
    gotoxy(x, y + 8);
    printf("5. Group E");
    gotoxy(x, y + 10);
    printf("6. Group F");
    gotoxy(x, y + 12);
    printf("7. Group G");
    gotoxy(x, y + 14);
    printf("8. Group H");
    gotoxy(x, y + 16);
    printf("9. Back");

    while (1) {

        int n = keyControl();

        switch (n) {

        case UP: {
            if (y > 7) {
                gotoxy(x - 2, y);
                printf(" ");
                y -= 2;
                gotoxy(x - 2, y);
                printf(">");
            }

            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x - 2, y);
                printf(" ");
                y += 2;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }
        case SELECT: {
            return (y - 7) / 2 + 1;
        }
        }
    }
}

void removeTeam(node* target) {

    CLEAN;

    list(target);

    int cnt = 0;
    char name[SIZE];

    node* remove = target->link;

    if (remove == NULL) return; // ����Ʈ ������� ���

    remove = target->link;
    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n");
    printf("  \t\t\t\t��\t   %c Group List delete  \t\b\b\b��\n\n", remove->data.groups);
    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n\n");

    int x = 25, y = 8;

    notice(x, y);
    gotoxy(x, y + 3);
    printf("   ����� ���� ���� �Է��ϼ��� : \n");

    gotoxy(x + 33, y + 3);
    scanf_s("%s", name, SIZE);
    getchar();

    while (remove != NULL) {
        if (strcmp(remove->data.team, name) == 0) {
            CLEAN;
            target->link = remove->link;
            int x = 25, y = 8;
            notice(x, y);
            gotoxy(x, y + 3);
            printf("\t\t ���� �Ϸ� \n");
            Sleep(1000);
            free(remove);
            break;
        }
        remove = remove->link;
        target = target->link;

        if (remove == NULL) {
            CLEAN;
            int x = 25, y = 8;
            notice(x, y);
            gotoxy(x, y + 3);
            printf("\t �ش��ϴ� ���� �����ϴ�. \n");
            Sleep(1000);
            break;
        }
    }

    CLEAN;
}

void reviseTeam(node* target) {

    CLEAN;

    list(target);

    char team[SIZE];
    int w, d, l;
    int cnt = 1;

    node* reviseNode = target->link;

    if (reviseNode == NULL) return; // ����Ʈ ������� ���

    while (reviseNode->link != NULL) { // ����Ʈ ���� ����
        cnt++;
        reviseNode = reviseNode->link;
    }

    reviseNode = target->link;

    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n");
    printf("  \t\t\t\t��\t         �� ����  \t\t\b\b\b��\n\n");
    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n\n");

    gotoxy(25, 7);
    printf("�����ϰ� ���� �� : ");
    scanf_s("%s", team, SIZE);
    getchar();

    while (reviseNode != NULL) {
        if (strcmp(reviseNode->data.team, team) == 0) {
            while (1) {
                int x = 25, y = 9;
                gotoxy(x, y);
                printf("���� �Է� : ");
                scanf_s("%s", team, SIZE);
                gotoxy(x - 10, y + 3);
                printf("�ؽ� �� �� Ȯ���� ���� 10�� �Ǿ�� �ϰ� 0�� ���� �� �����ϴ�. ex) 2 3 5");
                gotoxy(x, y + 5);
                printf("�� �� �� Ȯ�� �Է� : ");
                scanf_s("%d %d %d", &w, &d, &l);
                getchar();
                if (w + d + l > 10 || w + d + l < 10 || w == 10 || d == 10 || l == 10 || w == 0 || d == 0 || l == 0) {
                    CLEAN;
                    gotoxy(x, y - 3);
                    printf("�·� ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���\n");
                }
                else {
                    strcpy(reviseNode->data.team, team);
                    reviseNode->data.wPer = w;
                    reviseNode->data.dPer = d;
                    reviseNode->data.lPer = l;
                    reviseNode->data.w = 0;
                    reviseNode->data.d = 0;
                    reviseNode->data.l = 0;
                    reviseNode->data.point = 0;
                    CLEAN;
                    break;
                }
                break;
            }
            break;
        }
        else {
            CLEAN;
            notice(30, 8);
            gotoxy(30, 11);
            printf("\t\t\b\b�ش��ϴ� ���� �����ϴ�!");
            printf("\n\n\n\n\n\n\n\n\n\n");
            PAUSE;
            CLEAN;
            break;
        }
        reviseNode = reviseNode->link;
        target = target->link;
    }
}

void match(node* target) {

    int x = 45, y = 8;
    gotoxy(x - 35, y - 3);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for (int i = 6; i < 25; i++) {
        gotoxy(x - 35, i);
        printf("��");
        gotoxy(x + 49, i);
        printf("��");
    }
    gotoxy(x - 35, y + 17);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    node* home = target->link, * away;
    int win[] = { 0, }, draw[] = { 0, }, lose[] = { 0, }; //�� �� �� ����
    bool result = true;

    x = 38, y = 10;
    gotoxy(x, y);

    printf("%c�� ���� ��⸦ �����մϴ�.\n\n", home->data.groups);

    for (home = target->link; home->link != NULL; home = home->link) {
        for (away = home->link; away != NULL; away = away->link) {

            gotoxy(x + 3, y + 4);

            int num = randNum();

            int homeWin = home->data.wPer + away->data.lPer; // home �¸� Ȯ�� + away �й� Ȯ��
            int draw = homeWin + home->data.dPer + away->data.dPer; // home �¸� ���ں��� ũ�� ���� ������
            int awayWin = draw + home->data.lPer + away->data.wPer;

            if (num <= homeWin) { // home �¸�
                y++;
                printf("%s vs %s �� %s �¸�  \n\n", home->data.team, away->data.team, home->data.team);
                home->data.w += 1;
                home->data.point += 3;
                away->data.l += 1;
                continue;
            }

            else if (homeWin < num && num <= draw) {
                y++;
                printf("%s vs %s �� ���º�  \n\n", home->data.team, away->data.team);
                home->data.d += 1;
                home->data.point += 1;
                away->data.d += 1;
                away->data.point += 1;
                continue;
            }

            else if (draw < num && num <= awayWin) {
                y++;
                printf("%s vs %s �� %s �¸�  \n\n", home->data.team, away->data.team, away->data.team);
                away->data.w += 1;
                away->data.point += 3;
                home->data.l += 1;
                continue;
            }
            y = 12;
        }
    }

    printf("\n\n\n\n\n");
}

int selectTournamentMenu() {
    printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n\n");
    printf("\t\t\t\t\t\b\b\b\b��\t\t\b\b   ��ʸ�Ʈ ���� \t\t\t\b\b\b\b\b\b\b��\n\n");
    printf("\t\t\t\t\t\b\b\b\b����������������������������������������������������������������������������\n");
    int x = 45, y = 8;

    gotoxy(x - 35, y - 3);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for (int i = 6; i < 25; i++) {
        gotoxy(x - 35, i);
        printf("��");
        gotoxy(x + 49, i);
        printf("��");
    }
    gotoxy(x - 35, y + 17);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    gotoxy(x - 2, y);
    printf("> 1. Round of 16");
    gotoxy(x, y + 3);
    printf("2. Round of 8");
    gotoxy(x, y + 6);
    printf("3. semi-final");
    gotoxy(x, y + 9);
    printf("4. final");
    gotoxy(x, y + 12);
    printf("5. back");

    while (1) {

        int n = keyControl();

        switch (n) {

        case UP: {
            if (y > 8) {
                gotoxy(x - 2, y);
                printf(" ");
                y -= 3;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case DOWN: {
            if (y < 20) {
                gotoxy(x - 2, y);
                printf(" ");
                y += 3;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case SELECT: {
            return (y - 8) / 3 + 1;
        }
        }
    }
}

void round_16(node* target, node* target2) {

    bubbleSort(target);
    bubbleSort(target2);

    node* home = target->link, * away = target2->link->link;
    node* home2 = target->link->link, * away2 = target2->link;

    bool t = true;

    // ���� ���� �ֱ�
    for (int i = 0; i < home->data.wPer; i++) {
        home->data.winPoint[i] = i + 1;
    }

    for (int i = 0; i < home2->data.wPer; i++) {
        home2->data.winPoint[i] = i + 1;
    }

    for (int j = 0; j < away->data.wPer; j++) {
        away->data.winPoint[j] = 20 - j;
    }

    for (int j = 0; j < away2->data.wPer; j++) {
        away2->data.winPoint[j] = 20 - j;
    }

    // 1
    while (t) {
        int num = randNum();

        for (int i = 0; i < home->data.wPer; i++) {
            if (home->data.winPoint[i] == num) {
                home->data.tourWin = 1;
                printf("\b\b\b\b\b\b\t\tWin : %s   /   Lose : %s\t\t", home->data.team, away->data.team);
                t = false;
                break;
            }
        }
        for (int j = 0; j < away->data.wPer; j++) {
            if (away->data.winPoint[j] == num) {
                away->data.tourWin = 1;
                printf("\b\b\b\b\b\b\t\tWin : %s   /   Lose : %s\t\t", away->data.team, home->data.team);
                t = false;
                break;
            }
        }
    }

    t = true;

    // 2
    while (t) {
        int num = randNum();

        for (int i = 0; i < home2->data.wPer; i++) {
            if (home2->data.winPoint[i] == num) {
                home2->data.tourWin = 1;
                printf("\b\b\bWin : %s   /   Lose : %s\n\n", home2->data.team, away2->data.team);
                t = false;
                break;
            }
        }
        for (int j = 0; j < away2->data.wPer; j++) {
            if (away2->data.winPoint[j] == num) {
                away2->data.tourWin = 1;
                printf("\b\b\bWin : %s   /   Lose : %s\n\n", away2->data.team, home2->data.team);
                t = false;
                break;
            }
        }
    }
}

void round_8(node* target, node* target2) {

    node* home = target->link;
    node* away = target2->link;

    bool t = true;

    for (int i = 0; i < home->data.wPer; i++) {
        home->data.winPoint[i] = i + 1;
    }

    for (int j = 0; j < away->data.wPer; j++) {
        away->data.winPoint[j] = 20 - j;
    }

    while (t) {
        int num = randNum();

        for (int i = 0; i < home->data.wPer; i++) {
            if (home->data.winPoint[i] == num) {
                home->data.tourWin = 2;
                printf("\t\t\t\t\b\b\b\b\b\b\bWin : %s   /   Lose : %s\t\n", home->data.team, away->data.team);
                t = false;
                break;
            }
        }
        for (int j = 0; j < away->data.wPer; j++) {
            if (away->data.winPoint[j] == num) {
                away->data.tourWin = 2;
                printf("\t\t\t\t\b\b\b\b\b\b\bWin : %s   /   Lose : %s\t\n", away->data.team, home->data.team);
                t = false;
                break;
            }
        }
    }
}

void round_4(node* target, node* target2) {

    node* home = target->link;
    node* away = target2->link;

    bool t = true;

    for (int i = 0; i < home->data.wPer; i++) {
        home->data.winPoint[i] = i + 1;
    }

    for (int j = 0; j < away->data.wPer; j++) {
        away->data.winPoint[j] = 20 - j;
    }

    while (t) {
        int num = randNum();

        for (int i = 0; i < home->data.wPer; i++) {
            if (home->data.winPoint[i] == num) {
                home->data.tourWin = 4;
                printf("\t\t\t\t\b\b\b\b\b\b\bWin : %s   /   Lose : %s\t\t", home->data.team, away->data.team);
                t = false;
                break;
            }
        }
        for (int j = 0; j < away->data.wPer; j++) {
            if (away->data.winPoint[j] == num) {
                away->data.tourWin = 4;
                printf("\t\t\t\t\b\b\b\b\b\b\bWin : %s   /   Lose : %s\t\t", away->data.team, home->data.team);
                t = false;
                break;
            }
        }
    }
}

void round_2(node* target, node* target2) {

    node* home = target->link;
    node* away = target2->link;

    bool t = true;

    for (int i = 0; i < home->data.wPer; i++) {
        home->data.winPoint[i] = i + 1;
    }

    for (int j = 0; j < away->data.wPer; j++) {
        away->data.winPoint[j] = 20 - j;
    }

    while (t) {
        int num = randNum();

        for (int i = 0; i < home->data.wPer; i++) {
            if (home->data.winPoint[i] == num) {
                home->data.tourWin = 5;
                printf("\t\b\b\b\b\bWin : %s   /   Lose : %s\t\t", home->data.team, away->data.team);
                t = false;
                break;
            }
        }
        for (int j = 0; j < away->data.wPer; j++) {
            if (away->data.winPoint[j] == num) {
                away->data.tourWin = 5;
                printf("\t\b\b\b\b\bWin : %s   /   Lose : %s\t\t", away->data.team, home->data.team);
                t = false;
                break;
            }
        }
    }
}

void loser_round(node* target, node* target2) {

    node* home = target->link;
    node* away = target2->link;

    bool t = true;

    for (int i = 0; i < home->data.wPer; i++) {
        home->data.winPoint[i] = i + 1;
    }

    for (int j = 0; j < away->data.wPer; j++) {
        away->data.winPoint[j] = 20 - j;
    }

    while (t) {
        int num = randNum();

        for (int i = 0; i < home->data.wPer; i++) {
            if (home->data.winPoint[i] == num) {
                home->data.tourWin = 3;
                t = false;
                break;
            }
        }
        for (int j = 0; j < away->data.wPer; j++) {
            if (away->data.winPoint[j] == num) {
                away->data.tourWin = 3;
                t = false;
                break;
            }
        }
    }
}

int selectRankMenu() {

    printf("\t\t\t\t����������������������������������������������������������������������������\n\n");
    printf("\t\t\t\t��\t     ����ǥ ����  \t\t\b\b\b��\n\n");
    printf("\t\t\t\t����������������������������������������������������������������������������\n");

    int x = 45, y = 9;

    gotoxy(x - 35, y - 4);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    for (int i = 6; i < 25; i++) {
        gotoxy(x - 35, i);
        printf("��");
        gotoxy(x + 49, i);
        printf("��");
    }
    gotoxy(x - 35, y + 16);
    printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������");

    gotoxy(x - 2, y);
    printf("> 1.16�� ������");
    gotoxy(x, y + 4);
    printf("2. ����ǥ");
    gotoxy(x, y + 8);
    printf("3. back");


    while (1) {

        int n = keyControl();

        switch (n) {

        case UP: {
            if (y > 9) {
                gotoxy(x - 2, y);
                printf(" ");
                y -= 4;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case DOWN: {
            if (y < 17) {
                gotoxy(x - 2, y);
                printf(" ");
                y += 4;
                gotoxy(x - 2, y);
                printf(">");
            }
            break;
        }

        case SELECT: {
            return (y - 9) / 4 + 1;
        }
        }
    }
}

void addtxt(node* target, int groups, char txt[]) {
    int i = -1, cnt = 0, t = 0;
    FILE* fp;
    groups--;
    fp = fopen(txt, "r");

    while (feof(fp) == 0)
    {
        if (cnt % 4 == 0)
        {
            groups++;
            i++;
        }

        while (target->link != NULL) {
            target = target->link;
            t++;
        }

        if (t == 4) break;

        node* newNode = (node*)malloc(sizeof(node));

        newNode->link = NULL;
        target->link = newNode;

        fscanf(fp, "%s %d %d %d", newNode->data.team, &newNode->data.wPer, &newNode->data.dPer, &newNode->data.lPer);
        newNode->data.w = 0;
        newNode->data.d = 0;
        newNode->data.l = 0;
        newNode->data.point = 0;
        newNode->data.groups = groups;
        cnt++;

    }
    fclose(fp);
}

void getTxt() {

    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n");
    printf("  \t\t\t\t��\t     ���� �ҷ�����\t\t\b\b\b��\n\n");
    printf("  \t\t\t\t����������������������������������������������������������������������������\n\n\n");

    int x = 32, y = 8;

    notice(x, y);
    gotoxy(x - 2, y + 3);
    printf("\t       ������ �ҷ����� ���Դϴ� .");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    CLEAN;

    notice(x, y);
    gotoxy(x - 2, y + 3);
    printf("\t       ������ ��� �ҷ��Խ��ϴ�!");
    Sleep(1500);
    CLEAN;
}

void rainbow(unsigned short text, unsigned short back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | back);
}

void notice(int x, int y) {

    gotoxy(x, y);
    printf("���������������������������������������������������������������������������� \n");
    gotoxy(x, y + 1);
    printf("\n");
    gotoxy(x, y + 2);
    printf("\n");
    gotoxy(x, y + 4);
    printf("\n");
    gotoxy(x, y + 5);
    printf("\n");
    gotoxy(x, y + 6);
    printf("���������������������������������������������������������������������������� \n");
    gotoxy(x, y + 7);
    printf("             |          | \n");
    gotoxy(x, y + 8);
    printf("             | (- �� -) | \n");
}

void endProgram() {
    int cnt = 31;
    for (int i = 0; i < 16; i++)
    {
        int x = 30, y = 8;
        rainbow(i, 0);
        notice(x, y);
        gotoxy(x, y + 2);
        printf("  ���α׷��� �����մϴ�. �����մϴ�.\n");
        gotoxy(x, y + 4);
        printf(" \t\t%.1f���Ŀ� ����˴ϴ�  \n", (float)cnt / 10);
        gotoxy(x, y + 10);
        printf("���� : ���翬, �̽¹�, ������, �̵���");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        Sleep(100);
        CLEAN;
        if (i == 15) i = 0;
        cnt--;
        if (cnt == 0)
            break;
    }
}
void matchWinner(node* target) {

    bubbleSort(target);

    node* team = target->link;
    int t = 1;

    printf("%c�� : ", team->data.groups);

    for (team = target->link; t <= 2; team = team->link) {
        printf("%d�� �� : %s \t\t", t, team->data.team); // %d -> team->data.rank ����Ϸ��� ��� ���� ��
        t++;
    }
    printf("\n\n");
}