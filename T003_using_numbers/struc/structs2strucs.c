typedef struct Pessoa
{
    int x;
    float y;
    char * name;
} Pessoa;

int main(int argc, char const *argv[])
{
    Pessoa a;

    a.name = "Madara";
    a.x = 55;
    a.y = 1.85f;
    
    return 0;
}
