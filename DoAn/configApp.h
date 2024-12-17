#pragma once
#include "mydraw.h"
#include "mycolor.h"
#include "mywindows.h"
#include "mykeyboard.h"

// Input
#define WIDTH_INPUT 20
#define HEIGHT_INPUT 2
#define LENGTH_INPUT 15

// Content
#define DISTANCE_SIDEBAR 30
#define DISTANCE_HEADER 8
#define PADDING 1
#define MARGIN 6
#define COLUMN_CENTER 120
#define ROW_CENTER 30
#define COLUMN_RIGHT 40

// Frame Content
#define WIDTH_CONTENT  172
#define HEIGHT_CONTENT  36

#define YES "Co"
#define NO "Khong"
#define INSERT_FINISH "Them Thong Tin Thanh Cong!"
#define UPDATE_FINISH "Cap Nhat Thong Tin Thanh Cong!"
#define UPDATE_FAIL "Cap Nhat Thong Tin That Bai!"
#define NOTIFICATION_DELETE "Ban Co Muon Xoa Du Lieu Nay Khong?"



void init();
void cleanContent();
void cleanTable();
void cleanMessage(int y);