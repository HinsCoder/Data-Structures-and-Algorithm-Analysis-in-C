#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DispalyBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
//��û��������������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char is_win(char board[ROW][COL], int row, int col);