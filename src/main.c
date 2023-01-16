#include "fogml_sdk/fogml.h"

#define VECTOR_SIZE 12
#define FILE_NAME "data.txt"

tinyml_zscore_config_t config;
FILE *file;
float *vector;

void setup()
{
    file = fopen(FILE_NAME, "r");
    if (file == NULL) 
    {
        printf("FILE %s NOT FOUND.", FILE_NAME);
        exit(-1);
    }
    tinyml_zscore_init(VECTOR_SIZE, &config);
    vector = (float*)calloc(VECTOR_SIZE, sizeof(float));
}

void cleanup()
{
    fclose(file);
    free(vector);
}

void parse_line_from_file()
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        fscanf(file, "%f", &vector[i]);
    }
}

void learn()
{
    for (int i = 0; i < 10; i++)
    {
        parse_line_from_file();
        tinyml_zscore_learn(vector, &config);
    }
}

void test()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 0) printf("zscore for anomalies:\n");
        if (i == 5) printf("\nzscore for proper values:\n");
        parse_line_from_file();
        float *score = tinyml_zscore_score(vector, &config);
        for (int j = 0; j < VECTOR_SIZE; j++)
        {
            printf("%f ", score[j]);
        }
        printf("\n");
        free(score);
    }
}

int main()
{
    setup();

    learn();
    test();

    cleanup();
}