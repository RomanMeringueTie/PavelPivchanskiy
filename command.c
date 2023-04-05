#include "command.h"
#include "coder.h"

int encode_file(const char *in_file_name, const char *out_file_name)
{
    FILE *in;
    FILE *out;
    in = fopen(in_file_name, "r");
    if (!in)
    {
        return -1;
    }
    out = fopen(out_file_name, "wb");
    if (!out)
    {
        return -1;
    }
    fseek(in, 0, SEEK_END);
    int size = ftell(in);
    printf("%d\n", size);
    uint32_t code_point;
    CodeUnits code_unit;
    for (int i = 0; i < size; i++)
    {
        fscanf(in, "%" SCNx32, &code_point);
        printf("%" PRIx32, code_point);
        if (encode(code_point, &code_unit) != 0)
        {
            printf("Не удалось закодировать число\n");
        }
        if (write_code_unit(out, &code_unit) == 0)
        {
            printf("Не удалось записать число\n");
            return -1;
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
int decode_file(const char *in_file_name, const char *out_file_name)
{
    return 0;
}