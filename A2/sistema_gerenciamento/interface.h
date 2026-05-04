#ifndef INTERFACE_H
#define INTERFACE_H

#include "estrutura.h"

// Conversores enum -> string
const char* getTipoEvento(TipoEvento tipo);
const char* getRegiaoCidade(RegiaoCidade regiao);
const char* getStatusEvento(StatusEvento status);

// Menu principal do sistema
void menu(NO** raiz);

#endif