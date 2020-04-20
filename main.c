#include <stdio.h> /*for printf */
#include <stdlib.h> /* for atoi */
#include <windows.h>

const int repeat = 5;
POINT point[2] = {0};
INPUT input[2] = {0};

int main()
{
    // Initialize clicking simulation
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    while (TRUE)
    {
        int new_repeat = repeat;
        // Bungee exploit
        if (GetKeyState(VK_LCONTROL) < 0)
        {
            printf("Entered bungee exploit mode.\n");
            // Get position of the cursor from 2 clicks
            for (int i = 0; i < 2; ++i)
            {
                printf("Reading left click position %d...", i + 1);
                while (GetKeyState(VK_LBUTTON) >= 0);
                GetCursorPos(&point[i]);
                printf("[%ld, %ld]\n", point[i].x, point[i].y);
                // Prevent the code from being executed when holding the first left click
                while (GetKeyState(VK_LBUTTON) < 0 && i == 0);
            }
            
            // Execution
            printf("Executing macro...\n");
            while (new_repeat--)
            {
                for (int i = 0; i < 2; ++i)
                {
                    // Because too fast is not good
                    Sleep(25);
                    SetCursorPos(point[i].x, point[i].y);
                    SendInput(2, input, sizeof(INPUT));
                }
            }
            printf("Done.\n");
        }

        // Sun collecting
        while (GetKeyState(VK_LSHIFT) < 0)
        {
            SendInput(2, input, sizeof(INPUT));
            Sleep(50);
        }
		
		Sleep(100);
    }
    return 0;
}