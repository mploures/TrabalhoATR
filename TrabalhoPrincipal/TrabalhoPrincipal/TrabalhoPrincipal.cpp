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

DWORD WINAPI Tarefa1(LPVOID);	// declaração da thread  que  gerencia da tarefa 1
DWORD WINAPI Tarefa2(LPVOID);	// declaração da thread  que  gerencia da tarefa 2 
DWORD WINAPI Tarefa3(LPVOID);	// declaração da thread  que  gerencia da tarefa 3
DWORD WINAPI Tarefa4(LPVOID);	// declaração da thread  que  gerencia da tarefa 4
DWORD WINAPI Tarefa5(LPVOID);	// declaração da thread  que  gerencia da tarefa 5
DWORD WINAPI Encerramento(LPVOID);	// declaração da thread  que cuida do encerramento das tarefas

int main() {

	HANDLE hTarefa1, hTarefa2, hTarefa3, hTarefa4, hTarefa5, hEncerramento;
	DWORD dwtarefa1ID, dwtarefa2ID, dwtarefa3ID, dwtarefa4ID, dwtarefa5ID, dwencerramentoID;
	DWORD dwExitCode = 0;

	char a='n';
	int i=0;

	SetConsoleTitle(L"Programa Principal");
	printf("Digite uma tecla qualquer para iniciar \n");
	_getch();

	
	hTarefa1 = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Tarefa1, &i, 0, (CAST_LPDWORD)&dwtarefa1ID);
	if (hTarefa1) printf("Tarefa 1 criada com Id= %0x \n",dwtarefa1ID);

	hTarefa2 = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Tarefa2, &i, 0, (CAST_LPDWORD)&dwtarefa2ID);
	if (hTarefa2) printf("Tarefa 2 criada com Id= %0x \n", dwtarefa2ID);

	hTarefa3 = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Tarefa3, &i, 0, (CAST_LPDWORD)&dwtarefa3ID);
	if (hTarefa3) printf("Tarefa 3 criada com Id= %0x \n", dwtarefa3ID);

	hTarefa4 = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Tarefa4, &i, 0, (CAST_LPDWORD)&dwtarefa4ID);
	if (hTarefa4) printf("Tarefa 4 criada com Id= %0x \n", dwtarefa4ID);

	hTarefa5 = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Tarefa5, &i, 0, (CAST_LPDWORD)&dwtarefa5ID);
	if (hTarefa5) printf("Tarefa 5 criada com Id= %0x \n", dwtarefa5ID);

	hEncerramento = (HANDLE)_beginthreadex(NULL, 0, (CAST_FUNCTION)Encerramento, &i, 0, (CAST_LPDWORD)&dwencerramentoID);
	if (hEncerramento) printf("Tarefa de Encerramento criada com Id= %0x \n", dwencerramentoID);

	while (a!='s' & a!='S')
	{
		printf("aqui");
		a = getchar();

	}












		return EXIT_SUCCESS;
}

DWORD WINAPI Tarefa1(LPVOID index)
{
	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");
	

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);

	return(0);
} 

DWORD WINAPI Tarefa2(LPVOID index)
{
	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);
	return(0);
} 

DWORD WINAPI Tarefa3(LPVOID index)
{
	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);
	return(0);
} 

DWORD WINAPI Tarefa4(LPVOID index)
{
	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);
	return(0);
} 

DWORD WINAPI Tarefa5(LPVOID index)
{
	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);
	return(0);
} 

DWORD WINAPI Encerramento(LPVOID index)
{

	BOOL status;
	STARTUPINFO si;				    // StartUpInformation para novo processo
	PROCESS_INFORMATION NewProcess;	// Informações sobre novo processo criado

	SetConsoleTitle(L"Programa Tarefa1");
	printf("entrou");


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);	// Tamanho da estrutura em bytes

	status = CreateProcess(
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal\\tarefaaux.exe", // Caminho do arquivo executável
		NULL,                       // Apontador p/ parâmetros de linha de comando
		NULL,                       // Apontador p/ descritor de segurança
		NULL,                       // Idem, threads do processo
		FALSE,	                     // Herança de handles
		NORMAL_PRIORITY_CLASS,	     // Flags de criação
		NULL,	                     // Herança do amniente de execução
		L"D:\\arquivos ATR\\MeusProgramas\\TrabalhoFinal\\TrabalhoPrincipal",              // Diretório do arquivo executável
		&si,			             // lpStartUpInfo
		&NewProcess);	             // lpProcessInformation
	if (!status) printf("Erro na criacao do Notepad! Codigo = %d\n", GetLastError());




	_endthreadex((DWORD)index);
	return(0);
} 




// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração
// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
