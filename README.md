# rcgeclimatologia
Meu nome é Daniela Correia, faço graduação em Ciência e Tecnologia na UFABC. 
No ano de 2024 fiz minha primeira iniciação científica, orientada pelo Dr.Marcelo Augusto Leigui com foco em ciências atmosféricas e raios cósmicos.
Neste repositório, reúno todas as macros densenvolvidas ao longo do projeto.

Como elas funcionam?
As macros estão em linguagen C++ e foram desenvolvidas para serem utilizadas com o ROOT do CERN através do prompt de comando.

Para que elas servem? 
* Produção de gráficos simples;
* produção multigráficos (úteis para sobreposições de vários gráficos com diferentes bases de dados ou sobreposição de diferentes curvas mudando único parâmetro) 
* Cálculo do coeficiente de Pearson para análises de correlações estatísticas.

Como utilizar o Root no Windows?
1) Baixe o Root do Cern no seu computador;
2) Usando o comando "cd: nome da pasta", no prompt de comando, acesse a pasta onde está localizada a sua macro;
3) Digite: "root" e aguarde ele iniciar;
4) digite: ".L nome da macro.formato dela", o root acesserá a macro escolhida 
5) digite: "nome da macro()" isso produzirá seu gráfico (essa é a modularização do código, se não funcionar abra a macro em uma IDE e verifique nas primeiras linhas algo parecido com "nomedamacro()" e digite exatamente como aparece)
6) escreva ".q"  para sair, essencial caso você queira fazer quaisquer alteração nela
7) Para alterar as macros, utilize uma IDE de C++
