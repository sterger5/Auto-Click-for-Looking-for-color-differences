#include <Windows.h>
#include<iostream>
using namespace std;

void ClickAt(int x, int y) {
    // �������λ��
    SetCursorPos(x, y);

    // ׼���������INPUT�ṹ��
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;

    // ����������
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    // �������ͷ�
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // ����ÿ�����ӵĿ�Ⱥ͸߶ȡ���ʼ������
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

    //point cursorpos; // point��һ���ṹ�壬���ڴ洢������Ϣ

    //// ��ȡ��ǰ���λ��
    //getcursorpos(&cursorpos);

    //// ��ӡ������Ϣ
    //cout << "��ǰ���λ�ã�(" << cursorpos.x << ", " << cursorpos.y << ")" << std::endl;

    //while (Score)
    //{
    //    for (int i = 0; i < 8; ++i) {
    //        for (int j = 0; j < 8; ++j) {
    //            ClickAt(startX8 + j * gridSize8, startY8 + i * gridSize8);
    //            // ���Ը�����Ҫ����������ʵ�����ʱ������������
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
                // ���Ը�����Ҫ����������ʵ�����ʱ������������
                Sleep(1);
            }
        }
        Score--;
    }

    return 0;
}