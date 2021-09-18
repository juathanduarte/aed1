# AGENDA

• Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.

Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.
Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
Implementar a base de dados da agenda usando lista duplamente ligada
Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
Seguir as orientações elaborados pelo monitor para código!
Entregar um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.

- Link do vídeo: https://drive.google.com/file/d/1G1PmvWKB2jobW2AMfnrQz-DPQcoLyB3G/view?usp=sharing

# EXECUTANDO OS PROGRAMAS (compilação manual)

Para executar os arquivos, você precisa dos arquivos em seu PC.
Faça download de cada arquivo .c separadamente ou clone o repositório (git clone https://github.com/juathanduarte/aed1.git).

Linux: Instale a extensão C/C++ no VSCODE e aperte F6 para compilar o arquivo.
Windows: Instale a extensão C/C++ e Compile Run no VSCODE, configure o MinGW (GCC) e aperte F6 para compilar o arquivo.

___________________________________

Juathan C. Duarte (juathan.cduarte@inf.ufpel.edu.br).