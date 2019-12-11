# Para compilar usar: gcc main.c lib/proj2.c lib/stack.c

# Arquivos de entrada na pasta files/inputFiles/

# Arquivos de saida na pasta files/outputFiles/

# Caso ocorra um erro onde todos os blocos ficam com peso e capacidade 0, verificar se arquivo 
  não tem uma ultima linha em branco, pois a função feof não detectar essa linha como fim de
  arquivo

# Como testamos o codigo nos arquivos que estavam no moodle, deixamos o nome dos arquivos começando 
  em 0, para definir o numero de arquivos é só mudar a constante initialFile e finalFile na main, nesse 
  caso começa no arquivo 0 e vai até o 10.