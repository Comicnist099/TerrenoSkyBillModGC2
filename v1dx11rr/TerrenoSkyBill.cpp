#include <windows.h>
#include <windowsx.h>
#include "XACT3Util.h"
#include "DXRR.h"
#include "GamePadRR.h"
#include <mmsystem.h>

#include <dinput.h>
#include <xinput.h>
#include <string>
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

#pragma comment (lib,"Gdiplus.lib")

#define SCREEN_X 1366
#define SCREEN_Y 768

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

DXRR *dxrr;
GamePadRR *gamePad;
tagPOINT initialPoint;
tagPOINT actualPoint;
LPDIRECTINPUT8 m_pDirectInput = NULL;
LPDIRECTINPUTDEVICE8 m_pKeyboardDevice = NULL;
LPDIRECTINPUTDEVICE8 m_pMouseDevice = NULL;
Camara* cameraPosition;
CXACT3Util m_XACT3;
void createMouseDevice(HWND hWnd) {
    m_pDirectInput->CreateDevice(GUID_SysMouse, &m_pMouseDevice, 0);

    m_pMouseDevice->SetDataFormat(&c_dfDIMouse);

    m_pMouseDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    m_pMouseDevice->Acquire();

}

void createKeyboardDevice(HWND hWnd) {
    m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyboardDevice, 0);

    m_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);

    m_pKeyboardDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    m_pKeyboardDevice->Acquire();

}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{

    HWND hWnd;
    WNDCLASSEX wc;
    DEVMODE dmScreenSettings;
    int posX, posY;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"DXRR_E1";
    wc.cbSize = sizeof(WNDCLASSEX);



    RegisterClassEx(&wc);

    // If full screen set the screen to maximum size of the users desktop and 32bit.
    memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
    dmScreenSettings.dmSize = sizeof(dmScreenSettings);
    dmScreenSettings.dmPelsWidth = (unsigned long)SCREEN_X;
    dmScreenSettings.dmPelsHeight = (unsigned long)SCREEN_Y;
    dmScreenSettings.dmBitsPerPel = 32;
    dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

    // Change the display settings to full screen.
    ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

    // Set the position of the window to the top left corner.
    posX = posY = 0;

    //RECT wr = {0, 0, SCREEN_X, SCREEN_Y};
    //AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    hWnd = CreateWindowEx(WS_EX_APPWINDOW,
                          L"DXRR_E1",
                          L"PLANTILLA PROYECTO",
                          WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
        posX,
        posY,
        SCREEN_X,
        SCREEN_Y,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hWnd, nCmdShow);
    dxrr = new DXRR(hWnd, 800, 600);
    dxrr->vel = 0;
    dxrr->velSides = 0; // Inicializo en 0 para que no me crashee :3 
    dxrr->firstPerson = true;
    dxrr->once = false;
    gamePad = new GamePadRR(1);

    ClientToScreen(hWnd, &initialPoint);
    actualPoint.x = initialPoint.x + SCREEN_X / 2;
    actualPoint.y = initialPoint.y + SCREEN_Y / 2;

	SetTimer(hWnd, 100, 33, NULL);
    MSG msg;
    ::DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION,
        IID_IDirectInput8, (void**)&m_pDirectInput, 0);
    createMouseDevice(hWnd);
    createKeyboardDevice(hWnd);
    bool Una=false;
    bool Dos=false;
    bool Tres=false;
    bool Cuatro=false;
    bool Cinco=false;

    CXACT3Util m_XACT3;
    bool res; 
    //->aki
    res = m_XACT3.Initialize();
    if (!res) return false;
    res = m_XACT3.LoadWaveBank(L"Wave Bank.xwb");
    if (!res) return false;
    res = m_XACT3.LoadSoundBank(L"Sound Bank.xsb");
    if (!res) return false;

  



    // Play XACT3 cue
    XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Circu");
    m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);



    while(TRUE)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if(msg.message == WM_QUIT)
                break;
        }

        if (dxrr->payasos == 1) {
            if (Una == false) {
                XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Freddy");
                m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

                Una = true;
            }
        }

        if (dxrr->payasos == 2) {
            if (Dos == false) {
                XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Freddy");
                m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

                Dos = true;
            }
        }

        if (dxrr->payasos == 3) {
            if (Tres == false) {
                XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Freddy");
                m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

                Tres = true;
            }
        }


        if (dxrr->payasos == 4) {
            if (Cuatro == false) {
                XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Freddy");
                m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

                Cuatro = true;
            }
        }


        if (dxrr->payasos == 5) {
            if (Cinco == false) {
                XACTINDEX cueIndex = m_XACT3.m_pSoundBank->GetCueIndex("Freddy");
                m_XACT3.m_pSoundBank->Play(cueIndex, 0, 0, 0);

                Cinco = true;
            }
        }





        dxrr->Render();


    }

    if (m_pMouseDevice) {
        m_pMouseDevice->Unacquire();
        m_pMouseDevice->Release();
    }
    m_pMouseDevice = NULL;

    if (m_pKeyboardDevice) {
        m_pKeyboardDevice->Unacquire();
        m_pKeyboardDevice->Release();
    }
    m_pKeyboardDevice = NULL;

    if (m_pDirectInput)
        m_pDirectInput->Release();
    m_pDirectInput = NULL;

    return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

   // PlaySound("Omaru_Polka_BGM.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    float xPos = 0;
    float yPos = 0;
    ShowCursor(false);

    switch(message)
    {
        case WM_DESTROY:
            {
				KillTimer(hWnd, 100);
                PostQuitMessage(0);
                return 0;
            } break;

        case WM_TIMER:
        {
            dxrr->animacionagua = dxrr->animacionagua + 0.01;
            if (dxrr->animacionagua >= 2) {
                dxrr->animacionagua = 0;
            }
        } break;
        
        case WM_MOUSEMOVE: {

            SetCursorPos(actualPoint.x, actualPoint.y);
            dxrr->frameBillboard++;
            if (dxrr->frameBillboard == 32)
                dxrr->frameBillboard = 0;

            dxrr->izqder = 0;
            dxrr->arriaba = 0;
            dxrr->vel = 0;
            dxrr->velSides = 0;


            char keyboardData[256];
            m_pKeyboardDevice->GetDeviceState(sizeof(keyboardData), (void*)&keyboardData);

            if (keyboardData[DIK_S]) {
                dxrr->vel = -5.f;
                
            }

            if (keyboardData[DIK_W]) {
                dxrr->vel = 5.f;
            }

            if (keyboardData[DIK_D]) {
                dxrr->velSides = -5.f;
            }

            if (keyboardData[DIK_A]) {
                dxrr->velSides = 5.f;
            }

            if (keyboardData[DIK_B]) {
                dxrr->breakpoint = true;
            }
            if (keyboardData[DIK_J]) {

                wstring info = L"X: ";
                info.append(to_wstring(dxrr->posCam.x));
                info.append(L" Y: ");
                info.append(to_wstring(dxrr->posCam.y));
                info.append(L" Z: ");
                info.append(to_wstring(dxrr->posCam.z));
                MessageBox(hWnd, info.c_str(), L"INFO", MB_OK);
                break;
            }
            if (keyboardData[DIK_R])
            {

                if (dxrr->firstPerson==true)
                {
                    dxrr->firstPerson = false;
                    dxrr->once = true;
                    break;
                }
                else {
                    dxrr->firstPerson = true;
                    dxrr->once = false;
                    break;
                }
            
            }

            if (keyboardData[DIK_Q])
            {

                if (dxrr->Vehiculo == true)
                {
                    dxrr->Vehiculo = false;
                    break;
                }
                else {
                    dxrr->Vehiculo = true;
                    break;
                }

            }

            if (keyboardData[DIK_T])
            {
                if (!dxrr->firstPerson)
                {
                    dxrr->firstPerson = true;
                    dxrr->once = true;
                    break;
                }
            }

            if (keyboardData[DIK_ESCAPE]) {
                KillTimer(hWnd, 100);
                PostQuitMessage(0);
                return 0;
            }

            DIMOUSESTATE mouseData;
            m_pMouseDevice->GetDeviceState(sizeof(mouseData), (void*)&mouseData);

            // Mouse move
            dxrr->izqder = (mouseData.lX / 1000.0f);
            dxrr->arriaba = -(mouseData.lY / 1000.0f);


            if (gamePad->IsConnected()) {
                float gradosX = (float)gamePad->GetState().Gamepad.sThumbRX / 32767.0;
                float gradosY = (float)gamePad->GetState().Gamepad.sThumbRY / 32767.0;
                float sensibilidad = 20.0; //1.0
                float rango = 0.70; //0.19
                if (gradosX > rango || gradosX < -rango || gradosY > rango || gradosY < -rango) {
                    dxrr->izqder += gradosX / sensibilidad;
                    dxrr->arriaba += gradosY / sensibilidad;
                }

                float velocidadZ = (float)gamePad->GetState().Gamepad.sThumbLY / 32767.0;
                float velocidadX = -(float)gamePad->GetState().Gamepad.sThumbLX / 32767.0;
                float velocidad = 4.0f;
                if (velocidadZ > rango || velocidadZ < -rango || velocidadX > rango || velocidadX < -rango) {
                    dxrr->vel = velocidadZ * velocidad;
                    dxrr->velSides = velocidadX * velocidad;
                    //gamePad->GetState().Gamepad.bLeftTrigger / 255.0;
                }
            }

        }break;

    }

    return DefWindowProc (hWnd, message, wParam, lParam);
}



