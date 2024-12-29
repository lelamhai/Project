#pragma once
#include "mydraw.h"
#include "mycolor.h"
#include "mywindows.h"
#include "mykeyboard.h"

// Input
#define LENGTH_MIN 1
#define LENGTH_CODE 7
#define WIDTH_INPUT 20
#define HEIGHT_INPUT 2
#define LENGTH_INPUT 15

// Page
#define DISTANCE_SIDEBAR 30
#define DISTANCE_HEADER 8
#define PADDING 1
#define MARGIN 6
#define COLUMN_CENTER 120
#define ROW_CENTER 30
#define COLUMN_RIGHT 40

// Frame Content
#define WIDTH_CONTENT  179
#define HEIGHT_CONTENT  36

// Popups
#define YES "Co"
#define NO "Khong"
#define NOTIFICATION_EMPTY "Vui Long Khong Bo Trong!" 
#define NOTIFICATION_CODE "Vui Long Nhap It Nhat 7 Ky Tu!"
#define NOTIFICATION_INSERT_FINISH "Them Thong Tin Thanh Cong."
#define NOTIFICATION_UPDATE_FINISH "Cap Nhat Thong Tin Thanh Cong."
#define NOTIFICATION_UPDATE_FAIL "Cap Nhat Thong Tin That Bai."
#define NOTIFICATION_DELETE "Ban Co Muon Xoa Du Lieu Nay Khong?"
#define NOTIFICATION_NOT_DELETE "Du lieu nay khong the xoa duoc!"

#define SUBJECT_CODE "Ma Mon Hoc Khong Ton Tai!"
#define CLASSROOM_CODE "Ma Lop Khong Ton Tai!"

#define TIME_DELAY 2000



void init();
void cleanContent();
void cleanTable();
string truncateText(const string& text);