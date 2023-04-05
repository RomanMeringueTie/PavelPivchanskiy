#include <stdio.h>
#include "coder.h"
#include "command.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Неверное количество аргументов\n");
        return -1;
    }

    else if ((strcmp(argv[1], "encode")) && (strcmp(argv[1], "decode")))
    {
        printf("Неверно написана команда кодирования/декодирования\n");
        return -1;
    }
    char *command;
    char *in_file_name;
    char *out_file_name;
    strcpy(command, argv[1]);
    strcpy(in_file_name, argv[2]);
    strcpy(out_file_name, argv[3]);
    if (!(strcmp(command, "encode")))
    {
        encode_file(in_file_name, out_file_name);
    }
    else if (!(strcmp(command, "decode")))
    {
        decode_file(in_file_name, out_file_name);
    }
    return 0;
}