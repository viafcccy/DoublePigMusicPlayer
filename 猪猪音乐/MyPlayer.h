#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <Commctrl.h>
#include "resource.h"
#include "SkinH.h"
#pragma comment(lib, "SkinHu.lib")
#pragma comment(lib, "WINMM.LIB")

#define TIMEID 99
#define MENUADD 101
#define MENUDEL 102
#define MENUCLEAR 103

TCHAR AppName[10] = L"MusicList";
TCHAR iniPath[20] = L"D://musiclist.ini";
TCHAR CurrentMusic[MAX_PATH];
HMENU hmenu;//定义快捷菜单
HBITMAP hBmp;//List位图
int CurrentMusicLen;

//消息分流
BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void Cls_OnClose(HWND hwnd);

void Start(HWND hwnd); //打开播放歌曲
void Pause(HWND hwnd); //暂停/继续歌曲

void PlayMusic(TCHAR *MusicPath);//获取路径
void StopMusic(TCHAR* MusicPath);//暂停关闭歌曲
void PauseMusic(TCHAR* MusicPath);//暂停
void ResumeMusic(TCHAR* MusicPath);//继续
int GetMusicLength(TCHAR* MusicPath);//获取歌曲长度
int GetMusicPos(TCHAR* MusicPath);//得到当前歌曲的进度
void FromMusicPos(TCHAR* MusicPath, int pos);//从某个位置开始播放
void Add(HWND hwnd);//从列表中添加
void Del(HWND hwnd);//从列表中删除
void Clear(HWND hwnd);//清空列表