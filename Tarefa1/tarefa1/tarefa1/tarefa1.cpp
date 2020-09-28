// Trabalho de ATR
// 
//	Autores: Matheus Paiva e Vitória de Oliveira 
//
//	Processo Principal - tarefa 6
//
//	Versão: beta
//

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>	
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>		

#define _CHECKERROR	1
#include "CheckForError.h"


// Casting para terceiro e sexto parâmetros da função _beginthreadex
typedef unsigned (WINAPI* CAST_FUNCTION)(LPVOID);
typedef unsigned* CAST_LPDWORD;

typedef struct TIPO11 {
	int nseq=1;
	int tipo = 11;
	int cad=0;
	int gravidade=1;
	int classe=1;
	//char arq[6] = "arq123";
}TIPO11;

typedef struct TIPO22 {
	int nseq=1;
	int tipo = 22;
	int cad=1;
	int id=1;
	float temp=1;
	float vel=1;
}TIPO22;

HANDLE hMutexNSEQ;
TIPO11  novaMensagem11();
TIPO22  novaMensagem22();

int NSEQ = 1;

DWORD WINAPI LeituraTipo11(LPVOID);	// declaração da thread  que  gerencia da tarefa 1
DWORD WINAPI LeituraTipo22(LPVOID);	// declaração da thread  que  gerencia da tarefa 2 



int main() {

	HANDLE hThreads[2];
	DWORD dwLeitura11ID, dwLeitura22ID;
	DWORD dwExitCode = 0;
	DWORD dwRet;

	char a = 'n';
	int i = 0;

	hMutexNSEQ = CreateMutex(NULL,FALSE,L"ProtegeNSEQ");

	SetConsoleTitle(L"Programa Principal");
	printf("Digite uma tecla qualquer para iniciar \n");
	a=_getch();


	hThreads[0] = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)LeituraTipo11, &i, 0, (CAST_LPDWORD)&dwLeitura11ID);
	if (hThreads[0]) printf("Tarefa 1 criada com Id= %0x \n", dwLeitura11ID);

	hThreads[1] = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)LeituraTipo22, &i, 0, (CAST_LPDWORD)&dwLeitura22ID);
	if (hThreads[1]) printf("Tarefa 2 criada com Id= %0x \n", dwLeitura22ID);


	dwRet = WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
	//CheckForError((dwRet >= WAIT_OBJECT_0) && (dwRet < WAIT_OBJECT_0 + 2));

	for (i = 0; i < 2; i++) {
		GetExitCodeThread(hThreads[i], &dwExitCode);
		printf("thread %d terminou: codigo=%d\n", i, dwExitCode);
		CloseHandle(hThreads[i]);	// apaga referência ao objeto
	}  // for 
	CloseHandle(hMutexNSEQ);





	printf("\nAcione uma tecla para terminar\n");
	a=_getch(); // // Pare aqui, caso não esteja executando no ambiente MDS


	return(0);
}

DWORD WINAPI LeituraTipo11(LPVOID) {
	int status;
	TIPO11 m1;

	status=WaitForSingleObject(hMutexNSEQ,INFINITE); // mutex pra proteger a variavel NSEQ
	m1 = novaMensagem11();
	status = ReleaseMutex(hMutexNSEQ);

	
	return(0);

}

DWORD WINAPI LeituraTipo22(LPVOID) {
	int status;
	TIPO22 m1;

	status = WaitForSingleObject(hMutexNSEQ, INFINITE); // mutex pra proteger a variavel NSEQ
	m1 = novaMensagem22();
	status = ReleaseMutex(hMutexNSEQ);



	return(0);
}




TIPO11 novaMensagem11() {
	TIPO11 m1;
	m1.cad = rand() % 1 + 6;
	m1.classe = rand() % 1 + 9;
	m1.gravidade = rand() % 1 + 10;
	m1.nseq = NSEQ;	
	NSEQ++;
	if (NSEQ == 99999) {
		NSEQ = 1;
	}
	return m1;
};

TIPO22  novaMensagem22() {
	TIPO22 m2;
	int aux=rand() % 200 - 20000;
	int aux2 = rand() % 1 - 2000;
	m2.cad= rand() % 1 + 6;
	m2.id = rand() % 1 + 9999999;
	m2.temp = (float)aux/10;
	m2.vel = (float)aux2 / 10;
	m2.nseq = NSEQ;
	NSEQ++;
	if (NSEQ == 99999) {
		NSEQ = 1;
	}
	return m2;
};
