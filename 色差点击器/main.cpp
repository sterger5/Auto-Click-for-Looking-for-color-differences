#include <Windows.h>
#include<iostream>
using namespace std;

void ClickAt(int x, int y) {
    // 设置鼠标位置
    SetCursorPos(x, y);

    // 准备鼠标点击的INPUT结构体
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;

    // 鼠标左键按下
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    // 鼠标左键释放
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // 设置每个格子的宽度和高度、起始点坐标
    int gridSize8 = 62;
    int startX8 = 588;
    int startY8 = 213;

    int gridSize9 = 55;
    int startX9 = 585;
    int startY9 = 210;

    bool startClicking = false;

    while (!startClicking) 
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            startClicking = true;
        }
    }

    int Score = 70;

    //point cursorpos; // point是一个结构体，用于存储坐标信息

    //// 获取当前鼠标位置
    //getcursorpos(&cursorpos);

    //// 打印坐标信息
    //cout << "当前鼠标位置：(" << cursorpos.x << ", " << cursorpos.y << ")" << std::endl;

    //while (Score)
    //{
    //    for (int i = 0; i < 8; ++i) {
    //        for (int j = 0; j < 8; ++j) {
    //            ClickAt(startX8 + j * gridSize8, startY8 + i * gridSize8);
    //            // 可以根据需要在这里添加适当的延时，避免点击过快
    //            Sleep(4);
    //        }
    //    }
    //    Score--;
    //}

    //Score = 30;

    while (Score)
    {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                ClickAt(startX9 + j * gridSize9, startY9 + i * gridSize9);
                // 可以根据需要在这里添加适当的延时，避免点击过快
                Sleep(1);
            }
        }
        Score--;
    }

    return 0;
}